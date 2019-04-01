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



void Generador::guardoPalabra(char * ptr, int n){
    Palabra * pl = new Palabra(ptr);
        lista[n] = *pl;   
}

void Generador::posicionPalabra(Palabra p){
    int dir = p.getPosicion();
    int posF = rand() % f;
    int posC = rand() % c;
    ponerPalabra(dir, posF, posC, p);
}

void Generador::ponerPalabra (int dir, int posF, int posC, Palabra p){
    int i = 0;
    if(verificar(i, posF, posC, dir, p)){
        ponerLetras(i, posF, posC, dir, p);
    }
    else{
        dir++; 
        if(dir>= 8){
            dir = 0; 
        }
        ponerPalabra(dir, posF, posC, p);
    }
}

int Generador:: verificar(int i, int posF, int posC, int dir, Palabra p){
    int posible = 1; 
    if(i < p.getLength()){
        if(!m.posicionVacia(posF, posC) && m.getValor(posF, posC) != p.charAt(i)){
            posible = 0; 
        }
        else{
            verificar(i++, posF + sumaF[dir], posC + sumaC[dir], dir, p);
        }
    }
    return posible; 
}

void Generador:: ponerLetras(int i, int posF, int posC, int dir, Palabra p){
    if(i<p.getLength()){
        m.setValor(posF, posC, p.charAt(i)); 
        ponerLetras(i++, posF + sumaF[dir], posC + sumaC [dir], dir, p); 
    }
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
