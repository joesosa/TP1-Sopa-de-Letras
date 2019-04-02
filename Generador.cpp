#include "Generador.h"
#include "Matriz.h"
#include "Palabra.h"
#include <stdlib.h>
using namespace std;

Generador::Generador(int f, int c, int n){
    this->f = f;
    this->c = c;
    cuantasPalabras = n;
    Matriz m(int f, int c);
    lista = new Palabra[n];
}

Generador::~Generador()
{
    delete [] lista;
}

/**
 * @Descripcion: almacena los * a char en el vector de palabras
 * @Param: ptr: char* palabra
 * @Param: n:int cantida de palabras
 */
void Generador::guardoPalabra(char * ptr, int n){
    Palabra * pl = new Palabra(ptr);
        lista[n] = *pl;   
}

/**
 * @Descripcion:ciclo que coloca todas las palabras del vector en la sopa
 */
void Generador::palabrasEnSopa(){
    for(int i = 0; i <= cuantasPalabras;++i){
        posicionPalabra(lista[i]);
    }
}

/**
 * @Descripcion: busca una posicion aleatoria en la matriz y la forma en que se va a colocar,
 * y ademas llama al metodo encargado de llamar a los demas colocando una palabra en un posicion,
 * de la matriz, con una direccion
 * @Param: p: Palabra recibe una palabra
 */
void Generador::posicionPalabra(Palabra p){
    int dir = p.getPosicion();
    int posF = rand() % f;
    int posC = rand() % c;
    ponerPalabra(dir, posF, posC, p);
}
/**
 * @Descripcion:Devuelve el valor de una posicion en la matriz
 * @Param:fila:int posicion en la fila
 * @Param:columna:int posicion en la columna
 * @Return: el valor en la posicion
 */
char Generador::getValor(int fila,int columna){
   char valor = '\0';
   if(m.esPosicionValida(fila,columna)){
	   valor = m.getValor(f,c);
   }
   return valor;   
}
/**
 * @Descripcion:
 * @Param:
 * @Return:
 */
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

/**
 * @Descripcion:
 * @Param:
 * @Return:
 */
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

/**
 * @Descripcion:
 * @Param:
 * @Return:
 */
void Generador:: ponerLetras(int i, int posF, int posC, int dir, Palabra p){
    if(i<p.getLength()){
        m.setValor(posF, posC, p.charAt(i)); 
        ponerLetras(i++, posF + sumaF[dir], posC + sumaC [dir], dir, p); 
    }
}

/**
 * @Descripcion: termina de rellenar la sopa con letras aleatorias en donde no se ubiquen las palabras
 */
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

/**
 * @Descripcion:devuelve un char aleatorio atraves de un entero aleatorio
 * @Param:n:int numero random brindado
 * @Return:devuelve el char aleatorio
 */
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

