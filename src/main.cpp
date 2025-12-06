#include "imagem.h"
// criar um getter para o raio AQUI

int main() {
    Imagem img(256, 256);
    img.createCircle(90);
    img.bordas(90, 20);
    img.savePPM("resultados/circulo_filtro3.ppm");
}