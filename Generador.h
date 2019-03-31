#ifndef GENERADOR_H
#define GENERADOR_H


class Generador
{
    public:
        Generador(int f, int c);

        void ponerPalabra(int dir, int posF, int posC, char * palabra, int i);
        void ponerPalabra(char * palabra);
		int sumaF[]={-1,-1,0,1,1,1,0,-1};
    	int sumaC[]={0,-1,-1,-1,0,1,1,1};

    private:
		int f; 
		int c; 
};

#endif // GENERADOR_H
