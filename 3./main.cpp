#include "clases.hpp"

int main(void){
    Clase1 Datatest = Clase1("vec_doubles","palabras","listas");
    Datatest.Add(1.3);
    Datatest.Add(2.1);
    Datatest.Add(string("Hola"));
    Datatest.Add(vector<int>{1,2});
    Datatest.Add(string("Mundo"));
    Datatest.Add(vector<int>{3,4});
    Datatest.Add(3.2);
    Datatest.Add(float(12)); //Sera omitido al no estar implementado
    ofstream outFile("data.JSON", std::ios::binary);
    Clase2::Json_Convert(outFile,Datatest);
    outFile.close();
    ifstream inFile("data.JSON", std::ios::binary);
    Clase2::JsonPrint(inFile);



}