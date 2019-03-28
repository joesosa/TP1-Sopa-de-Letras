#ifndef _PALABROTA
#define _PALABROTA
class Palabra {
	private:
      char * palabra;
	   int length;
		int posicion;

	public:
	   Palabra();
       Palabra(char *);
	   ~Palabra();
	   int equals(Palabra&); // retorna 0 si son diferentes
       char * getHilera();
	   void setHilera(char *);
	   int getLength();
	   char charAt(int);
		int getPosicion();
		int nuevaPosicion();
};
#endif
