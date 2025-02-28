#include <iostream>
using namespace std;

#pragma region Encabezado
// Francisco Rochín Gómez
// Calculador de Media de Números
#pragma endregion 

//Función que calcula la media de un arreglo de números reales
float averageCalculator(float list[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += list[i];
    }
    return sum / n;
}

int main() {
    try{
        int n;
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
                throw invalid_argument("El valor ingresado debe ser mayor o igual a 10" + 
                    std::string("y menor o igual a 100."));
            }
        }
        delete[] list;  
    } catch (exception e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
