#include <stdio.h>

int main() {

//movimento da torre 5 casas  para  direita
printf("Movimento da torre \n");
for(int i = 1; i <= 5; i++){
printf("direita \n");

}
// Movimento do bispo 5 casas para cima e a direita
printf("Movimento do bispo \n");

int bispo = 1;

while (bispo <=5){
printf("Cima,direita \n");
bispo++;

}
//Movimento da rainha 8 casas para esquerda
printf("Movimento da rainha \n");

int rainha = 1;

do{
printf("esquerda \n");
rainha++;

}while(rainha <= 8);















    return 0;
}