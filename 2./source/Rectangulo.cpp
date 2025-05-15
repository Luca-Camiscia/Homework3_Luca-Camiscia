#include "../Figura.hpp"

Rectangulo::Rectangulo(Posicion V, double a,double l):
Viz(V), ancho(a), largo(l) {}

void Rectangulo::Set(Posicion V, double a, double l){
    this->Viz = V;
    this->ancho = a;
    this->largo = l;
}

tuple<Posicion,double,double> Rectangulo::Get(){
    return make_tuple(Viz,ancho,largo);
}
