#include <iostream>
#include <string>
using namespace std;

class Laptop {
private:
    std::string brand;
    int ram;

public:
    Laptop(const std::string& brandName, int ramSize) : brand(brandName), ram(ramSize) {}

    // Declarăm funcția friend
    friend void getDetails(const Laptop& laptop);
};

// Funcția friend care accesează atributele private ale clasei Laptop
void getDetails(const Laptop& laptop) {
    cout << "Brand: " << laptop.brand << ", RAM: " << laptop.ram << " GB" << endl;
}

int main() {
    Laptop laptop1("Dell", 16);  
    getDetails(laptop1);        
    Laptop laptop2("Apple", 32);
    getDetails(laptop2);        // Apelăm funcția friend pentru un alt laptop
    return 0;
}
