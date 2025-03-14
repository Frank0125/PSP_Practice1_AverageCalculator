#include "../Calculator/Calculator.hpp"

#pragma region Encabezado
// Francisco Rochín Gómez
// Calculador de Tamaño de Muestra
#pragma endregion 

int main() {
    try {
        Calculator c;
        int n;
        cout << "Introduce el tamaño de la lista para calcular los tamaños de muestra:" 
        << endl;
        cin >> n;
        if(cin.fail()) {
            throw invalid_argument("El valor ingresado no fue un número o no fue un " +
            std::string("número entero válido para el tamaño de la lista."));
        }
        if(n < 10 || n > 20) {
            throw invalid_argument("El tamaño de la lista de números a calificar " +
            std::string("no debe ser menor a 10 o mayor a 20."));
        }

        float* list = new float[n];
        cout << "Ahora introduce los números para calcular, uno a la vez: " <<endl;
        
        for(int i = 0; i < n; i++) {
            cin >> list[i];
            if(cin.fail()){
                throw invalid_argument("El valor ingresado para el número de " +
                std::string("la lista no es válido."));
                delete list;
            }
            if(list[i] < 3000 || list[i] > 15000) {
                throw invalid_argument("Los valores de los números a calcular" +
                std::string(" no deben ser menores a 3000 o mayores a 15000."));
                delete list;
            }
        }
        
        cout << "Resultado: " << endl;
        c.sampleSizeCalculator(list, n, 1000);
        delete list;
    } 
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
    }
    return 0;
}