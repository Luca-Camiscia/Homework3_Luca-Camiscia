#include "../Clases.hpp"


Posicion::Posicion(float lat, float lon,float alt, float t): MedicionBase(t), latitud(lat), longitud(lon), altitud(alt){
};


void Posicion::serializar(ofstream& out){
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(latitud));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(longitud));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(altitud));
}

void Posicion::deserializar(ifstream& in){
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&latitud), sizeof(latitud));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(longitud));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(altitud));
}


void Posicion::imprimir(){
    cout << "Posicion\n-------------------------" << endl;
    cout << "Latitud: " << latitud << ", Longitud: " << longitud << ", Altitud: " << altitud << ", Tiempo: " << getTiempo() << std::endl;
}
