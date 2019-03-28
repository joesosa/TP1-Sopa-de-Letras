#include <EjecutadorPalabras.h>


EjecutadorPalabras::EjecutadorPalabras(char * archico){
    contadorPalabras++;

    //falta
}

void EjecutadorPalabras::colocoPalabras(){
    int pos;
    for(int i =0; i < contadorPalabras;++i){
        pos = lista[i].getPosicion();
        while(!sePuedePoner()){
            pos = lista[i].nuevaPosicion();
        }
        posicionPalabra(pos);
    }
}

void EjecutadorPalabras::posicionPalabra(int pos){
    switch(pos){
        case 1: break;    //horizontal der
        case 2: break;    //horizontal isq
        case 3: break;    //vertical arriba
        case 4: break;    //vertical abajo
        case 5: break;    //diagonal arriba-der
        case 6: break;    //diagonal arriba-isq
        case 7: break;    //diagonal abajo-der
        case 8: break;    //diagonal abajo-isq
        default: break;
    }
}

int EjecutadorPalabras::sePuedePoner(){
    int puede;
    return puede;
}
