#include <iomanip> 
#include <cstring> 
#include <stdlib.h>
#include <conio.h>
#include <stdio.h> 
#include <fstream>                  
#include <iostream>

using namespace std;

struct Taksiler
{
	char ad[80];
	char soyad[80];
	char plaka[5];
	char cinsiyet;	
};
Taksiler taksi;
void TaksiEkle();
void TaksiListeleme();
void TaksiArama();
void TaksiSil();
void TaksiDuzenle();
int main(){
	 
	char anamenu;
	do{
	system("cls");	
	cout << "|*******Hosgeldiniz******|" << endl ;
	cout << "|     -Secim Yapiniz-    |" << endl ;
	cout << "|   1- Taksi Ekleme      |" << endl ;
	cout << "|   2- Taksi Listeleme   |" << endl ;
	cout << "|   3- Taksi Arama       |"<< endl;
	cout << "|   4- Taksi Sil         |"<< endl;
	cout << "|   5- Taksi Duzenle     |"<< endl;
	cout << "|************************|" << endl ;
    char secim;
	cin>> secim;	
	switch(secim) 
	{
		case '1' : 
		{
		TaksiEkle();
		break;	
		}
		case '2' : 
		{
		 TaksiListeleme()	;
		 break;
		}
		case '3' : 
		{
		 TaksiArama()	;
		 break;
		}
		case '4' : 
		{
		 TaksiSil()	;
		 break;
		}
		case '5' : 
		{
		 TaksiDuzenle();
		 break;
		}
	}	
	cout << "Anamenuye Donmek icin: a basin cikmak iï¿½in: c" <<endl ; 
	anamenu=getche();
	
    }while(anamenu=='a');
     

return 0;
}

void TaksiEkle()
{
	ofstream yaz("taksiler.dat",ios::binary |ios::app);
	char secim;
	int adet=0;
	
	do{
	cout << "Taksi sahibinin adını giriniz" << endl;
	cin>> taksi.ad;
	cout << "Taksi sahibinin soyadını giriniz" << endl;
	cin>> taksi.soyad;
	cout << "Taksi plakasını giriniz" << endl;
	cin>> taksi.plaka;
	cout << "Taksicinin cinsiyetini giriniz (E/K)" << endl;
	taksi.cinsiyet=getche();
	cout << endl;
	yaz.write((char*)&taksi, sizeof(taksi));	
	adet++;	
	cout << "Baska Kayit Eklemek Istermisin (E/H)" << endl;
	secim=getche();
	cout << endl;
	}while(secim=='e' || secim=='E');
	
	cout << adet << " adet Taksi Ekledi.." << endl;
	
	yaz.close();
		
}
void TaksiListeleme()
{	
	ifstream oku("taksiler.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);
	int kayits=oku.tellg()/sizeof(taksi);
	cout << "Toplam Taksi Sayisi:"<< kayits << endl;
	
	if(kayits>0)
	{
		for(int i=0; i<kayits;i++)
		{
			oku.seekg(i*sizeof(taksi));
			oku.read((char*)&taksi, sizeof(taksi));	
			cout << i+1 << ". Taksinin Bilgileri"<< endl;
			cout << "Taksicinin Adi: "<< taksi.ad <<endl ;
			cout << "Taksicinin Soyadi: "<< taksi.soyad <<endl ;
			cout << "Taksicinin plakası: "<< taksi.plaka <<endl ;
			if(taksi.cinsiyet=='e' || taksi.cinsiyet=='E')
			cout << "Taksici Cinsiyet: ERKEK " <<endl ;
			else if(taksi.cinsiyet=='k' || taksi.cinsiyet=='K')
			cout << "Taksici Cinsiyet: KADIN " <<endl ;			
		}		
	}
	else
	cout << "Taksi Bulunamadi..." << endl;

	oku.close();
}
void TaksiArama()
{
	
	ifstream oku("taksiler.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);
	int kayits=oku.tellg()/sizeof(taksi);

cout <<"Aranan Taksi plakasını giriniz"<< endl;
char plaka[80];
cin>> plaka;
 		
	if(kayits>0)
	{
		for(int i=0; i<kayits;i++)
		{			
			oku.seekg(i*sizeof(taksi));
			oku.read((char*)&taksi, sizeof(taksi));
			
			if(strcmp(taksi.plaka,plaka)==0)
			{
			cout <<  "Bulunan Taksinin Bilgileri"<< endl;
			cout << "Taksicinin Adi: "<< taksi.ad <<endl ;
			cout << "Taksicinin Soyadi: "<< taksi.soyad <<endl ;
			cout << "Taksinin plakası: "<< taksi.plaka <<endl ;
			if(taksi.cinsiyet=='e' || taksi.cinsiyet=='E')
			cout << "Taksicinin Cinsiyeti: ERKEK " <<endl ;
			else if(taksi.cinsiyet=='k' || taksi.cinsiyet=='K')
			cout << "Taksicinin Cinsiyeti: KADIN " <<endl ;
		    }
		}		
	}
	else
	cout << "Kayit Bulunamadi..." << endl;
	oku.close();
}

void TaksiSil()
{
	 char plaka1[80];
     char secim= ' ';
     bool var=false;
     
    ifstream oku("taksiler.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);

	int kayitsayisi=oku.tellg()/sizeof(taksi);
	
     cout<<"Kaydini Sileceginiz Taksi plakasını giriniz : ";
     cin>>plaka1;

     for(int i=0;i<kayitsayisi;i++)
     {
            oku.seekg(i*sizeof(taksi));
			oku.read((char*)&taksi, sizeof(taksi));
			
     if(strcmp(taksi.plaka,plaka1)==0)
       {
                cout<<endl;
                cout<<"Taksicinin";
                cout<<"\nAdi : "<<taksi.ad;
                cout<<"\nSoyadı : "<<taksi.soyad<<endl;
                cout<<"\nPlakası : "<<taksi.plaka;
                cout<<"\nCinsiyet [E/K]: ";
                if(taksi.cinsiyet=='e'||taksi.cinsiyet=='E')
                cout<<"Erkek";
                if(taksi.cinsiyet=='k'||taksi.cinsiyet=='K')
                cout<<"Bayan";
                		  
                cout<<"\n\nSilmek Istediginiz Taksi Bu Mu? [E/H] : ";
                 secim=getche();
            if(secim == 'H' || secim == 'h')
              {      
			    Taksiler y_taksi;
                ofstream y_dosya("Yedek.dat",ios::app|ios::binary);
                
                strcpy(y_taksi.ad,taksi.ad);
                strcpy(y_taksi.soyad,taksi.soyad);
                strcpy(y_taksi.plaka,taksi.plaka);
                taksi.cinsiyet=y_taksi.cinsiyet;
                        
                y_dosya.write((char*)&taksi, sizeof(taksi));
                y_dosya.close();
              }
            if(secim=='e'||secim=='E')
              {
   			   	var=true;
  		 	  }
        }
             else
             {
              Taksiler y_taksi;
              ofstream y_dosya("Yedek.dat",ios::app|ios::binary);
              
              strcpy(y_taksi.ad,taksi.ad);
              strcpy(y_taksi.soyad,taksi.soyad);
              strcpy(y_taksi.plaka,taksi.plaka);
              taksi.cinsiyet=y_taksi.cinsiyet;
                       
              y_dosya.write((char*)&taksi, sizeof(taksi));
              y_dosya.close();
             }
     }
    oku.close();
    if(var)
    {
               remove("taksiler.dat");
               rename("Yedek.dat","taksiler.dat");
               cout<<"\n Taksi Silindi"<<endl;
    }
    else
    {
               remove("Yedek.dat");
               cout<<"\n Kayit Bulunamadi"<<endl;                  
    }
	
}

void TaksiDuzenle()
{
	 char plaka1[80];
     char secim= ' ';
     bool var=false;
     
    ifstream oku("taksiler.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);

	int kayitsayisi=oku.tellg()/sizeof(taksi);
		
     cout<<"Kaydini Duzelteceginiz No Giriniz : ";
     cin>>plaka1;

     for(int i=0;i<kayitsayisi;i++)
     {
            oku.seekg(i*sizeof(taksi));
			oku.read((char*)&taksi, sizeof(taksi));
			
     		if(strcmp(taksi.plaka,plaka1)==0)
     		  {
     		  	
                 cout<<endl;
                 cout<<"Taksicinin";
                 cout<<"\nAdi : "<<taksi.ad;
                 cout<<"\nSoyad : "<<taksi.soyad<<endl;
                 cout<<"\nPlakasi : "<<taksi.plaka;
                 cout<<"\nCinsiyet [E/K]: ";
                 if(taksi.cinsiyet=='e'||taksi.cinsiyet=='E')
                 cout<<"Erkek";
                 if(taksi.cinsiyet=='k'||taksi.cinsiyet=='K')
                 cout<<"Bayan";
                 
                  cout<<"\n\nDuzeltmek Istediginiz Kayit Bu Mu? [E/H] : ";
                  secim=getche();
                  if(secim == 'E' || secim == 'e')
                  {
                     	var=true;
                        ofstream dosya("Yedek.dat",ios::app|ios::binary);
                        cout << "\nTaksicinin Ad Giriniz" << endl;
						cin>> taksi.ad;
						cout << "Taksicinin Soyad Giriniz" << endl;
						cin>> taksi.soyad;
						cout << "Taksicinin Plakasını Giriniz" << endl;
						cin>> taksi.plaka;
						cout << "Ogrenci Cinsiyet Giriniz (E/K)" << endl;
						taksi.cinsiyet=getche();
						cout << endl;
		  
                        dosya.write((char*)&taksi, sizeof(taksi));
                        dosya.close();
            	  }
            	 else
                 	{
                         Taksiler y_taksi;
                         ofstream y_dosya;
                         y_dosya.open("Yedek.dat",ios::app|ios::binary);
                         
                    	 strcpy(y_taksi.ad,taksi.ad);
            			 strcpy(y_taksi.soyad,taksi.soyad);
            			 strcpy(y_taksi.plaka,taksi.plaka);
             			y_taksi.cinsiyet=taksi.cinsiyet;
                         
             			 y_dosya.write((char*)&y_taksi, sizeof(y_taksi));
                         y_dosya.close();
                   }
     }
 }
    oku.close();
    if(var)
    {
               remove("Taksiler.dat");
               rename("Yedek.dat","taksiler.dat");
               cout<<"\nKayit Duzeltildi."<<endl;
    }
    else
    {
               remove("Yedek.dat");
               cout<<"\nKayit Bulunamadi"<<endl;                  
    }

}

