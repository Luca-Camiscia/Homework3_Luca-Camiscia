#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
using namespace std;

class Imediciones{
    public:
    virtual void serializar(ofstream& out) =0;
    virtual void deserializar(ifstream& in) = 0; //PREGUNTAR 
};

class MedicionBase: public Imediciones{
    protected:
    unique_ptr<float> tiempoMedicion;
    public:
    MedicionBase(float t);
    void serializar(ofstream& out) override;
    void deserializar(ifstream& in) override;
    float getTiempo() const;
    virtual void imprimir() = 0;
};


class Presion:public MedicionBase{
    public:
    float presionEstatica;
    float presionDinamica;
    Presion(float p, float q,float t);
    void serializar(ofstream& out) override;
    void deserializar(ifstream& in) override;
    void imprimir()override;
};

class Posicion: public MedicionBase{
    public:
    float latitud;
    float longitud;
    float altitud;
    Posicion(float lat, float lon, float alt, float t);
    void serializar(ofstream& out) override;
    void deserializar(ifstream& in) override;
    void imprimir()override;

};
class SaveFlightData{
    public:
    Posicion posicion;
    Presion presion;

    SaveFlightData(const Posicion& p, const Presion& q);
    void serializar(ofstream& out);
    void deserializar(ifstream& in);
    void imprimir();
};