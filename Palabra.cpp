#include "Palabra.h"
#include <stdlib.h>

Palabra::Palabra(){
   length = 0;	
   palabra = new char [length+1];
   palabra[0]= '\0';
   posicion = 1 + rand() % 8;
}

Palabra::Palabra(char * hilera){ 
   if(hilera!=0){  //mientras haya al menos un char
      int cantidadDeLetras = 0;
      while(hilera[cantidadDeLetras++]!='\0'){      
      }
      palabra = new char [cantidadDeLetras];
      length = cantidadDeLetras-1;
      for(int i=0; i < cantidadDeLetras; ++i){
         if(hilera[i] >= 'A' && hilera[i] <= 'Z'){
		      palabra[i]= hilera[i] - 'A' + 'a';
         }
         else{
	        palabra[i]= hilera[i];
         }
      }
   }
 else{
      length = 0;	
      palabra = new char [length+1];
      palabra[0]= '\0'; 
   
   }
   posicion = 1 + rand() % 8;
}

Palabra::~Palabra(){
   if(palabra!=0){
      delete [] palabra;
   }
}


int Palabra::equals(Palabra& otra){
   int iguales = 0;
   if(length==otra.length){
	  iguales = 1;
      for(int i=0; iguales && i < length; ++i){
		  iguales = palabra[i]==otra.palabra[i];
	  }
   }
   return iguales;   
} // retorna 0 si son diferentes

char * Palabra::getHilera(){ 
  return palabra;
}

void Palabra::setHilera(char * hilera){ 
   Palabra temporal(hilera);
   palabra = temporal.palabra;
   temporal.palabra = 0; 
   //Para que el delete no me mate lo que me robe
   length = temporal.length;
}

int Palabra::getLength(){ 
   return length;
}

char Palabra::charAt(int pos){
  char letra = '\0';
  if(pos>=0 && pos<length){
	letra = palabra[pos];  
  }
  return letra;  
}

int Palabra::getPosicion(){
   return posicion;
}

int Palabra::nuevaPosicion(){
   return 1 + rand() % 8;
}
