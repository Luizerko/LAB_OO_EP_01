#include <iostream>
#include "Pessoa.h"

using namespace std;

Pessoa::Pessoa(string nome, double valorPorHora, int horasDiarias) {
    this->nome = nome;
    this->valorPorHora = valorPorHora;
    this->horasDiarias = horasDiarias;
}

Pessoa::~Pessoa() {

}

string Pessoa::getNome() {
    return nome;
}

double Pessoa::getValorPorHora() {
    return valorPorHora;
}

int Pessoa::getHorasDiarias() {
    return horasDiarias;
}

double Pessoa::getCusto(int dias) {
    return (dias*horasDiarias)*valorPorHora;
}

void Pessoa::imprimir() {
    cout << nome << " - R$" << valorPorHora << " - " << horasDiarias << "h por dia" << endl;
}
