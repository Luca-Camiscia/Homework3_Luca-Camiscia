#include "Figura.hpp"


int main(void) {
    // Ejemplo con Posicion
    Posicion pos1(4, 4);
    Posicion pos2(2, 3);
    Posicion pos3(0, 0);
    Posicion pos4(5, 1);

    // Ejemplo con Circulo
    Circulo circulo(pos1, 2.0);
    cout << "Area circulo = " << to_string(ProcesadorFigura::Area(circulo)) << endl;    
    // Ejemplo con Elipse
    Elipse elipse(pos2, make_tuple(3.0,1.5));
    cout << "Area elipse = " << to_string(ProcesadorFigura::Area(elipse)) << endl;

    // Ejemplo con Rectangulo
    Rectangulo rectangulo(pos3, 4.0, 6.0);
    cout << "Area rectangulo = " << to_string(ProcesadorFigura::Area(rectangulo)) << endl;

    return 0;
}