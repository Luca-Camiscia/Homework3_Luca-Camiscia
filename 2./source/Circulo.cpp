#include "../Figura.hpp"

Circulo::Circulo(Posicion pos, double r):
posicion(pos), radio(r){}

void Circulo::Set(Posicion pos, double r){
    this->posicion = pos;
    this->radio = r;
}

tuple<Posicion, double> Circulo::Get(){
    return make_tuple(posicion, radio);
}