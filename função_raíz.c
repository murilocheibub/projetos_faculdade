#include <stdio.h>
#include <math.h>

int calcula_raizes(float a, float b, float c, float raizes[]) {
    if (a == 0) {
        return 0;
    }
    float delta = (b * b) - (4 * a * c);
    if (delta > 0) {
        raizes[0] = (-b + sqrt(delta)) / (2 * a);
        raizes[1] = (-b - sqrt(delta)) / (2 * a);
        return 2;
    } else if (delta == 0) {
        raizes[0] = -b / (2 * a);
        return 1;
    } else {
        return 0;
    }
}

int main() {
    float a, b, c, raizes[2];
    int repetir;


    do {
        scanf("%f %f %f", &a, &b, &c);
    
        int qtd = calcula_raizes(a, b, c, raizes);
    
        if (a == 0) {
            printf("Nao e equacao do 2 grau.\n");
        } else if (qtd == 2) {
            printf("Duas raizes reais e distintas: %.2f e %.2f\n", raizes[0], raizes[1]);
        } else if (qtd == 1) {
            printf("Uma raiz real: %.2f\n", raizes[0]);
        } else {
            printf("A equacao nao possui raizes reais.\n");
        } 

        printf("deseja repetir? 1-sim / 2-nao\n");
        scanf("%d", &repetir);

    } while (repetir != 2);
    
        return 0;
}
