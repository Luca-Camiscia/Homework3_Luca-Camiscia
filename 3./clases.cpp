#include "clases.hpp"

Clase1::Clase1(string Idnum, string Idstr, string Idmtx):
    numId(Idnum),strId(Idstr),mtxId(Idmtx)
{

}

void Clase2::Json_Convert(ostream& out, Clase1 data) {

    vector<double> doubs = data.vec_doubles;
    vector<string> pals = data.palabras;
    vector<vector<int>> mt = data.mtx;

    out << "{\n";
    out << " \"" << data.numId << "\": [";          //Voy escribiendo todo
    for (size_t i = 0; i < doubs.size(); ++i) {
        out << doubs[i];
        if (i != doubs.size() - 1) out << ", ";  // Si hay otro le pongo la coma
    }
    out << "],\n";

    out << " \""<<data.strId<<"\": [";
    for (size_t i = 0; i < pals.size(); ++i) {
        out << "\"" << pals[i] << "\"";
        if (i != pals.size() - 1) out << ", ";
    }
    out << "],\n";

    out << " \""<<data.mtxId<<"\": [\n";
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