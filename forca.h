#include "util.h"



void play(){
	FILE *fp;
	char * string_alvo;
	char * string_decifrada;
	int i, j, perdeu =0;
	char alfabeto[26];
	char chute, continua = 'S';
	int achou=0, pontuacao, pontuacao_total=0, letra_correta=0;
	string_alvo = malloc(sizeof(char*));
	string_decifrada = malloc(sizeof(char*));

	fp = fopen("palavras.txt", "r");
	if(fp){
		while((fscanf(fp, "%s", string_alvo) != EOF) && (toupper(continua) == 'S') && (perdeu == 0)){
			printf("*** JOGO DA FORCA ***");
			fscanf(fp,"%d",&pontuacao);
			decifra_string(string_decifrada, string_alvo);

			gerencia_alfabeto('.', alfabeto);
			i=0;
			while(i<6){
				printf("\e[H\e[2J");
				printf("PONTUACAO ACUMULADA = %d\n", pontuacao_total);
				printf("PONTUACAO DESTA PALAVRA = %d\n", pontuacao);
				printf("1-cabeça, 2-tronco, 3-braço direito, 4-braço esquerdo\n5-perna direita e 6-perna esquerda\n");
				if(i>0){//Printando as partes já desenhadas
					printf("Chances já executadas:");
					for(j=1 ; j<=i ; j++){
						printf("%d ", j);
					}
				}

				printf("\nA palavra eh: %s\n", string_decifrada);

				printf("------------------------------------------------------\n");
				for(j=0 ; j<=25 ; j++){
					printf("%c ", alfabeto[j]);
				}
				printf("\n------------------------------------------------------\n");
				do{
				scanf(" %c", &chute);

				achou = gerencia_alfabeto(toupper(chute), alfabeto);
					
				}while(achou == 0);

				letra_correta = verifica_letra(chute, string_alvo, string_decifrada);
				if(letra_correta == 0){
					printf("Letra incorreta, voce ainda tem %d chances!\n", 5-i);
					printf("Tecle enter para continuar..\n");
					i++;
					pontuacao = pontuacao - 5;
					getchar();
					getchar();
				}
				if(compara_string(string_alvo, string_decifrada) == 0){
					printf("\e[H\e[2J");
					pontuacao_total += pontuacao;
					printf("\n------------------------------------------------------\n");
					printf("PARABENS! Voce decifrou a palavra!\nA palavra e: %s\nVoce ganhou %d pontos!\n", string_decifrada, pontuacao);
					printf("Pontuacao total = %d\n", pontuacao_total);
					printf("\n------------------------------------------------------\n");
					break;
				}else{
					if(i == 5){
						printf("\e[H\e[2J");
						printf("\n------------------------------------------------------\n");
						printf("Infelizmente voce perdeu, boa sorte na próxima vez!\n");
						printf("\n------------------------------------------------------\n");
						perdeu = 1;
					}
				}
			}
			printf("\n\nDeseja continuar jogando?(S/N)");
			scanf(" %c", &continua);
			while(continua != 's' && continua != 'S' && continua != 'N' && continua !=  'n'){
				printf("Entrada invalida, tente novamente:");
				scanf(" %c", &continua);
			}	
		}
	}

}