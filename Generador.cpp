#include "Generador.h"
#include "Matriz.h"
#include "Palabra.h"
#include <stdlib.h>
using namespace std;

Generador::Generador(int f, int c, int n){
    this->f = f;
    this->c = c;
    Matriz m(f, c);
    lista = new Palabra [n]; 
   // m.rellenoSopa();
    m.imprimir(cout); 
}

void Generador::guardoPalabra(char * ptr, int n){
     m.imprimir(cout);
    Palabra pl(ptr);
    lista [n] = pl; 
    cout << lista [n].getHilera() << endl; 
    posicionPalabra(lista [n]); 
    m.imprimir(cout);
    m.rellenoSopa(); 
    m.imprimir(cout); 
}

void Generador::posicionPalabra(Palabra p){
    int dir = rand() % 8;
    int posF = rand() % f;
    int posC = rand() % c;

    cout << p.getHilera() << endl;
    cout << dir << "dir" << endl;
    cout << posF << "posF" << endl;
    cout << posC << "posC" << endl;
    
    m.ponerPalabra(dir, posF, posC, p);
}






Generador::~Generador(){
    delete [] lista;
}
