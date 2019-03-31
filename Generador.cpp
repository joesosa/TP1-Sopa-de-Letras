#include "Generador.h"
#include "Matriz.h"
#include "Palabra.h"
#include <stdlib.h>
using namespace std;

Generador::Generador(int f, int c){
    this->f = f;
    this->c = c;
    Matriz m(int f, int c);
}


void Generador::ponerPalabra(int dir, int posF, int posC, Palabra p, int i){
    if(m.posicionVacia(posF, posC)){
           if (i< lista[cuantasPalabras].getLength()){
            m.setValor(posF, posC, lista[cuantasPalabras].charAt(i));
			m.imprimir(cout); 
            ponerPalabra(dir, posF+sumaF[dir], posC+sumaC[dir], lista[cuantasPalabras], i++);
           }
    }
    else{
            if(i>0 && i < lista[cuantasPalabras].getLength()-1){
                m.quitarValor(posF, posC);
                ponerPalabra(dir, posF-sumaF[dir], posC-sumaC[dir], lista[cuantasPalabras], i--);
            }

    }
}

void Generador::guardoPalabra(char * ptr, int n){
    Palabra * pl = new Palabra(ptr);
        lista[n] = *pl;   
}

void Generador::ponerPalabra(char * palabra){
    int dir = 1 + rand() % 8;
    int posF = rand() % f;
    int posC = rand() % c;
    int i = 0;
    ponerPalabra(dir, posF, posC, palabra, i);

}

Generador::~Generador()
{
    //dtor
}
