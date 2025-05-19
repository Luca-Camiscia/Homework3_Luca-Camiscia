#include "clases.hpp"


void Clase2::Json_Convert(ostream& out, Clase1 data) {

    //Esto lo hice para que quede mas lindo pero capaz es muy mala para la memoria
    vector<double> doubs = data.vec_doubles;
    vector<string> pals = data.palabras;
    vector<vector<int>> mt = data.mtx;

    out << "{\n";
    out << "  \"vec_doubles\": [";          //Voy escribiendo todo
    for (size_t i = 0; i < doubs.size(); ++i) {
        out << doubs[i];
        if (i != doubs.size() - 1) out << ", ";  // Si hay otro le pongo la coma
    }
    out << "],\n";

    out << "  \"palabras\": [";
    for (size_t i = 0; i < pals.size(); ++i) {
        out << "\"" << pals[i] << "\"";
        if (i != pals.size() - 1) out << ", ";
    }
    out << "],\n";

    out << "  \"mtx\": [\n";
    for (size_t i = 0; i < mt.size(); ++i) {
        out << "    [";
        for (size_t j = 0; j < mt[i].size(); ++j) {
            out << mt[i][j];
            if (j != mt[i].size() - 1) out << ", ";
        }
        out << "]";
        if (i != mt.size() - 1) out << ",";
        out << "\n";
    }
    out << "  ]\n";
    out << "}\n";


    //Ahora lo quiero imprimir por consola
    
}