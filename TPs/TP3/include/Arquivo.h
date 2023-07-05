#ifndef ARQUIVO
#define ARQUIVO

#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

#include <Lista.h>
#include <NoArvore.h>

using namespace std;

/* Esta classe é responsável por fazer o manuseio dos arquivos utilizados no sistema,
   seja lendo, escrevendo ou criando tais aquivos */

class Arquivo {

    private:
        string nomeDoArquivo;
        int um_ou_zero(unsigned char byte, int i);
        string converteListaPraString(Lista* lista);
        string converteDecimalParaBinario(int numeroDecimal);
        int converteBinarioParaDecimal(string numeroBinario);
        char converteByteParaCaractere(const string& bits);
        int converteCaractereParaByte(string& caractere);
        string completaBits(string bits);
        
    public:
        Arquivo(string _nomeDoArquivo);
        Lista* lerArquivo();
        Lista* extrairListaDeFrequencias(char const *nomeDoArquivoComp);
        void compactar(string textoCodificado, char const *nomeDoArquivo, Lista* listaDeFrequencias);
        string descompactar(char const * nomeDoArquivoComp, char const * nomeDoArquivo, NoArvore* raiz);

};

#endif