#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int menu(){
	int opcao;
	printf("------------------------ MENU ----------------------------\n");
	printf("Digite a opcao desejada:\n");
	printf("1-Jogar\n");
	printf("5-Sair\n");
	scanf("%d", &opcao);
	return opcao;
}

int compara_string(char *string1, char *string2){
	int i=0, igual = 0;//se for igual, é zero
	while(string1[i] != '\0'){
		if(string1[i] != string2[i]){
			igual = 1;
		}
		i++;
	}
	return igual;
}

int size(char *string){
	int i=0;
	while(string[i] != '\0'){
		i++;
	}
	return i;
}

void decifra_string(char * string, char *string_alvo){
	int i;
	for	(i=0 ; i<size(string_alvo) ; i++){
		string[i] = '_';
	}
}

int verifica_letra(char letra, char * string_alvo, char * string_decifrada){
	int i, achou = 0;
	for(i=0; i<size(string_alvo) ; i++){
		if(tolower(string_alvo[i]) == tolower(letra)){
			string_decifrada[i] = toupper(letra);
			achou = 1;
			printf("ACERTO!\n");
		}
	}	
	return achou;
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
			printf("Letra ja utilizada ou inexistente, tente novamente!\n");
		}
	}
	return achou;//se retornar zero, é pq a letra já foi utilizada anteriormente.
}