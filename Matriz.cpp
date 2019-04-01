#include "Matriz.h"
#include<iostream>

using namespace std;

void Matriz::_init(int filas,int columnas, char relleno){
   this->filas = 0;
   this->columnas = 0;
   this->m = 0; // apunta a nulo
   if(filas>0 && columnas>0){
      cout << "Inicializar "<< filas << " x "<< columnas << endl;	   
	  this->filas = filas;
      this->columnas = columnas;	  
	  m = new char * [filas];
      for(int f=0; f< filas; ++f){
		m[f] = new char [columnas];
        for(int c=0; c<columnas; ++c){
			m[f][c] = relleno;
		}		
	  }	  
   }   
}
void Matriz::_liberar(){ 
   if(m){
	  cout << "Liberar "<< filas << " x "<< columnas << endl; 
	  for(int f=filas-1; f >=0; --f){
		  delete [] m[f];
	  }   
	  delete [] m; 
   }
}
Matriz::Matriz(){ 
  cout << "Constructor por omision"<< endl;
  _init(0,0,RELLENO);
}
Matriz::Matriz(int filas, int columnas){ 
  cout << "Constructor "<< filas << " "<< columnas << endl;
  _init(filas,columnas,RELLENO);
}


Matriz::Matriz(const Matriz & otra){
   _init(otra.filas,otra.columnas,RELLENO);
   for(int f=0; f< filas; ++f){
	   for(int c=0; c<columnas; ++c){
			m[f][c] = otra.m[f][c];
      }		
   }	  
}
void Matriz::asignar(const Matriz & otra){
	if(m){
		_liberar();
	}	
	Matriz victima(otra);
	this->filas = victima.filas;
	this->columnas = victima.columnas;
	this->m= victima.m;
	victima.m = 0;
		
}


Matriz::~Matriz(){ 
  cout << "Destructor matriz "<< filas << " x "<< columnas << endl;
  _liberar();
}
int Matriz::esPosicionValida(int fila,int columna){
   return fila >=0 && fila < filas && columna >=0 && columna < columnas;	
}

int Matriz::posicionVacia(int fila,int columna){
   return esPosicionValida(fila, columna) && m[fila][columna] == RELLENO ;	
}
void Matriz::setValor(int fila,int columna,char valor){
   if(esPosicionValida(fila,columna)){
	   m[fila][columna]=valor;
   }	
}
char Matriz::getValor(int fila,int columna){
   char valor = '\0';
   if(esPosicionValida(fila,columna)){
	   valor = m[fila][columna];
   }
   return valor;   
}

void Matriz::quitarValor(int fila,int columna){
   if(esPosicionValida(fila,columna)){
	   m[fila][columna] = RELLENO;
   }  
}

void Matriz::imprimir( ostream & salida){
   salida << filas << " " << columnas << endl;
   for(int f=0; f< filas; ++f){
	 for(int c=0; c<columnas; ++c){
	   salida << " "<<m[f][c];
	 }		
	 salida << endl;
   }	      
}

void Matriz::rellenoSopa(){
   int n = 0;  
   for(int f=0; f< filas; ++f){
	   for(int c=0; c<columnas; ++c){
			n = 1 + rand() % 26;
         m[f][c] = letraAleatoria(n);
      }		
   }	  
}

char Matriz::letraAleatoria(int n){
    char devuelvo = '\0';
    switch (n)
    {
        case 1: devuelvo = 'a';
            break;
        case 2: devuelvo = 'b';
            break;
        case 3: devuelvo = 'c';
            break;
        case 4: devuelvo = 'd';
            break;
        case 5: devuelvo = 'e';
            break;
        case 6: devuelvo = 'f';
            break;
        case 7: devuelvo = 'g';
            break;
        case 8: devuelvo = 'h';
            break;
        case 9: devuelvo = 'i';
            break;
        case 10: devuelvo = 'j';
            break;
        case 11: devuelvo = 'k';
            break;
        case 12: devuelvo = 'l';
            break;
        case 13: devuelvo = 'm';
            break;
        case 14: devuelvo = 'n';
            break;
        case 15: devuelvo = 'o';
            break;
        case 16: devuelvo = 'p';
            break;
        case 17: devuelvo = 'q';
            break;
        case 18: devuelvo = 'r';
            break;
        case 19: devuelvo = 's';
            break;
        case 20: devuelvo = 't';
            break;
        case 21: devuelvo = 'u';
            break;
        case 22: devuelvo = 'v';
            break;
        case 23: devuelvo = 'w';
            break;
        case 24: devuelvo = 'x';
            break;
        case 25: devuelvo = 'y';
            break;
        case 26: devuelvo = 'z';
            break;
        default:
            break;
    }
    return devuelvo;
}
