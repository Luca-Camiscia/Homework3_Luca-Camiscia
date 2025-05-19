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


//Podria usar mas Using para las tuplas
class Posicion{
    private:
    tuple<double,double> pos;
    public:
    Posicion(double x, double y);
    void Set(double x, double y);
    void SetX(double x);
    void SetY(double y);
    tuple<double,double>Get();
    double GetX();
    double GetY();
};

class Circulo{
    private:
    Posicion posicion;
    double radio;
    public:
    Circulo(Posicion pos, double r);
    void Set(Posicion pos, double r);
    void SetPos(Posicion pos);
    void SetRad(double rad);
    tuple<Posicion,double> Get();
    Posicion GetPos();
    double GetRad();
};

class Elipse{
    private:
    Posicion posicion;
    tuple<double, double> semiejes;
    public:
    Elipse(Posicion pos, tuple<double,double> semis);
    void Set(Posicion pos, tuple<double,double> semis);
    void SetPos(Posicion pos);
    void SetSemi1(double semi);
    void SetSemi2(double semi);
    tuple<Posicion, tuple<double,double>> Get();
    Posicion GetPos();
    double GetSemi1();
    double GetSemi2();
};

class Rectangulo {
    private:
    Posicion Viz;
    double ancho;
    double largo;
    public:
    Rectangulo(Posicion V, double a, double l);
    void Set(Posicion V, double a, double l);
    void SetPos(Posicion V);
    void SetAncho(double a);
    void SetLargo(double l);
    tuple<Posicion,double, double> Get();
    Posicion GetPos();
    double GetLar();
    double GetAncho();
};

template<typename F>
concept is_Pos = is_same_v<F,Posicion>;
template<typename F>
concept is_Cir = is_same_v<F,Circulo>;
template<typename F>
concept is_Eli = is_same_v<F,Elipse>;
template<typename F>
concept is_Rec = is_same_v<F,Rectangulo>;


// Declaración general
template<typename F>
class ProcesadorFigura {
public:
    static double Area(F f) {
        return 0;
    }
};

// Especialización para Circulo
template<>
class ProcesadorFigura<Circulo> {
public:
    static double Area(Circulo f) {
        auto [pos, radio] = f.Get();
        return pi * radio * radio;
    }
};

// Especialización para Elipse
template<>
class ProcesadorFigura<Elipse> {
public:
    static double Area(Elipse f) {
        auto [pos, semiejes] = f.Get();
        auto [a, b] = semiejes;
        return pi * a * b;
    }
};

// Especialización para Rectangulo
template<>
class ProcesadorFigura<Rectangulo> {
public:
    static double Area(Rectangulo f) {
        auto [pos, ancho, largo] = f.Get();
        return ancho * largo;
    }
};