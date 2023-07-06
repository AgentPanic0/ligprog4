#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Paciente
{
    public:
        Paciente(string nomeP, unsigned long idadeP);
        virtual ~Paciente();

        string getNome();
        unsigned long getIdade();

        virtual void imprimir();

        Paciente *esq;
        Paciente *dir;

    protected:
        void setNome(string nomeP);
        virtual void setIdade(unsigned long idadeP);

        string nome;
        unsigned long idade;
        unsigned maxIdade, minIdade;
};