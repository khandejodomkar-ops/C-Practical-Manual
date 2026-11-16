#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void writeStudentsCSV(const string& filename) {
    ofstream out(filename, ios::trunc);
    if (!out) {
        cout << "Could not open file for writing.\n";
        return;
    }

    out << "id,name,marks\n";
    out << "101,Alice,88.5\n";
    out << "102,Bob,76.0\n";
    out << "103,Charlie,92.2\n";
    out.close();
}

void readStudentsCSV(const string& filename) {
    ifstream in(filename);
    if (!in) {
        cout << "Could not open file for reading.\n";
        return;
    }

    string line;
    getline(in, line);
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        vector<string> fields;
        while (getline(ss, token, ',')) {
            fields.push_back(token);
        }
        if (fields.size() == 3) {
            cout << "ID: " << fields[0] << ", Name: " << fields[1] << ", Marks: " << fields[2] << "\n";
        }
    }
    in.close();
}

int main() {
    string filename = "students.csv";
    writeStudentsCSV(filename);
    cout << "CSV written.\n";
    readStudentsCSV(filename);

    ifstream file(filename);
    streampos pos1 = file.tellg();
    cout << "Initial tellg(): " << pos1 << "\n";
    file.seekg(0, ios::end);
    streampos end = file.tellg();
    cout << "After seekg(0, end), tellg(): " << end << "\n";

    ofstream out(filename, ios::app);
    streampos pos2 = out.tellp();
    cout << "Initial tellp(): " << pos2 << "\n";
    out << "104,David,81.4\n";
    out.close();

    cout << "\nCSV format stores data as comma-separated fields, while file-position functions tell us where reading or writing occurs.\n";
    return 0;
}
