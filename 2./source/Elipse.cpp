#include "../Figura.hpp"

Elipse::Elipse(Posicion pos, tuple<double,double> semis):
posicion(pos), semiejes(semis){}

void Elipse::Set(Posicion pos, tuple<double,double> semis){
    this->posicion = pos;
    this->semiejes = semis;
}

void Elipse::SetPos(Posicion pos){
    this->posicion = pos;
}
void Elipse::SetSemi1(double semi){
    get<0>(semiejes) = semi;

}

void Elipse::SetSemi2(double semi){
    get<1>(semiejes) = semi;
}

tuple<Posicion,tuple<double, double>> Elipse::Get(){
    return make_tuple(posicion, semiejes);
}

Posicion Elipse::GetPos(){
    return this->posicion;
}

double Elipse::GetSemi1(){
    return get<0>(semiejes);
}


double Elipse::GetSemi2(){
    return get<1>(semiejes);
}
