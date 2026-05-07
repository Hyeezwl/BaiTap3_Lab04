#include "CTime.h"
#include <iostream>
using namespace std;

CTime::CTime(int gio, int phut, int giay)
{
    iGio = gio;
    iPhut = phut;
    iGiay = giay;
    ChuanHoa();
}
CTime::~CTime()
{
    //dtor
}
void CTime::ChuanHoa() {
    //truong hop giay bi am
    while (iGiay < 0) {
        iGiay = iGiay + 60;
        iPhut = iPhut - 1;
    }
    //truong hop phut bi am
    while (iPhut < 0) {
        iPhut = iPhut + 60;
        iGio = iGio - 1;
    }
    //truong hop gio bi am
    while (iGio < 0) {
        iGio = iGio + 24;
    }

    //khi giay/phut lon hon 59, gio lon hon 23
    iPhut = iPhut + (iGiay / 60);
    iGiay = iGiay % 60;

    iGio = iGio + (iPhut / 60);
    iPhut = iPhut % 60;

    iGio = iGio % 24;
}

CTime CTime::operator+(int giay_them) {
    CTime ketQua(iGio, iPhut, iGiay + giay_them);
    return ketQua;
}

CTime CTime::operator-(int giay_bot) {
    CTime ketQua(iGio, iPhut, iGiay - giay_bot);
    return ketQua;
}

//prefix ++t
CTime CTime::operator++() {
    iGiay = iGiay + 1;
    ChuanHoa();
    return *this;
}

//postfix t++
CTime CTime::operator++(int) {
    CTime tam = *this;
    iGiay = iGiay + 1;
    ChuanHoa();
    return tam;
}

//prefix --t
CTime CTime::operator--() {
    iGiay = iGiay - 1;
    ChuanHoa();
    return *this;
}

//postfix t--
CTime CTime::operator--(int) {
    CTime tam = *this;
    iGiay = iGiay - 1;
    ChuanHoa();
    return tam;
}

istream& operator>>(istream& is, CTime& t) {
    is >> t.iGio >> t.iPhut >> t.iGiay;
    t.ChuanHoa();
    return is;
}

ostream& operator<<(ostream& os, CTime t) {
    if (t.iGio < 10) os << "0";
    os << t.iGio << ":";

    if (t.iPhut < 10) os << "0";
    os << t.iPhut << ":";

    if (t.iGiay < 10) os << "0";
    os << t.iGiay;

    return os;
}
