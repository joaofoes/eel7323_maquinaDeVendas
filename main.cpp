#include "MaquinaRefrigerante.h"
#include "Oled.h"
#include "ListaEncadeada.h"  // Incluímos o header da ListaEncadeada
#include "Clock.h"

int main() {
    Clock clock;
    ListaEncadeada lista;  // Cria a lista encadeada
    MaquinaRefrigerante maquina(&clock, &lista);  // Passa a lista para a máquina de refrigerante

    oledInit();

    maquina.mostrarEstado();

    while (true) {
        // O relógio será atualizado automaticamente dentro das funções da máquina
        Comando comando = maquina.escolherComando();
        maquina.proximoEstado(comando);
    }

    return 0;
}
