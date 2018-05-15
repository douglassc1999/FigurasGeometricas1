#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "screen.h"

class FiguraGeometrica{

public:

  FiguraGeometrica();

  ~FiguraGeometrica();

  // classes que possuem funcoes virtuais
  // puras sao chamadas de classes abstratas
  virtual void draw(Screen &t)=0;
};

#endif // FIGURAGEOMETRICA_H
