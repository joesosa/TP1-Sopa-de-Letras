#ifndef GENERADOR_H
#define GENERADOR_H
#include "Palabra.h"
#include "Matriz.h"

class Generador
{
    public:
        Generador(int, int, int);
        ~Generador();
        void guardoPalabra(char*, int );
        void posicionPalabra(Palabra);
    
        

    private:
		int f; 
		int c; 
        Matriz m;
        Palabra * lista;
        int cuantasPalabras = 0;
        
};

#endif // GENERADOR_H
