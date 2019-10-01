#include "FATURA.h"



void Fatura::tutarEkle(int fatura) {
    tutar += fatura;
}
void Fatura::faturaYazdir() {
    cout << "Faturaniz: " << tutar << " Turk Lirasi" << endl;
}

void Fatura::SETprivateprice(int privateprice) {
    privatePrice = privateprice;
}
int Fatura::GETprivateprice() {
    return privatePrice;
}