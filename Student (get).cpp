#include <iostream>
using namespace std;

class Student {
private:
    string name;

public:
    Student(const string& n) : name(n) {}
    // Metodă getName
    string getName() const {
        return name;
    }
};
