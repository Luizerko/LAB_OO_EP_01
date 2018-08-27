#include <iostream>
#include "Atividade.h"
#include "Pessoa.h"

using namespace std;

#define MAXIMO_ATIVIDADES 10

#ifndef PROJETO_H
#define PROJETO_H


class Projeto
{
public:
    Projeto(string nome);
    virtual ~Projeto();

    string getNome();

    bool adicionar(Atividade* a);
    Atividade** getAtividades();
    int getQuantidadeDeAtividades();

    bool adicionarRecurso(Pessoa* p);
    Pessoa** getPessoas();
    int getQuantidadeDePessoas();

    int getDuracao();
    double getCusto();

    void imprimir();

private:
    string nome;
    Atividade* vetorAtividades[MAXIMO_ATIVIDADES];
    Pessoa* vetorPessoas[MAXIMO_RECURSOS];
    int contadorPessoas = 0;
    int contadorAtividades = 0;

};

#endif // PROJETO_H
