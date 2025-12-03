#pragma once

struct Cor {
    int r, g, b;
};

class Pixel {
    private:
    int tamanho, capacidade;
    Cor* RGB;

    public:
    
    Pixel() {
        tamanho = 10;
        capacidade = 10;

        RGB = new Cor[10];
    }

    ~Pixel() {
        delete[] RGB;
    }
};