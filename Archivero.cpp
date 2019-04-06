#include "Archivero.h";
#include <iostream>;
#include <stdlib.h>;
#include <fstream>;
#include <istream>;
#include <string.h>
using namespace std; //REVISAR PUTEROS A VECTORES Y MATRICES 

//@func: El metodo lee el archivo que trae las palabras que se deben buscar en la sopa, y las guarda en una matriz
//@param:cantidadPalabras es un int que indica la cantidad de palabras por guardar en la matriz de palabras; 
//@param:misPalabras es un puntero a un vector de char que contiene el nombre del acrchivo que trae las palabras;
Archivero::sacaPalabras(int cantidadPalabras,char* misPalabras){
	this->listaPalabras = new char[cantidadPalabras];
	for(int i = 0; i < filas; ++i){
		this->listaPalabras[i] = new char [23];
	}
	ifstream filePalabras;
	filePalabras.open(misPalabras,ios::in); // Se abre el archivo en modo lectura
	if(filePalabras.fail()){ 
        cout<< "ERROR ABRIENDO FILEPALABRAS"<< endl;
        exit(1);
	}
	int i = 0;
	while(!filePalabras.eof()){ // Saca cada palabra del archivo
		if(i == 0){ // Guarda la primera linea que contiene las filas y columas en un lugar distinto a las palabras
			//char []
		}
        cin.getline(listaPalabras[i],23);
        cout<< "Se guardó la palabra: " << listaPalabras[i]<<endl;
        ++i;

	}
	filePalabras.close();
}

//@func: El metodo lee el archivo que trae las letras que se deben poner en la sopa, y las guarda en una matriz
//@param:filas es un int que me indica las filas de la sopa. 
//@param:columnas es un int que me indica las columnas de la sopa. 
//@param:miSopaLetras es un puntero a un vector de char que contiene el nombre del acrchivo que trae las palabras;
Archivero::lectorSopaLetras(int filas, int columnas ,char[]* miSopaLetras){
    this->matrizSopa = new char[filas];
    this->filaSopa = filas; // revisar ftotal y ctotal
    this->columSopa = columnas;
	for(int i = 0; i < filas; ++i){
		this->matrizSopa[i] = new char [columnas];
	}
	ifstream fileSopa;
	fileSopa.open(miSopaLetras,ios::in);
	if(fileSopa.fail()){
        cout<< "ERROR ABRIENDO FILESOPA"<< endl;
        exit(1);
	}
	int f = 0;
	int c = 0;
	while(!fileSopa.eof() && f<filas){
	    if(c == columnas){
                ++f; c = 0;
        }
        fileSopa >> matrizSopa[f][c]
        cout<< "Se guardó la letra: " << listaPalabras[f][c]<<endl;
	    ++c;
	}
	archivo.close();


}

//@func:Revisa que una posicion determinada dentro de la matriz sopa de letras sea valida
//@param: f es un int que indica la fila que quiero verificar si es valida
//@param: c es un int que indica la columna que quiero verificar si es valida
Archivero::posValida(int f, int c){
	return f < this->fTotal && f >= 0 && c < this->cTotal && c >=0;
}

//0@func: Dada una posicion dentro de la sopa que contiene una letra que coincide con la primera letra de la palabra que estoy buscando, el metodo
//revisa si a partir de esa posición determinada se encuentra la palabra que se está buscando
//@param:f es un int que indica la fila inicial a partir de la que debo buscar
//@param:c es un int que me indica la columna inicial a partir de la que debo buscar
//@param:palabraActual es un vector de char que me indica la palabra que estoy buscando
//@param:indicePalabra es un int que me indica cual palabra esto buscando, va en orden ascendente desde 0 hasta la cantidad total de palabras por buscar
//@return: Retorna el booleano "encontrada" e indica si la palabra se encontró o no
Archivero::revisarPalabra(int f, int c, char[] palabraActual, int indicePalabra) {
	bool encontrada = 0;
	int caso = 0, pasos; // Caso me permite moverme a través del switch y pasos me indica la cantidad de espacios que me he movido hacía un lado 
	switch (caso) { // El switch me permite seguir buscando en otra dirección si no lo encontré en la actual, si la encuentro uso un break ubicado dentro de un if en cada caso para salirme
	case 0: // DERECHA
		pasos = 1;
		int aciertos = 1;
		while (posValida(f, c + pasos) && (this->matrizSopa[f][c + pasos] == palabraActual[pasos])) {
			aciertos += 1;
			if (aciertos == largo palabra) {// Este if se encuentra cada caso y nos indica si ya encontré la palabra, de ser así guardo sus coordenadas inicales en una matriz 
			// arreglar esto
				this->cantidadPalabras[indicePalabra][0] = f;
				this->cantidadPalabras[indicePalabra][1] = c;
				encontrado = 1;
				break;
			}
			++pasos;
		}
	case 1: // IZQUIERDA
		pasos = 1;
		int aciertos = 1;
		while (posValida(f, c - pasos) && (this->matrizSopa[f][c + pasos] == palabraActual[pasos])) {
			aciertos += 1;
			if (aciertos == largo palabra) { // arreglar esto
				this->listaPalabras[indicePalabra][0] = f;
				this->listaPalabras[indicePalabra][1] = c;
				encontrado = 1;
				break;
			}
			++pasos;
		}
	case 2: // ARRIBA
		pasos = 1;
		int aciertos = 1;
		while (posValida(f - pasos, c) && (this->matrizSopa[f][c + pasos] == palabraActual[pasos])) {
			aciertos += 1;
			if (aciertos == largo palabra) { // arreglar esto
				this->listaPalabras[indicePalabra][0] = f;
				this->listaPalabras[indicePalabra][1] = c;
				encontrado = 1;
				break;
			}
			++pasos;
		}
	case 3: // ABAJO
		pasos = 1;
		int aciertos = 1;
		while (posValida(f + pasos, c) && (this->matrizSopa[f][c + pasos] == palabraActual[pasos])) {
			aciertos += 1;
			if (aciertos == largo palabra) { // arreglar esto
				this->listaPalabras[indicePalabra][0] = f;
				this->listaPalabras[indicePalabra][1] = c;
				encontrado = 1;
				break;
			}
			++pasos;
		}
	case 4: // Diagonal 1 (Abajo-Derecha)
		pasos = 1;
		int aciertos = 1;
		while (posValida(f + pasos, c + pasos) && (this->matrizSopa[f][c + pasos] == palabraActual[pasos])) {
			aciertos += 1;
			if (aciertos == largo palabra) { // arreglar esto
				this->listaPalabras[indicePalabra][0] = f;
				this->listaPalabras[indicePalabra][1] = c;
				encontrado = 1;
				break;
			}
			++pasos;
		}
	case 5: // Diagonal 2 (Abajo-Izquierda)
		pasos = 1;
		int aciertos = 1;
		while (posValida(f + pasos, c - pasos) && (this->matrizSopa[f][c + pasos] == palabraActual[pasos])) {
			aciertos += 1;
			if (aciertos == largo palabra) { // arreglar esto
				this->listaPalabras[indicePalabra][0] = f;
				this->listaPalabras[indicePalabra][1] = c;
				encontrado = 1;
				break;
			}
			++pasos;
		}
	case 6: // Diagonal 3 (Arriba-Derecha)
		pasos = 1;
		int aciertos = 1;
		while (posValida(f - pasos, c + pasos) && (this->matrizSopa[f][c + pasos] == palabraActual[pasos])) {
			aciertos += 1;
			if (aciertos == largo palabra) { // arreglar esto
				this->listaPalabras[indicePalabra][0] = f;
				this->listaPalabras[indicePalabra][1] = c;
				encontrado = 1;
				break;
			}
			++pasos;
		}
	case 7: // Diagonal 4 (Arriba-Izquierda)
		pasos = 1;
		int aciertos = 1;
		while (posValida(f - pasos, c - pasos) && (this->matrizSopa[f][c + pasos] == palabraActual[pasos])) {
			aciertos += 1;
			if (aciertos == largo palabra) { // arreglar esto
				this->listaPalabras[indicePalabra][0] = f;
				this->listaPalabras[indicePalabra][1] = c;
				encontrado = 1;
				break;
			}
			++pasos;
		}
	}
	return encontrada;
} // arreglar vectores cantidadpalabras

//@func: Este metodo empieza a solucionar la sopa de letras y buscar cada palabra, una  la vez  	
Archivero::solucionador() {
	bool sopaSolucionada = 0, palabraEncontrada;
	*char palabraXBuscar;
	int indicePalb = 0;
	int f,c;
	while (!sopaSolucionada){ // este while me mantiene en un bucle mientras no haya encontrado todas las palabras
		f = 0, c = 0,  //indicePalb me permite moverme en un vector de palbras para irlas escogiendo
		palabraEncontrada = 0;
		palabraXBuscar = this->listaPalabras[indicePalb];
	while(posValida(f,c) && !palabraEncontrada){ // Este while es el individual en cada palabra, o sea sale de el cada vez que encuentra una palabra
				if(this->matrizSopa[f][c] == *palabraXBuscar[]){
					palabraEncontrada = revisarPalabra(f,c,*palabraXBuscar, indicePalb);
				}
				++c;
				if(c == this->columSOpa){
					++f;
					j = 0;
				}
	}
	++indicePalb;
	if(indicePalb => palabras totales){ //Me indica si ya encontré todas las palabras // ARREGLAR ESTO IMPLEMENTACION . LENGTH
		sopaSolucionada = true;
	}
	
	}
}
