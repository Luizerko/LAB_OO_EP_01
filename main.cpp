#include <iostream>
#include "Pessoa.h"
#include "Atividade.h"

using namespace std;

int main()
{
    //Teste para pessoas:
    Pessoa *pessoa_01 = new Pessoa("Luis", 20, 4);
    cout << pessoa_01->getNome() << endl;
    cout << pessoa_01->getValorPorHora() << endl;
    cout << pessoa_01->getHorasDiarias() << endl;
    cout << pessoa_01->getCusto(22) << endl;
    pessoa_01->imprimir();

    //Teste para atividades:
    Pessoa *pessoa_02 = new Pessoa("Camila", 25, 4);
    Atividade *atividade_01 = new Atividade("Leitura", 15);
    cout << atividade_01->getNome() << endl;
    cout << atividade_01->getHorasNecessarias() << endl;
    cout << atividade_01->adicionar(pessoa_01) << endl;
    cout << atividade_01->adicionar(pessoa_02) << endl;
    cout << atividade_01->adicionar(pessoa_01) << endl;
    cout << atividade_01->getPessoas() << endl;
    cout << atividade_01->getQuantidadeDePessoas() << endl;
    cout << atividade_01->getDuracao() << endl;
    cout << atividade_01->getCusto() << endl;
    atividade_01->imprimir();

    //Teste para projeto:


    return 0;
}
