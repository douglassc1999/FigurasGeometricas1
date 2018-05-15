#ifndef CIRCULO_H
#define CIRCULO_H
#include "figurageometrica.h"

class Circulo : public FiguraGeometrica{

    int x, y, raio, fillmode;

public:

  Circulo(int _x, int _y, int _raio, int _fillmode);
  Circulo(Screen &t, int _x, int _y, int _raio, int _fillmode);
  ~Circulo();
  void draw(Screen &t);
};

#endif // CIRCULO_H
