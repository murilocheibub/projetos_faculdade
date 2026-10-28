#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

void cadastrarProduto(Produto *p) {
    printf("\n--- Cadastro de Produto ---\n");
    printf("Digite o codigo do produto: ");
    scanf("%d", &p->codigo);
    
    while (getchar() != '\n');
    
    printf("Digite o nome do produto: ");
    fgets(p->nome, 50, stdin);
    p->nome[strcspn(p->nome, "\n")] = '\0';
    
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &p->quantidade);
    
    printf("Digite o preco unitario (R$): ");
    scanf("%f", &p->preco);
}

void exibirProduto(Produto p) {
    printf("\n-----------------------------------\n");
    printf("Codigo     : %d\n", p.codigo);
    printf("Nome       : %s\n", p.nome);
    printf("Quantidade : %d unidades\n", p.quantidade);
    printf("Preco      : R$ %.2f\n", p.preco);
    printf("Valor Total: R$ %.2f\n", p.quantidade * p.preco);
    printf("-------------------------------------\n");
}

int main() {
    int n, i;

    printf("=== SISTEMA DE CONTROLE DE ESTOQUE ===\n");
    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &n);

    Produto *estoque = (Produto*) malloc(n * sizeof(Produto));

    if (estoque == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("\nCadastrando o produto %d de %d:\n", i + 1, n);
        cadastrarProduto(&estoque[i]);
    }

    // Exibição de todos os produtos cadastrados
    printf("\n\n=== RELATORIO GERAL DE ESTOQUE ===\n");
    for (i = 0; i < n; i++) {
        exibirProduto(estoque[i]);
    }

    free(estoque);
    estoque = NULL;

    printf("\nMemoria liberada com sucesso. Fim do programa!\n");
    return 0;
}

