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


    // Imagem: 
    void savePPM(const string& arquivo);
    Pixel& operator()(int x, int y);
    void clearImg();
    void criarImg();
    int getXc();
    int getYc();
    int distCirculo(int x, int y);
    void createCircle(int tamanhoRaio);

    // Filtros
    void alterarGradiente();
    void sombreamento();
    void bordas(int tamanhoRaio, int thickBorda);
};