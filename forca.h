#include "util.h"


void play(){
	FILE *fp;
	char * string_alvo;
	char * string_decifrada;
	int i, j, continua = 0, perdeu =0;
	char alfabeto[26];
	char chute;
	int achou=0;
	string_alvo = malloc(sizeof(char*));
	string_decifrada = malloc(sizeof(char*));

	fp = fopen("palavras.txt", "r");
	if(fp){
		while((fscanf(fp, "%s", string_alvo) != EOF) && (continua == 0) && (perdeu == 0)){
			
			for	(i=0 ; i<strlen(string_alvo) ; i++){
				string_decifrada[i] = '_';
			}

			for(j=0 ; j<=25 ; j++){
				alfabeto[j] = 65+j;
			}

			for(i=0 ; i<6 ; i++){
				printf("1-cabeça, 2-tronco, 3-braço direito, 4-braço esquerdo\n5-perna direita e 6-perna esquerda\n\n\n");

				if(i>0){//Printando as partes já desenhadas
					for(j=1 ; j<=i ; j++){
						printf("%d ", j);
					}
				}

				printf("A palavra eh: %s\n", string_decifrada);

				printf("Voce tem %d tentativas! Escolha uma das seguintes letras:\n", 6-i);

				printf("------------------------------------------------------\n");
				for(j=0 ; j<=25 ; j++){
					printf("%c ", alfabeto[j]);
				}
				printf("\n------------------------------------------------------\n");

				scanf(" %c", &chute);
				achou = 0;

				for(j=0 ; j<26 ; j++){
					if(alfabeto[j] == chute){
						printf("Letra ja utilizada!\n");
						achou = 1;
					}
				}
				if(achou == 1){
					//nothing to do.
				}else{
					alfabeto[strlen(alfabeto)] = chute;
				}

				printf("%s\n", string_decifrada);	

				for(i=0; i<strlen(string_alvo) ; i++){
					if(tolower(string_alvo[i]) == tolower(chute)){
						string_decifrada[i] = toupper(chute);
					}
				}
			}
			printf("PARABENS!!!!\n");
			printf("%s\n", string_alvo);
			printf("%s\n", string_decifrada);
			printf("------------------------------\n");		
		}
	}

}