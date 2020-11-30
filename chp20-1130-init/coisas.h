#pragma once
#include <iostream>
#define _um_ 1

namespace coisas
{
    const int um = 1;
    int i = UINT_MAX;
}

#include "coisas.h"
#include <initializer_list>
#include <vector>
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

// fim