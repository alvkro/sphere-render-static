#include "imagem.h"

int main() {
    Imagem img(256, 256);
    img.createCircle(30);
    img.savePPM("circulo.ppm");
}