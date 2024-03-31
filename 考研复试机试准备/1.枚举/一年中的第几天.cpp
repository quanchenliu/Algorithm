// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/3/26
// @Function	: year\month\day

#include <iostream>
#include <vector>
using namespace std;
void NextDay(int &year,int &month,int &day){
    int dayofMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool isleap = false;

    if(year % 400 ==0 || (year % 4 == 0 && year % 100 != 0)){           // whether is leap
        isleap = true;
    }
    if(isleap){                                     
        dayofMonth[2] = 29;                                             // leap's Feb is 29 days
    }
    
    day++;
    if(day > dayofMonth[month]){
        month++;
        day = 1;
    }
    if(month > 12){
        year++;
        month = 1;
    }
}
int main(){
    int year, month, day;
    while(scanf("%d %d %d", &year, &month, &day) != EOF){  
        int days = 1;
        int curmonth = 1, curday = 1;  
        while(1){
            if(curmonth == month && curday == day){
                break;
            }
            NextDay(year, curmonth, curday);
            days++;
        }
        cout<<days<<endl;
    }
    return 0;   
}