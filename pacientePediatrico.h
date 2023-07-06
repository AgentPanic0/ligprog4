#include <iostream>
#include <string>
#include <vector>
#ifndef PACIENTE_H
#define PACIENTE_H
#include "paciente.h"
#endif

using namespace std;

class PacientePediatrico : public Paciente
{
    public:
        PacientePediatrico(string nomeP, unsigned long idadeP): Paciente(nomeP, idadeP)
        {
            maxIdade = 18;
            setIdade(idadeP);
        }

        ~PacientePediatrico(){}

        void imprimir() override
        {
            Paciente::imprimir();
            cout << "Setor: Pediatria" << endl;
        }
};