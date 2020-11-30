#define _um_ 1

#include <initializer_list>
#include <iostream>
#include <vector>

namespace coisas
{
    const int um = 1;
    int i = UINT_MAX;
}

using namespace std;

class Vehiculo
{
protected:
    string  nome;
    vector<string> tag;
public:
    Vehiculo() = delete;
    Vehiculo(
        int r,
        initializer_list<string> tags)
    {
        num_rodas = r;
        for (auto t : tags) tag.push_back(t);
    };
public:
    friend ostream& operator<<(ostream&, Vehiculo&);
private:
    int num_rodas;
};

class Moto : public Vehiculo
{
public:
    Moto(string n, initializer_list<string> tags) :
        Vehiculo(2, tags) {
        nome = n;
    };
};

class Triciclo : public Vehiculo
{
public:
    Triciclo(string n, initializer_list<string> tags) :
        Vehiculo(3, tags) {
        nome = n;
    };
};

class Truck : public Vehiculo
{
public:
    Truck(string n, initializer_list<string> tags) :
        Vehiculo(18, tags) {
        nome = n;
    };
};

int main(void)
{
    std::cout << "a constante " << coisas::um << endl;
    std::cout << "via define: " << _um_ << endl;

    Moto        yamaha(
        "Moto XWE-3434", { "azul", "individual", "economico", "rapido" });
    Triciclo bmw("Triciclo SWE-2323", { "preto", "especial" });
    Truck gigante("18-Wheeler Peterbilt", { "verde", "gigante", "70Ton." });

    cout << yamaha;
    cout << bmw;
    cout << gigante;
};  // main()

ostream& operator<<(ostream& o, Vehiculo& v)
{
    o << "\n=>" << v.nome << " tem " << v.num_rodas << " rodas\n";
    o << v.tag.size() <<  " Tags: ";
    for (auto t : v.tag) cout << t << " ";
    cout << endl;
    return o;
};  // mostra()
