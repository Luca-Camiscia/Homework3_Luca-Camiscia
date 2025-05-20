// clases.hpp
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <type_traits>

using namespace std;

#define doubleTag "vec_doubles"
#define stringTag "palabras"
#define mtxTag "listas"

// Clase1: almacena datos y genera una cadena con formato simple para JSON
template<typename D>
class Clase1 {
private:
    vector<D> datos;
public:
    Clase1() = default;
    void Add(const D& new_dato) {
        datos.push_back(new_dato);
    }

    // Devuelve los datos en un string, sin corchetes, sin comas finales
    string Process() const {
        string res;
        if constexpr (is_same_v<D, double>) {
            for (size_t i = 0; i < datos.size(); ++i) {
                res += to_string(datos[i]);
                if (i + 1 < datos.size()) res += ", ";
            }
        }
        else if constexpr (is_same_v<D, string>) {
            for (size_t i = 0; i < datos.size(); ++i) {
                res += '"' + datos[i] + '"';
                if (i + 1 < datos.size()) res += ", ";
            }
        }
        else if constexpr (is_same_v<D, vector<int>>) {
            // Para vector<int>, Process devuelve subarrays: [1, 2, 3], [4, 5]
            for (size_t i = 0; i < datos.size(); ++i) {
                res += "[";
                for (size_t j = 0; j < datos[i].size(); ++j) {
                    res += to_string(datos[i][j]);
                    if (j + 1 < datos[i].size()) res += ", ";
                }
                res += "]";
                if (i + 1 < datos.size()) res += ", ";
            }
        }
        return res;
    }
};

// Clase2: genera un objeto JSON a partir de varias instancias de Clase1
class Clase2 {
private:
    bool firstEntry = true;
public:
    void JsonStart(ostream& out) {
        out << "{";
    }

    template<typename T>
    void JsonAdd(ostream& out, const Clase1<T>& datos) {
        if (!firstEntry) {
            out << ",\n ";
        }
        firstEntry = false;

        // Etiqueta según el tipo T
        if constexpr (is_same_v<T, double>) {
            out << '"' << doubleTag << '"';
        } else if constexpr (is_same_v<T, string>) {
            out << '"' << stringTag << '"';
        } else if constexpr (is_same_v<T, vector<int>>) {
            out << '"' << mtxTag << '"';
        }

        // Escribe el array de JSON
        out << ": [" << datos.Process() << "]";
    }

    void JsonEnd(ostream& out) {
        out << "}";
    }
};