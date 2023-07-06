#include <iostream>
#include <string>
#include <vector>
#ifndef PACIENTE_H
#define PACIENTE_H
#include "paciente.h"
#endif

using namespace std;


class PacienteGeriatrico : public Paciente
{
    public:
        PacienteGeriatrico(string nomeP, unsigned long idadeP): Paciente(nomeP, idadeP)
        {
            minIdade = 40;
            setIdade(idadeP);
        }

        ~PacienteGeriatrico(){}

        void imprimir() override
        {
            Paciente::imprimir();
            cout << "Setor: Geriatria" << endl;
        }

    protected:
        void setIdade(unsigned long idadeP) override
        {
            if (idadeP > maxIdade)
            {
                throw runtime_error("idade acima do maximo!!!");
            }
            if (idadeP < minIdade)
            {
                throw runtime_error("idade abaixo do minimo!!!");
            }
    
            idade = idadeP;
        }
};