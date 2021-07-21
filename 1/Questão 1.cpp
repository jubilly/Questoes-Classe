#include <iostream>
#include <stdbool.h>
#include <stdio.h>
#include <locale.h>

using namespace std;

struct Compromissos
{
    int dia,mes,ano,hora,minuto;
    string local,descricao;

};

Compromissos adicionarCompromisso(Compromissos com)
{
    cout << "Adicionar o dia:";
    cin >> com.dia;

    cout << "Adicionar o mês:";
    cin >> com.mes;

    cout << "Adicionar o ano:";
    cin >> com.ano;

    cout << "Adicionar o hora:";
    cin >> com.hora;

    cout << "Adicionar o minuto :";
    cin >> com.minuto;

    cout << "Adicionar o local:";
    cin.ignore();
    getline(cin, com.local);

    cout << "Adicionar o descrição:";

    getline(cin, com.descricao);

    system("pause");
    return com;

}

void verCompromissos(Compromissos agenda[], int qtd)
{
    cout << "Lista de compromissos\n\n";
    for(int i=0;i<qtd;i++)
    {
        cout << "Compromisso #" << i+1 <<":" << "\n";
        cout << "Local = " << agenda[i].local << "\n";
        cout << "Descrição = " << agenda[i].descricao << "\n";
        cout << "Data e Hora = " << agenda[i].dia << "/" << agenda[i].mes << "/" << agenda[i].ano << " " << agenda[i].hora <<":" << agenda[i].minuto <<"\n\n";


    }
    system("pause");
}


int main()
{
    setlocale(LC_ALL,"Portuguese");
    Compromissos com[100];
    int qtd=0;

    while (true)
    {
        system("cls");
        int opcao;
        cout <<"1 - Adicionar um compromisso\n2 - Ver os compromissos\n0 - Sair\nEscolha uma opção:";
        cin >> opcao;
        switch(opcao)
        {
            case 1:

              system("cls");
              com[qtd]=adicionarCompromisso(com[qtd]);
              qtd++;
            break;
            case 2:
                system("cls");
                verCompromissos(com,qtd);
            break;
            case 0:
                return 0;
            break;
        }
    }


}
