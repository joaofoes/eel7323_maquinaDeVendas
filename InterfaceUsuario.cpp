#include "InterfaceUsuario.h"
#include <iostream>
using namespace std;

// Constructor that initializes the lista pointer
InterfaceUsuario::InterfaceUsuario(Clock& clock, ListaEncadeada* listaEncadeada) : clock(clock), lista(listaEncadeada) {}

// Prints the list of transactions
void InterfaceUsuario::imprimirLista() const {
    Transacao* atual = lista->getCabeca();
    while (atual != nullptr) {
        cout << "Horario da Transacao: " << atual->horarioTransacao << "\n";
        cout << "Operacao: " << atual->operacaoRealizada << "\n";
        cout << "Saldo: " << atual->saldoAtual << "\n";
        cout << "--------------------------\n";
        atual = atual->proximo;
    }
}

// Various placeholder methods
void InterfaceUsuario::resetar() {
    cout << "Maquina resetada. Saldo zerado.\n";
    int hour = clock.getHours();
    int minute = clock.getMinutes();
    int seconds = clock.getSeconds();
    cout << "Horario: " << hour << ":" << minute << ":" << seconds << "\n";
    lista->limpar();
}

void InterfaceUsuario::liberarMEET(float saldo) {
    cout << "Refrigerante MEET liberado. Saldo zerado.\n";
    int hour = clock.getHours();
    int minute = clock.getMinutes();
    int seconds = clock.getSeconds();
    cout << "Horario: " << hour << ":" << minute << ":" << seconds << "\n";
    string horario = clock.showClock();
    lista->adicionarAoFim(horario, "compra_meet", saldo);
}

void InterfaceUsuario::liberarETIRPS(float saldo) {
    cout << "Refrigerante ETIRPS liberado. Saldo zerado.\n";
    int hour = clock.getHours();
    int minute = clock.getMinutes();
    int seconds = clock.getSeconds();
    cout << "Horario: " << hour << ":" << minute << ":" << seconds << "\n";
    string horario = clock.showClock();
    lista->adicionarAoFim(horario, "compra_etirps", saldo);
}

void InterfaceUsuario::saldoInsuficiente(float saldo) {
    cout << "Saldo insuficiente. Faltam R$" << 1.50f - saldo << ".\n";
}

void InterfaceUsuario::trocoDevolvido(float troco){
    cout << "Troco devolvido: R$" << troco << ".\n";
    int hour = clock.getHours();
    int minute = clock.getMinutes();
    int seconds = clock.getSeconds();
    cout << "Horario: " << hour << ":" << minute << ":" << seconds << "\n";
}

void InterfaceUsuario::imprimirS000(){
    cout << "Estado atual: S000";
}

void InterfaceUsuario::imprimirS025(){
    cout << "Estado atual: S025";
}

void InterfaceUsuario::imprimirS050(){
    cout << "Estado atual: S050";
}

void InterfaceUsuario::imprimirS075(){
    cout << "Estado atual: S075";
}

void InterfaceUsuario::imprimirS100(){
    cout << "Estado atual: S100";
}

void InterfaceUsuario::imprimirS125(){
    cout << "Estado atual: S125";
}

void InterfaceUsuario::imprimirS150(){
    cout << "Estado atual: S150";
}

void InterfaceUsuario::imprimirMenu(){
    cout << "Escolha um comando:\n";
    cout << "0: NADA.\n1: Inserir Moeda de R$0,25. \n2: Inserir Moeda de R$0,50.\n";
    cout << "3: Inserir Moeda de R$1,00. \n4: Devolver Moedas. \n";
    cout << "5: Escolher Refrigerante MEET.\n6: Escolher Refrigerante ETIRPS.\n7: Apresentar log de operacoes.\n";
    cout << "Aguardando escolha do usuario...\n";
}

void InterfaceUsuario::opcaoInvalida(){
    cout << "Opçao invalida. Tente novamente.\n";
}

void InterfaceUsuario::imprimirSaldo(float saldo){
    cout << " | Saldo Atual: R$" << saldo << " | Faltam R$" << max(0.0f, 1.50f - saldo) << ".\n";
}

void InterfaceUsuario::devolveMoedas(float saldo) {
    cout << "Devolvendo R$" << saldo << " em moedas.\n";
}

int InterfaceUsuario::dadoEntrada() {
    int entrada;
    cin >> entrada;
    return entrada;
}