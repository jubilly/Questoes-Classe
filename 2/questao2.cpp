#include <iostream>
#include <stdbool.h>
#include <stdio.h>
#include <locale.h>

using namespace std;

struct Compromissos
{
    int dia,mes,ano,hora,minuto;
    string local,descricao;
    bool confirmado;
};

Compromissos adicionarCompromisso(Compromissos com)
{
    com.confirmado=true;

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
        cout << "Data e Hora = " << agenda[i].dia << "/" << agenda[i].mes << "/" << agenda[i].ano << " " << agenda[i].hora <<":" << agenda[i].minuto <<"\n";
        if(agenda[i].confirmado==true)
        {
            cout << "Compromisso confirmado\n\n";

        }
        else
        {
            cout << "Compromisso cancelado\n\n";
        }

    }

}

bool cancelarCompromisso(Compromissos agenda[], int qtd, int opcao)
{
    if(agenda[opcao-1].ano)
    {
        if(agenda[opcao-1].confirmado)
        {

        agenda[opcao-1].confirmado=false;
        cout <<"\nCompromisso cancelado com sucesso \n";
        return true;
        }
        else
        {
            cout <<"\nCompromisso já cancelado\n\n";
        }
    }
    else
    {
        cout << "\nNão foi possível cancelar o compromisso\n\n";
        return false;
    }
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
        cout <<"1 - Adicionar um compromisso\n2 - Ver os compromissos\n3 - Cancelar compromisso\n0 - Sair\nEscolha uma opção:";
        cin >> opcao;
        switch(opcao)
        {
            case 0:
                return 0;
            break;
            case 1:

              system("cls");
              com[qtd]=adicionarCompromisso(com[qtd]);
              qtd++;
            break;
            case 2:
                system("cls");
                verCompromissos(com,qtd);
                system("pause");
            break;
            case 3:
                system("cls");
                verCompromissos(com,qtd);
                cout << "Escolha um dos compromissos para cancelar:";
                int op;
                cin >> op;
                bool resultado=cancelarCompromisso(com,qtd,op);
                system("pause");
                if(resultado==true)
                {
                    com[op].confirmado=false;
                }


            break;

        }
    }


}
