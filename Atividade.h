#include <iostream>
#include "Pessoa.h"

using namespace std;

#define MAXIMO_RECURSOS 10

#ifndef ATIVIDADE_H
#define ATIVIDADE_H


class Atividade {
public:
    Atividade(string nome, int horasNecessarias);
    virtual ~Atividade();

    string getNome();
    int getHorasNecessarias();

    bool adicionar(Pessoa* recurso);
    Pessoa** getPessoas();
    int getQuantidadeDePessoas();

    int getDuracao();

    double getCusto();

    void imprimir();

private:
    string nome;
    int horasNecessarias;
    int contadorPessoas = 0;
    Pessoa* vetorPessoas[MAXIMO_RECURSOS];
};

#endif // ATIVIDADE_H
