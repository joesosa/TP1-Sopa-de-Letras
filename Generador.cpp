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


void Generador::ponerPalabra(int dir, int posF, int posC, char * palabra, int i){
	Palabra p(palabra); 
    if(m.posicionVacia(posF, posC)){
           if (i< p.getLength()){
            m.setValor(posF, posC, p.charAt(i));
			m.imprimir(cout); 
            ponerPalabra(dir, posF+sumaF[dir], posC+sumaC[dir], p, i++);
           }
    }
    else{
            if(i>0 && i < p.getLength()-1){
                m.quitarValor(posF, posC);
                ponerPalabra(dir, posF-sumaF[dir], posC-sumaC[dir], p, i--);
            }

    }
}

void Generador::ponerPalabra(char * palabra){
    int dir= 1 + rand() % 8;
    int posF = rand() % f;
    int posC = rand() % c;
    int i = 0;
    ponerPalabra(dir, posF, posC, char * palabra, i);

}

Generador::~Generador()
{
    //dtor
}
