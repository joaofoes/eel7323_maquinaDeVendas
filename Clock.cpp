#include <time.h>
#include <sstream>
#include "Clock.h"
using namespace std;

// Construtor da classe Hour
Hour::Hour() {
    time_t t = time(NULL);           // Captura o tempo atual
    struct tm* now = localtime(&t);             // Converte para a estrutura de tempo local

    hours = now->tm_hour;
    minutes = now->tm_min;
    seconds = now->tm_sec;
}

// Incrementa o tempo em 1 segundo
void Hour::tick() {
    seconds++;
    if (seconds == 60) {
        seconds = 0;
        minutes++;
        if (minutes == 60) {
            minutes = 0;
            hours++;
            if (hours == 24) {
                hours = 0;
            }
        }
    }
}

int Hour::getHours() const {
    return hours;
}

int Hour::getMinutes() const {
    return minutes;
}

int Hour::getSeconds() const {
    return seconds;
}

// Exibe o horário no formato HH:MM:SS
string Hour::showTime() const {
    ostringstream oss;
    oss << (hours < 10 ? "0" : "") << hours << ":"
        << (minutes < 10 ? "0" : "") << minutes << ":"
        << (seconds < 10 ? "0" : "") << seconds;
    return oss.str();  // Retorna a string formatada
    // cout << (hours < 10 ? "0" : "") << hours << ":"
    //      << (minutes < 10 ? "0" : "") << minutes << ":"
    //      << (seconds < 10 ? "0" : "") << seconds << endl;
}

// Verifica se o horário atual é meia-noite
bool Hour::isMidnight() const {
    return hours == 0 && minutes == 0 && seconds == 0;
}

// Construtor da classe Calendar
Calendar::Calendar() {
    // Obtém a data e hora atuais do sistema
    time_t t = time(NULL);           // Captura o tempo atual
    struct tm* now = localtime(&t);             // Converte para a estrutura de tempo local

    // Inicializa os membros com a data atual
    day = now->tm_mday;
    month = now->tm_mon + 1;  // tm_mon é de 0 a 11, então somamos 1
    year = now->tm_year + 1900; // tm_year é o número de anos desde 1900
}

// Avança o dia e ajusta o mês e ano, se necessário
void Calendar::advanceDay() {
    day++;
    if (day > 30) {  // Simplificação: assumimos 30 dias por mês
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

// Exibe a data no formato DD/MM/YYYY
void Calendar::showDate() const {
    cout << (day < 10 ? "0" : "") << day << "/"
         << (month < 10 ? "0" : "") << month << "/"
         << year << endl;
}

// Construtor da classe Clock
Clock::Clock() {}

// Atualiza o relógio, avançando o horário e, se necessário, o calendário
void Clock::updateClock() {
    hour.tick();
    if (hour.isMidnight()) {  // Se for meia-noite, avança o dia
        calendar.advanceDay();
    }
}

int Clock::getHours() const {
    return hour.getHours();
}

int Clock::getMinutes() const {
    return hour.getMinutes();
}

int Clock::getSeconds() const {
    return hour.getSeconds();
}

// Mostra a data e a hora atual
string Clock::showClock() const {
    // calendar.showDate();
    string time = hour.showTime();
    return time;
}