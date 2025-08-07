#include <stdio.h>
#include <stdlib.h>

void viramosAmigos(char *);
void telefonar();
void chamarSair();
char perguntar(char *);
void descobrirInteresse();


int main(){

    telefonar();
    chamarSair();
    descobrirInteresse();

    return 0;
}

char perguntar(char *pergunta) {    
    char resposta;

    printf("%s\n", pergunta);
    scanf(" %c", &resposta);

    return resposta;
}

void telefonar(){

    char buffer[100];

    while(1){
        printf("Telefonando....\n");

        if(perguntar("Alguem em casa? s/n") == 's')
            return;

        printf("Deixe seu recado:\n");
        scanf("%99s", &buffer);
        system("clear");
        printf("Deixando recado.....\n");
    }
}

void chamarSair(){
    
    if(perguntar("Perguntar...gostaria de sair para jantar? s/n") == 's')
        viramosAmigos("Pagar a conta....\n");

    char *bebida;

    if(perguntar("Perguntar...gostaria de sair para beber? s/n") == 's'){

        switch (perguntar(" 1. Cha\n 2. Cafe\n 3. Chocolate\n"))
        {
        case '1':
            bebida = "Cha";
            break;
        
        case '2':
            bebida = "Cafe";
            break;

        case '3':
            bebida = "Chocolate";
            break;
        }

    printf("Tomar %s \n", bebida);
    viramosAmigos("");
    }
}

void viramosAmigos(char *declaracao){
    printf("%s", declaracao);
    printf("Viramos amigos!\n\n\n");
    exit(0);
}

void descobrirInteresse(){

    int quantidadePerguntas = 1;
    char interesse[100];
    char pergunta[100];
    
    while(quantidadePerguntas <= 3){
        printf("%s", "Conte-me um de seus interesses!\n");
        scanf("%99s", &interesse);
        sprintf(pergunta, "O interesse eh: %s\nCompartilho deste interesse? s/n", interesse);
        if(perguntar(pergunta) == 's'){
            viramosAmigos("Por que nao fazemos aquilo juntos?\n");
        }
        printf("Nao compartilho este interesse.....\n");
        quantidadePerguntas++;
    }

    viramosAmigos("Convidar para fazer a opcao menos incomoda para mim...\n");

}