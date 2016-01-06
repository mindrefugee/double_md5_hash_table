void hist()
{

  int ndev=2161;
  //int ndev=4327;
  //int ndev=9973;
  TH1F* h=new TH1F("hash1","random array hash test",ndev,-0.5,ndev-0.5);
  TH1F* h2=new TH1F("hash2","random array hash test",ndev,-0.5,ndev-0.5);
  TH1F* h3=new TH1F("hash3","random array hash test",ndev,-0.5,ndev-0.5);
  TH1F* h4=new TH1F("hash4","random array hash test",ndev,-0.5,ndev-0.5);
  TH2F*  h2d=new TH2F("2d","map 3 vs. 4",2161,-0.5,2160.5,2161,-0.5,2160.5);
  TH2F*  h2d2=new TH2F("2d2","map 1 vs. 3",2161,-0.5,2160.5,2161,-0.5,2160.5);
  ifstream ifs;double x,y,z,w;

  ifs.open("double_test.dat");
  while(ifs>>x>>y>>z>>w){
    h->Fill(x);
    h2->Fill(y);
    h3->Fill(z);
    h4->Fill(w);

    h2d->Fill(z,w);
    h2d2->Fill(x,z);
  }
  ifs.close();
  TCanvas* c=new TCanvas("c1","hash",900,1200);

  c->Divide(2,3);
  c->cd(1);  
  h->Draw();
  c->cd(2);
  h2->Draw();  
  c->cd(3);
  h3->Draw();  
  c->cd(4);
  h4->Draw();  

  c->cd(5);
  h2d->Draw("lego");
  c->cd(6);
  h2d2->Draw("lego");

  
  
}
