#pragma once
#include <string>
#include <iostream>
using namespace std;

struct Pixel {
    int r, g, b;
};

class Imagem {
    private:
    int w, h;
    Pixel** MeasuresImg;

    public:
    Imagem(int larg, int alt) {
        w = larg;
        h = alt;
        criarImg();
    }

    ~Imagem() {
        clearImg();
    }


    void savePPM(const string& arquivo);
    Pixel& operator()(int x, int y);
    void clearImg();
    void criarImg();
};