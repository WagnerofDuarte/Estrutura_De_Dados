#include <Arquivo.h>

Arquivo::Arquivo(string _nomeDoArquivo){
    nomeDoArquivo = _nomeDoArquivo;
}

//Retorna se um bit de um byte é 0 ou 1
int Arquivo::um_ou_zero(unsigned char byte, int i){
    unsigned char mascara = (1 << i);
    return byte & mascara;
}

//retorna um byte de 8 bits completo com zeros nos bits mais significativos,
//caso o parametro "bits" possua menos de 8 bits, formando um "byte" completo
string Arquivo::completaBits(string bits){

    int complemento = bits.size() % 8;
    int qtdDeZeros = 8 - complemento;
    
    if(qtdDeZeros != 8){
        while(qtdDeZeros != 0){
            bits = "0" + bits;
            qtdDeZeros--;
        }
    }

    return bits;
}

/* Converte um número da base binária qualquer, em sua respectiva representação na base decimal */
string Arquivo::converteDecimalParaBinario(int numeroDecimal){

    string binarioAux = "";
    string binario = "";

    while(numeroDecimal > 0){
        if(numeroDecimal % 2 == 0){
            binarioAux = binarioAux + "0";
        } else {
            binarioAux = binarioAux + "1";
        }
        numeroDecimal = numeroDecimal/2;
    }
    int j = binarioAux.size() - 1;

    while(j >= 0){
        binario = binario + binarioAux[j];
        j--;
    }

    binario = completaBits(binario);

    return binario;
}

/* Converte um número da base decimal qualquer, em sua respectiva representação na base binária */
int Arquivo::converteBinarioParaDecimal(string numeroBinario){

    int decimal = 0;
    int tamanho = numeroBinario.size();

    for (int i = 0; i < tamanho; i++) {
        if (numeroBinario[i] == '1') {
            decimal += pow(2, tamanho - 1 - i);
        }
    }

    return decimal;

}
/* Converte um byte para seu respectivo caractere da tabela UTF-8 */
char Arquivo::converteByteParaCaractere(const string& bits){

    string caractere = "";

    unsigned char caractereByte = static_cast<unsigned char>(stoi(bits, nullptr, 2));
    caractere += caractereByte;

    return caractere[0];

}

/* Converte um caractere para seu respectivo byte da tabela UTF-8 */
int Arquivo::converteCaractereParaByte(string& caractere){

    string byte = caractere;
    string stringByte = "";

    for (char c : byte) {
       stringByte.append(to_string(static_cast<unsigned int>(static_cast<unsigned char>(c))));
    }

    return stoi(stringByte);
}
/* Lê e armazena os dados do arquivo de texto que será compactado */
Lista* Arquivo::lerArquivo(){

    fstream arquivoDeLeitura(nomeDoArquivo);

    if(!arquivoDeLeitura){
        cout << "ARQUIVO " << nomeDoArquivo << " NAO FOI ENCONTRADO OU NAO PODE SER ABERTO" << endl;
        exit(1);
    }

    Lista* listaCaracteres = new Lista();

    string linha;
    string arquivoCompleto;

    while(getline(arquivoDeLeitura, linha)){
        arquivoCompleto = arquivoCompleto + '\n' + linha;
    }

    for(int i = 0; i < arquivoCompleto.size(); i++){
        listaCaracteres->insereFinal(arquivoCompleto[i], true);
    }

    return listaCaracteres;
}

/* Esse método faz a compactação do arquivo de entrada*/
void Arquivo::compactar(string textoCodificado,char const *nomeDoArquivo, Lista* listaDeFrequencias){

    FILE *compactado = fopen(nomeDoArquivo, "wb");
    int i = 0;
    int posBit = 7;
    unsigned char mascara = 0;
    unsigned char byte = 0;

    if(compactado){
        // Escreve a frequencia
        string frequenciasString = "";
        string byteDivisor = "00000000";
        CelulaLista* aux = listaDeFrequencias->getPrimeiro();

        while(aux != NULL){
            //adicionar o byte do caractere
            string caractere = to_string(aux->getCaractere());
            frequenciasString = frequenciasString + converteDecimalParaBinario(stoi(caractere));
            //adicionar o byte da frequencia do caractere
            int frequencia = aux->getFrequencia();
            frequenciasString = frequenciasString + converteDecimalParaBinario(frequencia) + byteDivisor;

            aux = aux->getProx();
        }

        //adicionar o(s) byte(s) de separacao
        frequenciasString = frequenciasString + byteDivisor;
        textoCodificado = frequenciasString + textoCodificado;

        // Escreve o texto em formato de bytes
        i = 0;
        posBit = 7;
        mascara = 0;
        byte = 0;
        while(i < textoCodificado.size()){
            mascara = 1;
            if(textoCodificado[i] == '1'){
                mascara = mascara << posBit;
                byte = byte | mascara;
            }
            posBit--;

            if(posBit < 0){
                fwrite(&byte, sizeof(unsigned char), 1, compactado);
                byte = 0;
                posBit = 7;
            }
            i++;
        }
        if(posBit != 7){
            fwrite(&byte, sizeof(unsigned char), 1, compactado);
            fclose(compactado);
        }

    } else {
        cout << "ARQUIVO " << nomeDoArquivo << " NAO FOI ENCONTRADO OU NAO PODE SER ABERTO" << endl;
    }
}

/* Essa funcao extrai a lista de frequencias do arquivo compactado, de forma que a arvore de huffman possa ser gerada
   e consequentemente sua descomapctacao */
Lista* Arquivo::extrairListaDeFrequencias(char const *nomeDoArquivoComp){
    Lista* listaDeFrequencia = new Lista();

    FILE *arquivo = fopen(nomeDoArquivoComp, "rb");
    unsigned char byte;

    if(arquivo){

        bool caractere_ou_frequencia = false; //false é caractere e true é frequencia
        int fimDaFrequencia = 0;
        string byte_num_aux = "";
        while(fread(&byte, sizeof(unsigned char), 1, arquivo)){
            string byte_aux = "";
            for(int i = 7; i >= 0; i--){
                if(um_ou_zero(byte, i)){
                    byte_aux = byte_aux + "1";
                } else {
                    byte_aux = byte_aux + "0";
                }
            }
            //Se encontrar o byte de separacao;
            if(converteBinarioParaDecimal(byte_aux) == 0){
                fimDaFrequencia++;
                //Terminou de ler os bytes de freqeuncia do caractere em questao
                if(fimDaFrequencia == 1){
                    int frequencia = converteBinarioParaDecimal(byte_num_aux);
                    listaDeFrequencia->getUltimo()->setFrequencia(frequencia);
                    listaDeFrequencia->getUltimo()->getArvoreFrequencias()->raiz->setFrequencia(frequencia);
                    caractere_ou_frequencia = false;
                    byte_num_aux = "";
                } else if (fimDaFrequencia == 2){
                    break;
                }
            } else {
                fimDaFrequencia = 0;
                //Lê o caractere
                if(!caractere_ou_frequencia){
                    listaDeFrequencia->insereFinal(converteByteParaCaractere(byte_aux), true);
                    caractere_ou_frequencia = true;
                //Lê e acumula os bytes de frequencia do caractere em questao
                } else {
                    byte_num_aux = byte_num_aux + byte_aux;
                }
            }
        }
        fclose(arquivo);
        return listaDeFrequencia;
    }
    cout << "ARQUIVO " << nomeDoArquivoComp << " NAO FOI ENCONTRADO OU NAO PODE SER ABERTO" << endl;
    return NULL;
}
/* Faz a descompactação do arquivo compactado, criando um arquivo com o texto descompactado escrito nele */
string Arquivo::descompactar(char const * nomeDoArquivoComp, char const * nomeDoArquivo, NoArvore* raiz){
    
    FILE *arquivo = fopen(nomeDoArquivoComp, "rb");
    unsigned char byte;
    string textoDescompactado = "";

    if(arquivo){
        NoArvore* aux = raiz;
        int inicioTexto = 0;
        while(fread(&byte, sizeof(unsigned char), 1, arquivo)){
            //Ignora a primeira parte do arquivo compactdado, pois é a lista de frequencias (que ja foi extraida)
            if(inicioTexto < 2){
                string byte_aux = "";
                for(int i = 7; i >= 0; i--){
                    if(um_ou_zero(byte, i)){
                        byte_aux = byte_aux + "1";
                    } else {
                        byte_aux = byte_aux + "0";
                    }
                }
                if(byte_aux == "00000000"){ 
                    inicioTexto++;
                } else {
                    inicioTexto = 0;
                }
            // Lê a segunda parte do arquivo, que contém o texto compactado á ser descompactado
            } else {
                for(int i = 7; i >= 0; i--){
                    if(um_ou_zero(byte, i)){
                        aux = aux->dir;
                    } else {
                        aux = aux->esq;
                    }
                    if(aux->esq == NULL && aux->dir == NULL){
                        textoDescompactado = textoDescompactado + aux->getCaractere();
                        aux = raiz;
                    }
                }
            }
        }
        fclose(arquivo);

        ofstream arquivoDescompactado(nomeDoArquivo);
        arquivoDescompactado << textoDescompactado;
        arquivoDescompactado.close();

        return textoDescompactado;
    } else {
        cout << "ARQUIVO " << nomeDoArquivoComp << " NAO FOI ENCONTRADO OU NAO PODE SER ABERTO" << endl;
        return NULL;
    }
    
}