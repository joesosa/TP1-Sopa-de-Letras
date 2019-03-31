#ifndef GENERADOR_H
#define GENERADOR_H


class Generador
{
    public:
        Generador(int f, int c);

        void ponerPalabra(int dir, int posF, int posC, char * palabra, int i);
        void ponerPalabra(char * palabra);

    private:
		int f; 
		int c; 
        Matriz m;
        const int sumaF[8]={-1,-1,0,1,1,1,0,-1};
    	const int sumaC[8]={0,-1,-1,-1,0,1,1,1};
};

#endif // GENERADOR_H
