#include <Arquivos.h>

Arquivos::Arquivos(string _nomeDoArquivo){

    nomeDoArquivo = _nomeDoArquivo;

}


string Arquivos::lerArquivo(){

    fstream arquivoDeLeitura(nomeDoArquivo);

    if(!arquivoDeLeitura){
        // ERRO!
    }

    string linha;
    string arquivoCompleto;

    while(getline(arquivoDeLeitura, linha)){

        arquivoCompleto = arquivoCompleto + "|" + linha;
    }

    return arquivoCompleto + "|";

}