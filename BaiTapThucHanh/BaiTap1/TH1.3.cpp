#include <iostream>
#include <iomanip>
using namespace std;

class Date {
private:
    int nYear;
    int nMonth;
    int nDay;

public:
    void Input();
    void Init(int yy, int mm, int dd);
    int IsValid();
    void NextDay(Date& next);
    void Printf();
    int DaysSinceEpoch(); 
};

void Date::Input() {
    cout << "Nhap mot ngay (yyyy/mm/dd): ";
    char temp;
    cin >> nYear >> temp >> nMonth >> temp >> nDay;

    if (!IsValid()) {
        cout << "Ngay nhap khong hop le. Vui long nhap lai.\n";
        Input();
    }
}

void Date::Init(int yy, int mm, int dd) {
    nYear = yy;
    nMonth = mm;
    nDay = dd;

    if (!IsValid()) {
        cout << "Ngay khong hop le! Khoi tao that bai." << endl;
        nYear = nMonth = nDay = 0;
    }
}

int Date::IsValid() {
    if (nYear < 1 || nMonth < 1 || nMonth > 12 || nDay < 1) return 0;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((nYear % 4 == 0 && nYear % 100 != 0) || (nYear % 400 == 0)) {
        daysInMonth[1] = 29;
    }

    if (nDay > daysInMonth[nMonth - 1]) return 0;

    return 1;
}

void Date::NextDay(Date& next) {
    next.nYear = nYear;
    next.nMonth = nMonth;
    next.nDay = nDay + 1;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((nYear % 4 == 0 && nYear % 100 != 0) || (nYear % 400 == 0)) {
        daysInMonth[1] = 29;
    }

    if (next.nDay > daysInMonth[nMonth - 1]) {
        next.nDay = 1;
        next.nMonth++;
        if (next.nMonth > 12) {
            next.nMonth = 1;
            next.nYear++;
        }
    }
}

void Date::Printf() {
    cout << "Ngay: " 
         << nYear << "/" 
         << setw(2) << setfill('0') << nMonth << "/" 
         << setw(2) << setfill('0') << nDay 
         << endl;
}

int Date::DaysSinceEpoch() {
    int days = nDay;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((nYear % 4 == 0 && nYear % 100 != 0) || (nYear % 400 == 0)) {
        daysInMonth[1] = 29;
    }

    for (int i = 0; i < nMonth - 1; ++i) {
        days += daysInMonth[i];
    }

    days += (nYear - 1) * 365;
    days += (nYear - 1) / 4 - (nYear - 1) / 100 + (nYear - 1) / 400; // S? nam nhu?n

    return days;
}

int main() {
    Date date1, date2;

    cout << "Nhap moc thoi gian thu nhat:\n";
    date1.Input();

    cout << "Nhap moc thoi gian thu hai:\n";
    date2.Input();

    int days1 = date1.DaysSinceEpoch();
    int days2 = date2.DaysSinceEpoch();

    cout << "So ngay giua hai moc thoi gian la: " << abs(days2 - days1) << " ngay." << endl;

    return 0;
}
