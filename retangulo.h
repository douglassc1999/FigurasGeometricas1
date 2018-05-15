#ifndef RETANGULO_H
#define RETANGULO_H
#include "figurageometrica.h"

class Retangulo : public FiguraGeometrica{
   int x, y, largura, altura, fillmode;

public:

  Retangulo(int _y, int _x,int _largura,int _altura, int _fillmode);

  ~Retangulo();

  void draw(Screen &t);
};

#endif // RETANGULO_H
