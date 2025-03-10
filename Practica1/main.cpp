#include <iostream>
#include <stdexcept>
#include "../Calculator/Calculator.hpp"
using namespace std;

#pragma region Encabezado
// Francisco Rochín Gómez
// Calculador de Media de Números
#pragma endregion 

int main() {
    try {
        int n;
        Calculator c;
        cout << "Ingrese la cantidad de números para calcular la media: ";
        cin >> n;
        if (cin.fail()) {
            throw invalid_argument("El valor ingresado no es un número entero.");
        }
        if (n < 5 || n > 15) {
            throw invalid_argument("El valor ingresado debe ser mayor o igual a 5" +
            std::string(" y menor o igual a 15."));
        }
        float* list = new float[n];
        for (int i = 0; i < n; i++) {
            cout << "Ingrese el número " << i + 1 << ": ";
            cin >> list[i];
            if (cin.fail()) {
                throw invalid_argument("El valor ingresado no es un número real.");
            }
            if (list[i] < 10 || list[i] > 100) {
                throw invalid_argument("El valor ingresado debe ser mayor o igual" +  
                    std::string( "a 10 y menor o igual a 100."));
            }
        }
        cout << "La media de los números ingresados es: " << c.averageCalculator(list, n) << endl;
        delete[] list;  
    } 
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
    }
    return 0;
}
