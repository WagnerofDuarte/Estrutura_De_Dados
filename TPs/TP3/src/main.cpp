#include <iostream>

#include <Arquivo.h>
#include <Huffman.h>

using namespace std;

/*

    1 - Ler arquivo OK
    2 - Determinar Frequencias OK

*/

int main(int argc, char const *argv[]){

    Arquivo* arquivo = new Arquivo("teste.txt");
    Lista* listaCaracteres = arquivo->lerArquivo();

    listaCaracteres->imprime();
    cout << endl;

    Huffman* huffman = new Huffman();
    huffman->calcularFrequencias(listaCaracteres);
    
    return 0;
}
