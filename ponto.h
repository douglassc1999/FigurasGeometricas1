#ifndef PONTO_H
#define PONTO_H

#include "figurageometrica.h"

class Ponto : public FiguraGeometrica
{
    int x, y;
public:
  Ponto(int _x, int _y);
  void draw(Screen &t);
};

#endif // PONTO_H
