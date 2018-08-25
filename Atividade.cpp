#include <iostream>
#include <cmath>
#include <string>
#include "Atividade.h"

using namespace std;

Atividade::Atividade(string nome, int horasNecessarias) {
    this->nome = nome;
    this->horasNecessarias = horasNecessarias;
}

Atividade::~Atividade(){

}

string Atividade::getNome() {
    return nome;
}

int Atividade::getHorasNecessarias() {
    return horasNecessarias;
}

bool Atividade::adicionar(Pessoa* recurso) {
    if (contadorPessoas < MAXIMO_RECURSOS) {
        for(int i = 0; i < contadorPessoas; i++) {
            if(vetorPessoas[i]->getNome().compare(recurso->getNome()) == 0) {
                if(vetorPessoas[i]->getValorPorHora() == recurso->getValorPorHora()) {
                    if(vetorPessoas[i]->getHorasDiarias() == recurso->getHorasDiarias()) {
                        return false;
                    }
                }
            }
        }
        vetorPessoas[contadorPessoas] = recurso;
        contadorPessoas++;
        return true;
    }
    return false;
}

Pessoa** Atividade::getPessoas() {
    return vetorPessoas;
}

int Atividade::getQuantidadeDePessoas() {
    return contadorPessoas;
}

int Atividade::getDuracao() {
    double totalDeHoras = 0;
    if(contadorPessoas > 0) {
        for(int i = 0; i < contadorPessoas; i++) {
            totalDeHoras = totalDeHoras + vetorPessoas[i]->getHorasDiarias();
        }
        return ceil(getHorasNecessarias()/totalDeHoras);
    }
    return -1;
}

double Atividade::getCusto() {
    int totalDeCusto = 0;
    if(contadorPessoas > 0) {
        for(int i = 0; i < contadorPessoas; i++) {
            totalDeCusto = totalDeCusto + ((vetorPessoas[i]->getValorPorHora() * vetorPessoas[i]->getHorasDiarias())*getDuracao());
        }
        return totalDeCusto;
    }
    return -1;
}

void Atividade::imprimir() {
    cout << getNome() << " - " << getDuracao() << " dias - R$" << getCusto() << endl;
}
