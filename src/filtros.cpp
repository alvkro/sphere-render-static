#include "imagem.h"

// Função experimental
void Imagem::alterarGradiente() {
    double percent = 1; 

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            MeasuresImg[x][y].r *= percent;
                percent -= 0.01;
                if (percent <= 0.0) {
                    percent = 1;
                }
        }
    }
}

void Imagem::sombreamento() { // tomar como referencia o xc e yc (?)
    double shadowing = 0.9;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (MeasuresImg[x][y].r == 255 && x > getXc()) { 
                MeasuresImg[x][y].r *= shadowing;
                shadowing -= 0.05;
                if (shadowing <= 0.0) {
                    shadowing = 0.9;
                }
            }
        }
    }
}

void Imagem::bordas(int tamanhoRaio, int thickBorda) {

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (tamanhoRaio - thickBorda <= distCirculo(x, y) && distCirculo(x, y) <= tamanhoRaio) {
                MeasuresImg[x][y].r = 255;
                MeasuresImg[x][y].g = 255;
                MeasuresImg[x][y].b = 255;
            }
        }
    }
}