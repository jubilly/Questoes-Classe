#include <iostream>
#include <locale.h>

using namespace std;

struct Aluno
{
    string nome;
    int matricula;
    float notas[4];
};

Aluno addAluno(Aluno aluno)
{
    cin.ignore();
    cout << "Insira o nome:";
    getline(cin,aluno.nome);

    cout << "Insira a matrícula:";
    cin >> aluno.matricula;

    cout << "Insira a primeira nota:";
    cin >> aluno.notas[0];

    cout << "Insira a segunda nota:";
    cin >> aluno.notas[1];

    cout << "Insira a terceira nota:";
    cin >> aluno.notas[2];

    aluno.notas[3]=(aluno.notas[0]+aluno.notas[1]+aluno.notas[2])/3;
    return aluno;
}

 void printAlunos(Aluno alunos[], int qtd)
 {
     cout <<"ALUNOS CADASTRADOS\n\n";
     for(int i=0;i<qtd;i++)
     {
         cout << "Nome:" << alunos[i].nome << "\n";
         cout << "Matrícula:" << alunos[i].matricula << "\n";
         cout << "Nota da 1º:" << alunos[i].notas[0] << "\n";
         cout << "Nota da 2º:" << alunos[i].notas[1] << "\n";
        cout << "Nota da 3º:" << alunos[i].notas[2] << "\n";
        cout << "Média:" << alunos[i].notas[3] << "\n";
        if(alunos[i].notas[3]>=7)
        {
            cout << "Aluno aprovado\n\n";
        }
        else
        {
            cout << "Aluno reprovado\n\n";
        }
     }
 }

 void printAluno(Aluno aluno)
 {
         cout << "Nome:" << aluno.nome << "\n";
         cout << "Matrícula:" << aluno.matricula << "\n";
         cout << "Nota da 1º:" << aluno.notas[0] << "\n";
         cout << "Nota da 2º:" << aluno.notas[1] << "\n";
        cout << "Nota da 3º:" << aluno.notas[2] << "\n";
        cout << "Média:" << aluno.notas[3] << "\n";
        if(aluno.notas[3]>=7)
        {
            cout << "Aluno aprovado\n\n";
        }
        else
        {
            cout << "Aluno reprovado\n\n";
        }
 }

 Aluno maiorNota(Aluno alunos[], int qtd)
 {
     float aux;
     int indice;
     for(int i = 0;i<qtd;i++)
     {
         if(alunos[i].notas[0]>aux)
         {
             aux=alunos[i].notas[0];
             indice=i;
         }
     }

     return alunos[indice];

 }

 Aluno maiorMedia(Aluno alunos[], int qtd)
 {
     float aux;
     int indice;
     for(int i = 0;i<qtd;i++)
     {
         if(alunos[i].notas[3]>aux)
         {
             aux=alunos[i].notas[3];
             indice=i;
         }
     }

     return alunos[indice];

 }

 Aluno menorMedia(Aluno alunos[], int qtd)
 {
     float aux=alunos[0].notas[3];
     int indice;
     for(int i = 0;i<qtd;i++)
     {
         if(alunos[i].notas[3]< aux)
         {
             aux=alunos[i].notas[3];
             indice=i;
         }
     }

     return alunos[indice];

 }


int main()
{
    setlocale(LC_ALL,"Portuguese");

    int qtd=0;
    Aluno alunos[100];

    system("cls");
    while(true)
    {
    system("cls");
    cout<< "1 - Adicionar aluno:\n2 - Mostrar os alunos cadastrados\n3 - Aluno com maior nota na primeira prova\n4 - Aluno com maior média\n5 - Aluno com menor média\n0 - sair\nEsolha uma das opções a seguir:";
    int opcao;
    cin >> opcao;


    switch(opcao)
    {
    case 0:
        return 0;
    break;
    case 1:
        system("cls");
        alunos[qtd]=addAluno(alunos[qtd]);
        qtd++;
        system("pause");
    break;
    case 2:
        system("cls");
        if(qtd!=0)
        {

        printAlunos(alunos,qtd);
        }
        else
        {
            cout << "Nenhum aluno cadastrado\n";
        }
        system("pause");
    break;
    case 3:
        system("cls");
        if(qtd!=0)
        {
        cout << "ALUNO COM MAIOR NOTA NA PRIMEIRA NOTAS\n\n";
        printAluno(maiorNota(alunos,qtd));
        }
        else
        {
            cout << "Nenhum aluno cadastrado\n";
        }
        system("pause");
    break;
    case 4:
        system("cls");
        if(qtd!=0)
        {
        cout << "ALUNO COM MAIOR MÉDIA\n\n";
        printAluno(maiorMedia(alunos,qtd));
        }
        else
        {
            cout << "Nenhum aluno cadastrado\n";
        }
        system("pause");
    break;
    case 5:
        system("cls");
        if(qtd!=0)
        {
        cout << "ALUNO COM MENOR MÉDIA\n\n";
        printAluno(menorMedia(alunos,qtd));
        }
        else
        {
            cout << "Nenhum aluno cadastrado\n";
        }
        system("pause");
    break;
    }


    }
}
