#include<fstream>
#include<iostream>
#include<stdlib.h>
#include "Matriz.h"
using namespace std;
// PARA PROBAR ESTE PROGRAMA
// Ejecute en consola
// g++ -o programa Main.cpp
// programa Main.cpp MainConNumerosDeLinea.txt
int main(int argc, char * * argv){
	int filas,columnas;
   cout << "Cantidad de parametros: " << argc << endl;
   for(int i=0; i< argc; ++i){
	   cout << "Parametro "<< i << ": "<< argv[i]<< endl; 
	    filas = atoi(argv[1]);
	   columnas = atoi(argv[2]);
	   
   } 
   cout<<"Las filas son "<<filas<<"y las colunmas "<<columnas<<endl;
   if(argc >= 3){
     ifstream entrada(argv[1]);
     ofstream salida(argv[2]);
     int i= 0;
     char buffer[100];
	 while(!entrada.eof()){
       entrada.getline(buffer,100);
       salida << ++i << " "<< buffer << endl;
	 } 
   }
   Matriz m(filas,columnas);
   //ejecute(m)
   
   //ejecuta(filas,columnas);
   //archivo de salida
   // f c
   // a b c d
   // f e t a
   
   m.imprimir(cout);
	  
   return 0;
}
