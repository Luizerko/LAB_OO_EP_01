#include <iostream>
#include "Pessoa.h"
#include "Atividade.h"
#include "Projeto.h"

using namespace std;

int main()
{
    /*
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
    Pessoa *pessoa_03 = new Pessoa("joao", 24, 3);
    cout << projeto_01->getNome() << endl;
    cout << projeto_01->adicionar(atividade_01) << endl;
    cout << projeto_01->adicionar(atividade_01) << endl;
    cout << projeto_01->adicionar(atividade_02) << endl;
    cout << projeto_01->adicionar(atividade_02) << endl;
    cout << projeto_01->getAtividades() << endl;
    cout << projeto_01->getQuantidadeDeAtividades() << endl;
    cout << projeto_01->adicionarRecurso(pessoa_01) << endl;
    cout << projeto_01->adicionarRecurso(pessoa_01) << endl;
    cout << projeto_01->adicionarRecurso(pessoa_02) << endl;
    cout << projeto_01->adicionarRecurso(pessoa_03) << endl;
    cout << projeto_01->getPessoas() << endl;
    cout << projeto_01->getQuantidadeDePessoas() << endl;
    cout << projeto_01->getDuracao() << endl;
    cout << projeto_01->getCusto() << endl;
    projeto_01->imprimir();
    cout << "----------------      " << endl;
    */


    //Implementação da main:
    string nome_projeto;
    cout << "Digite o nome do projeto: ";
    cin >> nome_projeto;
    Projeto* projeto_01 = new Projeto(nome_projeto);

    int opcao, i, contador_pessoas = 0, contador_atividades = 0;
    string nome_pessoa, nome_atividade;
    int valor_por_hora, horas_diarias, horas_necessarias;
    char add_recurso;
    Pessoa* pessoas[MAXIMO_RECURSOS];
    Atividade* atividades[MAXIMO_ATIVIDADES];
    while(opcao != 0) {
        cout << "1 - Adicionar pessoa" << endl;
        cout << "2 - Adicionar atividade" << endl;
        cout << "3 - Imprimir projeto" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha a opcao: ";
        cin >> opcao;

        if(opcao == 1) {
            cout << "Nome: ";
            cin >> nome_pessoa;
            cout << "Valor por hora (em R$): ";
            cin >> valor_por_hora;
            cout << "Horas diarias: ";
            cin >> horas_diarias;
            if(contador_pessoas < MAXIMO_RECURSOS) {
                pessoas[contador_pessoas] = new Pessoa(nome_pessoa, valor_por_hora, horas_diarias);
                if(projeto_01->adicionarRecurso(pessoas[contador_pessoas]) == 1) {
                    projeto_01->adicionarRecurso(pessoas[contador_pessoas]) == 1;
                    contador_pessoas++;
                }
                else {
                    cout << "Nao eh possivel adicionar uma nova pessoa" << endl;
                }
            }
            else {
                cout << "Nao eh possivel adicionar uma nova pessoa" << endl;
            }
        }

        if(opcao == 2) {
            cout << "Nome: ";
            cin >> nome_atividade;
            cout << "Horas necessarias: ";
            cin >> horas_necessarias;
            if(contador_atividades < MAXIMO_ATIVIDADES) {
                atividades[contador_atividades] = new Atividade(nome_atividade, horas_necessarias);
                projeto_01->adicionar(atividades[contador_atividades]);
                add_recurso = 's';
                while(add_recurso != 'n') {
                    cout << "Deseja adicionar um recurso (s/n)? ";
                    cin >> add_recurso;
                    if(add_recurso == 's') {
                        for(i = 1; i <= contador_pessoas; i++) {
                            cout << i << " - " << pessoas[i-1]->getNome() << " - R$" << pessoas[i-1]->getValorPorHora() << " - " << pessoas[i-1]->getHorasDiarias() << "h por dia" << endl;
                        }
                        cout << "Escolha uma pessoa ou 0 para cancelar: ";
                        cin >> i;
                        if(atividades[contador_atividades]->adicionar(pessoas[i-1]) == 1 && i != 0) {
                            atividades[contador_atividades]->adicionar(pessoas[i-1]);
                        }
                        else {
                            cout << "Nao foi possivel adicionar a pessoa" << endl;
                        }
                    }
                }
                contador_atividades++;
            }
            else {
                cout << "Nao eh possivel adicionar uma nova atividade" << endl;
            }
        }

        if(opcao == 3) {
            projeto_01->imprimir();
        }
    }
    return 0;
}
