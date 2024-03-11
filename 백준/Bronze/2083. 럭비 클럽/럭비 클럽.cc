#include <bits/stdc++.h>
using namespace std;
vector<string> names;
vector<bool> classes;
int main(){
    string name;
    int age;
    int weight;
    while(true){
        cin >> name >> age >> weight;
        if(name == "#" && age == 0 && weight == 0 ) break;
        names.push_back(name);
        classes.push_back(age > 17 || weight >= 80);
    }
    
    for(int i = 0 ; i < classes.size(); i++){
        cout << names[i] << " " << (classes[i] ? "Senior" : "Junior") << "\n";
    }
}