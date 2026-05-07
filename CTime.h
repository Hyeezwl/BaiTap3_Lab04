#ifndef CTIME_H
#define CTIME_H

#include <iostream>
using namespace std;

class CTime
{
    public:
        virtual ~CTime();
        CTime(int gio = 0, int phut = 0, int giay = 0);
        //ham dua thoi gian ve dang chuan (giay va phut ko vuot 59, gio ko vuot 23
        void ChuanHoa();
        //cong, tru them mot so nguyen giay
        CTime operator+(int giay_them);
        CTime operator-(int giay_bot);

        //them bot mot giay (prefix ++t, --t)
        CTime operator++();
        CTime operator--();

        //them bot mot giay (postfix t++, t--)
        //tham so int de phan biet prefix va postfix
        CTime operator++(int);
        CTime operator--(int);

    friend istream& operator>>(istream& is, CTime& t);
    friend ostream& operator<<(ostream& os, CTime t);
    protected:

    private:
        int iGio;
        int iPhut;
        int iGiay;
};

#endif // CTIME_H
