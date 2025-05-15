#include "../Clases.hpp"

MedicionBase::MedicionBase(float t):tiempoMedicion(make_unique<float>(t)){};

float MedicionBase::getTiempo()const{
    return *tiempoMedicion;
}
