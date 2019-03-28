#ifndef _EXE_PALABRAS
#define _EXE_PALABRAS
#include "Palabra.h"

class EjecutadorPalabras{

    private:
        Palabra lista [];
        int contadorPalabras;
        const int nombreDireccion[]={3,6,2,8,4,7,1,5};
   		const int sumaF[]={-1,-1,0,1,1,1,0,-1};
    	const int sumaC[]={0,-1,-1,-1,0,1,1,1};   

    public:
        EjecutadorPalabras(char *);
        void colocoPalabras();
        void posicionPalabra(int);
        int sePuedePoner();

        //coloca por posicion
        //elige letra aleatoria
        // manipula la matriz
        /*void llenar(char[][10]);
        void leer(char[][10]);
        void nuevaPalabra(char * hilera, int pos); //recursivo, se mete la palabra segun su orden/pos
        char letraAleatoria(char);//cambia el - por una letra entre A-Z
        int vacia();
        int funciona(); 
        int posValida(int pos);
        int finalizo(); //deermina si el programa ya escribio las palabras
        */
};

#endif
