#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>

using namespace std;

// Classe Hour
class Hour {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Hour();  // Construtor padrão
    void tick();  // Incrementa o tempo (segundos)
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    string showTime() const;  // Mostra o horário atual
    bool isMidnight() const;  // Verifica se é meia-noite
};

// Classe Calendar
class Calendar {
private:
    int day;
    int month;
    int year;

public:
    Calendar();  // Construtor padrão
    void advanceDay();  // Avança o dia
    void showDate() const;  // Mostra a data atual
};

// Classe Clock (que contém Hour e Calendar)
class Clock {
private:
    Hour hour;
    Calendar calendar;

public:
    Clock();  // Construtor padrão
    void updateClock();  // Atualiza o relógio
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    string showClock() const;  // Mostra o relógio (data e hora)
};

#endif