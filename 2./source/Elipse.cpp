#include "../Figura.hpp"

Elipse::Elipse(Posicion pos, tuple<double,double> semis):
posicion(pos), semiejes(semis){}

void Elipse::Set(Posicion pos, tuple<double,double> semis){
    this->posicion = pos;
    this->semiejes = semis;
}

tuple<Posicion, std::tuple<double, double>> Elipse::Get(){
    return std::make_tuple(posicion, semiejes);
}
