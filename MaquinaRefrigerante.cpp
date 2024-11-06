#include "MaquinaRefrigerante.h"
#include <ctime>
#include <iostream>

using namespace std;

// Construtor que aceita um ponteiro para ListaEncadeada e inicializa o estado e o saldo
MaquinaRefrigerante::MaquinaRefrigerante(Clock* clock, ListaEncadeada* listaEncadeada)
    : clock(clock), InterfaceUsuario(*clock, listaEncadeada), estadoAtual(S000), reset(false), saldo(0.0f) {}

// Função para resetar a máquina
void MaquinaRefrigerante::resetar() {
    estadoAtual = S000;
    saldo = 0.0f;
    reset = true;
    resetar();
}

// Função para processar transições de estado com base no comando inserido
void MaquinaRefrigerante::proximoEstado(Comando comando) {
    float valorInserido = 0.0f;

    switch (comando) {
        case M025: valorInserido = 0.25f; break;
        case M050: valorInserido = 0.50f; break;
        case M100: valorInserido = 1.00f; break;
        case DEV: devolverMoedas(); return;
        case MEET: 
            if (saldo >= 1.50f) {
                liberarMEET(saldo);
                liberarRefrigerante();
                return;
            } else {
                saldoInsuficiente(saldo);
                // cout << "Saldo insuficiente. Faltam R$" << 1.50f - saldo << ".\n";
                return;
            }
        case ETIRPS:
            if (saldo >= 1.50f) {
                liberarETIRPS(saldo);
                liberarRefrigerante();
                return;
            } else {
                saldoInsuficiente(saldo);
                // cout << "Saldo insuficiente. Faltam R$" << 1.50f - saldo << ".\n";
                return;
            }
        case LOG:
            imprimirLista();
            return;
        default: break;
    }

    float novoSaldo = saldo + valorInserido;
    if (novoSaldo > 1.50f) {
        float troco = novoSaldo - 1.50f;
        saldo = 1.50f;
        trocoDevolvido(troco);
        // cout << "Troco devolvido: R$" << troco << ".\n";
    } else {
        saldo = novoSaldo;
    }

    if (saldo == 0.25f) estadoAtual = S025;
    else if (saldo == 0.50f) estadoAtual = S050;
    else if (saldo == 0.75f) estadoAtual = S075;
    else if (saldo == 1.00f) estadoAtual = S100;
    else if (saldo == 1.25f) estadoAtual = S125;
    else if (saldo == 1.50f) estadoAtual = S150;

    mostrarEstado();
}

// Função para exibir o estado atual e o saldo da máquina
void MaquinaRefrigerante::mostrarEstado() {
    // clock.updateClock();  // Atualiza o relógio
    // cout << "Estado Atual: ";
    switch (estadoAtual) {
        case S000: 
            // cout << "S000"; 
            imprimirS000();
            break;
        case S025: 
            imprimirS025();
            break;
        case S050: 
            imprimirS050();
            break;
        case S075: 
            imprimirS075();
            break;
        case S100: 
            imprimirS100();
            break;
        case S125: 
            imprimirS125();
            break;
        case S150: 
            imprimirS150();
            break;
    }
    imprimirSaldo(saldo);
}

// Função para devolver moedas
void MaquinaRefrigerante::devolverMoedas() {
    devolveMoedas(saldo);
    saldo = 0.0f;
    estadoAtual = S000;
}

// Função para liberar o refrigerante
void MaquinaRefrigerante::liberarRefrigerante() {
    saldo = 0.0f;
    estadoAtual = S000;
}

// Função para mapear entrada do usuário para um comando
Comando MaquinaRefrigerante::escolherComando() {
    int escolha = -1;

    while (escolha == -1) {
        imprimirMenu();

        // Captura o horário antes de aguardar a entrada
        std::time_t startTime = std::time(nullptr);

        int escolha = dadoEntrada();

        if (escolha > -1) {
            std::time_t endTime = std::time(nullptr);
            int secondsElapsed = static_cast<int>(endTime - startTime);

            // Atualiza o relógio com base no tempo decorrido
            for (int i = 0; i < secondsElapsed; ++i) {
                clock->updateClock();
            }

            switch (escolha) {
                case 0: return NADA;
                case 1: return M025;
                case 2: return M050;
                case 3: return M100;
                case 4: return DEV;
                case 5: return MEET;
                case 6: return ETIRPS;
                case 7: return LOG;
                default:
                    opcaoInvalida();
                    // cout << "Opção invalida. Tente novamente.\n";
                    escolha = -1; // Reinicia para aguardar nova
            }
        }
    }
}
