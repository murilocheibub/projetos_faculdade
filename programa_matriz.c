#include <stdio.h>

int main() {
    int matriz[5][20][2], i, j, k;
    int resposta_pergunta1, resposta_pergunta2, total_respostas, total_sim, total_nao, formulario, continuar, cliente;
    int nao_p2, TC[5], total_satisfeitos, encontraram, total_clientes;

    for(i = 0; i < 5; i++) {
                TC[i] = 0;

            do {
            printf("digite se o cliente encontrou o que procurava. (1-sim / 2-nao):");
            scanf("%d", &resposta_pergunta1);
            matriz[i][TC[i]][0] = resposta_pergunta1;
            total_respostas++;

            printf("digite se o cliente ficou satisfeito 1-sim / 2-nao");
            scanf("%d", &resposta_pergunta2);
            matriz[i][TC[i]][1] = resposta_pergunta2;
            total_respostas++;

            printf("voce deseja armazenar a resposta de algum cliente? (1-sim / 2-nao)");
            scanf("%d", &cliente);

            TC[i]++;

            } while (cliente == 1 && TC[i] < 20);


    }

    do {
        printf("escolha uma das opções de relatorio:\n");
        printf("1- em um dia específico, mostre todas as respostas dos clientes\n");
        printf("2- em uma pergunta específica (1 ou 2), mostre a porcentagem de sim e nao diante do total\n");
        printf("3- dado um cliente específico em um dia específico, mostre as respostas dele\n");
        printf("4- quantos clientes foram consultados, quantos responderam “não” para as duas perguntas, quantos estão satisfeitos, a percentagem de clientes que encontraram o que precisavam no dia 5 da pesquisa\n");

        scanf("%d", &formulario);
        total_sim = 0;
        total_nao = 0;
        nao_p2 = 0;
        encontraram = 0;
        total_satisfeitos = 0;

            if (formulario == 1) {
                printf("digite o dia específico");
                scanf("%d", &i);

                for(j = 0; j < TC[i - 1]; j++) {
                    for(k = 0; k < 2; k++) {
                    printf("a resposta do cliente %d na pergunta %d é: %d\n", j + 1, k + 1, matriz[i - 1][j][k]);
                    }
                }

            } else if (formulario == 2) {
                printf("digite a pergunta que voce deseja consultar");
                scanf("%d", &k);

                for(i = 0; i < 5; i++) {
                    for(j = 0; j < TC[i]; j++) {
                        if (matriz[i][j][k - 1] == 1) {
                            total_sim += 1;
                        } else if (matriz[i][j][k - 1] == 2) {
                            total_nao += 1;

                        }

                    } 

                }
                printf("a porcentagem de respostas sim para essa pergunta é de %d\n", total_sim * 100 / total_respostas);
                printf("a porcentagem de respostas nao para essa pergunta é de %d\n", total_nao * 100 / total_respostas);

            } else if (formulario == 3) {
                printf("digite o nome do cliente");
                scanf("%d", &j);
                printf("digite o dia específico");
                scanf("%d", &i);

                for(k = 0; k < 2; k++) {
                    printf("a resposta do cliente %d no dia %d foi %d\n", j, i, matriz[i - 1][j - 1][k]);
                }
                printf("a quantidade de clientes consultados foi de %d", TC[i + 1]);

                nao_p2 = 0;

                for(i = 0; i < 5; i++) {
                    for(j = 0; j < TC[i]; j++) {

                        if (matriz[i][j][0] == 2 && matriz[i][j][1] == 2) {
                            nao_p2++;

                        }
                    }
                }
            } else if (formulario == 4) {

                for(i = 0; i < 5; i++) {

                    total_clientes += TC[i];
                 
                
                  printf("o numero total de clientes consultados foi de %d", total_clientes);

                    for(j = 0; j < TC[i]; j++) {

                        if(matriz[i][j][0] == 2 && matriz[i][j][1] == 2) {
                            nao_p2++;
                        } 

                        if (matriz[i][j][0] == 1) {
                            total_satisfeitos++;
                        }

                        if (matriz[4][j][0] == 1) {
                            encontraram++;
                        }
                    }
                    
                    printf("a quantidade de clientes que responderam 2 pras 2 perguntas foi %d", nao_p2);
                    printf("o total de clientes satisfeitos foi %d", total_satisfeitos);
                    printf("total que encontraram oq precisavam: %d", encontraram);
                }
            } else {

                printf("formulario invalido");
                }

                printf("voce deseja imprimir mais um relatorio? 1-sim / 2-nao");
                scanf("%d", &continuar);
    
    } while (continuar !=2 );

    return 0;
}



