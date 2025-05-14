#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <tuple> //preguntar
using namespace std;


class Figura{
    public:
    virtual float Area() =0;
};

class Posicion:public Figura{
    private:
    tuple<float,float> pos;
    public:
    Posicion(float x, float y);
    void Set(float x, float y);
    tuple<float,float>Get();
    float Area() override;
};

class Circulo:public Figura{
    private:
    Posicion posicion;
    float radio;
    public:
    Circulo(Posicion pos, float radio);
    void Set(Posicion pos, float radio);
    tuple<Posicion,float> Get();
    float Area() override;
};

