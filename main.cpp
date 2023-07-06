#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <exception>
#include "sistema.h"

using namespace std;

int main (int argc, char *argv[]) 
{
    Sistema sistema;
    
    int opcao = 0;

    cout << endl;
    cout <<  setw(25) <<"Bem vindo! :)" << endl;

    while(opcao != 4)
    {
        opcao = 0;

        cout << endl;

        //Menu Principal
        cout << setw(18) << "MENU" << endl;
        cout << "Digite o numero da opcao que deseja:" << endl;
        cout << left << setw(25) << "1.Adcicionar paciente" << left << setw(25) << "2.Buscar paciente" << endl;
        cout << left << setw(25) << "3.Exibir pacientes" << left << setw(25) << "4.Sair" << endl;
        cout << endl;

        cout << "Digite aqui:";
        cin >> opcao;
        cout << endl;

        switch(opcao)
        {
            case 1:
                try
                {
                    sistema.insere();
                }
                catch(const exception& e)
                {
                    cerr << "Erro: " << e.what() << endl;
                }
                
                break;

            case 2:
                try
                {
                    sistema.busca();
                }
                catch(const exception& e)
                {
                    cerr << "Erro: " << e.what() << endl;
                }
                
                break;

            case 3:
                sistema.imprime();
               
                break;

             case 4:
                cout << "Volte sempre! :)" << endl;
                cout << endl;

                break;
                
            default:
                cout << "Opcao invalida!!!" << endl;
        }
    }

    return 0;
}
