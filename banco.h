#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Conta {
    int numeroConta;
    int agencia;
    int tipoConta;
    char cpfCliente[11];
    float saldo; };

void buscarClientePorCPF(struct Conta contas[], int totalContas, char cpfBusca[]);
void realizarDeposito(struct Conta contas[], int totalContas, char cpfBusca[], float valor);
void realizarSaque(struct Conta contas[], int totalContas, char cpfBusca[], float valor);
void listarClientesCrescente(struct Conta contas[], int totalContas);
void listarClientesDecrescente(struct Conta contas[], int totalContas);
