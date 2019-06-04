#ifndef EL_ARBOL
#define EL_ARBOL
#define HIJOS 2
#define IZQ 0
#define DER 1
#include<iostream>
#include "Pila.h"
using namespace std;
template< class T >
class Arbol {

    friend ostream& operator<<(ostream & salida, Arbol& arbol){
      if(arbol.raiz){
	     arbol.raiz->imprimir(salida);
	  }
	  return salida;
    }
   
    class Nodo {
      private:
	     T valor;
         Nodo * hijo[HIJOS];		 
      public:
	     Nodo(T valor){
		    this->valor = valor;
		    hijo[IZQ]=0;
			hijo[DER]=0;
		 }
		 ~Nodo(){
		    if(hijo[IZQ]){
			   delete hijo[IZQ];			   
			}
			if(hijo[DER]){
			   delete hijo[DER];			   
			}
		 }
		 void insertar(T valor){
		    if(this->valor!=valor){
			   int lado = (valor < this->valor)? IZQ : DER;
			   if(hijo[lado]){
			      hijo[lado]->insertar(valor);
			   }
			   else {
			      hijo[lado] = new Nodo(valor);
			   }
			}
		 }
		 ostream& imprimir(ostream& salida){
		    if(hijo[IZQ]){
			   hijo[IZQ]->imprimir(salida);
			}
			salida << valor << " ";
			if(hijo[DER]){
			   hijo[DER]->imprimir(salida);			
			}
		 }
    };
   
    private:
       Nodo * raiz;
	   
	public:
		 class Iterador {
		 friend class Lista; // Para solo la lista pueda acceder a los campos de la celda mediante el puntero actual
	     private:
		    Celda * actual;
	     public:
            Iterador();
            Iterador(Celda *);
            Iterador & operator++();
            Iterador operator++(int);
            int operator==(const Iterador &);
            int operator!=(const Iterador &);
	         int * & operator*();
	  };

	   Arbol(){
		   raiz=0;
	   }
	   ~Arbol(){
		   if(raiz){
			   delete raiz;
		   }
	   }	   
	   void insertar(T valor){
		   if(raiz){
			   raiz->insertar(valor);
		   }
		   else {
			   raiz = new Nodo(valor);
		   }
	   }
		Iterador begin(){
			Nodo *actual = raiz;
			while(actual->hijo[IZQ]){
				actual = actual->hijo[IZQ];
			}
			Iterador inicio(actual);
			return inicio;
		}
		Iterador end(){
			Nodo *actual = raiz;
			while(actual->hijo[DER]){
				actual = actual->hijo[DER];
			}
			Iterador final(actual);
			return final;
		}

};


#endif
