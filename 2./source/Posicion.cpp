#include "../Figura.hpp"

Posicion::Posicion(double x, double y): pos(tuple<double,double>{x,y}){

} 

void Posicion::Set(double x, double y){

    tuple<double,double> new_pos = make_tuple(x,y);
    this->pos = new_pos;

}

tuple<double,double> Posicion::Get(){
    return pos;
}