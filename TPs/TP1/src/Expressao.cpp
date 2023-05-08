#include <Expressao.h>

Expressao::Expressao(char expressaoChar[1000], int tamanho, int _infixaOuPosfixa){

    tamanhoExpressao = tamanho;
    infixaOuPosfixa = _infixaOuPosfixa;
    expressaoInfixaOuPosfixa = _infixaOuPosfixa;

    expressao = new Lista();
    posFixa = new Fila();
    inFixa = new Arvore();

    armazenaExpressao(expressaoChar);
} 

Expressao::~Expressao() {

}

void Expressao::imprimirExpressao(char expressaoChar[1000], int tamanho){

    for(int i = 0; i < tamanho; i++){
        cout << expressaoChar[i];
    }

}

int Expressao::validacaoDeExpressao(char expressaoChar[1000], int tamanho, int _infixaOuPosfixa){

    int i = 0;

    while(expressaoChar[i] == ' '){
        i++;
    }

    if(expressaoChar[i] == '('){

        if(_infixaOuPosfixa == 2){
            
            int qtdNum = 0;
            int qtdOperadores = 0;
            int qtdAbreP = 0;
            int qtdFechaP = 0;
            bool seqOperadores = false;
            bool seqNumeros = false;
            
            for(i = 0; i < tamanho; i++){

                if(expressaoChar[i] != ' '){

                    if(eOperador(expressaoChar[i])){

                        if(seqOperadores == true){
                            return 0;
                        }
                        qtdOperadores++;
                        seqNumeros = false;
                        seqOperadores = true;
                    } else 

                    if(expressaoChar[i] == ','){
                        if(seqNumeros == true){
                            return 0;
                        }
                        qtdNum++;
                        seqNumeros = true;
                        seqOperadores = false;
                    } else 

                    if(expressaoChar[i] == '('){
                        qtdAbreP++;
                        seqNumeros = false;
                        seqOperadores = false;
                    } else 

                    if(expressaoChar[i] == ')'){
                        qtdFechaP++;
                        seqNumeros = false;
                        seqOperadores = false;
                    } else
                    
                    if(eNumero(expressaoChar[i])){
                        seqOperadores = false;
                        seqNumeros = false;
                    } else {
                        
                        return 0;
                    }             
                }
            }

            if(qtdNum == qtdOperadores + 1 && qtdAbreP == qtdFechaP){
                return 2;
            } else {
                return 0;
            }
        } else {
            return 0;
        }

    } else if(eNumero(expressaoChar[i])){

        if(_infixaOuPosfixa == 1){

            int qtdNum = 0;
            int qtdOperadores = 0;
            
            for(i = 0; i < tamanho; i++){

                if(eOperador(expressaoChar[i])){
                    qtdOperadores++;
                }

                if(expressaoChar[i] == ','){
                    qtdNum++;
                }

            }

            if(qtdNum == qtdOperadores + 1){
                return 1;
            } else {
                return 0;
            }
    
        } else {
            return 0;
        }

    } else {
        return 0;
    }    
}

bool Expressao::eNumero(char c) {
    if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'){
        return true;
    } else {
        return false;
    }
}

bool Expressao::eOperador(char c) {

    if(c == '+' || c == '-' || c == '*' || c == '/'){
        return true;
    } else {
        return false;
    }

}

void Expressao::armazenaExpressao(char expressaoChar[1000]){

    /* Armazena a expressao em uma lista encadeada */

    if(expressao->getTamanho() == 0){ 

        cout << "EXPRESSAO OK: ";

        for(int i = 0; i < tamanhoExpressao; i++){

            char c = expressaoChar[i];
            expressao->insereFinal(c, 0);

            cout << c;

        }

        cout << endl;
    }

    CelulaLista* aux = new CelulaLista();
    aux = expressao->getPrimeiro();

    if(expressaoInfixaOuPosfixa == 1) { // posfixa

        while(aux != NULL){

            char caractere = aux->getCaractere();

            if(eNumero(caractere)){
                aux = converteNum(aux);
                posFixa->enfileira(caractere, aux->getNum());

            } else if(caractere != ' ') {
                posFixa->enfileira(caractere, 0);
                aux = aux->getProx();

            } else {

                aux = aux->getProx();

            }
        }
        posFixa->desenfileira();
        

    } else { // infixa

        while(aux != NULL){

            char caractere = aux->getCaractere();

            if(eNumero(caractere)){
                aux = converteNum(aux);
                inFixa->InsereExpressaoPosFixa(inFixa->raiz, caractere, aux->getNum());

            } else {
                inFixa->InsereExpressaoPosFixa(inFixa->raiz, caractere, 0);
                aux = aux->getProx();

            }
        }

    }

}

void Expressao::converteExpressao(int _infixaOuPosfixa){

    if(_infixaOuPosfixa != infixaOuPosfixa){

        if(infixaOuPosfixa == 1){
            cout << "INFIXA:";
            inFixa = new Arvore();
            convertePraInFixa();
            inFixa->leInFixa(inFixa->raiz);
            cout << endl;
            infixaOuPosfixa = 2;
        } else {
            posFixa = new Fila();
            convertePraPosFixa(inFixa->raiz);
            cout << "POSFIXA: ";
            posFixa->leFila();
            infixaOuPosfixa = 1;
        }

    } else {
        if(infixaOuPosfixa == 2){
            cout << "INFIXA:";
            inFixa->leInFixa(inFixa->raiz);
            cout << endl;
        } else {
            cout << "POSFIXA: ";
            posFixa->leFila();
        }
    }

}


void Expressao::convertePraPosFixa(NoArvore* no){

    if(no != NULL){

        convertePraPosFixa(no->esq);
        convertePraPosFixa(no->dir);
        posFixa->enfileira(no->getCaractere(), no->getNum());

    }

}

void Expressao::convertePraInFixa(){

    Pilha* pilha = new Pilha();
    //Lista* aux = new Lista();

    while(posFixa->getTamanho() > 0){

        char caractere = posFixa->desenfileira();

        if(eNumero(caractere)){

            double num = posFixa->getFrenteNumero();
            pilha->empilha(num, num);

        } else {

            CelulaPilha* celula1; 
            CelulaPilha* celula2;

            char operador = posFixa->getFrente();
            //double p2 = pilha->desempilha();
            //double p1 = pilha->desempilha();

            celula1 = pilha->getTopo();

            if(celula1->getL() == NULL){ //celula 1 representa um numero

                double p2 = pilha->desempilha();
                celula2 = pilha->getTopo();

                if(celula2->getL() == NULL){ //celula 2 representa um numero

                    Lista* aux = new Lista();
                    double p1 = pilha->desempilha();

                    aux->insereFinal('(', 0);
                    aux->insereFinal('(', 0);
                    aux->insereFinal('0', p1);
                    aux->insereFinal(')', 0);
                    aux->insereFinal(operador, '0');
                    aux->insereFinal('(', 0);
                    aux->insereFinal('0', p2);
                    aux->insereFinal(')', 0);
                    aux->insereFinal(')', 0);

                    pilha->empilhaLista(aux);

                } else { //celula 2 representa uma lista

                    Lista* aux = new Lista();
                    aux = celula2->getL();

                    aux->insereInicio('(', 0);
                    aux->insereFinal(operador, '0');
                    aux->insereFinal('(', 0);
                    aux->insereFinal('0', p2);
                    aux->insereFinal(')', 0);
                    aux->insereFinal(')', 0);

                }

            } else { // celula 1 representa uma lista

                Lista* aux = new Lista();
                aux = celula1->getL();

                pilha->desempilha();

                celula2 = pilha->getTopo();

                if(celula2->getL() == NULL){ //celula 2 representa um numero

                    double p1 = pilha->desempilha();

                    aux->insereInicio(operador, 0);
                    aux->insereInicio(')', 0);
                    aux->insereInicio('0', p1);
                    aux->insereInicio('(', 0);
                    aux->insereInicio('(', 0);
                    aux->insereFinal(')', 0);

                    pilha->empilhaLista(aux);

                } else { //celula 2 representa uma lista

                    Lista* aux2 = new Lista();
                    aux2 = celula2->getL();

                    aux2->insereInicio('(', 0);
                    aux2->insereFinal(operador, 0);
                    aux->insereFinal(')', 0);

                    aux2->concatena(aux);            
                }
            }
        }
    }

    Lista* conversao = pilha->getTopo()->getL();

    CelulaLista* celulaLista;

    celulaLista = conversao->getPrimeiro()->getProx();
    
    while(celulaLista != NULL){

        inFixa->InsereExpressaoPosFixa(inFixa->raiz, celulaLista->getCaractere(), celulaLista->getNum());
        celulaLista = celulaLista->getProx();

    }

}

void Expressao::resolveExpressao(){

    if(infixaOuPosfixa == 1){
        resolvePosFixa();
        if(expressaoInfixaOuPosfixa == 1){
            char c[0];
            armazenaExpressao(c);
        } else {
            convertePraPosFixa(inFixa->raiz);
        }
        
    } else {
        resolveInFixa();
    }

}

void Expressao::resolvePosFixa(){

    resultadoExpressao = posFixa->gerarResultado();

    cout << "POSFIXA: " << resultadoExpressao << endl;

    //recuperaExpressaoPosFixa();
    
}

void Expressao::resolveInFixa(){

    resultadoExpressao = inFixa->gerarResultado(inFixa->raiz);

    cout << "INFIXA: " << resultadoExpressao << endl;
    
}

CelulaLista* Expressao::converteNum(CelulaLista* celula){

    CelulaLista* aux;

    double potencia = 1;
    double num = 0;

    while(celula->getCaractere() != ',' && celula->getCaractere() != ')' && celula->getCaractere() != ' '){

        aux = celula;
        potencia = 1;

        while(aux->getProx()->getCaractere() != ',' && aux->getProx()->getCaractere() != ')' && aux->getProx()->getCaractere() != ' '){
            potencia = potencia * 10;
            aux = aux->getProx();
        }

        num = num + ((celula->getCaractere() - '0')*(potencia));
        celula = celula->getProx();

    }

    if(celula->getCaractere() == ','){

        potencia = 0.1;
        aux = celula->getProx();

        while(eNumero(aux->getCaractere())){
            num = num + ((aux->getCaractere() - '0')*(potencia));
            aux = aux->getProx();
            potencia = potencia / 10;
        }

        aux->setNum(num);
        return aux;

    } else {

        aux = aux->getProx();
        aux->setNum(num);

        return aux;

    }

}

int Expressao::getTamanhoExpressao(){

    return tamanhoExpressao;

}