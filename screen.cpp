#include "screen.h"
#include <fstream>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

Screen::Screen(int _nlin, int _ncol){

    // atribuição das variáveis
    nlin = _nlin;
    ncol = _ncol;
    brush = ' ';
    mat = vector<vector<char>>(nlin, vector<char>(ncol, brush));

    cout<<"Chamou construtor da classe Screen\n";
};

Screen::~Screen()
{
    cout<<"Chamou destrutor da classe Screen\n";
};

void Screen::setPixel(int x, int y)
{

   //Avisa caso o usuário digite valores inválidos
   if(x>nlin || x<0){
       cout<<"Posicao NAO existente!\n";
       exit(0);
   }
   if(y>ncol || y<0){
       cout<<"Posicao NAO existente!\n";
       exit(0);
   }

   mat[x][y] = brush;
};

void Screen::clear()
{
    // Preenche toda a matriz com caracter ' '
    for(int i=0; i<nlin;i++){
        for(int j= 0; j<ncol; j++){
            mat[i][j] = ' ';
        }
    }

};

void Screen::setBrush(char _brush)
{
    // preenche a variável brush com _brush
    brush = _brush;
};

