#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"

void buscarClientePorCPF(struct Conta contas[], int totalContas, char cpfBusca[]) {
    int clienteEncontrado = -1;
    int esquerda = 0;
    int direita = totalContas - 1;

        while (esquerda <= direita) {
            int meio = esquerda + (direita - esquerda) / 2;
            int comparacao = strcmp(contas[meio].cpfCliente, cpfBusca);
                if (comparacao == 0) {
                    clienteEncontrado = meio; break; }
                        else if (comparacao < 0) {
                            esquerda = meio + 1; }
                                else { direita = meio - 1; } }

    if (clienteEncontrado != -1) {
        printf("CPF: %s\n", contas[clienteEncontrado].cpfCliente);
        printf("Agência: %03d\n", contas[clienteEncontrado].agencia);
        printf("Número da Conta: %04d\n", contas[clienteEncontrado].numeroConta);
        printf("Tipo de Conta: %s\n", (contas[clienteEncontrado].tipoConta == 1) ? "Conta Corrente" : "Conta Poupança"); } else {
        printf("Cliente não localizado!\n"); } }

void realizarDeposito(struct Conta contas[], int totalContas, char cpfBusca[], float valor) {
    for (int i = 0; i < totalContas; i++) {
        if (strcmp(contas[i].cpfCliente, cpfBusca) == 0) {
            contas[i].saldo += valor;
                printf("Depósito realizado com sucesso. Novo saldo: %.2f\n", contas[i].saldo);
                    return; } }
                        printf("Cliente com CPF %s não encontrado. Depósito não realizado.\n", cpfBusca); }

void realizarSaque(struct Conta contas[], int totalContas, char cpfBusca[], float valor) {
    for (int i = 0; i < totalContas; i++) {
        if (strcmp(contas[i].cpfCliente, cpfBusca) == 0) {
            if (contas[i].saldo >= valor) {
                contas[i].saldo -= valor;
                    printf("Saque realizado com sucesso. Novo saldo: %.2f\n", contas[i].saldo); }
                        else {
                    printf("Saldo insuficiente para realizar o saque.\n"); }
                        return; } }
                    printf("Cliente com CPF %s não encontrado. Saque não realizado.\n", cpfBusca); }

void listarClientesCrescente(struct Conta contas[], int totalContas) {
    struct Conta temp;
        for (int i = 0; i < totalContas - 1; i++) {
            for (int j = 0; j < totalContas - i - 1; j++) {
                if (strcmp(contas[j].cpfCliente, contas[j + 1].cpfCliente) > 0) {
                    temp = contas[j];
                        contas[j] = contas[j + 1];
                        contas[j + 1] = temp; } } }

    printf("Clientes em ordem crescente de CPF:\n");
        for (int i = 0; i < totalContas; i++) {
            printf("CPF: %s, Agência: %03d, Número da Conta: %04d, Saldo: %.2f\n",
                contas[i].cpfCliente, contas[i].agencia, contas[i].numeroConta, contas[i].saldo); } }

void listarClientesDecrescente(struct Conta contas[], int totalContas) {
    struct Conta temp;
        for (int i = 0; i < totalContas - 1; i++) {
                for (int j = 0; j < totalContas - i - 1; j++) {
                    if (contas[j].saldo < contas[j + 1].saldo) {
                        temp = contas[j];
                            contas[j] = contas[j + 1];
                            contas[j + 1] = temp; } } }

    printf("Clientes em ordem decrescente de saldo:\n");
        for (int i = 0; i < totalContas; i++) {
            printf("CPF: %s, Agência: %03d, Número da Conta: %04d, Saldo: %.2f\n",
                contas[i].cpfCliente, contas[i].agencia, contas[i].numeroConta, contas[i].saldo); } }
