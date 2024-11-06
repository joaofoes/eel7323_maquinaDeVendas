#ifndef INTERFACE_USUARIO_H
#define INTERFACE_USUARIO_H

#include <iostream>
#include "Clock.h"
#include "ListaEncadeada.h"

class InterfaceUsuario : public Clock {
private:
    ListaEncadeada* lista;
    Clock& clock;

public:
    InterfaceUsuario(Clock& clock, ListaEncadeada* listaEncadeada);
    void imprimirLista() const;
    void resetar();
    void liberarMEET(float saldo);
    void liberarETIRPS(float saldo);
    void saldoInsuficiente(float saldo);
    void trocoDevolvido(float troco);
    void imprimirS000();
    void imprimirS025();
    void imprimirS050();
    void imprimirS075();
    void imprimirS100();
    void imprimirS125();
    void imprimirS150();
    void imprimirMenu();
    void opcaoInvalida();
    void imprimirSaldo(float saldo);
    void devolveMoedas(float saldo);
    int dadoEntrada();
};

#endif // INTERFACE_USUARIO_H