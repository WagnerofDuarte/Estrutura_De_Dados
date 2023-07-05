#ifndef HUFFMAN
#define HUFFMAN

#include <Lista.h>
#include <Arvore.h>
#include <Dicionario.h>
#include <string>
#include <Arquivo.h>

using namespace std;

/* Esta classe é responsável por armazenar os atributos e métodos cruciais para a execucao do algorítimo
   de Huffman, como a criacao do dicionário e geração da árvore de frequencias necessárias para a compactação */

class Huffman {

    private:
        Lista* listaDeFrequencias;
        Arvore* arvoreDeFrequencias;
        Dicionario* dicionario;
        string textoCodificado;

        void preencheDicionario(NoArvore* p, string bits);

    public:
        Huffman();

        void calcularFrequencias(Lista* listaDeCaracteres);
        void gerarArvoreDeFrequencias();

        Lista* getListaDeFrequecias();
        Arvore* getArvoreDeFrequencias();

        void gerarDicionario();
        void codificar(Lista* listaCaracteres);

        void compactar(char const *nomeDoArquivo);
        void descompactar(char const * nomeDoArquivoComp, char const * nomeDoArquivo);
};

#endif