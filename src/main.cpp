#include "imagem.h"

int main() {
    Imagem img(256, 256);
    img.createCircle(90);
    img.sombreamento();
    img.savePPM("circulo_filtro.ppm");
}