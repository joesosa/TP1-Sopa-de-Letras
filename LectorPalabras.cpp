#include<fstream> // istream ostream 
#include<iostream>
#define _MAX_BUFFER_SIZE 30

// PARA PROBAR ESTE PROGRAMA
// Ejecute en consola
// g++ -o programa Main.cpp
// programa palabras.txt palabrasAlReves.txt

using namespace std;
int main(int argc, char * * argv){
	
	cout << "Cantidad de argumentos: "<< argc << endl;
   
	for(int i=0; i< argc; ++i){
	   cout << "Argumento " << i <<": "<< argv[i] << endl;  
	}
	if(argc > 2){
		int n = 0;
		ifstream entrada( argv[1]);
		ofstream salida( argv[2]);
		char * * palabra;
		 
		entrada >> n;
		palabra = new char * [n];
		//Palabra lista [n;]
		for(int i=0; i<n; ++i){
			palabra[i]= new char [_MAX_BUFFER_SIZE];
			entrada >> palabra[i];
			// Palabra lista[i](palabra[i]); si funciona el de abajo se ignora
			//lista[i] = palabra[i];
		}
		/*for(int i=0; i<n; ++i){
			Palabra palabra[i]();
			entrada >> lista[i];
		}*/
		for(int i=n-1; i>=0; --i){
			salida << palabra[i] << endl;
			delete [] palabra[i];
		}
		delete [] palabra;
	}
	return 0;
}
