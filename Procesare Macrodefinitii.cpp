#include <iostream>
using namespace std;

#define Patrat(x) x*x

int main() {
    int a = 4;
    cout << Patrat(a) << endl;     // afiseaza 16
    cout << Patrat(a + 2) << endl; // afiseaza 14
    cout << Patrat(++a) << endl;   // afiseaza 36
}