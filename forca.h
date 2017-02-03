#include "util.h"

void decifra_string(char * string, char *string_alvo){
	int i;
	for	(i=0 ; i<strlen(string_alvo) ; i++){
		string[i] = '_';
	}
}

void verifica_letra(char letra, char * string_alvo, char * string_decifrada){
	int i;
	for(i=0; i<strlen(string_alvo) ; i++){
		if(tolower(string_alvo[i]) == tolower(letra)){
			string_decifrada[i] = toupper(letra);
		}
	}	
}

int gerencia_alfabeto(char letra, char *alfabeto){
	int j, achou=0;
	if(letra == '.'){
		for(j=0 ; j<=25 ; j++){
			alfabeto[j] = 65+j;
		}
	}else{
		for(j=0 ; j<=25 ; j++){
			if(letra == alfabeto[j]){
				alfabeto[j] = ' ';
				achou = 1;
			}
		}
		if(achou == 0){
			printf("Letra ja utilizada, tente novamente!\n");
		}
	}
	return achou;//se retornar zero, é pq a letra já foi utilizada anteriormente.
}

void play(){
	FILE *fp;
	char * string_alvo;
	char * string_decifrada;
	int i, j, perdeu =0;
	char alfabeto[26];
	char chute, continua = 'S';
	int achou=0, pontos;
	string_alvo = malloc(sizeof(char*));
	string_decifrada = malloc(sizeof(char*));

	fp = fopen("palavras.txt", "r");
	if(fp){
		while((fscanf(fp, "%s", string_alvo) != EOF) && (toupper(continua) == 'S') && (perdeu == 0)){
			fscanf(fp,"%d",&pontos);
			decifra_string(string_decifrada, string_alvo);

			gerencia_alfabeto('.', alfabeto);

			for(i=0 ; i<6 ; i++){
				printf("\e[H\e[2J");
				printf("1-cabeça, 2-tronco, 3-braço direito, 4-braço esquerdo\n5-perna direita e 6-perna esquerda\n");
				if(i>0){//Printando as partes já desenhadas
					printf("Chances já executadas:");
					for(j=1 ; j<=i ; j++){
						printf("%d ", j);
					}
				}

				printf("\nA palavra eh: %s\n", string_decifrada);

				printf("Voce tem %d tentativas! Escolha uma das seguintes letras:\n", 6-i);

				printf("------------------------------------------------------\n");
				for(j=0 ; j<=25 ; j++){
					printf("%c ", alfabeto[j]);
				}
				printf("\n------------------------------------------------------\n");
				do{
				scanf(" %c", &chute);

				achou = gerencia_alfabeto(toupper(chute), alfabeto);
					
				}while(achou == 0);

				verifica_letra(chute, string_alvo, string_decifrada);
				if(strcmp(string_decifrada, string_alvo) == 0){
					printf("\e[H\e[2J");
					printf("\n------------------------------------------------------\n");
					printf("PARABENS! Voce decifrou a palavra!\nA palavra e: %s\n", string_decifrada);
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
		}
	}

}