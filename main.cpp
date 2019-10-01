#include <iostream>
#include <fstream>
#include "ICECEKLER.h"
#include "YIYECEKLER.h"
#include "FATURA.h"
using namespace std;

int main() {

    string kupon,iSecim;
    int siralama=0,secim,adet=0,tutar=0;
    cout << "Kebap Salonuna Hos Geldiniz" << endl;
    Fatura fatura;
    Yiyecekler yiyecek1;
    Yiyecekler yiyecek2;
    Yiyecekler yiyecek3;
    Yiyecekler yiyecek4;
    icecekler icecek1;
    icecekler icecek2;
    icecekler icecek3;
    yiyecek1.Id = 1;
    yiyecek1.name = "Adana Kebap";
    yiyecek1.price = 16;
    yiyecek2.Id = 2;
    yiyecek2.name = "Urfa Kebap";
    yiyecek2.price = 16;
    yiyecek3.Id = 3;
    yiyecek3.name = "Ciger Durum";
    yiyecek3.price = 13;
    yiyecek4.Id = 4;
    yiyecek4.name = "Yurek Durum";
    yiyecek4.price = 12;
    icecek1.Id = 1;
    icecek1.name = "Kola";
    icecek1.price = 7;
    icecek2.Id = 2;
    icecek2.name = "Ayran";
    icecek2.price = 5;
    icecek3.Id = 3;
    icecek3.name = "Soda";
    icecek3.price = 2;
    cout << "Yiyecekleri Siralamak Icin 1 Giriniz: ";
    cin >> siralama;
    if (siralama == 1) {
        yiyecek1.Listele();
        yiyecek2.Listele();
        yiyecek3.Listele();
        yiyecek4.Listele();
    }
    else
        return 0;
    while (secim !=5) {
        cout << "Secim Yapmayi Bitirmek Icin 5 Rakamini Giriniz" << endl;
        cout << "Secim Giriniz: ";
        cin >> secim;
        if (secim == 5)
            break;
        cout << "Adet Giriniz: ";
        cin >> adet;

        switch (secim) {
            case 1:
                tutar += yiyecek1.price*adet;
                break;
            case 2:
                tutar += yiyecek2.price*adet;
                break;
            case 3:
                tutar += yiyecek3.price*adet;
                break;
            case 4:
                tutar += yiyecek4.price*adet;
                break;
            default:
                cout << "Gecersiz Secim" << endl;
        }

    }
    secim=0,adet=0;
    cout << "Icecek Ister Misiniz ? (E/H)";
    cin >> iSecim;
    if (iSecim == "E") {
        icecek1.Listele();
        icecek2.Listele();
        icecek3.Listele();
    }
        while (secim != 5) {
            cout << "Secim Yapmayi Bitirmek Icin 5 Rakamini Giriniz" << endl;
            cout << "Secim Giriniz: ";
            cin >> secim;
            if (secim == 5)
                break;
            cout << "Adet Giriniz: ";
            cin >> adet;

            switch (secim) {
                case 1:
                    tutar += icecek1.price * adet;
                    break;
                case 2:
                    tutar += icecek2.price * adet;
                    break;
                case 3:
                    tutar += icecek3.price * adet;
                    break;
                default:
                    cout << "Gecersiz Secim" << endl;
            }
        }


        fatura.tutarEkle(tutar);
    cout << "Indirim Kodunuz Varsa Giriniz: " << endl;
    cin >> kupon;
    if (kupon == "MASTER50"){
        fatura.SETprivateprice(tutar-(tutar/2));
        cout << "Odemeniz Gereken Tutar: " << tutar << " Indirimli: "<< fatura.GETprivateprice() << " TL" << endl;}
    else if (kupon == "MASTER25"){
        fatura.SETprivateprice(tutar-((tutar/2)/2));
        cout << "Odemeniz Gereken Tutar: " << tutar << " Indirimli: "<< fatura.GETprivateprice() << " TL" << endl;}
    else
    fatura.faturaYazdir();
    //***************
    ofstream dosya;
    dosya.open("deneme.txt");
    if(dosya.is_open()){
        dosya << tutar << endl;
        dosya.close();
    }
    else
        cout << "Dosya acilamadi" << endl;
    //***************
}