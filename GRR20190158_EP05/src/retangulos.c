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
	double resultado = retangulos_xy(a, b, n_amostras);	
	printf("Integral Retângulos : %f\n", resultado);

	return 0;
}