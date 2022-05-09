{
  TCanvas *c = new TCanvas("c","c",0,0,900,600);
  TF1 *f[4]; TPaveText *pt[4];
  double E[4] = {11,8.8,6.6,4.4};
  int col[4] = {kRed,kOrange,kGreen+2,kBlue};
  double y_1[4] = {0.8,0.64,0.49,0.33}, y_2[4] = {0.85,0.695,0.54,0.38};
  for(int i=0;i<4;++i){
    f[i] = new TF1(Form("f%i",i),Form("4*pow(%f*sin(x*3.1415927/180./2),2)/(1+2*%f/0.939*pow(sin(x*3.1415927/180./2),2))",E[i],E[i]),0,180);
    f[i]->SetLineColor(col[i]);
    f[i]->SetLineWidth(3);
    if(i==0){
      f[i]->Draw();
      f[i]->SetTitle("Q^{2} versus Scattering Angle for eN Elastic Scattering");
      f[i]->GetXaxis()->SetTitle("Scattering Angle (#circ)");
      f[i]->GetYaxis()->SetTitle("Q^{2} (GeV/c)^{2}");
    }else f[i]->Draw("same");
    pt[i] = new TPaveText(0.75,y_1[i],0.89,y_2[i],"ndc");
    pt[i]->SetFillColor(0);pt[i]->SetBorderSize(0);pt[i]->SetShadowColor(0);pt[i]->SetTextColor(col[i]);
    pt[i]->AddText(Form("E_{beam} = %0.1f GeV",E[i]));
    pt[i]->Draw();
    gPad->Update();
  }
  c->SaveAs("Q2vsAngle.png"); 
}
