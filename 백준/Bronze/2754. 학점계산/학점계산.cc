
// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;

int main()
{
    string grade;
    cin >> grade;
    float grade_score;
    switch(grade[0]){
        case 'A':
        grade_score = 4;
        break;
        case 'B':
        grade_score = 3;
        break;
        case 'C':
        grade_score = 2;
        break;
        case 'D':
        grade_score = 1;
        break;
        default :
        grade_score = 0;
    }
    
    if(grade[1] == '+'){
        grade_score+= 0.3;
    }else if(grade[1] == '-'){
        grade_score -= 0.3;
    }
    
    cout <<fixed<<setprecision(1) << grade_score;
}
