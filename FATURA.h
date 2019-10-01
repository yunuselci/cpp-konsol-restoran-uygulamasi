#ifndef RESTORAN_FATURA_H
#define RESTORAN_FATURA_H
#include <iostream>
using namespace std;
class Fatura{
private:
    int privatePrice=0;
public:
    int tutar=0;
    void tutarEkle(int fatura);
    void faturaYazdir();
    void SETprivateprice(int privateprice);
    int GETprivateprice();

};

#endif
