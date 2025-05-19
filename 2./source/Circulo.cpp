#include "../Figura.hpp"

Circulo::Circulo(Posicion pos, double r):
posicion(pos), radio(r){

    if (radio < 0){
        throw invalid_argument("El radio no puede ser menor a 0");
    }
    
}

void Circulo::Set(Posicion pos, double r){
    this->posicion = pos;
    this->radio = r;
}

void Circulo::SetPos(Posicion pos){
    this->posicion = pos;
}
void Circulo::SetRad(double rad){
    this->radio = rad;
}

tuple<Posicion, double> Circulo::Get(){
    return make_tuple(posicion, radio);
}

Posicion Circulo::GetPos(){
    return this->posicion;
}

double Circulo::GetRad(){
    return radio;
}