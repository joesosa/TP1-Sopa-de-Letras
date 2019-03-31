#include<fstream>
#include<iostream>
#include "Generador.h"
#define _MAX_BUFFER_SIZE 30
using namespace std;
// PARA PROBAR ESTE PROGRAMA
// Ejecute en consola
// g++ -o programa Main.cpp
// programa Main.cpp MainConNumerosDeLinea.txt
int main(int argc, char * * argv){
   int filas,columnas,cantPalabras;
   
   if(argc >= 3){ 
        ifstream entrada(argv[0]);
	      filas = atoi(argv[1]);
	      columnas = atoi(argv[2]);
        ofstream salida(argv[3]);
        char ** palabra;
        entrada>>cantPalabras;
        palabra = new char * [cantPalabras];
        Generador pal(filas,columnas);
        for(int i =0;i<cantPalabras;++i){
            entrada >> palabra[i];
            pal.guardoPalabra(palabra[i],cantPalabras++);
         }
   } 

   // f c
   // a b c d
   // f e t a


   return 0;
}
