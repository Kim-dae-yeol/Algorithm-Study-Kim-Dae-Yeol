
// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    float sum = 0;
    int sum_credit = 0;
    while(n--){
        string sub;
        int credit;
        string grade;
        cin >> sub >> credit >> grade;
        sum_credit += credit;
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
        
        sum += grade_score * credit;
    }
    
    float result = sum / (float)sum_credit;
    // cout << sum << "\n";
    cout <<fixed << setprecision(2) << result;
    return 0;
}
