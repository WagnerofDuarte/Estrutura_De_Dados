#ifndef ARQUIVO
#define ARQUIVO

#include <fstream>
#include <iostream>
#include <string>
#include <Lista.h>

using namespace std;

class Arquivo {

    private:
        string nomeDoArquivo;
        
    public:
        Arquivo(string _nomeDoArquivo);
        Lista* lerArquivo();
        //void determinarFrequencias();

};

#endif