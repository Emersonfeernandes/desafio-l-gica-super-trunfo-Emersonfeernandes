#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

typedef struct {
    char estado[4];
    char cidade[20];
    char letra;
    unsigned long int populacao;
    unsigned int pontosTuristico;
    double area;
    double PIB;
    float densidade;
    float perCapita;
} Carta;


// Função para Calcular o PIB per Capita
float calcularPIBperCapita(float PIB, unsigned long int populacao) {
    return (float) PIB / populacao;
}
 
// Função para Calcular a Densidade Populacional
float calcularDensidade(unsigned long int populacao, float area) {
    return (float) populacao / area;
}

// Função para somar todos os atributos númericos de cada carta
double calcularSuperPoder(Carta c) {
    return c.populacao +
           c.area +
           c.PIB +
           c.pontosTuristico +
           c.densidade +
           c.perCapita;
}

// Função para verificar a carta vencedora ou se houve empate
char* venceuEmpatou(double valor1, double valor2){
    if (valor1 > valor2){
        return "Carta 1 venceu";
    } else if (valor1 < valor2){
        return "Carta 2 venceu";
    } else{
        return "esse atributo empatou";
    }
}
// Função para entrar com dados
void entradaDados(Carta *carta1, Carta *carta2) {
    // Entrada Carta 1
    printf("##### Informações da carta 1 #####\n");
    printf("Digite a letra da carta 1: ");
    scanf(" %c", &carta1->letra);

    printf("Digite o código do estado da carta 1: ");
    scanf("%s", carta1->estado);
    getchar();

    printf("Digite o nome da cidade da carta 1: ");
    fgets(carta1->cidade, 20, stdin);
    carta1->cidade[strcspn(carta1->cidade, "\n")] = 0;

    printf("População: ");
    scanf("%lu", &carta1->populacao);

    printf("Pontos turísticos: ");
    scanf("%u", &carta1->pontosTuristico);

    printf("Área: ");
    scanf("%lf", &carta1->area);

    printf("PIB: ");
    scanf("%lf", &carta1->PIB);

    // Cálculos automáticos
    carta1->densidade = calcularDensidade(carta1->populacao, carta1->area);
    carta1->perCapita = calcularPIBperCapita(carta1->PIB, carta1->populacao);

    // Entrada Carta 2
    printf("\n##### Informações da carta 2 #####\n");
    printf("Digite a letra da carta 2: ");
    scanf(" %c", &carta2->letra);

    printf("Digite o código do estado da carta 2: ");
    scanf("%s", carta2->estado);
    getchar();

    printf("Digite o nome da cidade da carta 2: ");
    fgets(carta2->cidade, 20, stdin);
    carta2->cidade[strcspn(carta2->cidade, "\n")] = 0;

    printf("População: ");
    scanf("%lu", &carta2->populacao);

    printf("Pontos turísticos: ");
    scanf("%u", &carta2->pontosTuristico);

    printf("Área: ");
    scanf("%lf", &carta2->area);

    printf("PIB: ");
    scanf("%lf", &carta2->PIB);

    // Cálculos automáticos
    carta2->densidade = calcularDensidade(carta2->populacao, carta2->area);
    carta2->perCapita = calcularPIBperCapita(carta2->PIB, carta2->populacao);

}

// Função para escolha do atributo de comparação
void escolhaAtributo(Carta carta1, Carta carta2){
    // Variaveis da função
    int atributo, numCartaVencedora;
    char *cidadeVencedora;

    // opções para escolha
    printf("\n=================================================\n");
    printf("\n1 - População\n2 - Área\n3 - PIB\n4 - Densidade Populacional\n5 - PIB per capita\n");
    printf("\nEscolha um dos atributos para comparação digitando de 1 a 5: ");
    scanf("%d", &atributo);

    switch (atributo){
        // caso escolha 1 - População
        case 1:
            printf("\n### Comparação de cartas (Atributo: População): ###\n");
            if (carta1.populacao > carta2.populacao){
                printf("Carta 1 (%s) venceu\n", carta1.cidade);
            } else if (carta1.populacao < carta2.populacao){
                printf("Carta 2 (%s) venceu\n", carta2.cidade);
            } else {
                printf("Empate!\n");
            }                                                                       
            break;  

        // caso escolha 2 - Área
        case 2:
            printf("\n### Comparação de cartas (Atributo: Área): ###\n");
            if (carta1.area > carta2.area){
                printf("Carta 1 (%s) venceu\n", carta1.cidade);
            } else if (carta1.area < carta2.area){
                printf("Carta 2 (%s) venceu\n", carta2.cidade);
            } else {
                printf("Empate!\n");
            }
            break;
        // caso escolha 3 - PIB
        case 3:
            printf("\n### Comparação de cartas (Atributo: PIB): ###\n");
            if (carta1.PIB > carta2.PIB){
                printf("Carta 1 (%s) venceu\n", carta1.cidade);
            } else if (carta1.PIB < carta2.PIB){
                printf("Carta 2 (%s) venceu\n", carta2.cidade);
            } else {
                printf("Empate!\n");
            }
            break;
    
        // caso escolha 4 - Densidade Populacional
        case 4:
            printf("\n### Comparação de cartas (Atributo: Densidade Populacional): ###\n");
            if (carta1.densidade < carta2.densidade){
                printf("Carta 1 (%s) venceu\n", carta1.cidade);
            } else if (carta1.densidade > carta2.densidade){
                printf("Carta 2 (%s) venceu\n", carta2.cidade);
            } else {
                printf("Empate!\n");
            }
            break;

        // caso escolha 5 - PIB per capita
        case 5:
            printf("\n### Comparação de cartas (Atributo: PIB per Capita): ###\n");
            if (carta1.perCapita > carta2.perCapita){
                printf("Carta 1 (%s) venceu\n", carta1.cidade);
            } else if (carta1.perCapita < carta2.perCapita){
                printf("Carta 2 (%s) venceu\n", carta2.cidade);
            } else {
                printf("Empate!\n");
            }
            break;
    
        default:
            printf("Opção inválida!\n");
    }
}

// Função para exibir dados
void saidaDados(Carta carta1, Carta carta2) {
    
    // PRINTs DA CARTA 1
    printf("\n### Carta 1 ###\n");
    printf("Estado: %c\n", carta1.letra);
    printf("Código: %c%s\n", carta1.letra, carta1.estado);
    printf("Cidade: %s\n", carta1.cidade);
    printf("População: %lu\n", carta1.populacao);
    printf("Área: %.2lf km²\n", carta1.area);
    printf("PIB: %.2lf bilhões de reais\n", carta1.PIB);
    printf("Número de Pontos Turísticos: %u\n", carta1.pontosTuristico);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidade);
    printf("PIB per Capita: %.2f reais\n", carta1.perCapita);

    // PRINTs DA CARTA 2
    printf("\n### Carta 2 ###\n");
    printf("Estado: %c\n", carta2.letra);
    printf("Código: %c%s\n", carta2.letra, carta2.estado);
    printf("Cidade: %s\n", carta2.cidade);
    printf("População: %lu\n", carta2.populacao);
    printf("Área: %.2lf km²\n", carta2.area);
    printf("PIB: %.2lf bilhões de reais\n", carta2.PIB);
    printf("Número de Pontos Turísticos: %u\n", carta2.pontosTuristico);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidade);
    printf("PIB per Capita: %.2f reais\n", carta2.perCapita);

}

// Função para exibir comparação entre as cartas
void exibirComparacao(Carta carta1, Carta carta2){
    
    double somaC1 = calcularSuperPoder(carta1);

    double somaC2 = calcularSuperPoder(carta2);

    double resultadoSoma = (somaC1 > somaC2) ? somaC1 : somaC2;

    if (somaC1 > somaC2){
        printf("\n### Carta 1 venceu no Super Poder! ###\n");
    } else if (somaC1 < somaC2){
        printf("\n### Carta 2 venceu no Super Poder! ###\n");
    } else {
        printf("\n### As cartas empataram no Super Poder! ###\n");
    }
    printf("População: %s\n",
           venceuEmpatou(carta1.populacao, carta2.populacao));
    printf("Área: %s\n",
           venceuEmpatou(carta1.area, carta2.area));
    printf("PIB: %s\n",
           venceuEmpatou(carta1.PIB, carta2.PIB));
    printf("Pontos Turísticos: %s\n",
           venceuEmpatou(carta1.pontosTuristico, carta2.pontosTuristico));
    printf("Densidade Populacional: Carta %d venceu\n",
           (carta1.densidade < carta2.densidade) ? 1 : 2);
    printf("PIB per Capita: %s\n",
           venceuEmpatou(carta1.perCapita, carta2.perCapita));

    if (somaC1 == somaC2)
    {
        printf("\n### As cartas empataram ###\n");
    } else{
        printf("\n### Super Poder: %.lf, carta %d venceu ###\n", resultadoSoma, 
            (somaC1 > somaC2) ? 1 : 2);
    }
}


int main(){
    Carta carta1, carta2;
    int opcao;

    entradaDados(&carta1, &carta2);

    printf("\n### Escolha exibir dados, comparar um dos atributos ou todos ###\n");
    printf("\n1 - Exibir Dados das Cartas.\n2 - Escolher um Atributo.\n3 - Exibir Todas comparações.\n");
    printf("\nDigite sua escolha: ");
    scanf("%d", &opcao);

    if (opcao > 0 && opcao <= 3)
    {
        switch (opcao)
        {
            case 1:
            saidaDados(carta1, carta2);
            break;
            case 2:
            escolhaAtributo(carta1, carta2);
            break;
            case 3:
            exibirComparacao(carta1, carta2);
            break;
        }
    } else {
        printf("\nPor favor, digite: 1, 2 ou 3\n");
    }

    return 0;    
}