#include <iostream>
using namespace std;

class Rect {
private:
	int nWidth;
	int nHeight;
	
public:
	void Input();
	void Init(int w, int h);
	int Area();
	int isSquare();
};

void Rect::Input() {
	cout << "Nhap lan luot chieu dai va chieu rong: ";
	do {
		cin >> nWidth >> nHeight;
		if (nWidth <= 0 || nHeight <= 0) 
			cout << "Gia tri nhap vao phai lon hon 0. Vui long nhap lai: ";
	} while (nWidth <= 0 || nHeight <= 0);
}

void Rect::Init(int w, int h) {
	nWidth = w;
	nHeight = h;
}

int Rect::Area() {
	return nWidth * nHeight;
}

int Rect::isSquare() {
	if (nWidth == nHeight) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	Rect a, b;
	a.Init(4, 4);
	b.Input();
	cout << "Dien tich hinh chu nhat a bang " << a.Area() << endl;
	cout << "Dien tich hinh chu nhat b bang " << b.Area() << endl;	
	
	if (a.isSquare()) {
		cout << "Hinh chu nhat a la mot hinh vuong!\n";
	} else {
		cout << "Hinh chu nhat a khong phai la mot hinh vuong!\n";
	} 
	
	int n, cnt = 0, max = -1;
	cout << "Nhap so luong hinh chu nhat: ";
	cin >> n;
	
	Rect* r = new Rect[n];
	for (int i = 0; i < n; i++) {
		r[i].Input();
		if (r[i].isSquare()) {
			cnt++;
			if (r[i].Area() > max) {
				max = r[i].Area();
			}
		}
	}
	if (cnt != 0) {
		cout << "Co tat ca " << cnt << " hinh vuong trong day!\n";
		cout << "Dien tich hinh vuong lon nhat bang: " << max;
	}
}