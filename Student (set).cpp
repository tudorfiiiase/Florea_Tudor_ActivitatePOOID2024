#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    Student(const string& n, int a) : name(n), age(a) {}

    string getName() const {
        return name;
    }

    // Metodă setAge
    void setAge(int newAge) {
        if (newAge > 0) {
            age = newAge;
        }
        else {
            cout << "Varsta trebuie sa fie pozitiva!" << endl;
        }
    }

    int getAge() const {
        return age;
    }
};
