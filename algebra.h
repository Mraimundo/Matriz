#ifndef ALGEBRA_H
#define ALGEBRA_H

#define TAM 9


//========================Criação da Biblioteca "define ALGEBRA_H" que será útil no calculo das matrizes======================== 
typedef struct mat{
	char nome[50];
	int l;
	int c;
	int *v;
	int **M;
}Mat;

Mat *criaMat();
Mat *criaMat2(int l, int c, char *nome);
Mat *somaMat(Mat *A, Mat *B);
Mat *multMat(Mat *A, Mat *B);
Mat *TranspMat(Mat *A);
Mat* lerArq(char *nome);
Mat *laplace(Mat *M,int x,int y);

void showMat(Mat *M);
void carregaM (Mat *A);
void liberaMat(Mat *M);
void lerArquivo(Mat*)
void escreverArquivo(int m);
void listaMat();
void removeMatList(int pos);
void insereMatList(Mat *M)

void zerarlista();
void listaMat();
void escluiListaMat(int pos);
void insereMatList();
void removeMatList();
void lerArquivo();
void escreverArquivo();

int detMat(Mat *Matrix);
int auxcM(int j, int i);

#endif