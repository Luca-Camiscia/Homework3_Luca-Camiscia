#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "clases.hpp"

using namespace std;

int main() {
    // 1) Probar Clase1<double>
    Clase1<double> vd;
    vd.Add(1.3);
    vd.Add(2.1);
    vd.Add(3.2);

    // 2) Probar Clase1<string>
    Clase1<string> vs;
    vs.Add("hola");
    vs.Add("mundo");

    // 3) Probar Clase1<vector<int>>
    Clase1<vector<int>> vm;
    vm.Add({1,2});
    vm.Add({3,4});

    // 4) Generar JSON con Clase2
    ofstream outFile("data.JSON", std::ios::binary);

    Clase2 j;
    cout << "\nJSON generado:" << endl;
    j.JsonStart(outFile);
    // Añadimos cada arreglo como entrada JSON
    j.JsonAdd(outFile, vd);
    cout << ", ";
    j.JsonAdd(outFile, vs);
    cout << ", ";
    j.JsonAdd(outFile, vm);
    j.JsonEnd(outFile);
    cout << endl;

    return 0;
}