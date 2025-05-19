#include "clases.hpp"

int main(void){
    Clase1 Datatest;
    Datatest.Add(1.3);
    Datatest.Add(2.1);
    Datatest.Add(string("Hola"));
    Datatest.Add(vector<int>{1,2});
    Datatest.Add(string("Mundo"));
    Datatest.Add(vector<int>{3,4});
    Datatest.Add(3.2);

    ofstream outFile("data.JSON", std::ios::binary);
    Clase2::Json_Convert(outFile,Datatest);




}