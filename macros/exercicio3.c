#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "TCanvas.h"
void exercicio3()
{
TF1 *gaus = new TF1("gaus","TMath::Gaus(x,5,2)",0,10); //Criando a função de gaus que será utilizada para preencher o histograma
TH1F h("h","Histograma",50,0,10); //Criando histograma
h.FillRandom("gaus",10000);  // Preenchendo histograma
h.GetXaxis()->SetTitle("X"); //Mudando titulo do eixo X
h.GetYaxis()->SetTitle("Y");// Mudando titulo do eixo Y
gStyle->SetOptStat("nmeri"); // Mudando a caixa de estatísticas, cada letra corresponde a uma modificação
h.DrawCopy(); //desenhando uma cópia do histograma h
}
