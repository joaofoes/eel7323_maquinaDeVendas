#include "ListaEncadeada.h"
#include <iostream>
using namespace std;

// Constructor: initializes the list as empty
ListaEncadeada::ListaEncadeada() : cabeca(nullptr) {}

// Adds a transaction to the end of the list
void ListaEncadeada::adicionarAoFim(const string& horario, const string& operacao, const float& saldo) {
    Transacao* novo = new Transacao{horario, operacao, saldo, nullptr};
    if (cabeca == nullptr) {
        cabeca = novo;
    } else {
        Transacao* atual = cabeca;
        while (atual->proximo != nullptr) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}

// Returns the head of the list
Transacao* ListaEncadeada::getCabeca() const {
    return cabeca;
}

void ListaEncadeada::limpar() {
    Transacao* atual = cabeca;
    while (atual != nullptr) {
        Transacao* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
}

// Destrutor, que também chama `limpar` ao destruir o objeto
ListaEncadeada::~ListaEncadeada() {
    limpar(); // Garante que a lista é liberada ao destruir o objeto
}