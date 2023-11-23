#ifndef __METODOS_H__
#define __METODOS_H__

#include "./utils.h"

#define DIFF 0.0
#define NRAND    ((double) rand() / RAND_MAX)  // drand48() 
#define SRAND(a) srand(a) // srand48(a)

// Integral Retângulos da função Styblinski-Tang de 2 variáveis
double retangulos_xy(double a, double b, int npontos);

double retangulos_xyprof(double a, double b, int npontos);

// Integral Monte Carlo da função Styblinski-Tang de 2, 4 e 8 variáveis
double monte_carlo(double a, double b, int namostras, int ndim);

#endif // __METODOS_H__