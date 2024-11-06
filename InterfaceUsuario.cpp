#include "InterfaceUsuario.h"
#include "config.h"
#include <iostream>
using namespace std;

volatile unsigned int *data = (volatile unsigned int *)0x80000a00;
volatile unsigned int *output = (volatile unsigned int *)0x80000a04;
volatile unsigned int *direction = (volatile unsigned int *)0x80000a08;

// Constructor that initializes the lista pointer
InterfaceUsuario::InterfaceUsuario(Clock& clock, ListaEncadeada* listaEncadeada) : clock(clock), lista(listaEncadeada) {}

#ifdef LINUXKERNEL
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
#endif

#ifdef ATLYSKERNEL
// Prints the list of transactions
void InterfaceUsuario::imprimirLista() const {
    int i = 0;
    Transacao* atual = lista->getCabeca();
    while (atual != nullptr) {
        atual = atual->proximo;
        i += 1;
    }
}
#endif

#ifdef LINUXKERNEL
void InterfaceUsuario::resetar() {
    cout << "Maquina resetada. Saldo zerado.\n";
    int hour = clock.getHours();
    int minute = clock.getMinutes();
    int seconds = clock.getSeconds();
    cout << "Horario: " << hour << ":" << minute << ":" << seconds << "\n";
    lista->limpar();
}
#endif

#ifdef ATLYSKERNEL
void InterfaceUsuario::resetar() {
    cout << "Maquina resetada. Saldo zerado.\n";
    int hour = clock.getHours();
    int minute = clock.getMinutes();
    int seconds = clock.getSeconds();
    cout << "Horario: " << hour << ":" << minute << ":" << seconds << "\n";
    lista->limpar();
}
#endif

#ifdef LINUXKERNEL
void InterfaceUsuario::liberarMEET(float saldo) {
    cout << "Refrigerante MEET liberado. Saldo zerado.\n";
    int hour = clock.getHours();
    int minute = clock.getMinutes();
    int seconds = clock.getSeconds();
    cout << "Horario: " << hour << ":" << minute << ":" << seconds << "\n";
    string horario = clock.showClock();
    lista->adicionarAoFim(horario, "compra_meet", saldo);
}
#endif

#ifdef ATLYSKERNEL
void InterfaceUsuario::liberarMEET(float saldo) {
    cout << "Refrigerante MEET liberado. Saldo zerado.\n";
    int hour = clock.getHours();
    int minute = clock.getMinutes();
    int seconds = clock.getSeconds();
    cout << "Horario: " << hour << ":" << minute << ":" << seconds << "\n";
    string horario = clock.showClock();
    lista->adicionarAoFim(horario, "compra_meet", saldo);
}
#endif

#ifdef LINUXKERNEL
void InterfaceUsuario::liberarETIRPS(float saldo) {
    cout << "Refrigerante ETIRPS liberado. Saldo zerado.\n";
    int hour = clock.getHours();
    int minute = clock.getMinutes();
    int seconds = clock.getSeconds();
    cout << "Horario: " << hour << ":" << minute << ":" << seconds << "\n";
    string horario = clock.showClock();
    lista->adicionarAoFim(horario, "compra_etirps", saldo);
}
#endif

#ifdef ATLYSKERNEL
void InterfaceUsuario::liberarETIRPS(float saldo) {
    cout << "Refrigerante ETIRPS liberado. Saldo zerado.\n";
    int hour = clock.getHours();
    int minute = clock.getMinutes();
    int seconds = clock.getSeconds();
    cout << "Horario: " << hour << ":" << minute << ":" << seconds << "\n";
    string horario = clock.showClock();
    lista->adicionarAoFim(horario, "compra_etirps", saldo);
}
#endif

#ifdef LINUXKERNEL
void InterfaceUsuario::saldoInsuficiente(float saldo) {
    cout << "Saldo insuficiente. Faltam R$" << 1.50f - saldo << ".\n";
}
#endif

#ifdef ATLYSKERNEL
void InterfaceUsuario::saldoInsuficiente(float saldo) {
    cout << "Saldo insuficiente. Faltam R$" << 1.50f - saldo << ".\n";
}
#endif

#ifdef LINUXKERNEL
void InterfaceUsuario::trocoDevolvido(float troco){
    cout << "Troco devolvido: R$" << troco << ".\n";
    int hour = clock.getHours();
    int minute = clock.getMinutes();
    int seconds = clock.getSeconds();
    cout << "Horario: " << hour << ":" << minute << ":" << seconds << "\n";
}
#endif

#ifdef ATLYSKERNEL
void InterfaceUsuario::trocoDevolvido(float troco){
    cout << "Troco devolvido: R$" << troco << ".\n";
    int hour = clock.getHours();
    int minute = clock.getMinutes();
    int seconds = clock.getSeconds();
    cout << "Horario: " << hour << ":" << minute << ":" << seconds << "\n";
}
#endif

#ifdef LINUXKERNEL
void InterfaceUsuario::imprimirS000(){
    cout << "Estado atual: S000";
}
#endif

#ifdef ATLYSKERNEL
void InterfaceUsuario::imprimirS000(){
    cout << "Estado atual: S000";
}
#endif

#ifdef LINUXKERNEL
void InterfaceUsuario::imprimirS025(){
    cout << "Estado atual: S025";
}
#endif

#ifdef ATLYSKERNEL
void InterfaceUsuario::imprimirS025(){
    cout << "Estado atual: S025";
}
#endif

#ifdef LINUXKERNEL
void InterfaceUsuario::imprimirS050(){
    cout << "Estado atual: S050";
}
#endif

#ifdef ATLYSKERNEL
void InterfaceUsuario::imprimirS050(){
    cout << "Estado atual: S050";
}
#endif

#ifdef LINUXKERNEL
void InterfaceUsuario::imprimirS075(){
    cout << "Estado atual: S075";
}
#endif

#ifdef ATLYSKERNEL
void InterfaceUsuario::imprimirS075(){
    cout << "Estado atual: S075";
}
#endif

#ifdef LINUXKERNEL
void InterfaceUsuario::imprimirS100(){
    cout << "Estado atual: S100";
}
#endif

#ifdef ATLYSKERNEL
void InterfaceUsuario::imprimirS100(){
    cout << "Estado atual: S100";
}
#endif

#ifdef LINUXKERNEL
void InterfaceUsuario::imprimirS125(){
    cout << "Estado atual: S125";
}
#endif

#ifdef ATLYSKERNEL
void InterfaceUsuario::imprimirS125(){
    cout << "Estado atual: S125";
}
#endif

#ifdef LINUXKERNEL
void InterfaceUsuario::imprimirS150(){
    cout << "Estado atual: S150";
}
#endif

#ifdef ATLYSKERNEL
void InterfaceUsuario::imprimirS150(){
    cout << "Estado atual: S150";
}
#endif

#ifdef LINUXKERNEL
void InterfaceUsuario::imprimirMenu(){
    cout << "Escolha um comando:\n";
    cout << "0: NADA.\n1: Inserir Moeda de R$0,25. \n2: Inserir Moeda de R$0,50.\n";
    cout << "3: Inserir Moeda de R$1,00. \n4: Devolver Moedas. \n";
    cout << "5: Escolher Refrigerante MEET.\n6: Escolher Refrigerante ETIRPS.\n7: Apresentar log de operacoes.\n";
    cout << "Aguardando escolha do usuario...\n";
}
#endif

#ifdef ATLYSKERNEL
void InterfaceUsuario::imprimirMenu(){
    cout << "Escolha um comando:\n";
    cout << "0: NADA.\n1: Inserir Moeda de R$0,25. \n2: Inserir Moeda de R$0,50.\n";
    cout << "3: Inserir Moeda de R$1,00. \n4: Devolver Moedas. \n";
    cout << "5: Escolher Refrigerante MEET.\n6: Escolher Refrigerante ETIRPS.\n7: Apresentar log de operacoes.\n";
    cout << "Aguardando escolha do usuario...\n";
}
#endif

#ifdef LINUXKERNEL
void InterfaceUsuario::opcaoInvalida(){
    cout << "Opçao invalida. Tente novamente.\n";
}
#endif

#ifdef ATLYSKERNEL
void InterfaceUsuario::opcaoInvalida(){
    cout << "Opçao invalida. Tente novamente.\n";
}
#endif

#ifdef LINUXKERNEL
void InterfaceUsuario::imprimirSaldo(float saldo){
    cout << " | Saldo Atual: R$" << saldo << " | Faltam R$" << max(0.0f, 1.50f - saldo) << ".\n";
}
#endif

#ifdef ATLYSKERNEL
void InterfaceUsuario::imprimirSaldo(float saldo){
    cout << " | Saldo Atual: R$" << saldo << " | Faltam R$" << max(0.0f, 1.50f - saldo) << ".\n";
}
#endif

#ifdef LINUXKERNEL
void InterfaceUsuario::devolveMoedas(float saldo) {
    cout << "Devolvendo R$" << saldo << " em moedas.\n";
}
#endif

#ifdef ATLYSKERNEL
void InterfaceUsuario::devolveMoedas(float saldo) {
    cout << "Devolvendo R$" << saldo << " em moedas.\n";
}
#endif

#ifdef LINUXKERNEL
int InterfaceUsuario::dadoEntrada() {
    int entrada;
    cin >> entrada;
    return entrada;
}
#endif

#ifdef ATLYSKERNEL
int InterfaceUsuario::dadoEntrada() {
    int entrada;
    cin >> entrada;
    return entrada;
}
#endif