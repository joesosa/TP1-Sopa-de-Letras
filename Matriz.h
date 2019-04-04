#ifndef MATRIZ_G02
#define MATRIZ_G02
#define RELLENO '_'
#include <stdlib.h>
#include<iostream>
#include "Palabra.h"
using namespace std;
class Matriz {
   private:
      int filas;
	  int columnas;
	  char **m;
	  int sumaF[8]={-1,-1,0,1,1,1,0,-1};
      int sumaC[8]={0,-1,-1,-1,0,1,1,1};
	  
	  void _init(int,int,char);
	  void _liberar();
   public:
      Matriz(); // Constructor por omision
	  Matriz(int,int); // Constructor con parametros
	  ~Matriz();
	  void asignar(const Matriz &);
	  void guardoPalabra(char * );
	  int esPosicionValida(int,int);
	  int posicionVacia(int,int); 
	  void quitarValor(int,int); 
      void setValor(int,int,char);
	  char getValor(int,int);
	  void imprimir( ostream & );
	  void rellenoSopa();
	  char letraAleatoria(int);
   	  void ponerPalabra(int, int, int, Palabra); 
      int verificar(int, int, int, Palabra); 
      void ponerLetras(int, int, int, Palabra);
};
#endif
