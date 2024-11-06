#ifndef MAQUINAREFRIGERANTE_H
#define MAQUINAREFRIGERANTE_H

#include "ListaEncadeada.h"
#include <iostream>
#include "Clock.h"  
#include "InterfaceUsuario.h"  

enum Estado {
    S000, S025, S050, S075, S100, S125, S150
};

enum Comando {
    NADA, M025, M050, M100, DEV, MEET, ETIRPS, LOG
};

class MaquinaRefrigerante : public InterfaceUsuario {
private:
    Estado estadoAtual;
    bool reset;
    float saldo;
    Clock* clock;
    ListaEncadeada* lista;

public:
    // Construtor que passa a lista encadeada para InterfaceUsuario
    MaquinaRefrigerante(Clock* clock, ListaEncadeada* listaEncadeada);
    void resetar();
    void proximoEstado(Comando comando);
    void mostrarEstado();
    void devolverMoedas();
    void liberarRefrigerante();
    Comando escolherComando();
};

#endif