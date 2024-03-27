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

void DateToDate(int (&a)[3], int date){
    a[0] = date/10000;
    a[1] = (date - a[0]*10000)/100;
    a[2] = date%100;
}

int main(){
    int date1, date2;
    int a[3] = {0};
    int b[3] = {0};
    while(scanf("%d %d", &date1, &date2) != EOF){
        DateToDate(a, date1);
        DateToDate(b, date2);
        int days = 1;
        while(1){
            if(a[0] == b[0] && a[1] == b[1] && a[2]==b[2]){
                break;
            }
            NextDay(a[0], a[1], a[2]);
            days++;
        }
        cout<<days<<endl;
    }
    return 0;
}