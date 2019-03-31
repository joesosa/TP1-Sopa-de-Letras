#ifndef GENERADOR_H
#define GENERADOR_H
#include "Palabra.h"
#include "Matriz.h"

class Generador
{
    public:
        Generador(int f, int c);

        void ponerPalabra(int, int, int, Palabra, int);
        void ponerPalabra(char*);
        void guardoPalabra(char*,int);

    private:
		int f; 
		int c; 
        Matriz m;
        Palabra lista[];
        int cuantasPalabras = 0;
        const int sumaF[8]={-1,-1,0,1,1,1,0,-1};
    	const int sumaC[8]={0,-1,-1,-1,0,1,1,1};
};

#endif // GENERADOR_H
