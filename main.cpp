// Tema1(TC1). Clasa Autobuz;

#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
class Autobuz
{
private:
    static int nrAutobuze;
    int idAutobuz;
    int capacitate;
    int nrPersoaneImbarcate;
    char* producator;

public:
    Autobuz() : idAutobuz(++nrAutobuze)
    {
        this->capacitate=0;
        this->nrPersoaneImbarcate=0;
        this->producator = nullptr;
    }
    Autobuz(int capacitate, int nrPersoaneimbarcate, const char* producator) :idAutobuz(++nrAutobuze)
    {
        if (capacitate>=0)
            this->capacitate=capacitate;
        if (nrPersoaneimbarcate<=capacitate)
            this->nrPersoaneImbarcate=nrPersoaneImbarcate;
        else
        {
            nrPersoaneimbarcate=capacitate;
            cout << "Autobuzul este plin. " << "Are o supracapacitate de: " << nrPersoaneImbarcate << " persoane " << "; Autobuzul: " << this->idAutobuz << endl;
            this->nrPersoaneImbarcate=capacitate;
            cout << "Capacitatea a fost redusa la numarul de persoane imbarcate.\n";
        }
        this->producator = new char[strlen(producator) + 1]; // alocare dinamica a memorie pentru string literal char *producator;
        strcpy_s(this->producator, strlen(producator) + 1, producator);
    }
    Autobuz(const Autobuz& b) : idAutobuz(++nrAutobuze)
    {
        this->capacitate = b.capacitate;
        this->nrPersoaneImbarcate = b.nrPersoaneImbarcate;
        this->producator = new char[strlen(b.producator) + 1]; // aloca dinamica a memorie pentru string literal char *producator;
        strcpy(this->producator, b.producator);
    }
    int getcapacitate()
    {
		return this->capacitate;
    }

	void setcapacitate(int locuri)
	{
		if (locuri > 0)
			this->capacitate = capacitate;
	}

	int getnrPersoaneImbarcate()
	{
		return this->nrPersoaneImbarcate;
	}

	void setnrPersoaneImbarcate(int _pasageri)
	{
		if (_pasageri > 0)
			this->nrPersoaneImbarcate = _pasageri;
	}
    ~Autobuz()
    {
        if (this->producator != nullptr)
        {
            delete[] producator;
            cout << "Destructor chemat !!! \n";
        }
    }
    Autobuz &operator=(const Autobuz& b)
    {
        if (&b != this) // evitam auto-atribuirea;
        {
            this->capacitate = b.capacitate;
            this->nrPersoaneImbarcate = b.nrPersoaneImbarcate;
            delete[] producator;
            this->producator = new char[strlen(b.producator) + 1];
            strcpy(this->producator, b.producator);
            if (b.producator != NULL) {
				this->producator = new char[strlen(b.producator) + 1];
				strcpy_s(this->producator, strlen(b.producator) + 1, b.producator);
			}
			else {
				this->producator = NULL;
			}
        }
        return *this; // returneaza referinta la obiectul Autobuz, evitand copierea obiectului
    }

    friend ostream& operator<<(ostream& Ostream, const Autobuz& b);

    int getNumarLocuriLibere()
    {
		return capacitate - nrPersoaneImbarcate;
	}

	operator int()
	{
		return nrPersoaneImbarcate;
	}

	bool operator>(Autobuz& b)
	{
		if (this->capacitate > b.capacitate)
			return true;
		else
			return false;
	}

    // Overloading operator <<
    ostream& operator<<(ostream& Ostream, const Autobuz& b)
    {
	Ostream << b.idAutobuz << "\n";
	Ostream << b.capacitate << "\n";
	Ostream << b.nrPersoaneImbarcate << "\n";
	if (b.producator == nullptr)
		Ostream << "Producator: nedefinit\n";
	else
		Ostream << "Producator: " << b.producator << "\n";
	return Ostream;
}

    // Getter and Setter;
    int getCapacitate() const
    {
        return this->capacitate;
    }
    void setCapacitate(int newCapacitate)
    {
        if (newCapacitate >= this->nrPersoaneImbarcate)
        {
            this->capacitate = newCapacitate;
            cout << "Noua capacitate a autobuzului a fost setata la: " << this->capacitate << endl;
        }
        else
            cout << "Noua capacitate nu poate fi mai mica decant numarul de persoane. \n";
    }

    int getPersoaneImbarcate() const
    {
        return this->nrPersoaneImbarcate;
    }
    void setPersoaneImbarcate(int pers)
    {
        if (nrPersoaneImbarcate <= this->capacitate)
        {
            this->nrPersoaneImbarcate = nrPersoaneImbarcate;
            cout << "Autobuzul are capacitatea admisa. \n";
        }
        else if (pers > this->capacitate)
        {
            this->nrPersoaneImbarcate = this->capacitate;
            cout << "Autobuzul are peste capacitatea admisa. " << "Autobuzul se opreste. \n";
            cout << (pers - this->capacitate) << " de persoane se vor da jos la oprire /in statie. \n";
        }
    }

     // operator cast to int;
    operator int() const
    {
        return this->nrPersoaneImbarcate;
    }
    bool operator>(const Autobuz& b) const
    {
        return this->capacitate > b.capacitate;
    }
    int getNumarLocuriLibere() const
    {
        int locuriLibere = this->capacitate - this->nrPersoaneImbarcate;
        return this -> capacitate - this ->nrPersoaneImbarcate;
    }
};

// Initializare membru/atribut static;
int Autobuz::nrAutobuze = 0;

int main() {
	char producator1[] = "Producator 1";
	Autobuz b1(10, 5, producator1);
	Autobuz b2(b1);
	Autobuz b3;
	b3 = b1;
	cout << "b1: " << b1 << "\n";
	cout << "b2: " << b2 << "\n";
	cout << "b3: " << b3 << "\n";

	b1.setcapacitate(4);
	cout << "capacitate b1: " << b1.getcapacitate() << "\n";
	b1.setnrPersoaneImbarcate(2);
	cout << "persoane imbarcate b1: " << b1.getnrPersoaneImbarcate() << "\n";
	cout << "nr locuri libere b1: " << b1.getNumarLocuriLibere() << "\n";

	int nrPersoaneImbarcate_b1 = b1;
	cout << "persoane imbarcate b1: " << nrPersoaneImbarcate_b1 << "\n";

	char producator2[] = "Producator 2";
	Autobuz b4(11, 5, producator2);

	bool x = b1 > b4;
	cout << "b1 > b4: " << x << "\n";
}
