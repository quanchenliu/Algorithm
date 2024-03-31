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
int main(){
    int m, year, month, day, acc_num;
    cin>>m;
    for(int i=0;i<m;i++){
        while(scanf("%d %d %d %d", &year, &month, &day, &acc_num) != EOF){
            int acc_days = 0;
            while(1){
                if(acc_days == acc_num){
                    break;
                }
                NextDay(year, month, day);
                acc_days++;
            }
            cout<<setfill('0')<<setw(4)<<year<<'-';
            cout<<setfill('0')<<setw(2)<<month<<'-';
            cout<<setfill('0')<<setw(2)<<day<<endl;
        }
    }
    return 0;
}