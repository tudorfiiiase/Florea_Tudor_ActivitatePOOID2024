#include<iostream>
#include<string>
using namespace std;

class Student {
private:
	string nume;
	int varsta;
	float media;

public:
	Student(const string nume, int varsta, float media) : nume(nume), varsta(varsta), media(media){}

	void Afisare() const
	{
		cout << "Nume:" << nume << endl;
		cout << "Varsta:" << varsta << endl;
		cout << "Media:" << media << endl;
	}
};

int main()
{
	Student student1("Florea Tudor", 22, 9.25);
	student1.Afisare();
	return 0;
}