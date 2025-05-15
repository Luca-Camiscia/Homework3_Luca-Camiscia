#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <tuple> //preguntar
#include <concepts>
using namespace std;

class Posicion{
    private:
    tuple<float,float> pos;
    public:
    Posicion(float x, float y);
    void Set(float x, float y);
    tuple<float,float>Get();
};

class Circulo{
    private:
    Posicion posicion;
    float radio;
    public:
    Circulo(Posicion pos, float radio);
    void Set(Posicion pos, float radio);
    tuple<Posicion,float> Get();
};

class elipse{
    private:
    

};

