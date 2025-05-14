#include "Clases.hpp"
SaveFlightData::SaveFlightData(const Posicion& p, const Presion& q): posicion(make_shared<Posicion>(p)), presion(make_shared<Presion>(q)){

}

void SaveFlightData::serializar(ofstream& out){
    this->posicion->serializar(out);
    this->presion->serializar(out);
}

void SaveFlightData::deserializar(ifstream& in){
    this->posicion->deserializar(in);
    this->presion->deserializar(in);   
}   
