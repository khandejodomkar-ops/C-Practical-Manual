#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class Book {
private:
    int id;
    std::string title;
    std::string author;
    bool available;

public:
    Book() : id(0), title(""), author(""), available(true) {}
    Book(int id, std::string title, std::string author, bool available) : id(id), title(title), author(author), available(available) {}

    int getId() const { return id; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    bool isAvailable() const { return available; }

    void issue() {
        if (!available) {
            throw std::runtime_error("Book already issued.");
        }
        available = false;
    }

    void returnBook() {
        if (available) {
            throw std::runtime_error("Book is already available.");
        }
        available = true;
    }

    void display() const {
        std::cout << id << " | " << title << " | " << author << " | " << (available ? "Available" : "Issued") << "\n";
    }
};

class Library {
private:
    std::vector<Book> books;
    std::string fileName;

public:
    Library(const std::string& fileName) : fileName(fileName) {
        load();
    }

    void addBook(int id, const std::string& title, const std::string& author, bool available = true) {
        for (const auto& book : books) {
            if (book.getId() == id) {
                throw std::runtime_error("Book ID already exists.");
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
            throw std::runtime_error("Book not found.");
        }
        book->issue();
        save();
    }

    void returnBook(int id) {
        Book* book = findBook(id);
        if (!book) {
            throw std::runtime_error("Book not found.");
        }
        book->returnBook();
        save();
    }

    void save() const {
        std::ofstream out(fileName, std::ios::trunc);
        if (!out) {
            throw std::runtime_error("Unable to open library file.");
        }
        for (const auto& book : books) {
            out << book.getId() << "," << book.getTitle() << "," << book.getAuthor() << "," << (book.isAvailable() ? 1 : 0) << "\n";
        }
        out.close();
    }

    void load() {
        std::ifstream in(fileName);
        if (!in) {
            return;
        }
        books.clear();
        std::string line;
        while (std::getline(in, line)) {
            if (line.empty()) continue;
            std::size_t pos1 = line.find(',');
            std::size_t pos2 = line.find(',', pos1 + 1);
            std::size_t pos3 = line.find(',', pos2 + 1);
            if (pos1 == std::string::npos || pos2 == std::string::npos || pos3 == std::string::npos) continue;
            int id = std::stoi(line.substr(0, pos1));
            std::string title = line.substr(pos1 + 1, pos2 - pos1 - 1);
            std::string author = line.substr(pos2 + 1, pos3 - pos2 - 1);
            bool available = (std::stoi(line.substr(pos3 + 1)) == 1);
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

        std::cout << "Library books:\n";
        library.listBooks();

        std::cout << "\nTrying to issue again...\n";
        library.issueBook(101);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    std::cout << "\nThis mini project uses OOP, STL, files, and exceptions.\n";
    return 0;
}
