#include <stdio.h>
#include <stdlib.h>
#include "algebra.h"
#include<string.h>
#include <windows.h>
#include <locale.h>


Mat *criaMat()
{
 Mat *m = (Mat*) malloc(sizeof(Mat));
 int x,y;
 printf("Digite o nome:  ");
 scanf("%s",m->nome);
 printf("Digite a quantidade de linhas: ");
 scanf("%d",&m->l);
 printf("Digite a quantidade de colunas: ");
 scanf("%d",&m->c);
 m->M = (int**)malloc(sizeof(int*)* m->l);
 for( x=0; x< m->l; x++)
  m->M[x] = (int*)malloc(sizeof(int)* m->c);
 for( x=0; x<m->l; x++)
 {
  for( y=0; y<m->c; y++)
  {
   m->M[x][y]=0;
  }
 }
 return m;
}

Mat *criaMat2(int l, int c, char *nome)
{
 int x,y;
 Mat *m = (Mat*) malloc(sizeof(Mat));
 m->l=l;
 m->c=c;
 strcpy(m->nome,nome);
 
 m->M = (int**)malloc(sizeof(int*)*l);
 for( x=0; x<l; x++)
  m->M[x] = (int*)malloc(sizeof(int)*c);
 for( x=0; x<l; x++)
 {
  for( y=0; y<c; y++)
  {
   m->M[x][y]=0;
  }
 }
 return m;
}

void showMat(Mat *M)
{
 int x, y;
 printf("Matriz: %s\n",M->nome);
 for( x=0; x<M->l; x++)
 {
        printf("| ");
  for( y=0; y<M->c; y++)
	{
		printf("%d ",M->M[x][y]);
	}
        printf("|\n");
 } 
}

//==============================Função responsavel por Carregar as Matrizes==================================
void carregaM(Mat *A)
{
	int i, j;
	
	for (i=0; i<A->l; i++)
	{
		for ( j=0; j<A->c; j++)
		{
			printf("Elemento Mat [%d] [%d]: ", i, j);
			scanf("%d", &A->M[i][j]);
		}
	}
}
 
 //=============================Função responsavel por Somar as Matrizes====================================
Mat *somaMat(Mat *A, Mat *B)
{
	int x, y;
	Mat *ops;
	
	ops=criaMat2(A ->l, A -> c, "SOMA");
	
	for(x=0; x<A->l; x++)
	{
		for (y=0; y<B->c; y++ )
		{
			ops ->M[x] [y] = A->M[x][y] + B->M[x][y];
			printf("\n");
		}
	}
		
		return ops;
}

//==============================Função Responsavel Por Somar as Matrizes===================================
Mat *multMat(Mat *A, Mat *B)
{
	int k1, k2, p;
	Mat *temp;
	
	temp=criaMat2(A ->l, A ->c, "PRODUTO");
	
	for (k1=0; k1<A->l; k1++)
	{
		for (k2=0; k2<A ->c; k2++)
		{
			temp ->M[k1][k2]=0;
			
			for (p=0; p<A ->c; p++)
			{
				temp ->M[k1][k2] = temp ->M[k1][k2] +   A->M[k1][p] * B->M[p][k2];
				printf("\n");
			}
				
		}
	}
	return temp;
}

//=============================Função Responsavel Por Calcular a Matriz Transposta========================
Mat *TranspMat (Mat *A ) {
  int i, j, aux;
  
  for (i = 0; i < A->l; i++) {
    for (j = i+1; j <A-> c; j++) {
      if (j != i) {
   aux = A->M[i][j];
   A->M[i][j] = A->M[j][i];
   A->M[j][i] = aux;
      }
    }
  }
  return A;
} 
//================================ Função Responsavel por Liberar o Espaço na memória


void escreverArquivo(int m)
{
	int x,y;

	for( x=0; x<listaMats[m]->l; x++)
	{

		printf("| ");
		for( y=0; y<listaMats[m]->c; y++)
		{

			FILE *file15;
			file15 = fopen(".\\arquivo txt\\Listas\\Carros.txt", "ab+");
			fprintf(file15,"%d\n%s\n%d X %d\n%d ",m,listaMats[m]->uso,listaMats[m]->l,listaMats[m]->c,listaMats[m]->M[x][y]);
			fclose(file15);
		}

		printf("|\n");
	}
}

void zerarlista()
{
	int x;
	for(x=0;x<15;x++)
	{
		// aqui vc está inserindo um dado na posição x
		listaMats[x]=NULL;

	}

}


void removeMatList(int pos){

	if(pos<15&&listaMats[pos]!=NULL)
	{

		liberaMat(listaMats[pos]);
		listaMats[pos]=NULL;
	}
}

void insereMatList(Mat *M)
{
	int x;
	for(x=0;x<15;x++)
	{
		// aqui vc está inserindo um dado na posição x
		if(listaMats[x]==NULL)
		{

			listaMats[x]=M;
			auxiliar++;
			return;
		}

	}
	printf("Lista cheia, para inserir nessesario remover.");
}

void listaMat()
{
	int x;
	for(x=0;x<15;x++)
	{
	 // aqui vc está exibindo as matrizes que estão na listaMat
	 // acha que esse era a sua dúvida, como acessar as matrizes a partir da lista né
	 // se vc quise acessar os dados basta: listaMats[x]->
     // Beleza?
	 if(listaMat[x]!=NULL){

		printf(" %d : %s  %d X %d \n",x,listaMat[x]->uso,listaMat[x]->l,listaMat[x]->c);
	 }
	 }

	printf("\n");
}
void lerArquivo()
{

FILE *file12;

	 char arquivo[1000];

     file12 = fopen (".\\MatZ.txt", "r");
     if(file12 == NULL){
         printf("\n\n\n    Nao foi possivel abrir o arquivo. \n");
         getch();
         }
     while(fgets(arquivo, 1000, file12) !=NULL){
         printf("    %s", arquivo);
         }
     fclose(file12);
}
void liberaMat(Mat *M)
{
	int x;
	for(x=0;x<M->l;x++)
		free(M->M[x]);

	free(M);
}
//============================== Função Responsavel por ler os Arquinos TXT.
Mat *lerArq(char *nome)
{

	FILE *ler;
	ler=fopen(nome,"r");
	if(ler==NULL){
		fprintf(ler,"Arquino nao encontrado.");
		}


}
//=========================== Função Responsavel por Calcular a Determinante
int detMat(Mat* M)
{
	int det=0,i;
	if(M->l==M->c)
	{
		if(M->l==2&&M->c==2){
			
			return (M->M[0][0]*M->M[1][1]) - (M->M[0][1]*M->M[1][0]);
			}

		else if(M->l==1&&M->c==1){

			return M->M[0][0];
			}

		for(i=0;i<M->c;i++){

			
			showMat(laplace(M,0,i));
			det +=(detMat(laplace(M,0,i)))*M->M[0][i]*(auxcM(i,-1));
			}

		return (det);
	}
	printf("\n\nMatriz invalida.");
	return -1;
}

int auxcM(int j, int i)
{
	int aux=1,k;
	if(j>0){

		for(k=0;k<j;k++){
			aux*=i;
			}
		}
	else if(j=0){
		aux=1;
	}
	else if(j<0){
		for(k=0;k>j;k--){
			aux*=1/i;
		}
	}
	return aux;
}
//=================================== Função Usando o Método de Laplace
Mat *laplace(Mat *M, int x, int y){

	Mat *aux;
	char nome[30];
	int k=0,f=0,i,j;
	static int cont=0;
	sprintf(nome,"Reduzida%d",cont++);
	aux = criaMat2(M->l-1,M->c-1,"Reduzida");//(aux->M,((M->l) -1),((M->c) -1));
	for(i=0;i<M->l;i++){

		for(j=0;j<M->c;j++){

			if(i==x){

				i++;
				if(i==M->l){
					break;
					}
				}
			if(j==y){

				j++;
				if(j==M->c){
					break;
					}
				}
			aux->M[k][f] = M->M[i][j];
			f++;
			}

		f=0;
		k++;
		}

	return aux;
	}

