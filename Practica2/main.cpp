#include <iostream>
#include <stdexcept>
#include "../Calculator/Calculator.hpp"
using namespace std;

#pragma region Encabezado
// Francisco Rochín Gómez
// Calculador de Desviación Standard
#pragma endregion 

int main() {
    try {
        int n;
        Calculator c;
        cout << "Ingresa la cantidad de números para calcular su desviación estándar: " <<endl;
        cin >> n;
        if(cin.fail()) {
            throw invalid_argument("El tipo de valor introducido no es aceptado.");
        }
        if(n >15 || n < 5) {
            throw invalid_argument("El tamaño de lista de números a calificar debe no debe ser menor a " +
            std::string("5 o mayor a 15."));
        }

        float *list = new float[n];
        for (int i; i < n; i++){
            cout << "Ingresa los números a calcular, uno por uno:";
            cin >> list[i];
            if (cin.fail()) {
                throw invalid_argument("El tipo de valor introducido no es aceptado.");
            }
            if(list[i] > 100 || list[i] < 5) {
                throw invalid_argument("El valor de número a calcular no debe ser menor a 5 o mayor a" +
                std::string("100"));
            }
        }
        cout<<"La desviación estándar de la lista dada es: " << c.standDevCalculator(list, n);
    } catch(const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}