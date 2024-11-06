#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include <string>
using namespace std;

struct Transacao {
    string horarioTransacao;
    string operacaoRealizada;
    float saldoAtual;
    Transacao* proximo;
};

class ListaEncadeada {
private:
    Transacao* cabeca;

public:
    ListaEncadeada();
    ~ListaEncadeada();
    void adicionarAoFim(const string& horario, const string& operacao, const float& saldo);
    Transacao* getCabeca() const;
    void limpar();
};

#endif // LISTA_ENCADEADA_H