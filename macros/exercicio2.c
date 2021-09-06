#include <string>
void exercicio2()
{
   TCanvas *c1=new TCanvas();
   c1->Draw();
TGraph* gr = new TGraph("graphdata.txt"); //Criando Tgraph já com os pontos do graphdata.txt
   gr->SetLineColor(2); //Mudando a cor da linha
   gr->SetLineWidth(4); //Mudando a espessura da linha
   gr->SetMarkerColor(3); //Mudando a cor dos pontos
   gr->SetMarkerSize(1.5); //Mudando a grossura dos pontos
   gr->SetMarkerStyle(21); //Mudando os pontos para serem representados por uma caixa
   gr->SetTitle("Exercicio 2");//Mudando o Título do histograma
   gr->GetXaxis()->SetTitle("X");//Mudando titulo no eixo X para "X"
   gr->GetYaxis()->SetTitle("Y");//Mudando titulo no eixo X para "X"
   gr->Draw();
}
