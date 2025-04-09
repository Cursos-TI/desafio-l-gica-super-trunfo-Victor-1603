
// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta de país
typedef struct {
    char nome[50];
    int populacao;
    int area;
    int densidade;
    int pib;
} Carta;

// Função para exibir os atributos disponíveis
void exibirAtributos() {
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - Densidade Demografica\n");
    printf("4 - PIB\n");
}

// Função para selecionar um atributo garantindo que não seja repetido
int selecionarAtributo(int escolhido) {
    int opcao;
    do {
        printf("Escolha um atributo diferente do anterior: ");
        scanf("%d", &opcao);
        if (opcao == escolhido) {
            printf("Erro: voce ja escolheu esse atributo. Tente novamente.\n");
        }
    } while (opcao == escolhido);
    return opcao;
}

// Função para obter o valor de um atributo específico de uma carta
int obterValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.densidade;
        case 4: return c.pib;
        default: return 0;
    }
}

// Função para determinar o vencedor com base na soma dos atributos
void determinarVencedor(Carta c1, Carta c2, int atributo1, int atributo2) {
    int valor1_1 = obterValorAtributo(c1, atributo1);
    int valor1_2 = obterValorAtributo(c1, atributo2);
    int valor2_1 = obterValorAtributo(c2, atributo1);
    int valor2_2 = obterValorAtributo(c2, atributo2);

    int pontosC1 = ((atributo1 == 3 ? valor1_1 < valor2_1 : valor1_1 > valor2_1) ? 1 : 0) +
                   ((atributo2 == 3 ? valor1_2 < valor2_2 : valor1_2 > valor2_2) ? 1 : 0);

    int pontosC2 = ((atributo1 == 3 ? valor2_1 < valor1_1 : valor2_1 > valor1_1) ? 1 : 0) +
                   ((atributo2 == 3 ? valor2_2 < valor1_2 : valor2_2 > valor1_2) ? 1 : 0);

    int soma1 = valor1_1 + valor1_2;
    int soma2 = valor2_1 + valor2_2;

    printf("\nResultado:\n");
    printf("%s - %s\n", c1.nome, c2.nome);
    printf("Atributos escolhidos: %d e %d\n", atributo1, atributo2);
    printf("Valores: %d e %d para %s | %d e %d para %s\n", valor1_1, valor1_2, c1.nome, valor2_1, valor2_2, c2.nome);
    printf("Somas: %d para %s | %d para %s\n", soma1, c1.nome, soma2, c2.nome);

    if (soma1 > soma2) {
        printf("Vencedor: %s!\n", c1.nome);
    } else if (soma2 > soma1) {
        printf("Vencedor: %s!\n", c2.nome);
    } else {
        printf("Empate!\n");
    }
}

int main() {
    // Cartas pré-definidas
    Carta c1 = {"Brasil", 213000000, 8515767, 25, 14400};
    Carta c2 = {"Alemanha", 83000000, 357022, 233, 46000};

    printf("Bem-vindo ao Super Trunfo!\n");
    printf("Escolha dois atributos para comparar:\n");

    // Exibir atributos e coletar escolha do usuário
    exibirAtributos();
    int atributo1;
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &atributo1);
    int atributo2 = selecionarAtributo(atributo1);

    // Determinar vencedor
    determinarVencedor(c1, c2, atributo1, atributo2);

    
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    return 0;
}
