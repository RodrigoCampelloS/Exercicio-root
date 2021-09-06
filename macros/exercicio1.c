#include <sstream>
const char* ConvertDoubleToString(double value){ //criando função que converte double para const char que será utilizada no código
    std::stringstream ss ;
    ss << value;
    const char* str = ss.str().c_str();
    return str;
}
void exercicio1()
{

TF1 *f1 = new TF1("f1","sin(x)/x",0,10); //Criando primeiro TF1 

TF1 *f2 = new TF1("f2","[0]*sin([1]*x)/x",-5,5); //Criando segundo TF1

//Definindo e nomeando parametros da segunda função
f2->SetParameter(0,2); //definindo o primeiro parametro da segunda função 
f2->SetParameter(1,4); //definindo o segundo parametro da segunda função
f2->SetParName(0,"P0");//nomeando o primeiro parametro da segunda função como "P2"
f2->SetParName(1,"P1");//nomeando o segundo parametro da segunda função como "P1"

//Mudanças cosméticas 
f2->SetLineColor(4); //Mudando a cor da segunda função para azul
f1->GetXaxis()->SetTitle("X"); //Inserindo titulo no eixo X para "X"
f1->GetYaxis()->SetTitle("Y");//Inserindo titulo no eixo Y para "Y"


//Inicialização dos canvas
TCanvas *c1=new TCanvas();
f1->Draw();
TCanvas *c2=new TCanvas();
f2->Draw();

//Iniciando variaveis v1,v2,v3 que serão utilizadas para guardar os resultados das perguntas 1.1;1.2;1.3 deste exercício
double v1 = 0.0;
double v2 = 0.0;
double v3 = 0.0;

//Redefinindo os parametros 
f2->SetParameter(0,1);
f2->SetParameter(1,2);

//calculando o que foi pedido no exercício
v1=f2->Eval(1); // Calculando da função para x=1
v2=f2->Derivative(1); // Calculando a derivada da função para X=1
v3=f2->Integral(0.0,3.0); // calculando a integral da função entre 0 e 3

//Criando e preenchendo a legenda
auto* legend = new TLegend(0.6, 0.6, 0.95, 0.95);
legend->SetNColumns(2); // Definindo número de colunas na legenda
legend->SetHeader("Para P0=1 e P1=2; temos:","C"); // Definindo título da legenda
legend->AddEntry((TObject*)0, "Valor da funcao para x=1 :", "");
legend->AddEntry((TObject*)0, ConvertDoubleToString(v1), ""); //Usando a função ConvertDoubleToString definida anteriormente para converter v1 para const char
legend->AddEntry((TObject*)0, "Derivada de funcao para x=1:", "");
legend->AddEntry((TObject*)0, ConvertDoubleToString(v2), ""); //Usando a função ConvertDoubleToString definida anteriormente para converter v2 para const char
legend->AddEntry((TObject*)0, "integral da funcao entre 0 e 3", "");
legend->AddEntry((TObject*)0, ConvertDoubleToString(v3), ""); //Usando a função ConvertDoubleToString definida anteriormente para converter v3 para const char

legend->Draw();
f2->GetXaxis()->SetTitle("X");//Inserindo titulo no eixo X para "X"
f2->GetYaxis()->SetTitle("Y");//Inserindo titulo no eixo Y para "Y"


}
