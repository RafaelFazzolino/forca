#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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