#include "sistema.h"

ostream& operator<<(ostream &Saida, Paciente &paciente)
{
    paciente.imprimir();
    cout << endl;

    return Saida;
};

template <class P>
ostream& operator<<(ostream &Saida, Arvore<P> &arvore)
{
    arvore.imprime();

    return Saida;
};

void Sistema::insere()
{
    string nome, idade, tipo;

    cout << "Digite o nome do paciente"<< endl;

    cout << endl;
    cout << "Digite aqui:";
    cin.ignore(100,'\n');
    getline(cin, nome,'\n');
    cout << endl;

    for (unsigned i = 0; i < nome.size(); i++)
    {
        if (isupper(nome[i]))//Tratamento letras maiusculas transforma em minusculas
        {
            nome[i] = tolower(nome[i]);
        }
    }

    if (arvore[nome] != NULL)
    {
        throw runtime_error("Paciente ja foi registrado!!!");
    }

    cout << "Digite a idade do paciente"<< endl;

    cout << endl;
    cout << "Digite aqui:";
    getline(cin, idade,'\n');
    cout << endl;

    cout << "Digite a opcao referente ao setor do paciente:"<< endl;
    cout << "1. Pediatria"<< endl;
    cout << "2. Geriatria"<< endl;

    cout << endl;
    cout << "Digite aqui:";
    getline(cin, tipo,'\n');
    cout << endl;

    if (tipo == "1")
    {
        PacientePediatrico paciente(nome, stoul(idade));
        arvore = arvore + paciente;
    }
    else if (tipo == "2")
    {
        PacienteGeriatrico paciente(nome, stoul(idade));
        arvore = arvore + paciente;
    }
    else
    {
        throw runtime_error ("Opcao da categoria do paciente inexistente!!!");
    }
}

void Sistema::busca()
{
    string nome;
    cout << "Digite o nome do paciente"<< endl;

    cout << endl;
    cout << "Digite aqui:";
    cin.ignore(100,'\n');
    getline(cin, nome,'\n');
    cout << endl;

    for (unsigned i = 0; i < nome.size(); i++)
    {
        if (isupper(nome[i]))//Tratamento letras maiusculas transforma em minusculas
        {
            nome[i] = tolower(nome[i]);
        }
    }

    if (arvore[nome] == NULL)
    {
        throw runtime_error("Paciente nao encontrado!!!");
    }
    else
    {
        cout << *(arvore[nome]) << endl;
    }
}

void Sistema::imprime(){cout << arvore;}