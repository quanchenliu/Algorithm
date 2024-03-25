// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/3/25
// @Function	: 学分绩点

#include <iostream>
#include <vector>
using namespace std;

void score_to_grade(vector<float>& grade, vector<vector<float>> score, int n){               // 将课程成绩换算成绩点
    for(int i=0;i<n;i++){
        if(score[1][i]>=90 && score[1][i]<=100){
            grade[i] = 4.0;
        }
        else if(score[1][i]>=85 && score[1][i]<=89){
            grade[i] = 3.7;
        }
        else if(score[1][i]>=82 && score[1][i]<=84){
            grade[i] = 3.3;
        }
        else if(score[1][i]>=78 && score[1][i]<=81){
            grade[i] = 3.0;
        }
        else if(score[1][i]>=75 && score[1][i]<=77){
            grade[i] = 2.7;
        }
        else if(score[1][i]>=72 && score[1][i]<=74){
            grade[i] = 2.3;
        }
        else if(score[1][i]>=68 && score[1][i]<=71){
            grade[i] = 2.0;
        }
        else if(score[1][i]>=64 && score[1][i]<=67){
            grade[i] = 1.5;
        }
        else if(score[1][i]>=60 && score[1][i]<=63){
            grade[i] = 1.0;
        }
        else{
            grade[i] = 0;
        } 
    }
}

int main(){
    int n;              
    cin>>n;                                         // 输入课程总数

    vector<vector<float>> score(3, vector<float>(n)); // 存储学分、成绩和学分绩点
    vector<float> grade(n);                         // 课程绩点

    for(int i=0;i<n;i++){
        cin>>score[0][i];                           // 输入学分
    }
    for(int i=0;i<n;i++){
        cin>>score[1][i];                           // 输入成绩
    }          
    
    // 成绩与绩点的转换
    score_to_grade(grade, score, n);
    
    for(int i=0;i<n;i++){                           // 计算每门课程的学分绩点
        score[2][i] = grade[i]*score[0][i];
    }

    float xuefen_sum = 0, jidian_sum = 0, gpa = 0;
    for(int i=0;i<n;i++){
        xuefen_sum += score[0][i];                  // 计算总学分
        jidian_sum += score[2][i];                  // 计算总绩点
    }
    gpa = jidian_sum / xuefen_sum;
    printf("%.2f\n", gpa);
    return 0;
}