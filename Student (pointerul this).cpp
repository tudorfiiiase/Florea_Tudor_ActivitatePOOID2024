#include<iostream>
#include<string>
using namespace std;

class Student {
private:
	string nume;
	int varsta;
	float media;

public:
	Student(const string nume, int varsta, float media) : nume(nume), varsta(varsta), media(media) {}

	void Afisare() const
	{
		cout << "Nume:" << nume << endl;
		cout << "Varsta:" << varsta << endl;
		cout << "Media:" << media << endl;
	}

	void comparaMedia(const Student& Altstudent) {
		if (this->media > Altstudent.media)
			cout << nume << " are o medie mai mare decat " << Altstudent.media << "." << endl:
		else if (this->media < Altstudent.media)
			cout << Altstudent.nume << " are o medie mai mare decat " << nume << "." << endl;
		else
			cout << nume << "si" << Altstudent.nume << " au aceasi medie." << endl;
	};
};

int main()
{
	Student student1("Florea Tudor", 22, 9.25);
	Student student2("Muntean Andrei", 21, 9.5);
	student1.Afisare();
	student2.Afisare();
	student1.comparaMedia(student2);
	return 0;
}