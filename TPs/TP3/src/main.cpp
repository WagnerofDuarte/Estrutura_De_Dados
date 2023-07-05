#include <iostream>

#include <Arquivo.h>
#include <Huffman.h>

using namespace std;

int main(int argc, char const *argv[]){

    char const *arquivo1 = argv[1];
    char const *arquivo2 = argv[2];
    string comando = argv[3];

    Huffman* huffman = new Huffman();
    

    if(comando == "-c"){

        Arquivo* arquivo = new Arquivo(arquivo1);

        Lista* listaCaracteres = arquivo->lerArquivo();
        huffman->calcularFrequencias(listaCaracteres);
        huffman->getListaDeFrequecias()->ordena();
        huffman->gerarArvoreDeFrequencias();
        huffman->gerarDicionario();
        huffman->codificar(listaCaracteres);
        huffman->compactar(arquivo2);


        return 0;

    } else if(comando == "-d"){

        huffman->descompactar(arquivo1, arquivo2);

        return 0;

    } else {

        cout << "COMANDO INVÁLIDO" << endl;

        return -1;

    }   
}