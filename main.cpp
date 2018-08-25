#include <iostream>
#include "Pessoa.h"
#include "Atividade.h"
#include "Projeto.h"

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
    cout << "----------------      " << endl;

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
    cout << "----------------      " << endl;

    //Teste para projeto:
    Projeto *projeto_01 = new Projeto("Teste");
    Atividade *atividade_02 = new Atividade("Contas", 20);
    cout << projeto_01->getNome() << endl;
    cout << projeto_01->adicionar(atividade_01) << endl;
    cout << projeto_01->adicionar(atividade_01) << endl;
    cout << projeto_01->adicionar(atividade_02) << endl;
    cout << projeto_01->getAtividades() << endl;
    cout << projeto_01->getQuantidadeDeAtividades() << endl;
    cout << projeto_01->adicionarRecurso(pessoa_01) << endl;
    cout << projeto_01->adicionarRecurso(pessoa_01) << endl;
    cout << projeto_01->adicionarRecurso(pessoa_02) << endl;
    cout << projeto_01->getPessoas() << endl;
    cout << projeto_01->getQuantidadeDePessoas() << endl;
    cout << projeto_01->getDuracao() << endl;
    cout << projeto_01->getCusto() << endl;
    projeto_01->imprimir();
    cout << "----------------      " << endl;

    return 0;
}
