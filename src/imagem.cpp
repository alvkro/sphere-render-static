#include "imagem.h"
#include <fstream>
using namespace std;

// Depois estudar o porquê Pixel não está acessando r, g e b...

Cor& Imagem::operator()(int x, int y) {
    return MeasuresImg[x][y];
}

// Constructor
void Imagem::criarImg() {
    MeasuresImg = new Cor*[w];
    for (int i = 0; i < w; i++) {
        MeasuresImg[i] = new Cor[h];
    }
}

// Destructor
void Imagem::clearImg() {
    for (int i = 0; i < w; i++) {
        delete MeasuresImg[i];
    }
    delete[] MeasuresImg;
}

void Imagem::savePPM(string& arquivo) {
    ofstream ppm(arquivo);

    ppm << "P3\n";
    ppm << w << " " << h << "\n";
    ppm << "255\n";

    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            Cor& p = MeasuresImg[x][y];

            ppm << p.r << p.g << p.b << "\n";
        }
    }
}