#ifndef RETANGULO_H
#define RETANGULO_H
#include "figurageometrica.h"

class Retangulo : public FiguraGeometrica{
   //Váriáveis usadas para desenho do retângulo
   int x, y, largura, altura, fillmode;

public:
  //Construtor
  Retangulo(int _y, int _x,int _largura,int _altura, int _fillmode);
  //Destrutor
  ~Retangulo();

  //Método de desenho da classe
  void draw(Screen &t);
};

#endif // RETANGULO_H
