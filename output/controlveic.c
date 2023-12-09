#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VEICULOS 100

typedef struct {
    char proprietario[50];
    char combustivel[10];
    char modelo[50];
    char cor[20];
    char chassi[20];
    int ano;
    char placa[10];
} Veiculo;

Veiculo veiculos[MAX_VEICULOS];
int num_veiculos = 0;

void listar_proprietarios_diesel() {
    printf("Proprietários de carros a diesel fabricados em 2010 ou posterior:\n");
    for (int i = 0; i < num_veiculos; i++) {
        Veiculo v = veiculos[i];
        if (strcmp(v.combustivel, "diesel") == 0 && v.ano >= 2010) {
            printf("%s\n", v.proprietario);
        }
    }
}

void listar_placas_j() {
    printf("Placas que começam com J e terminam com 0, 2, 4 ou 7:\n");
    for (int i = 0; i < num_veiculos; i++) {
        Veiculo v = veiculos[i];
        if (v.placa[0] == 'J' && (v.placa[6] == '0' || v.placa[6] == '2' || v.placa[6] == '4' || v.placa[6] == '7')) {
            printf("%s - %s\n", v.placa, v.proprietario);
        }
    }
}

void listar_modelo_cor_vogal_soma_par() {
    printf("Modelo e cor dos veículos cujas placas possuem como segunda letra uma vogal e cuja soma dos valores numéricos fornece um número par:\n");
    for (int i = 0; i < num_veiculos; i++) {
        Veiculo v = veiculos[i];
        if ((tolower(v.placa[1]) == 'a' || tolower(v.placa[1]) == 'e' || tolower(v.placa[1]) == 'i' || tolower(v.placa[1]) == 'o' || tolower(v.placa[1]) == 'u') && ((v.placa[2] - '0') + (v.placa[3] - '0') + (v.placa[4] - '0') + (v.placa[5] - '0')) % 2 == 0) {
            printf("%s - %s\n", v.modelo, v.cor);
        }
    }
}

void trocar_proprietario() {
    char chassi[20];
    printf("Digite o número do chassi: ");
    scanf("%s", chassi);

    for (int i = 0; i < num_veiculos; i++) {
        Veiculo v = veiculos[i];
        if (strcmp(v.chassi, chassi) == 0 && strchr(v.placa, '0') == NULL) {
            printf("Digite o novo proprietário: ");
            scanf("%s", v.proprietario);
            strcpy(veiculos[i].proprietario, v.proprietario);
            printf("Proprietário atualizado com sucesso.\n");
            return;
        }
    }

    printf("Veículo não encontrado ou não pode ter o proprietário trocado.\n");
}

int main() {
    int opcao = 0;
    while (opcao != 5) {
        printf("\nSistema de Controle de Veículos\n");
        printf("1 - Listar proprietários de carros a diesel fabricados em 2010 ou posterior\n");
        printf("2 - Listar placas que começam com J e terminam com 0, 2, 4 ou 7\n");
        printf("3 - Listar modelo e cor dos veículos cujas placas possuem como segunda letra uma vogal e cuja soma dos valores numéricos fornece um número par\n");
        printf("4 - Trocar proprietário\n");
        printf("5 - Sair\n");
        printf("Digite uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listar_proprietarios_diesel();
                break;
            case 2:
                listar_placas_j();
                break;
            case 3:
                listar_modelo_cor_vogal_soma_par();
                break;
            case 4:
                trocar_proprietario();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    }

    return 0;
}