#include "paciente.h"

Paciente::Paciente(string nomeP, unsigned long idadeP)
{
    maxIdade = 150;
    minIdade = 0;
    esq = NULL;
    dir = NULL;
    setNome(nomeP);
    setIdade(idadeP);
}
Paciente::~Paciente(){}

string Paciente::getNome() {return nome;}
unsigned long Paciente::getIdade() {return idade;}

void Paciente::imprimir()
{
    cout << "Nome: " << getNome() << "\n" << "Idade: " << getIdade() << endl;
}

void Paciente::setNome(string nomeP) {nome = nomeP;}

void Paciente::setIdade(unsigned long idadeP)
{
    if (idadeP > maxIdade)
    {
        throw runtime_error("idade acima do maximo!!!");
    }
    
    idade = idadeP;
}