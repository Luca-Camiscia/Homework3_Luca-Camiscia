#include "../Clases.hpp"


Presion::Presion(float p, float q, float t)
    : MedicionBase(t), presionEstatica(p), presionDinamica(q)
{
}

void Presion::serializar(ofstream& out){
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*> (&presionEstatica), sizeof(presionEstatica));
    out.write(reinterpret_cast<const char*> (&presionDinamica), sizeof(presionDinamica));
}

void Presion::deserializar(ifstream& in){
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(presionEstatica));
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(presionDinamica));
}
void Presion::imprimir(){
    cout << "Presion\n-------------------------" << endl;
    cout << "Presion Estatica: " << presionEstatica << ", Presion Dinamica: " << presionDinamica << ", Tiempo: " << getTiempo() << std::endl;
}
