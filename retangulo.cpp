#include "retangulo.h"
#include <iostream>

using namespace std;
Retangulo::Retangulo(int _x, int _y, int _largura, int _altura, int _fillmode){

    // Atribuição das variáveis
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

  // A construçã do retângulo consiste na delimitação do laço pelas variáveis
  // de largura e altura, e seu preenchimento linha a linha
  if(fillmode > 0){
      for(int i=0; i<altura;i++){
          for(int j=0; j<largura;j++){
              t.setPixel(y+i, x+j);
          }
      }
      cout<<t;
  }

  // Para o retangulo nao preenchido, fazemos o retangulo como anteriormente, e adicionamos
  // um novo retangulo sobreposto ao mesmo com o caracter ' ' como brush, e de limites menores
  // num fator de '1'
  else{
      for(int i=0; i<altura;i++){
          for(int j=0; j<largura;j++){
              t.setPixel(y+i, x+j);
          }
      }
      t.setBrush(' ');
      for(int i=1; i<altura-1;i++){
          for(int j=1; j<largura-1;j++){
              t.setPixel(y+i, x+j);
          }
      }
       cout<<t;
   }

}
