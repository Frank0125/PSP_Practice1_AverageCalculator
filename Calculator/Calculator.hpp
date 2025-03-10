#pragma once
#include "math.h"
class Calculator {
    public:
        #pragma region AverageCalculator
        //Función que calcula la media de un arreglo de números reales
        float averageCalculator(float list[], int n) {
            float sum = 0;
            for (int i = 0; i < n; i++) {
                sum += list[i];
            }
            return sum / n;
        }
        #pragma endregion

        #pragma region StandardDeviationCalculator
        //Función que calcula la desviación estándar de un arreglo de números reales
        float standDevCalculator(float list[], int n) {
            float sum = 0;
            float avg = averageCalculator(list, n);
            float* diff = new float[n];
            for (int i = 0; i < n; i++) {
                diff[i] = list[i] - avg;
                diff[i] = diff[i] * diff[i]; 
                sum += diff[i];
            }
            delete[] diff;
            return pow((sum / (n - 1)), 0.5);
        }
        #pragma endregion

        #pragma region StandardScoreCalculator
        //Función que calcula los puntajes estándar de una lista de números reales
        float* standScoreCalculator(float list[], int n) {
            float* values = new float[n];
            float avg = this->averageCalculator(list, n); //THIS apuntador para mejor memoria sisisi
            float sta = this->standDevCalculator(list, n);
            for (int i = 0; i < n; i++) {
                values[i] = ((list[i] - avg) / sta);
            }
            return values;
        }
        #pragma endregion
};