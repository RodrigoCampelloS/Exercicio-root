void exercicio4()
{
auto c = new TCanvas("c","c");//criando o canvas
TFile *f1 = new TFile("tree.root");//definindo TFile
TTree *mytree =(TTree *)f1->Get("tree1");//Pegando a Ttree do TFile
TCut* corte1 = new TCut("ebeam>150.2");//Definindo corte numero 1
TCut* corte2 = new TCut("ebeam<149.8");//Definindo corte numero 2
mytree->Draw("sqrt(px*px+py*py+pz*pz)",*corte1||*corte2); //Desenhando a distribuição com valores de energia do feixe que estejam F O R A do valor médio em mais de 0,2 como foi pedido no exercício
c->SaveAs("canvas.png");//Não ficou claro qual tipo de arquivo que era para salvar, portanto está salvando como uma imagem
}
