#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <tuple> 
#include <concepts>
#include <type_traits>
using namespace std;

class Clase1 {
private:
    vector<double> vec_doubles;
    vector<string> palabras;
    vector<vector<int>> mtx; 

public:
    template <typename D>
    void Add(D d) {
        if constexpr (is_same_v<D, double>) {
            vec_doubles.push_back(d);
        } else if constexpr (is_same_v<D, string>) {
            palabras.push_back(d);
        } else if constexpr (is_same_v<D, vector<int>>) {
            //Podria chequear dimensiones
            mtx.push_back(d);
        }

    }
    friend class Clase2;

};

class Clase2{
    public:
    static void Json_Convert(ostream& out, Clase1 data);
    
};