#include "../Figura.hpp"

Posicion::Posicion(double x, double y): pos(tuple<double,double>{x,y}){

} 

void Posicion::Set(double x, double y){

    tuple<double,double> new_pos = make_tuple(x,y);
    this->pos = new_pos;

}
void Posicion::SetX(double x){
    get<0>(pos) = x;
}

void Posicion::SetY(double y){
    get<1>(pos) = y;
}
tuple<double,double> Posicion::Get(){
    return pos;
}

double Posicion::GetX(){
    return get<0>(pos);
}

double Posicion::GetY(){
    return get<1>(pos);
}
