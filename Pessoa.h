#include <iostream>

using namespace std;

#ifndef PESSOA_H
#define PESSOA_H

class Pessoa {
public:
    Pessoa(string nome, double valorPorHora, int horasDiarias);
    virtual ~Pessoa();

    string getNome();
    double getValorPorHora();
    int getHorasDiarias();
    double getCusto(int dias);

    void imprimir();

private:
    string nome;
    double valorPorHora;
    int horasDiarias;

};

#endif // PESSOA_H
