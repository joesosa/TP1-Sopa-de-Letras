#include "Generador.h"
#include "Matriz.h"
#include "Palabra.h"
#include <stdlib.h>
using namespace std;

Generador::Generador(int f, int c, int n){
    this->f = f;
    this->c = c;
    Matriz m(int f, int c);
    lista = new Palabra[n];
}


void Generador::ponerPalabra(int dir, int posF, int posC, Palabra p, int i){
    if(m.posicionVacia(posF, posC)){
        if(i< lista[cuantasPalabras].getLength()){
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

void Generador::ponerPalabra(Palabra palabra){
    int dir = palabra.getPosicion();
    int posF = rand() % f;
    int posC = rand() % c;
    int i = 0;
    ponerPalabra(dir, posF, posC, palabra, i);

}

void Generador::rellenaSopa(){
    int rand = 0;
    for(int f = 0; f < this->f;++f){
        for(int c = 0; c < this->c;++c){
            if(m.getValor(f,c) ==  '_'){
                rand = 1 + rand % 26;
                m.setValor(f,c,letraAleatoria(rand));
            }
        }
    }
}

char Generador::letraAleatoria(int n){
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

Generador::~Generador()
{
    delete [] lista;
}
