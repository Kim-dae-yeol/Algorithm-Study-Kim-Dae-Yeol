#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#define endl "\n"
using namespace std; 
int N, M, P;
int Move_Area[10];
int Count_Area[10];
bool Flag[10];
char MAP[1001][1001];
queue<pair<pair<int, int>, int>> Q[10]; 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
void print(){
    cout <<"====="<<endl;
    for(int i = 0; i < N;i++){
        for(int j = 0 ; j < M; j ++){
            cout << MAP[i][j];
        }
        
        cout <<"\n";
    }
    cout <<"====="<<endl;
}
void Input(){
    cin >> N >> M >> P;	
    for (int i = 1; i <= P; i++) 
        cin >> Move_Area[i];
    for (int i = 0; i < N; i++)	{
        for (int j = 0; j < M; j++){
            cin >> MAP[i][j];
            if ('1' <= MAP[i][j] && MAP[i][j] <= '9'){
                int pn = MAP[i][j] - '0';
                Q[pn].push(make_pair(make_pair(i, j), Move_Area[pn]));	
                Count_Area[pn]++;
            }
        }
    }	
    fill(Flag, Flag+P + 1,true);
}

bool BFS(int Idx){
    bool ret = false;
    queue<pair<pair<int, int>, int>> curQ = Q[Idx];
    while (curQ.empty() == false)	{
        auto cur = curQ.front(); curQ.pop();
        auto pos = cur.first;
        int x = pos.first;	
        int y = pos.second;
        int cnt = cur.second;
        
        if (cnt == Move_Area[Idx]) Q[Idx].pop();
        if(cnt == 0) break;
        
        for (int i = 0; i < 4; i++)	{
            int nx = x + dx[i];			
            int ny = y + dy[i];		
            int nCnt = cnt; 		
            if (nx >= 0 && ny >= 0 && nx < N && ny < M){	
                if (MAP[nx][ny] == '.'){
                    MAP[nx][ny] = Idx + '0';
                    Count_Area[Idx]++;	
                    Q[Idx].push(make_pair(make_pair(nx, ny), Move_Area[Idx]));
                    curQ.push(make_pair(make_pair(nx, ny), nCnt - 1));	
                    ret = true;
                }			
            }		
            
        }	
        
    }	
    return ret;
    
} 
bool Check(){	
    for (int i = 1; i <= P; i++)	{
        if (Flag[i] == true) return true;
    }	
    return false;
    
} 

void Solution(){
    while (1)	{
        for (int i = 1; i <= P; i++)		{
            if (Flag[i] == false) continue;	
            bool canMove = BFS(i);
            if (canMove == false) Flag[i] = false;
        }
        if (Check() == false) break;
    }
    
    for (int i = 1; i <= P; i++){
        cout << Count_Area[i] << " ";
    }
    cout << endl;
    
} 
void Solve(){	
    Input();
    Solution();
    
}
int main(void){	
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    //freopen("Input.txt", "r", stdin);	
    Solve(); 	
    return 0;
}
