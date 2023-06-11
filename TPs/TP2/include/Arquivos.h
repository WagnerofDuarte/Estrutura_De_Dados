#ifndef ARQUIVOS
#define ARQUIVOS

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Arquivos {

    private:
        string nomeDoArquivo;
        
    public:
        Arquivos(string _nomeDoArquivo);
        string lerArquivo();
};

#endif