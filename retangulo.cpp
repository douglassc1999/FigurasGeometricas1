#include "retangulo.h"
#include <iostream>

using namespace std;
Retangulo::Retangulo(int _x, int _y, int _largura, int _altura, int _fillmode){

    x = _x;
    y = _y;
    largura = _largura;
    altura = _altura;
    fillmode = _fillmode;
}

Retangulo::~Retangulo()
{
    cout<<"Chamou destrutor de RETANGULO\n";
}

void Retangulo::draw(Screen &t){

  cout << "desenhando retangulo\n";

  if(fillmode > 0){
      for(int i=0; i<altura;i++){
          for(int j=0; j<largura;j++){
              t.setPixel(y+i, x+j);
          }
      }
      cout<<t;
  }

  else{
      for(int i=0; i<altura;i++){
          for(int j=0; j<largura;j++){
              t.setPixel(y+i, x+j);
          }
      }
      t.setBrush(' ');
      for(int i=1; i<altura;i++){
          for(int j=1; j<largura;j++){
              t.setPixel(y+i, x+j);
          }
      }
       cout<<t;
   }

}
