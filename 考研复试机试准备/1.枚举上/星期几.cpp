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
void DatetoSevenday(int days){
    int num = days % 7;
    switch(num){
        case 0: cout<<"Sunday"<<endl;break;
        case 1: cout<<"Monday"<<endl;break;
        case 2: cout<<"Tuesday"<<endl;break;
        case 3: cout<<"Wednesday"<<endl;break;
        case 4: cout<<"Thursday"<<endl;break;
        case 5: cout<<"Friday"<<endl;break;
        case 6: cout<<"Saturday"<<endl;break;
        case 7: cout<<"Sunday"<<endl;break;
        default: break;
    }
}
int main() {
    int year = 2014;
    int month, day;     // 4 <= month <=12, 1 <= day <= 31
    while(scanf("%d %d", &month, &day) != EOF){
        int curmonth=1, curday=1, days=1;
        while(1){
            if(curmonth == month && curday == day){
                break;
            }
            NextDay(year, curmonth,curday);
            days++;
        }
        DatetoSevenday(days);
    }
    return 0;
}
