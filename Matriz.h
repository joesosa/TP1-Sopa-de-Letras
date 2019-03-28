#ifndef MATRIZ_
#define MATRIZ_
#include<iostream>
using namespace std;
class Matriz {
   private:
       char * * m;
	   int filas;
	   int columnas;
	   void _init(int,int); // pide memoria y rellana de '_'
	   void liberarMemoria();
   public:
	   Matriz();
	   Matriz(int,int);
	   Matriz(const Matriz &); // Constructor por copia
	   ~Matriz();
	   void asignar(const Matriz &);
	   int getFilas();
	   int getColumnas();
	   int esPosicionValida(int,int);
	   void setValor(int,int,char); // fila columna char
       char getValor(int,int);
	   void imprimir( ostream & );
};
#endif
