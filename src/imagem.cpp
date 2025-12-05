#include <fstream>
#include <math.h>
#include "imagem.h"
using namespace std;

Pixel& Imagem::operator()(int x, int y) {
    return MeasuresImg[x][y];
}

// Constructor
void Imagem::criarImg() {
    MeasuresImg = new Pixel*[w];
    for (int i = 0; i < w; i++) {
        MeasuresImg[i] = new Pixel[h];
    }
}

// Destructor
void Imagem::clearImg() {
    for (int i = 0; i < w; i++) {
        delete MeasuresImg[i];
    }
    delete[] MeasuresImg;
}

void Imagem::savePPM(const string& arquivo) {
    ofstream ppm(arquivo);

    ppm << "P3\n";
    ppm << w << " " << h << "\n";
    ppm << "255\n";

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            Pixel& p = MeasuresImg[x][y];

            ppm << p.r << " " << p.g << " " << p.b << "\n";
        }
    }
}

int Imagem::getXc() {
    return w / 2;
}

int Imagem::getYc() {
    return h / 2; 
}

// Poderia otimizar essa função futuramente

void Imagem::createCircle(int tamanhoRaio) {
    int yc = getYc();
    int xc = getXc();

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int distCirculo = pow((x - xc), 2) + pow((y - yc), 2);

            if (distCirculo <= pow(tamanhoRaio, 2)) {
                // Vermelho
                MeasuresImg[x][y].r = 255;
            }
            else {
                // Branco
                MeasuresImg[x][y].r = 255;
                MeasuresImg[x][y].g = 255;
                MeasuresImg[x][y].b = 255;
            }
        }
    }
}

// Função experimental
// void Imagem::alterarGradiente() {
//     // Teste com a cor vermelha
//     int increaseColor = 255;
//     for (int y = 0; y < h; y++) {
//         for (int x = 0; x < w; x++) {
//             MeasuresImg[x][y].r = increaseColor;
//             increaseColor *= 0.99999999999;
//         }
//     }
// }