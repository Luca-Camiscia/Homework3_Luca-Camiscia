#include "Clases.hpp"

int main(void){
    {
        Posicion posicion = Posicion(-34.6f, -58.4f, 950.0f, 5.3);
        Presion presion = Presion(101.3f, 5.8f, 6.1f);

        posicion.imprimir();
        presion.imprimir();

        //Prueba serializacion 
        SaveFlightData Data1 = SaveFlightData(posicion, presion);

        ofstream outFile("data.dat", std::ios::binary);
        if (outFile.is_open()){ 
            Data1.serializar(outFile);
            outFile.close();
        }
        
        // Aquí termina el scope de posicion, presion y Data1. Si no lo agrego tengo el tema de los dos frees
    }

    //Creo un Data2
    Posicion pos2 = Posicion(0,0,0,0);
    Presion pres2 = Presion(0,0,0);
    SaveFlightData Data2 = SaveFlightData(pos2,pres2);

    //Imprimo lo vacio
    Data2.imprimir();

    cout << "Deserealizo\n------------------" << endl;

    ifstream inFile("data.dat", std::ios::binary);
    if (inFile.is_open()) { 
        Data2.deserializar(inFile);
        inFile.close();
    }

    Data2.imprimir();

    return 0;
}
