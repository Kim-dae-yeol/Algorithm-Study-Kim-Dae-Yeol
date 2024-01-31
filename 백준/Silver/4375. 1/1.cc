// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> v;
    while(true){
        int n;
        cin >> n;
        if(cin.eof()) break;
        // if(n <= 0) break;
        long long result = 1;
        int num;
        for(int i = 0; i < 10; i++){
            num = i * n;
            if(num % 10 == 1){
                num /= 10;
                break;
            }
        }
        
        while(num){
            // cout << "num :: "<< num << "\n";
            result++;
            for(int i = 0; i < 10; i++){
                int nxt = num + i * n;
                if(nxt % 10 == 1) {
                    // cout << nxt << " = "  << i <<" * " << n << "( " << i * n <<" )"<< " + " << num << "\n";
                    num = nxt;
                    num /= 10;
                    break;
                }
            }
        }
        v.push_back(result);
        
    }
    for(auto e : v){
        cout << e <<"\n";
    }
    return 0;
}
