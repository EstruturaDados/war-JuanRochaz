// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================

#include <stdio.h>  // Biblioteca para entrada e saída de dados (printf e scanf)
#include <string.h> // Biblioteca para manipulação de strings (embora não usada diretamente aqui, incluída conforme requisito)
// Definição da struct Territorio
// Esta estrutura armazena as informações de cada território: nome (string de até 29 caracteres + null terminator),
// cor do exército (string de até 9 caracteres + null terminator) e quantidade de tropas (inteiro).
typedef struct {
    char nome[30];  // Nome do território (máximo 29 caracteres para evitar overflow)
    char cor[10];   // Cor do exército (máximo 9 caracteres)
    int tropas;     // Quantidade de tropas (valor inteiro positivo)
} Territorio;
int main() {
    // Declaração de um vetor (array) de structs com capacidade para 5 territórios
    // Isso permite armazenar múltiplas instâncias da struct de forma organizada.
    Territorio territorios[5];
    // Laço de entrada de dados: utiliza um for para cadastrar exatamente 5 territórios
    // O usuário é orientado com mensagens claras sobre o que digitar.
    // Usamos scanf com especificadores de tamanho para strings para evitar buffer overflow.
    // Para o nome e cor, assumimos que não há espaços nos inputs (scanf %s para strings simples).
    // Para tropas, usamos %d diretamente.
    for (int i = 0; i < 5; i++) {
        printf("=== Cadastro do Territorio %d ===\n", i + 1);
        printf("Digite o nome do territorio: ");
        scanf("%29s", territorios[i].nome);  // Lê até 29 caracteres para nome, evitando overflow
        
        printf("Digite a cor do exercito: ");
        scanf("%9s", territorios[i].cor);    // Lê até 9 caracteres para cor
        
        printf("Digite o numero de tropas: ");
        scanf("%d", &territorios[i].tropas); // Lê o inteiro para tropas
        
        // Limpa o buffer de entrada para evitar problemas com scanf subsequentes (boa prática)
        // Usamos getchar() para consumir o newline pendente.
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        
        printf("\n");  // Linha em branco para melhor usabilidade
    }
    // Exibição dos dados: após o cadastro, percorre o vetor com outro laço for
    // e exibe as informações de cada território de forma formatada e clara.
    // Isso garante que o sistema responda rapidamente (desempenho < 2s, trivial para este caso).
    printf("\n=== Dados dos Territorios Registrados ===\n");
    for (int i = 0; i < 5; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("  Nome: %s\n", territorios[i].nome);
        printf("  Cor do Exercito: %s\n", territorios[i].cor);
        printf("  Quantidade de Tropas: %d\n", territorios[i].tropas);
        printf("\n");  // Separação para melhor legibilidade
    }
    // Mensagem final para indicar o término do programa (usabilidade)
    printf("Cadastro e exibicao concluídos!\n");
    return 0;  // Indica que o programa terminou com sucesso
}