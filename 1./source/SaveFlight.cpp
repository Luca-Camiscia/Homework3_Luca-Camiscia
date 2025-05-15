#include "../Clases.hpp"
SaveFlightData::SaveFlightData(const Posicion& p, const Presion& q) :
    posicion(p.latitud, p.longitud, p.altitud, p.getTiempo()),
    presion(q.presionEstatica, q.presionDinamica, q.getTiempo())
{
}

void SaveFlightData::serializar(ofstream& out){
    posicion.serializar(out);
    presion.serializar(out);
}

void SaveFlightData::deserializar(ifstream& in){
    posicion.deserializar(in);
    presion.deserializar(in);   
}   

void SaveFlightData::imprimir(){
    posicion.imprimir();
    presion.imprimir();
}