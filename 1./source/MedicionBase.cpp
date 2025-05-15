#include "../Clases.hpp"

MedicionBase::MedicionBase(float t):tiempoMedicion(make_unique<float>(t)){};

float MedicionBase::getTiempo()const{
    return *tiempoMedicion;
}

void MedicionBase::serializar(ofstream& out){
    out.write(reinterpret_cast<const char*> (&tiempoMedicion), sizeof(tiempoMedicion));
} 

void MedicionBase::deserializar(ifstream& in){
    in.read(reinterpret_cast<char*>(&tiempoMedicion), sizeof(tiempoMedicion));
}