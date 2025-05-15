#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <tuple> //preguntar
#include <concepts>
using namespace std;
constexpr double pi = 3.14159265358979323846;
template<typename F>
concept is_Pos = is_same_v<F,Posicion>;
template<typename F>
concept is_Cir = is_same_v<F,Circulo>;
template<typename F>
concept is_Eli = is_same_v<F,Elipse>;
template<typename F>
concept is_Rec = is_same_v<F,Rectangulo>;

//Podria usar mas Using para las tuplas
class Posicion{
    private:
    tuple<double,double> pos;
    public:
    Posicion(double x, double y);
    void Set(double x, double y);
    tuple<double,double>Get();
};

class Circulo{
    private:
    Posicion posicion;
    double radio;
    public:
    Circulo(Posicion pos, double r);
    void Set(Posicion pos, double r);
    tuple<Posicion,double> Get();
};

class Elipse{
    private:
    Posicion posicion;
    tuple<double, double> semiejes;
    public:
    Elipse(Posicion pos, tuple<double,double> semis);
    void Set(Posicion pos, tuple<double,double> semis);
    tuple<Posicion, tuple<double,double>> Get();
};

class Rectangulo {
    private:
    Posicion Viz;
    double ancho;
    double largo;
    public:
    Rectangulo(Posicion V, double a, double l);
    void Set(Posicion V, double a, double l);
    tuple<Posicion,double, double> Get();
};

class ProcesadorFigura{
public:
    template<typename F>
    static double Area(F f);

    template<is_Pos F>

    

    // Especialización para Circulo
    template<is_Cir F>
    static double Area(Circulo f) {
        auto [pos, radio] = f.Get();
        return pi * radio * radio;
    }

    // Especialización para Elipse
    template<is_Eli F>
    static double Area(Elipse f) {
        auto [pos, semiejes] = f.Get();
        auto [a, b] = semiejes;
        return pi * a * b;
    }

    // Especialización para Rectangulo
    template<is_Rec F>
    static double Area(Rectangulo f) {
        auto [pos, ancho, largo] = f.Get();
        return ancho * largo;
    }
};