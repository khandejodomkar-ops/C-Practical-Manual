#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void writeStudentsCSV(const std::string& filename) {
    std::ofstream out(filename, std::ios::trunc);
    if (!out) {
        std::cout << "Could not open file for writing.\n";
        return;
    }

    out << "id,name,marks\n";
    out << "101,Alice,88.5\n";
    out << "102,Bob,76.0\n";
    out << "103,Charlie,92.2\n";
    out.close();
}

void readStudentsCSV(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        std::cout << "Could not open file for reading.\n";
        return;
    }

    std::string line;
    std::getline(in, line);
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> fields;
        while (std::getline(ss, token, ',')) {
            fields.push_back(token);
        }
        if (fields.size() == 3) {
            std::cout << "ID: " << fields[0] << ", Name: " << fields[1] << ", Marks: " << fields[2] << "\n";
        }
    }
    in.close();
}

int main() {
    std::string filename = "students.csv";
    writeStudentsCSV(filename);
    std::cout << "CSV written.\n";
    readStudentsCSV(filename);

    std::ifstream file(filename);
    std::streampos pos1 = file.tellg();
    std::cout << "Initial tellg(): " << pos1 << "\n";
    file.seekg(0, std::ios::end);
    std::streampos end = file.tellg();
    std::cout << "After seekg(0, end), tellg(): " << end << "\n";

    std::ofstream out(filename, std::ios::app);
    std::streampos pos2 = out.tellp();
    std::cout << "Initial tellp(): " << pos2 << "\n";
    out << "104,David,81.4\n";
    out.close();

    std::cout << "\nCSV format stores data as comma-separated fields, while file-position functions tell us where reading or writing occurs.\n";
    return 0;
}
