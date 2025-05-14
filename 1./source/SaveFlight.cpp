#include "../Clases.hpp"
SaveFlightData::SaveFlightData(const Posicion& p, const Presion& q)
    : posicion(p), presion(q) {
}
void SaveFlightData::serializar(ofstream& out){
    this->posicion->serializar(out);
    this->presion->serializar(out);
}

void SaveFlightData::deserializar(ifstream& in){
    this->posicion->deserializar(in);
    this->presion->deserializar(in);   
}   

void SaveFlightData::imprimir(){
    this->posicion->imprimir();
    this->presion->imprimir();
}