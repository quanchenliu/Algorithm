#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void NextDay(int &y, int &m, int &d) {
    int dayofMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) { // leap year
        dayofMonth[2] = 29; // February has 29 days
    }
    d++;
    if (d > dayofMonth[m]) {
        m++;
        d = 1;
    }
    if (m > 12) {
        y++;
        m = 1;
    }
}

int main() {
    int year, days;
    while (scanf("%d %d", &year, &days) != EOF) {
        int month = 1, day = 1;
        days--;
        while (days > 0) {
            NextDay(year, month, day);
            days--;
            cout<<days<<endl;
        }
        ///printf("%04d-%02d-%02d\n", year, month, day);
        cout << setfill('0') << setw(4) << year << '-';
        cout << setfill('0') << setw(2) << month << '-';
        cout << setfill('0') << setw(2) << day << endl;
    }
    return 0;
}
