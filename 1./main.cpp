#include "Clases.hpp"


int main(void){
  
    Posicion posicion = Posicion(-34.6f, -58.4f, 950.0f, 5.3);
    Presion presion = Presion(101.3f, 5.8f, 6.1f);

    posicion.imprimir();
    presion.imprimir();

    SaveFlightData Data1 = SaveFlightData(posicion, presion);

    std::ofstream outFile("data.dat", std::ios::binary);
    Data1.serializar(outFile);


    return 0;

};