#include <iostream>
#include "CTime.h"

using namespace std;

int main() {
    CTime t1;
    cout << "Nhap thoi gian ban dau (Gio/Phut/Giay): ";
    cin >> t1;

    int giayThem, giayBot;

    cout << "\nPhep cong/tru so giay" << endl;

    cout << "Nhap so giay muon cong them: ";
    cin >> giayThem;
    CTime t2 = t1 + giayThem;
    cout << "Thoi gian sau khi cong " << giayThem << " giay: " << t2 << endl;

    cout << "\nNhap so giay muon tru di: ";
    cin >> giayBot;
    CTime t3 = t1 - giayBot;
    cout << "Thoi gian sau khi tru " << giayBot << " giay : " << t3 << endl;

    cout << "\nPhep tang/giam 1 giay" << endl;
    cout << "Thoi gian hien tai : " << t1 << endl;

    t1++;
    cout << "Sau khi tang 1 giay: " << t1 << endl;

    t1--;
    cout << "Sau khi giam 1 giay: " << t1 << endl;

    return 0;
}
