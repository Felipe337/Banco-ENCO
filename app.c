#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app.h"

int menu() {

    struct Conta contas[15];
    int totalContas = 0;
    int escolha;
    char cpfBusca[11];
    float valor;

    while (1) {
    	printf("\n\n\n\n\n");
        printf("\t\t\tDESENVOLVIDO POR FELIPE A. ARAÚJO & ROBERTA R. F. ASENCIO\n\n");
		printf("\t\t\t**********************************************************************\n");
		printf("\t\t\t**********************************************************************\n");		
		printf("\t\t\t**********************************************************************\n");
		printf("\t\t\t**********************************************************************\n");
		printf("\t\t\t**********                                                  **********\n");		
        printf("\t\t\t**********    Menu de Opções:                               **********\n");
        printf("\t\t\t**********    1. Cadastrar Conta                            **********\n");
        printf("\t\t\t**********    2. Buscar Cliente por CPF                     **********\n");
        printf("\t\t\t**********    3. Realizar Depósito                          **********\n");
        printf("\t\t\t**********    4. Realizar Saque                             **********\n");
        printf("\t\t\t**********    5. Listar Clientes por CPF Crescente          **********\n");
        printf("\t\t\t**********    6. Listar Clientes por Saldo Decrescente      **********\n");
        printf("\t\t\t**********    7. Sair                                       **********\n");
       	printf("\t\t\t**********                                                  **********\n");
        printf("\t\t\t**********************************************************************\n");
		printf("\t\t\t**********************************************************************\n");
		printf("\t\t\t**********************************************************************\n");        
   		printf("\t\t\t**********************************************************************\n\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        system("clear");

        switch (escolha) {
            case 1:
                cadastrarConta(contas, &totalContas);
                    break;
            case 2:
                printf("Digite o CPF do cliente: ");
                    scanf("%s", cpfBusca);
                        buscarClientePorCPF(contas, totalContas, cpfBusca);
                            break;
            case 3:
                printf("Digite o CPF do cliente: ");
                    scanf("%s", cpfBusca);
                        printf("Digite o valor do depósito: ");
                            scanf("%f", &valor);
                                realizarDeposito(contas, totalContas, cpfBusca, valor);
                                    break;
            case 4:
                printf("Digite o CPF do cliente: ");
                    scanf("%s", cpfBusca);
                        printf("Digite o valor do saque: ");
                            scanf("%f", &valor);
                                realizarSaque(contas, totalContas, cpfBusca, valor);
                                    break;
            case 5:
                listarClientesCrescente(contas, totalContas);
                    break;
            case 6:
                listarClientesDecrescente(contas, totalContas);
                    break;
            case 7:
                printf("DESENVOLVIDO POR FELIPE A. ARAÚJO & ROBERTA R. F. ASENCIO");
                    return 0;
            default:
                printf("Opção inválida. Tente novamente.\n"); } }
                    return 0; }

void cadastrarConta(struct Conta contas[], int *totalContas) {
    if (*totalContas < 15){
        printf("Digite o número da conta (entre 1000 e 9999): ");
            scanf("%d", &contas[*totalContas].numeroConta);
    if (contas[*totalContas].numeroConta < 1000 || contas[*totalContas].numeroConta > 9999) {
                printf("Número de conta inválido.\n");
                    return; }

        printf("Digite o número da agência (entre 001 e 999): ");
            scanf("%d", &contas[*totalContas].agencia);

        if (contas[*totalContas].agencia < 1 || contas[*totalContas].agencia > 999) {
            printf("Número de agência inválido.\n");
                return; }

        printf("Digite o tipo de conta (1 - Conta Corrente, 2 - Conta Poupança): ");
            scanf("%d", &contas[*totalContas].tipoConta);

        if (contas[*totalContas].tipoConta != 1 && contas[*totalContas].tipoConta != 2) {
            printf("Tipo de conta inválido.\n");
                return; }

        printf("Digite o CPF do cliente (11 dígitos): ");
            scanf("%s", contas[*totalContas].cpfCliente);

        printf("Digite o saldo inicial: ");
            scanf("%f", &contas[*totalContas].saldo);
                system("clear");
                    (*totalContas)++;
                        printf("Conta cadastrada com sucesso.\n");
    } else {
        printf("O banco atingiu o limite máximo de contas.\n"); } }
