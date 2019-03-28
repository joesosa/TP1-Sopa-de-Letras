#include "Matriz.h"
#include<iostream>
using namespace std;

void Matriz::_init(int filas,int columnas){ 
   this->filas =0;
   this->columnas=0;
   this->m = 0; // puntero es null
   if(filas > 0 && columnas > 0){
	   this->filas = filas;
       this->columnas = columnas;
       this->m = new char * [filas];
       for( int f= 0; f < filas ; ++f){
		   this->m[f]= new char [columnas];
		   for(int c= 0; c < columnas; ++c){
			   this->m[f][c]='_';
		   }
	   }
   } 
}
 
Matriz::Matriz(){
   cout << "Matriz vacia creada"<< endl;

   _init(0,0);
}
Matriz::Matriz(int filas,int columnas){
   cout << "Matriz de "<< filas<< " x "<< columnas << " creada"<<endl;	
   _init(filas,columnas);
}

Matriz::Matriz(const Matriz & otra){
   cout << "Matriz por copia "<< otra.filas<< " x "<< otra.columnas << " creada"<<endl;	
   //liberarMemoria();
   _init(otra.filas,otra.columnas);// Pide memoria y rellena de blancos
   for(int f=0; f< otra.filas; ++f){
	   for(int c=0; c < otra.columnas; ++c){
		  cout << "copiando letra "<< otra.m[f][c]<< endl;
		  this->m[f][c] = otra.m[f][c]; 
	   }
   }
}

void Matriz::asignar(const Matriz & otra){
   cout << "Se asigna una matriz a otra "<< otra.filas<< " x "<< otra.columnas << " creada"<<endl;	
   liberarMemoria();
   _init(otra.filas,otra.columnas);// Pide memoria y rellena de blancos
   for(int f=0; f< otra.filas; ++f){
	   for(int c=0; c < otra.columnas; ++c){
		  cout << "copiando letra "<< otra.m[f][c]<< endl;
		  this->m[f][c] = otra.m[f][c]; 
	   }
   }	
	
}

Matriz::~Matriz(){
   cout << "Se destruye la Matriz de "<< filas<< " x "<< columnas << endl;
   liberarMemoria(); 
}
void Matriz::liberarMemoria(){   
   if(m){
      for(int f= filas-1; f >=0 ; --f){
	     delete [] m[f]; 
      }	
      delete [] m;
	  m = 0;
	  filas = 0;
	  columnas =0;
   }
}
int Matriz::getFilas(){
	return filas;
}
int Matriz::getColumnas(){
	return columnas;
}

int Matriz::esPosicionValida(int fila,int columna){
	return (fila>=0 && fila < filas && columna >=0 && columna < columnas);
}

void Matriz::setValor(int fila,int columna,char valor){
	if(esPosicionValida(fila,columna)){
		m[fila][columna] = valor;
	}	
} // fila columna char
char Matriz::getValor(int fila,int columna){
   char valor = '\0';
   if(esPosicionValida(fila,columna)){
	   valor = m[fila][columna];
   }
   return valor;
}
void Matriz::imprimir( ostream & salida){
	  salida << filas << " "<<columnas<< endl << endl;
      for( int f= 0; f < filas ; ++f){
		   for(int c= 0; c < columnas; ++c){
			   salida << " "<< m[f][c];
		   }
		   salida << endl;
	  }	
}
