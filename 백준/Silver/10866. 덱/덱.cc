
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<deque>

using namespace std;

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n;
    deque<int> d;
    string cmd;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> cmd;
        if(cmd == "push_back"){
            int num;
            cin >> num;
            d.push_back(num);
        }else if(cmd == "push_front"){
            int num;
            cin >> num;
            d.push_front(num);
        }else if(cmd == "pop_front"){
            if(d.empty()){
                cout << -1 << "\n";
            }else {
                int num = d.front();
                d.pop_front();
                cout << num << endl;
            }
        }else if(cmd == "pop_back"){
            if(d.empty()){
                cout << -1 << "\n";
            }else {
                int num = d.back();
                d.pop_back();
                cout << num << endl;
            }
        }else if(cmd == "size"){
            cout << d.size() << endl;
        }else if(cmd == "empty"){
            cout << d.empty() << endl;
        }else if(cmd == "front"){
            cout <<( d.empty() ? -1 : d.front()) << endl;
        }else if(cmd == "back"){
            cout << (d.empty() ? -1 : d.back()) << endl;
        }
    }
    return 0;
}
