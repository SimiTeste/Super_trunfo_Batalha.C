#include <stdio.h>
#include <string.h>

// Definição da estrutura da carta
struct Carta {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    double pib;
    int pontosTuristicos;
    float densidadePopulacional;
    double pibPerCapita;
    float superPoder;
};

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Funções auxiliares
float calcularDensidade(unsigned long int pop, float area) {
    return (area != 0.0f) ? pop / area : 0.0f;
}

double calcularPIBPerCapita(double pib, unsigned long int pop) {
    return (pop != 0) ? pib / pop : 0.0;
}

float calcularSuperPoder(struct Carta c) {
    float inversoDensidade = (c.densidadePopulacional != 0.0f) ? 1.0f / c.densidadePopulacional : 0.0f;
    return (float)c.populacao + c.area + (float)c.pib + (float)c.pontosTuristicos + (float)c.pibPerCapita + inversoDensidade;
}

// Função de comparação
void compararCartas(struct Carta c1, struct Carta c2) {
    printf("\nComparação de Cartas:\n");

    printf("Populacao: Carta 1 venceu (%d)\n", c1.populacao > c2.populacao);
    printf("Area: Carta 1 venceu (%d)\n", c1.area > c2.area);
    printf("PIB: Carta 1 venceu (%d)\n", c1.pib > c2.pib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", c1.pontosTuristicos > c2.pontosTuristicos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", c1.densidadePopulacional < c2.densidadePopulacional);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", c1.pibPerCapita > c2.pibPerCapita);
    printf("Super Poder: Carta 1 venceu (%d)\n", c1.superPoder > c2.superPoder);
}

int main() {
    struct Carta carta1, carta2;

    // Leitura da Carta 1
    printf("Cadastro da Carta 1:\n");

    printf("Estado (A-H): ");
    scanf(" %c", &carta1.estado);
    limparBuffer();

    printf("Codigo (ex: A01): ");
    scanf("%3s", carta1.codigo);
    limparBuffer();

    printf("Nome da Cidade: ");
    fgets(carta1.nomeCidade, sizeof(carta1.nomeCidade), stdin);
    carta1.nomeCidade[strcspn(carta1.nomeCidade, "\n")] = '\0';

    printf("Populacao: ");
    scanf("%lu", &carta1.populacao);

    printf("Area (km): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhoes): ");
    scanf("%lf", &carta1.pib);

    printf("N de Pontos Turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    limparBuffer();

    // Leitura da Carta 2
    printf("\nCadastro da Carta 2:\n");

    printf("Estado: ");
    scanf(" %c", &carta2.estado);
    limparBuffer();

    printf("Codigo (ex: B02): ");
    scanf("%3s", carta2.codigo);
    limparBuffer();

    printf("Nome da Cidade: ");
    fgets(carta2.nomeCidade, sizeof(carta2.nomeCidade), stdin);
    carta2.nomeCidade[strcspn(carta2.nomeCidade, "\n")] = '\0';

    printf("Populaçao: ");
    scanf("%lu", &carta2.populacao);

    printf("Area (km): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhoes): ");
    scanf("%lf", &carta2.pib);

    printf("N de Pontos Turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Cálculos das cartas
    carta1.densidadePopulacional = calcularDensidade(carta1.populacao, carta1.area);
    carta1.pibPerCapita = calcularPIBPerCapita(carta1.pib, carta1.populacao);
    carta1.superPoder = calcularSuperPoder(carta1);

    carta2.densidadePopulacional = calcularDensidade(carta2.populacao, carta2.area);
    carta2.pibPerCapita = calcularPIBPerCapita(carta2.pib, carta2.populacao);
    carta2.superPoder = calcularSuperPoder(carta2);

    // Exibição das cartas
    printf("\n----------------------\n");
    printf("Carta 1:\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Codigo: %s\n", carta1.codigo);
    printf("Cidade: %s\n", carta1.nomeCidade);
    printf("Populacao: %lu\n", carta1.populacao);
    printf("Area: %.2f km\n", carta1.area);
    printf("PIB: %.2f bilhoes\n", carta1.pib);
    printf("Pontos Turisticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidadePopulacional);
    printf("PIB per Capita: %.2f\n", carta1.pibPerCapita);
    printf("Super Poder: %.2f\n", carta1.superPoder);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Codigo: %s\n", carta2.codigo);
    printf("Cidade: %s\n", carta2.nomeCidade);
    printf("Populacao: %lu\n", carta2.populacao);
    printf("Area: %.2f km\n", carta2.area);
    printf("PIB: %.2f bilhoes\n", carta2.pib);
    printf("Pontos Turisticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidadePopulacional);
    printf("PIB per Capita: %.2f\n", carta2.pibPerCapita);
    printf("Super Poder: %.2f\n", carta2.superPoder);

    // Comparação
    compararCartas(carta1, carta2);

    return 0;
}
