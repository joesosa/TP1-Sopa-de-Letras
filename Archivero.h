#ifndef _Archivero
#define _Archivero
#include <fstream>
using namespace std;
class Archivero {
	private:
	   char** listaPalabras;
	   int** cantidadPalabras; // inicializar cant palabras, 2
	   char** matrizSopa;
	   bool posValida(int, int);
	   bool revisarPalabra(int,int, char[], int);
	   int** posiciones;
	   const int filaSopa;
	   const int columSOpa;
	public:                                                                        
	   Archivero();
	   ~Archivero(); // Destructor
	   void sacaPalabras(int,char*);
	   void solucionador();
	   void lectorSopaLetras(int,int,char*);
	   void liberarMemoria();

};
#endif

