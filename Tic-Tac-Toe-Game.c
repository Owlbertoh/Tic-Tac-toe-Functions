#include <stdio.h>

char matrizprincesa[3][3];
int l, col, player = 1, ganhou = 0, opcao;
// Putting space in matrizprincesa
void starting(){
    for(l=0;l<3;l++){
        for(col=0;col<3;col++){
            matrizprincesa[l][col] = ' ';
        }
    }
}
// Imprimir o tabuleiro 
void showgame(){
    printf("Made by owlbertoh\n\n");
    printf("        0       1       2\n\n");
    for(l=0;l<3;l++){
        for(col=0;col<3;col++){
        printf("\t%c ", matrizprincesa[l][col]);
        if(col<2){
            printf("  |  ");
        }
        if(col==2){
            printf("     %d", l);
        }
        }
        printf("\n");
        if(l<2){
            printf("    -------------------------\n");
        }
    }
    printf("\n\n");
}
// Colocar o Caracter do player
void pochar(char x){
    l=0;
    col=0;
    printf("\tWrite the bearings: ");
    scanf("%d %d", &l, &col);
    opcao = valid(l, col);
        if(opcao == 0){
        do{
        printf("\tinvalid bearings! Write the bearings again: ");
        scanf("%d %d", &l, &col);
        opcao = valid(l, col);            
        }while(opcao == 0);
        }
    matrizprincesa[l][col] = x;
}
//Validar coordenada
int valid(int l, int col){
    if(l>=0 && l<=2 && col>=0 && col<=2 && matrizprincesa[l][col] == ' '){
        return 1;
    }
    else{
        return 0;
    }
}
//QUANTIDADE DE ESPAÇO EM BRANCO
int espaco(){
    int cont = 0;
    for(l=0;l<3;l++){
        for(col=0;col<3;col++){
            if(matrizprincesa[l][col] != ' '){
                cont++;
            }
        }
    }
    if(cont == 9){
        return 1;
    }
    else{
        return 0;
    }
}
// Checar se alguem ganhou
int vitoriaporlinha (int l, char x){
    if(matrizprincesa[l][0] == x && matrizprincesa[l][1] == x && matrizprincesa[l][2] == x){
        return 1;
    }
    else{
        return 0;
    }
}
int vitoriaporlinhas(char x){
    ganhou = 0;
    for(l=0;l<3;l++){
        ganhou += vitoriaporlinha(l, x);
    }
    return ganhou;
}
// Vitoria por coluna
 int vitoriaporcoluna(int col, char x){
    if(matrizprincesa[0][col] == x && matrizprincesa[1][col] == x && matrizprincesa[2][col] == x){
        return 1;
    }
    else{
        return 0;
    }        
}
int vitoriaporcolunas(char x){
    ganhou = 0;
    for(col=0;col<3;col++){
        ganhou += vitoriaporcoluna(col, x);
    }
    if(ganhou >= 1){
        return 1;
    }
    else{
        return 0;
    }
}
//Diagonal principal
int diagprinc(char x){
    if(matrizprincesa[0][0] == x && matrizprincesa[1][1] == x && matrizprincesa[2][2] == x){
        return 1;
    }
    else{
        return 0;
    }    
}
//Diagonal Secundaria
int diagsecun(char x){
    if(matrizprincesa[0][2] == x && matrizprincesa[1][1] == x && matrizprincesa[2][0] == x){
        return 1;
    }
    else{
        return 0;
    }    
}
//Jogar
void jogar(){
    int ganhou = 0;
    int cont = 0;
    do{
        showgame();
        if(player == 1){
            pochar('X');
            ganhou += vitoriaporlinhas('X');
            ganhou += vitoriaporcolunas('X');
            ganhou += diagprinc('X');
            ganhou += diagsecun('X');
            if(ganhou == 1){
                showgame();
                printf("\n\tPlayer 1 wins !!\n");
            }
                player = 0;
        }
        else{
            pochar('0');
            ganhou += vitoriaporlinhas('0');
            ganhou += vitoriaporcolunas('0');
            ganhou += diagprinc('0');
            ganhou += diagsecun('0');
            if(ganhou == 1){
                showgame();
                printf("\n\tPlayer 2 wins !!\n");
            }
            player = 1;                
        }
        cont = espaco();  
    }while(cont == 0 && ganhou == 0);
    if(cont == 1){
        showgame();
        printf("\n\n\tDeu velha!\n");
    }  
}
int main () {
    int pcao = 1 ;
    do{
    starting();
    jogar();
    printf("Game is over!!\n");
    printf("Do you want to play again ? press 1!\n");
    scanf("%d", &pcao);
    }while(pcao == 1);
    return 0;
}