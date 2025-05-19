#include "../Figura.hpp"

Rectangulo::Rectangulo(Posicion V, double a,double l):
Viz(V), ancho(a), largo(l) {

    if (ancho < 0 || largo <0){
        throw invalid_argument("Error el largo/ancho no puede ser menor a 0");
    }
}

void Rectangulo::Set(Posicion V, double a, double l){
    this->Viz = V;
    this->ancho = a;
    this->largo = l;
}
void Rectangulo::SetPos(Posicion pos){
    this->Viz = pos;
}
void Rectangulo::SetAncho(double a){
    this->ancho = a;
}

void Rectangulo::SetLargo(double l){
    this->largo = l;
}

tuple<Posicion,double,double> Rectangulo::Get(){
    return make_tuple(Viz,ancho,largo);
}

Posicion Rectangulo::GetPos(){
    return this->Viz;
}

double Rectangulo::GetLar(){
    return this->largo;
}

double Rectangulo::GetAncho(){
    return this->largo;
}
