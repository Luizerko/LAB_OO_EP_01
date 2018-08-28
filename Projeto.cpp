#include <iostream>
#include "Projeto.h"

using namespace std;

Projeto::Projeto(string nome) {
    this->nome = nome;
}

Projeto::~Projeto() {
    //dtor
}

string Projeto::getNome() {
    return nome;
}

bool Projeto::adicionar(Atividade* a) {
    if (contadorAtividades < MAXIMO_ATIVIDADES) {
        vetorAtividades[contadorAtividades] = a;
        contadorAtividades++;
        return true;
    }
    return false;
}

Atividade** Projeto::getAtividades() {
    return vetorAtividades;
}

int Projeto::getQuantidadeDeAtividades() {
    return contadorAtividades;
}

bool Projeto::adicionarRecurso(Pessoa* p) {
    if (contadorPessoas < MAXIMO_RECURSOS) {
        for(int i = 0; i < contadorPessoas; i++) {
            if(vetorPessoas[i]->getNome().compare(p->getNome()) == 0) {
                if(vetorPessoas[i]->getValorPorHora() == p->getValorPorHora()) {
                    if(vetorPessoas[i]->getHorasDiarias() == p->getHorasDiarias()) {
                        return false;
                    }
                }
            }
        }
        vetorPessoas[contadorPessoas] = p;
        contadorPessoas++;
        return true;
    }
    return false;
}

Pessoa** Projeto::getPessoas() {
    return vetorPessoas;
}

int Projeto::getQuantidadeDePessoas() {
    return contadorPessoas;
}

int Projeto::getDuracao() {
    int totalDuracao = 0;
    for(int i = 0; i < contadorAtividades; i++) {
        if(vetorAtividades[i]->getDuracao() != -1) {
            totalDuracao = totalDuracao + vetorAtividades[i]->getDuracao();
        }
    }
    return totalDuracao;
}

double Projeto::getCusto() {
    double totalCusto = 0;
    for(int i = 0; i < contadorAtividades; i++) {
        if(vetorAtividades[i]->getCusto() != -1) {
            totalCusto = totalCusto + vetorAtividades[i]->getCusto();
        }
    }
    return totalCusto;
}

void Projeto::imprimir() {
    if (getDuracao() == 1) {
        cout << getNome() << " - " << getDuracao() << "dia - R$" << getCusto() << endl;
    }
    else {
        cout << getNome() << " - " << getDuracao() << "dias - R$" << getCusto() << endl;
    }
}
