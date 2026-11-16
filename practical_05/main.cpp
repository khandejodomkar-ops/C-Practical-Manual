#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    void displayPerson() const {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
    }
};

class Student : public Person {
protected:
    string studentId;
    string course;

public:
    Student(string n, int a, string id, string c)
        : Person(n, a), studentId(id), course(c) {}

    void displayStudent() const {
        displayPerson();
        cout << "Student ID: " << studentId << "\n";
        cout << "Course: " << course << "\n";
    }
};

class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    GraduateStudent(string n, int a, string id, string c, string topic)
        : Student(n, a, id, c), researchTopic(topic) {}

    void displayGraduateStudent() const {
        displayStudent();
        cout << "Research Topic: " << researchTopic << "\n";
    }
};

int main() {
    Student s("Aisha", 20, "STU101", "BSC CS");
    GraduateStudent gs("Rahul", 23, "GRA507", "MCA", "AI and ML");

    cout << "Student Details:\n";
    s.displayStudent();

    cout << "\nGraduate Student Details:\n";
    gs.displayGraduateStudent();

    cout << "\nInheritance flow: Person -> Student -> GraduateStudent\n";
    return 0;
}
