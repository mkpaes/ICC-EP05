#include <stdio.h>
#include <stdlib.h>

#include "../include/metodos.h"

int main(int argc, char **argv) {
	if (argc < 4) {
		printf("Utilização: %s inicial final n_amostras\n", argv[0]);
		return 1;
	}

	// LER VALORES DA LINHA DE COMANDO
	double a = atof(argv[1]);  // Valor inicial
	double b = atof(argv[2]);  // Valor final
	int n_amostras = atoi(argv[3]);  // Número de amostras

	// INICIAR VALOR DA SEMENTE
	SRAND(20232);

	// CHAMA FUNÇÃO DE INTEGRAÇÃO E EXIBE RESULTADO
	double resultado;

	// Dimensões = 2
	resultado = monte_carlo(a, b, n_amostras, 2);
	printf("Integral Monte Carlo (2): %f\n\n", resultado);

	// Dimensões = 4
	resultado = monte_carlo(a, b, n_amostras, 4);
	printf("Integral Monte Carlo (4): %f\n\n", resultado);

	// Dimensões = 8
	resultado = monte_carlo(a, b, n_amostras, 8);
	printf("Integral Monte Carlo (8): %f\n\n", resultado);

	return 0;
}