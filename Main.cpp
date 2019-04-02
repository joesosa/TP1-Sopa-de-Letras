#include<fstream>
#include<iostream>
#include "Generador.h"
using namespace std;

// g++ -o programa Main.cpp

int main(int argc, char * * argv){
   
   int filas,columnas,cantPalabras;
   if(argc > 4){ 
        ifstream entrada(argv[1]); //la entrada
	     filas = atoi(argv[2]);
	     columnas = atoi(argv[3]);
        ofstream salida(argv[4]); //la salida
        char ** palabra;
        entrada>>cantPalabras;
        salida << filas << " " << columnas << endl;
        palabra = new char * [cantPalabras]; //se crea un vector de punteros a char
        Generador pal(filas,columnas,cantPalabras);
        
       // for(int i =0;i<cantPalabras;++i){ //almacena los punteros a char en el vector de palabras
          //  entrada >> palabra[i];
           // pal.guardoPalabra(palabra[i],i);
         //}
         
         //salida << filas << "\0" << columnas << endl; //saca en el archico las filas y las columnas
        
         for(int f = 0; f < filas;++f){
            for(int c = 0; c < columnas; ++c){
               salida << pal.getValor(f,c)<<"\0";
            }
            salida<<endl;
         }
   } 
   else if(argc == 4){
        ifstream entrada(argv[0]);
	     filas = atoi(argv[1]);
	     columnas = atoi(argv[2]);
        char ** palabra;
        entrada>>cantPalabras;
        palabra = new char * [cantPalabras];
        Generador pal(filas,columnas,cantPalabras);
        
        /*for(int i =0;i<cantPalabras;++i){
            entrada >> palabra[i];
            pal.guardoPalabra(palabra[i],i);
         }*/

         cout<<filas<<"\0"<<columnas<<endl;
        
         /*for(int f = 0; f < filas;++f){
            for(int c = 0; c < columnas; ++c){
               cout << pal.getValor(f,c)<<"\0";
            }
            cout<<endl;
         }*/
   }
   else{
      cout<<"No se pasaron los suficientes parametros"<<endl;
   }

   return 0;
}
