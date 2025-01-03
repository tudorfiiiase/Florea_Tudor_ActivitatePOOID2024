#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string nume;
    float media;

public:
    Student(const string& nume, float media)
        : nume(nume), media(media) {}

    void afiseazaDetalii() const {
        cout << "Nume: " << nume << ", Media: " << media << endl;
    }

    void comparaMedia(const Student& altStudent) const {
        if (this->media > altStudent.media) {
            cout << this->nume << " are o medie mai mare decat "<< altStudent.nume << "." << endl;
        }
        else if (this->media < altStudent.media) {
            cout << altStudent.nume << " are o medie mai mare decat "<< this->nume << "." << endl;
        }
        else {
            cout << this->nume << " și " << altStudent.nume << " au aceeasi medie." << endl;
        }
    }
};

int main() {
    Student s1("Florea Tudor", 8.50f);
    Student s2("Costache Alina", 9.00f);

    s1.afiseazaDetalii();
    s2.afiseazaDetalii();

    s1.comparaMedia(s2);

    return 0;
}
