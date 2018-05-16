#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "figurageometrica.h"
#include "circulo.h"
#include "reta.h"
#include "retangulo.h"
#include "ponto.h"
#include <vector>

using namespace std;

int main(){

    vector<FiguraGeometrica*> figuras;
    char sel;

    cout<<"Modo de Desenho ou Padrao? (d/p)\n";
    cin>>sel;

    // MODO DE DESENHO ARBITRARIO

    if(sel == 'd'){
    system("cls");  

    int nl, nc;
    int x0, y0, xn, yn, largura, altura, raio, fillmode;
    char brush;


    cout<<"Informe o tamanho da matriz (numero de linhas e colunas, respectivamente)\n";
    cin>>nl>>nc;
    Screen t(nl,nc);

    system("cls");

    cout<<"Informe o tipo de figura que voce quer desenhar: reta(r), retangulo(e) ou circulo(c)\n";
    cin>>sel;
    system("cls");

    // De acordo com a escolha do usuário, faz a alocação no vetor figuras

    if (sel=='r' ||sel== 'R'){
        cout<<"Informe as coordenadas iniciais e finais da reta (x0, y0), (xn,yn):\n";
        cin>>x0>>y0>>xn>>yn;

        cout<<"Informe o caracter para preenchimento: \n";
        cin>>brush;

        t.setBrush(brush);
        figuras.push_back(new Reta(x0, y0, xn, yn));

    }
    if (sel=='e' ||sel== 'E'){
        cout<<"Informe as coordenadas do canto superior esquerdo do retangulo (x0, y0), a largura e a altura:\n";
        cin>>x0>>y0>>largura>>altura;

        cout<<"Informe o caracter para preenchimento: \n";
        cin>>brush;

        cout<<"Seu retangulo deve ser preenchido? (se sim, digite um numero maior que zero): \n";
        cin>>fillmode;

         t.setBrush(brush);
        figuras.push_back(new Retangulo(x0, y0, largura, altura, fillmode));
    }
    if (sel=='c' ||sel== 'C'){
        cout<<"Informe as coordenadas  do centro do circulo ou circunferencia (x0, y0), e o raio:\n";
        cin>>x0>>y0>>raio;

        cout<<"Seu circulo deve ser preenchido? (se sim, digite um numero maior que zero): \n";
        cin>>fillmode;

        cout<<"Informe o caracter para preenchimento: \n";
        cin>>brush;

        t.setBrush(brush);
        figuras.push_back(new Circulo(x0, y0, raio, fillmode));

    }
    system("cls");

    //Imprime o que está no vetor usando iteradores

      for(vector<FiguraGeometrica*>::iterator it = figuras.begin(); it != figuras.end(); it++){

          (*it)->draw(t);
          t.clear();

    }

    // Desaloca o vetor

    for(int i=0; i<figuras.size(); i++){

      delete figuras[i];

    }

    }else{

    //MODO DE DESENHO PADRAO

    system("cls");

    ifstream fin;
    ofstream fout;
    vector<string*> s2;
    string s, cmd;
    int nc, nl, x0, y0, xn, yn, largura, altura, raio, fillmode;
    char caracter;

    fin.open("C:/Users/carva/Desktop/ProjetoPA/Arquivo/bola.txt"); //Diretório do arquivo de referência

    if(!fin.is_open()){

        cout<<"ERRO!";
        exit(0);

    }

    // Faz a análise do que está no arquivo e suas
    // devidas atribuições de variáveis
    // e alocação
    while(fin.good()){

        getline(fin, s);

        stringstream sstream(s);
        sstream >> cmd;
        if(cmd.compare("dim")==0){
            sstream >> nl >> nc;
            cout << "nl = " << nl << endl;
            cout << "nc = " << nc << endl;
        }
        if(cmd.compare("brush")==0){
            sstream >> caracter;
            cout << "caracter = " << caracter << endl;
        }
        // RETA
        if(cmd.compare("line")==0){
            sstream >> x0 >> y0 >> xn >> yn;
            cout << "x0 = " << x0 << endl;
            cout << "y0 = " << y0 << endl;
            cout << "x1 = " << xn << endl;
            cout << "y1 = " << yn << endl;
            figuras.push_back(new Reta(x0,y0,xn,yn));
            cout<<"A figura no diretorio escolhido eh uma RETA!\n";
        }

        //RETANGULO
        if(cmd.compare("rectangle")==0){
            sstream >> x0 >> y0 >> largura >> altura >> fillmode;
            cout << "x0 = " << x0 << endl;
            cout << "y0 = " << y0 << endl;
            cout << "largura = " << largura << endl;
            cout << "altura = " << altura << endl;
            cout << "fillmode = " << fillmode << endl;
            figuras.push_back(new Retangulo(x0,y0, largura, altura, fillmode));
            cout<<"A figura no diretorio escolhido eh um RETANGULO!\n";
        }

        // CIRCULO
        if(cmd.compare("circle")==0){
            sstream >> x0 >> y0 >> raio >> fillmode;
            cout << "x0 = " << x0 << endl;
            cout << "y0 = " << y0 << endl;
            cout << "raio = " << raio << endl;
            cout << "fillmode = " << fillmode << endl;
            figuras.push_back(new Circulo(x0,y0,raio, fillmode));
            cout<<"A figura no diretorio escolhido eh um CIRCULO!\n";
        }

    }

    Screen t(nl, nc); // criação da "tela"
    t.setBrush(caracter); // set com o caracter lido

    // Mostra o que esta no vetor
    for(vector<FiguraGeometrica*>::iterator it = figuras.begin(); it != figuras.end(); it++){

        t.clear();
        (*it)->draw(t);

    }

    //PARA GRAVAR EM UM ARQUIVO EXTERNO

    fout.open("C:/Users/carva/Desktop/ProjetoPA/Arquivo/2.txt"); // Onde sera gravado a figura

    if(!fout.is_open()){

        cout<<"ERRO!";
        exit(0);
    }

    // Atribui o que está no objeto ao arquivo direcionado
    fout<<t;
    fout.close();

    // Desaloca o vetor
    for(int i=0; i<figuras.size(); i++){
        delete figuras[i];
    }

    }

    return 0;
}
