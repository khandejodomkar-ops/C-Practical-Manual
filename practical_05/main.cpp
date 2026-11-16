#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int age;

public:
    Person(std::string n, int a) : name(n), age(a) {}

    void displayPerson() const {
        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
    }
};

class Student : public Person {
protected:
    std::string studentId;
    std::string course;

public:
    Student(std::string n, int a, std::string id, std::string c)
        : Person(n, a), studentId(id), course(c) {}

    void displayStudent() const {
        displayPerson();
        std::cout << "Student ID: " << studentId << "\n";
        std::cout << "Course: " << course << "\n";
    }
};

class GraduateStudent : public Student {
private:
    std::string researchTopic;

public:
    GraduateStudent(std::string n, int a, std::string id, std::string c, std::string topic)
        : Student(n, a, id, c), researchTopic(topic) {}

    void displayGraduateStudent() const {
        displayStudent();
        std::cout << "Research Topic: " << researchTopic << "\n";
    }
};

int main() {
    Student s("Aisha", 20, "STU101", "BSC CS");
    GraduateStudent gs("Rahul", 23, "GRA507", "MCA", "AI and ML");

    std::cout << "Student Details:\n";
    s.displayStudent();

    std::cout << "\nGraduate Student Details:\n";
    gs.displayGraduateStudent();

    std::cout << "\nInheritance flow: Person -> Student -> GraduateStudent\n";
    return 0;
}
