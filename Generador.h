#ifndef GENERADOR_H
#define GENERADOR_H
#include "Palabra.h"
#include "Matriz.h"

class Generador
{
    public:
        Generador(int, int, int);

        void guardoPalabra(char*,int);
        void rellenaSopa();
        char letraAleatoria(int);
        void posicionPalabra(Palabra);
        void ponerPalabra(int, int, int, Palabra); 
        int verificar(int, int, int, int, Palabra); 
        void ponerLetras(int, int, int, int, Palabra);

    private:
		int f; 
		int c; 
        Matriz m;
        Palabra * lista;
        int cuantasPalabras = 0;
        const int sumaF[8]={-1,-1,0,1,1,1,0,-1};
    	const int sumaC[8]={0,-1,-1,-1,0,1,1,1};
};

#endif // GENERADOR_H

