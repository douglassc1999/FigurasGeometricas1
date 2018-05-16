#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class Screen{
private:
  // armazenam o tamanho da tela de desenho
  // no de linhas e de colunas

   int nlin, ncol;
  // guarda o caractere usado para desenhar
  char brush;

  // armazena a matriz da tela


  vector<vector<char>> mat;
public:


  // construtor da classe
  Screen(int _nlin, int _ncol);

  ~Screen();
  // desenha um pixel da matriz usando o caratere
  // guardado em 'brush'
  void setPixel(int x, int y);

  // limpa a tela
  void clear();

  // muda o caractere de desenho
  void setBrush(char _brush);

  // envia a tela para um stream de saida
  friend ostream& operator<<(ostream &os, Screen &t){

       for(int i=0; i<t.nlin; i++){
          for(int j= 0; j<t.ncol; j++){
              os << t.mat[i][j]<<" ";
          }
          os<<"\n";
      }
       return os;
  }
  
};
#endif // SCREEN_H
