#include "Generador.h"
#include "Matriz.h"
#include "Palabra.h"
#include <stdlib.h>
using namespace std;

Generador::Generador(int f, int c, int n){
    this->f = f;
    this->c = c;
    m = new Matriz(f,c);
    lista = new Palabra [n]; 
   // m.rellenoSopa();
    m->imprimir(cout); 
}

Generador::~Generador(){
    delete [] lista;
	delete m;
}

/**
 * @Descripcion: almacena los * a char en el vector de palabras
 * @Param: ptr: char* palabra
 * @Param: n:int cantida de palabras
 */
void Generador::guardoPalabra(char * ptr, int n){
    Palabra pl(ptr);
    lista [n] = pl; 
    posicionPalabra(lista [n]); 
}

/**
 * @Descripcion: busca una posicion aleatoria en la matriz y la forma en que se va a colocar,
 * y ademas llama al metodo encargado de llamar a los demas colocando una palabra en un posicion,
 * de la matriz, con una direccion
 * @Param: p: Palabra recibe una palabra
 */
void Generador::posicionPalabra(Palabra p){
    int dir = p.getDireccion();
    int posF = rand() % f;
    int posC = rand() % c;
	m->ponerPalabra(dir, posF, posC, p);
}

