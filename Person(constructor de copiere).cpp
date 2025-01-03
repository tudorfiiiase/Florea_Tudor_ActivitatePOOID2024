#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Person {
private:
    char* name; 
    int age;    

public:
    Person(const char* personName, int personAge) : age(personAge) {
        name = new char[strlen(personName) + 1];
        strcpy_s(name, strlen(personName) + 1, personName);
    }

    // Constructor de copiere (deep copy)
    Person(const Person& other) : age(other.age) {
        name = new char[strlen(other.name) + 1]; 
        strcpy_s(name, strlen(other.name) + 1, other.name);               
    }

    // Operatorul = (deep copy)
    Person& operator=(const Person& other) {
        if (this != &other) { 
            delete[] name;    
            name = new char[strlen(other.name) + 1];
            strcpy_s(name, strlen(other.name) + 1, other.name);
            age = other.age;
        }
        return *this;
    }

    // Destructor
    ~Person() {
        delete[] name;
    }

    void print() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Person p1("Florea Tudor", 22);
    p1.print();
    Person p2 = p1;
    p2.print();
    Person p3("Popescu Maria", 20);
    p3.print();
    p3 = p1; // Folosim operatorul =
    p3.print();
    return 0;
}
