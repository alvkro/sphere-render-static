#pragma once
#include "pixel.h"
#include <string>
using namespace std;

class Imagem {
    private:
    int w, h;
    Cor** MeasuresImg;

    public:
    Imagem(int w, int h) {
        criarImg();
    }

    ~Imagem() {
        clearImg();
    }

    void savePPM(string& arquivo);
    Cor& operator()(int x, int y);
    void clearImg();
    void criarImg();
};