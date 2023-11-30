# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void init ( float m [3][3]) {//funcion qe recibe como parametro la matriz
    int i;
    int j;
    for (i=0; i<3; i++) {
        for ( j=0; j<3 ; j++) {
            m[i][j] = random()*100;// rellenamos los campos de la matriz con valores aleatorios
        }
    }
}

void multiplyMatrices(float m1[3][3], float m2[3][3], float result[3][3]) {
    int i, j, k;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            result[i][j] = 0;
            for (k = 0; k < 3; ++k) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void printMatriz(float m [3][3]){
    int i;
    int j;
    for (i=0; i<3; i++) {
        for ( j=0; j<3 ; j++) {
            printf ("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main (int argc, char *argv[]) {
    float matriz1 [3][3];
    float matriz2 [3][3];
    init(matriz1);
    init(matriz2);
    printf("Matriz 1:\n");
    printMatriz(matriz1);
    printf("\nMatriz 2:\n");
    printMatriz(matriz2);
    printf("\n");
    float matrizResultado[3][3];
    multiplyMatrices(matriz1, matriz2, matrizResultado);
    printf("Resultado de la multiplicación:\n");
    printMatriz(matrizResultado);
    printf ( "Fin\n"); //Imprime Fin
    return 0;
}