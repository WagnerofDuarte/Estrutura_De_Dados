#ifndef ARQUIVOS
#define ARQUIVOS

#include <fstream>
#include <string>

using namespace std;

class Arquivos {

    private:
        string nomeDoArquivo;
        
    public:
        Arquivos(string _nomeDoArquivo);
        ~Arquivos();

        string lerArquivo();

};

#endif