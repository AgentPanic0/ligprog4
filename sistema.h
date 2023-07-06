#include <iostream>
#include <string>
#include <vector>
#include "arvore.h"

using namespace std;

class Sistema
{
    public:

        void insere();
        void busca();
        void imprime();

    private:
        Arvore <Paciente> arvore;
};