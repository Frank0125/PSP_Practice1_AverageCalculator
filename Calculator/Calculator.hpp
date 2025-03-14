#pragma once
#include "math.h"
#include <iostream>
#include <stdexcept>
#include "../Calculator/Calculator.hpp"

using namespace std;

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

        #pragma region SampleSizeCalculator 
        //Función para calcular el tamaño de muestra de una lista de números con un valor de confianza
        //de 95 y de 99
        void sampleSizeCalculator(float list[], int size, float maxError) {
            float n1, n2; //es permitido en el estandar
            float std = this->standDevCalculator(list, size);
            //trust 95
            n1 = ( 1.96 * std ) / maxError;
            n1 *= n1;
            //trust 99
            n2 = ( 2.58 * std ) / maxError;
            n2 *= n2;
            
            cout << "El tamaño de muestra de la lista dada con 95% de confianza es: " << n1
            << endl;
            cout << endl;
            cout << "El tamaño de muestra de la lista dada con 99% de confianza es: " << n2
            << endl;
            return;
        }
};