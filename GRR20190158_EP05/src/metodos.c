#include <stdio.h>
#include <math.h>
#include "../include/metodos.h"

double retangulos_xy(double a, double b, int npontos) {
    double resultado;
    double soma = 0.0;
    double t_inicial = timestamp();

    // Pela definição do enunciado, temos:
    double h = (b - a) / npontos; 
    double h_squared = h * h;

    printf("Metodo dos Retangulos (x, y).\n");
    printf("a = (%f), b = (%f), n = (%d), h = (%lg)\n", a, b, npontos, h);

    // Calcula a função de Styblinski-Tang para as coordenadas (x, y)
    for (double i = a; i < b; i += h) {
        double xx = i * i;
        double fx = xx * xx - 16 * xx + 5 * i; // ∑ = x⁴ - 16x² + 5x

        for (double j = a; j < b; j += h){
            double yy = j * j;
            double fxy = fx + (yy * yy - 16 * yy + 5 * j); // ∑ = ∑ + y⁴ - 16y² + 5y
            soma += fxy;
        }
    }

    // resultado = f(x,y) * h² = (soma / 2.0) * h²
    resultado = soma * h_squared / 2.0;

    double t_final = timestamp();

    printf("Tempo decorrido: %f seg.\n\n", (t_final - t_inicial) / 1000);
    
    return resultado;
}

double f(double x, double y){
    double xx = x*x;
    double yy = y*y;
    return ( xx * xx - 16 * xx + 5 * x + yy * yy - 16 * yy + 5 * y);
}

double monte_carlo(double a, double b, int namostras, int ndim) {
    printf("Método de Monte Carlo (%d dimensões).\n", ndim);
    printf("a = (%f), b = (%f), n = (%d), variaveis = %d\n", a, b, namostras, ndim);
    
    double resultado = 0.0;
    double soma = 0.0;
    double t_inicial = timestamp();

    // Calcula a função de Styblinski-Tang para as coordenadas (x, y)
    for (int i = 0; i < namostras; ++i) {
        double coordenadas[ndim];
        double fxy = 0.0;

        // Geração de coordenadas aleatórias para cada dimensão
        for (int j = 0; j < ndim; ++j) {
            coordenadas[j] = a + NRAND * (b - a);
        }

        // Cálculo da função Styblinski-Tang para ndim dimensoes
        for (int j = 0; j < ndim; ++j) {
            double x = coordenadas[j];
            double xx = x * x;

            // ∑ = x⁴ - 16x² + 5x
            fxy += xx * xx - 16 * xx + 5 * x;
        }

        soma += fxy;
    }
    // f(x,y) = ∑ / 2
    soma /= 2.0;

    // Considerando a normalização ( (b-a) ^ ndim ), o resultado fica:
    resultado = (soma * pow((b - a), ndim)) / namostras;

    double t_final = timestamp();
    printf("Tempo decorrido: %f seg.\n", (t_final - t_inicial)/1000);

    return resultado;
}
