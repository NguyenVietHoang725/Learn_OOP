#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Diem {
private:
    double x;
    double y;
    
public:
    void nhap();
    void xuat();
    double kc();  
    double kc(Diem d);  
    friend double kc(Diem d1, Diem d2); 
};

void Diem::nhap() {
    cout << "Nhap lan luot hoanh do (x) va tung do (y): ";
    cin >> x >> y;
}

void Diem::xuat() {
    cout << "(" << x << ", " << y << ")";
}

double Diem::kc() {
    return sqrt(pow(x, 2) + pow(y, 2));
}

double Diem::kc(Diem d) {
    return sqrt(pow(d.x - x, 2) + pow(d.y - y, 2));
}

double kc(Diem d1, Diem d2) {
    return sqrt(pow(d2.x - d1.x, 2) + pow(d2.y - d1.y, 2));
}

int main() {    
    Diem* a = new Diem[3];  
    for (int i = 0; i < 3; i++) {
        cout << "Nhap diem a[" << i << "]:\n";
        a[i].nhap();
        cout << "Diem vua nhap la: ";
        a[i].xuat();
        cout << "\n";
    }
    
    cout << fixed << setprecision(2);  
    cout << "Khoang cach tu diem a[0] den goc toa do bang: " << a[0].kc() << endl;
    cout << "Khoang cach tu diem a[0] den diem a[1] bang: " << a[0].kc(a[1]) << endl;
    cout << "Khoang cach tu diem a[1] den diem a[2] bang: " << kc(a[1], a[2]) << endl;
    
    delete[] a; 
    return 0;
}
