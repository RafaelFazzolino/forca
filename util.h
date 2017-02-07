#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*Universidade de Brasilia
Instituto de Ciencias Exatas
Departamento de Ciencia da Computacao
Algoritmos e Programação de Computadores – 0/2017
Aluno(a): Rafael Fazzolino Pinto Barbosa
Matricula: 11/0136942
Turma: VERAO
Versão do compilador: 4.8.4
Descricao: Neste arquivo se encontram algumas funções úteis para desenvolvimento do jogo, principalmente funções
que estão substituindo as encontradas na biblioteca string.h
*/


	char * string_alvo;/*variável onde será guardada a plavra lida no arquivo*/
	char * string_decifrada;/*String que será manipulada com as letras do usuário*/
	char alfabeto[26];/*todas as possibilidades de letras.. será alterado sempre que uma letra for utilizada*/
	int pontuacao_total=0, parte_corpo=0;
	char forca[23][31];


void limpa_forca(){
	int i, j;
	for(i=0 ; i<23 ; i++){
		for(j=0 ; j<30 ; j++){
			forca[i][j] = ' ';
		}
	}
}

void inicia_forca(){
	int i, j;
	for(i=0 ; i<23 ; i++){
		for(j=0 ; j<30 ; j++){
			forca[i][j] = ' ';
		}
	}
	for(i=0 ; i<23 ; i++){
		forca[i][30] = '\0';
	}
	forca[1][1] = '+';
	for(i=2 ; i<20 ; i++){
		forca[1][i] = '-';
	}
	forca[1][20] = '+';
	forca[1][21] = ' ';
	forca[1][22] = ' ';

	for(i=2 ; i<=18 ; i++){
		forca[i][4] = '|';
	}

	for(i=3 ; i<6 ; i++){
		forca[19][i] = '+';
	}
	for(i=2 ; i<7 ; i++){
		forca[20][i] = '+';
	}
	for(i=1 ; i<8 ; i++){
		forca[21][i] = '+';
	}
	
}

void cria_forca(int num){
	int i,j;

	switch(num){
		case 1:/*Cabeça*/
			for(i=23 ; i<=25 ; i++){
				forca[5][i] = '_';
			}

			forca[6][22] = '/';
			forca[6][26] = '\\';
			forca[7][22] = '\\';
			forca[7][26] = '/';
			forca[7][23] = '_';
			forca[7][24] = ' ';
			forca[7][25] = '_';			
			break;
		case 2:/*Tronco*/
			forca[8][24] = '|';
			forca[9][24] = '+';
			for(i=10 ; i<=12 ; i++){
				forca[i][24] = '|';
			}
			forca[9][25] = '-';
			forca[9][23] = '-';
			break;
		case 3:
			//braco direito
			forca[10][26] = '\\';
			forca[11][27] = '\\';
			forca[12][28] = '\\';
			break;
		case 4:
			//braco esquerdo
			forca[10][22] = '/';
			forca[11][21] = '/';
			forca[12][20] = '/';
			break;
		case 5:
			//Perna direita
			forca[13][25] = '\\';
			forca[14][26] = '\\';
			forca[15][27] = '\\';
			forca[16][28] = '\\';
			break;
		case 6:
			//perna esquerda
			forca[13][23] = '/';
			forca[14][22] = '/';
			forca[15][21] = '/';
			forca[16][20] = '/';
			break;
	}
}

void forca_fim(){
	forca[2][23] = '|';
	forca[3][23] = '|';
	forca[4][23] = '+';
	forca[4][22] = '_';
	forca[4][21] = '_';
	forca[5][20] = '/';
	forca[6][19] = '/';
	forca[7][19] = '\\';
	forca[8][20] = '-';
	forca[8][21] = '-';
	forca[8][22] = '-';
	forca[8][24] = '-';
	forca[8][25] = '-';
	forca[8][26] = '-';
}



void imprime_forca(){
	int i, j;
	for(i=0 ; i<23 ; i++){
		for(j=0 ; j<31 ; j++){
			if(forca[i][j] == '\0'){
				printf("%c\n", forca[i][j]);
			}else{
				printf("%c", forca[i][j]);
			}
		}
	}
}

/*Função que imprime as opções do usuário, recebendo a opção desejada*/
int menu(){
	int opcao;
	printf("------------------------ MENU ----------------------------\n");
	printf("Digite a opcao desejada:\n");
	printf("1-Jogar\n");
	printf("2-Sair\n");
	scanf("%d", &opcao);
	return opcao;
}

/*Função semelhante a função strcmp, comparando duas strings*/
int compara_string(){
	int i=0, igual = 0;//se for igual, é zero
	while(string_alvo[i] != '\0'){/*Vai ate o fim da string comparando item por item */
		if(string_alvo[i] != string_decifrada[i]){
			igual = 1;
		}
		i++;
	}
	return igual;
}

/*Função semelhante a função strlen, contando o tamanho da string*/
int size(char *string){
	int i=0;
	while(string[i] != '\0'){/*Vai até o fim da mesma incrementando um contador*/
		i++;
	}
	return i;
}

/*Transforma a string em '_', de acordo com o tamanho da string alvo*/
void decifra_string(){
	int i;
	for	(i=0 ; i<size(string_alvo) ; i++){
		string_decifrada[i] = '_';
	}
}

/*Verifica se letra existe na palavra alvo*/
int verifica_letra(char letra){
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

/*Função que cuida das atualizações do alfabeto.. caso a mesma receba um caractere '.', o alfabeto será criado*/
int gerencia_alfabeto(char letra){
	int j, achou=0;
	if(letra == '.'){
		for(j=0 ; j<=25 ; j++){
			alfabeto[j] = 65+j; /*65 é a posição do A na tabela ascII, desse modo, incrementando i ao 65, 26 vezes, obtenho
			todo o alfabeto*/
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