#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    bool available;

public:
    Book() : id(0), title(""), author(""), available(true) {}
    Book(int id, string title, string author, bool available) : id(id), title(title), author(author), available(available) {}

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool isAvailable() const { return available; }

    void issue() {
        if (!available) {
            throw runtime_error("Book already issued.");
        }
        available = false;
    }

    void returnBook() {
        if (available) {
            throw runtime_error("Book is already available.");
        }
        available = true;
    }

    void display() const {
        cout << id << " | " << title << " | " << author << " | " << (available ? "Available" : "Issued") << "\n";
    }
};

class Library {
private:
    vector<Book> books;
    string fileName;

public:
    Library(const string& fileName) : fileName(fileName) {
        load();
    }

    void addBook(int id, const string& title, const string& author, bool available = true) {
        for (const auto& book : books) {
            if (book.getId() == id) {
                throw runtime_error("Book ID already exists.");
            }
        }
        books.push_back(Book(id, title, author, available));
        save();
    }

    void listBooks() const {
        for (const auto& book : books) {
            book.display();
        }
    }

    Book* findBook(int id) {
        for (auto& book : books) {
            if (book.getId() == id) return &book;
        }
        return nullptr;
    }

    void issueBook(int id) {
        Book* book = findBook(id);
        if (!book) {
            throw runtime_error("Book not found.");
        }
        book->issue();
        save();
    }

    void returnBook(int id) {
        Book* book = findBook(id);
        if (!book) {
            throw runtime_error("Book not found.");
        }
        book->returnBook();
        save();
    }

    void save() const {
        ofstream out(fileName, ios::trunc);
        if (!out) {
            throw runtime_error("Unable to open library file.");
        }
        for (const auto& book : books) {
            out << book.getId() << "," << book.getTitle() << "," << book.getAuthor() << "," << (book.isAvailable() ? 1 : 0) << "\n";
        }
        out.close();
    }

    void load() {
        ifstream in(fileName);
        if (!in) {
            return;
        }
        books.clear();
        string line;
        while (getline(in, line)) {
            if (line.empty()) continue;
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.find(',', pos2 + 1);
            if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos) continue;
            int id = stoi(line.substr(0, pos1));
            string title = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string author = line.substr(pos2 + 1, pos3 - pos2 - 1);
            bool available = (stoi(line.substr(pos3 + 1)) == 1);
            books.push_back(Book(id, title, author, available));
        }
    }
};

int main() {
    Library library("library.csv");

    try {
        library.addBook(101, "C++ Primer", "Lippman", true);
        library.addBook(102, "Effective Modern C++", "Meyers", true);
        library.addBook(103, "Thinking in Java", "Eckel", true);
        library.issueBook(101);

        cout << "Library books:\n";
        library.listBooks();

        cout << "\nTrying to issue again...\n";
        library.issueBook(101);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";
    }

    cout << "\nThis mini project uses OOP, STL, files, and exceptions.\n";
    return 0;
}
