#include <iostream>
#include <stdexcept>
#include "../Calculator/Calculator.hpp"
using namespace std;

#pragma region Encabezado
// Francisco Rochín Gómez
// Calculador de Puntajes Estándar
#pragma endregion 

int main() {
    try {
        Calculator c;
        int n;
        cout << "Introduce el tamaño de la lista para calcular los puntajes estándar:" 
        <<endl;
        cin >> n;
        if(cin.fail()) {
            throw invalid_argument("El valor ingresado no fue un número o no fue un " +
            std::string("número entero válido para el tamaño de la lista."));
        }
        if(n < 3 || n > 15) {
            throw invalid_argument("El tamaño de la lista de números a calificar " +
            std::string("no debe ser menor a 3 o mayor a 15."));
        }

        float* list = new float[n];
        cout << "Ahora introduce los números para calcular, uno a la vez: " <<endl;
        
        for(int i = 0; i < n; i++) {
            cin >> list[i];
            if(cin.fail()){
                throw invalid_argument("El valor ingresado para el número de" +
                std::string(" la lista no es válido."));
                delete list;
            }
            if(list[i] < 5 || list[i] > 100) {
                throw invalid_argument("Los valores de los números a calcular" +
                std::string(" no deben ser menores a 5 o mayores a 100."));
                delete list;
            }
        }
        float* zValues = c.standScoreCalculator(list, n);
        cout << "Los puntajes estándar de los números introducidos son los " 
        << "siguientes:" <<endl;
        for(int i = 0; i < n; i++) {
            cout << list[i] << " -> " << zValues[i] << endl;
        }
        delete list;
        delete zValues;
    } 
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
    }
    return 0;
}