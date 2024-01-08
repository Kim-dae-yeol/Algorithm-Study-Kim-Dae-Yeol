
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<vector>

using namespace std;

vector<int> inorder;
vector<int> postorder;
int n;

void preorder(vector<int>::iterator inBegin,
    vector<int>::iterator inEnd,
    vector<int>::iterator postBegin,
    vector<int>::iterator postEnd){
    if(inBegin == inEnd || postBegin == postEnd){ 
        return;
    }
    
    int root = *(postEnd - 1);
    cout << root << " ";
    
    auto itPost = postBegin;
    int offset = 0;
    
    for(auto itIn = inBegin; itIn < inEnd; itIn++){
        if(*itIn == root){
            preorder(inBegin,  itIn, postBegin, postBegin + offset); //left
            preorder(itIn + 1, inEnd, postBegin + offset, postEnd - 1); // right
            break;
        }
        offset++;
    }
    
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++){
        int num;
        cin >> num;
        inorder.push_back(num);
    }
    
    for(int i = 0; i < n; i ++){
        int num;
        cin >> num;
        postorder.push_back(num);
    }
    
    preorder(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
}
