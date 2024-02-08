// Online IDE - Code Editor, Compiler, Interpreter

#include <bits/stdc++.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Author : jinhan814
 * Date : 2021-05-05
 * Source : https://blog.naver.com/jinhan814/222266396476
 * Description : FastIO implementation for cin, cout.
 */
constexpr int SZ = 1 << 20;

class INPUT {
private:
	char read_buf[SZ];
	int read_idx, next_idx;
	bool __END_FLAG__, __GETLINE_FLAG__;
public:
	explicit operator bool() { return !__END_FLAG__; }
	bool IsBlank(char c) { return c == ' ' || c == '\n'; }
	bool IsEnd(char c) { return c == '\0'; }
	char _ReadChar() {
		if (read_idx == next_idx) {
			next_idx = fread(read_buf, sizeof(char), SZ, stdin);
			if (next_idx == 0) return 0;
			read_idx = 0;
		}
		return read_buf[read_idx++];
	}
	char ReadChar() {
		char ret = _ReadChar();
		for (; IsBlank(ret); ret = _ReadChar());
		return ret;
	}
	template<typename T> T ReadInt() {
		T ret = 0; char cur = _ReadChar(); bool flag = 0;
		for (; IsBlank(cur); cur = _ReadChar());
		if (cur == '-') flag = 1, cur = _ReadChar();
		for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret = 10 * ret + (cur & 15);
		if (IsEnd(cur)) __END_FLAG__ = 1;
		return flag ? -ret : ret;
	}
	string ReadString() {
		string ret; char cur = _ReadChar();
		for (; IsBlank(cur); cur = _ReadChar());
		for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
		if (IsEnd(cur)) __END_FLAG__ = 1;
		return ret;
	}
	double ReadDouble() {
		string ret = ReadString();
		return stod(ret);
	}
	string getline() {
		string ret; char cur = _ReadChar();
		for (; cur != '\n' && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
		if (__GETLINE_FLAG__) __END_FLAG__ = 1;
		if (IsEnd(cur)) __GETLINE_FLAG__ = 1;
		return ret;
	}
	friend INPUT& getline(INPUT& in, string& s) { s = in.getline(); return in; }
} _in;

class OUTPUT {
private:
	char write_buf[SZ];
	int write_idx;
public:
	~OUTPUT() { Flush(); }
	explicit operator bool() { return 1; }
	void Flush() {
		fwrite(write_buf, sizeof(char), write_idx, stdout);
		write_idx = 0;
	}
	void WriteChar(char c) {
		if (write_idx == SZ) Flush();
		write_buf[write_idx++] = c;
	}
	template<typename T> int GetSize(T n) {
		int ret = 1;
		for (n = n >= 0 ? n : -n; n >= 10; n /= 10) ret++;
		return ret;
	}
	template<typename T> void WriteInt(T n) {
		int sz = GetSize(n);
		if (write_idx + sz >= SZ) Flush();
		if (n < 0) write_buf[write_idx++] = '-', n = -n;
		for (int i = sz; i-- > 0; n /= 10) write_buf[write_idx + i] = n % 10 | 48;
		write_idx += sz;
	}
	void WriteString(string s) { for (auto& c : s) WriteChar(c); }
	void WriteDouble(double d) { WriteString(to_string(d)); }
} _out;

/* operators */
INPUT& operator>> (INPUT& in, char& i) { i = in.ReadChar(); return in; }
INPUT& operator>> (INPUT& in, string& i) { i = in.ReadString(); return in; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
INPUT& operator>> (INPUT& in, T& i) {
	if constexpr (is_floating_point_v<T>) i = in.ReadDouble();
	else if constexpr (is_integral_v<T>) i = in.ReadInt<T>(); return in; }

OUTPUT& operator<< (OUTPUT& out, char i) { out.WriteChar(i); return out; }
OUTPUT& operator<< (OUTPUT& out, string i) { out.WriteString(i); return out; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
OUTPUT& operator<< (OUTPUT& out, T i) {
	if constexpr (is_floating_point_v<T>) out.WriteDouble(i);
	else if constexpr (is_integral_v<T>) out.WriteInt<T>(i); return out; }

/* macros */
#define fastio 1
#define cin _in
#define cout _out
#define istream INPUT
#define ostream OUTPUT
/////////////////////////////////////////////////////////////////////////////////////////////
int n, m;
int map_mat[101][101];
bool vis[101][101];
bool vis_edge_q[101][101][4][6];
int par[10];
int dx[4]{0,1,0,-1};
int dy[4]{-1, 0, 1, 0};
vector<pair<int, pair <int, int>>> adj; //dist a - b (i, j)

int find(int r){
    if(par[r] == r) return r;
    return par[r] = find(par[r]); //압축 : 조상이 있으면 조상을 부모로 만듬
}

bool is_diff_group_else_union(int r, int v){
    r = find(r); v = find(v);
    
    if(r == v) return false;
    if(r < v) par[v] = r;
    else par[r] = v;
    return true;
}

void print_map(){
    cout <<"============================\n";
    for(int i = 0 ;i < n ;i ++){
        for(int j = 0 ; j < m; j++){
            cout << map_mat[i][j] <<" ";
        }
        cout << "\n";
    }
    cout <<"============================\n";
}

int main(){
    queue <pair<int, int>> q;
    vector<pair<int, int>>lands;
    cin >> n >> m;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m ;j++){
            cin >> map_mat[i][j];
            if(map_mat[i][j]){
                lands.push_back({i, j});
            }
        }
    }
    
    //1. 섬을 측정함 
    int island = 0;
    for(auto e : lands){
        if(vis[e.first][e.second]) continue;
        vis[e.first][e.second] = true;
        island++;
        map_mat[e.first][e.second] = island;
        q.push(e);
        
        while(q.empty() == false){
            auto cur = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int nx = cur.second + dx[i];
                int ny = cur.first + dy[i];
                
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(map_mat[ny][nx] == 0) continue;
                if(vis[ny][nx]) continue;
                
                map_mat[ny][nx] = island;
                vis[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
    
    // cout << "island :: " << island << "\n";
    // print_map();
    
    //2. 섬들의 부모를 자기자신으로 만듬
    for(int i = 1; i <= island;i ++){
        par[i] = i;
    }
    
    //3. 간선들을 모두 찾아서 만듬 
    //간선을 찾기 위해서 하는 과정에서 한 방향 이동 (방향), 좌표, 시작 하는 섬의 번호, 
    queue<tuple<int, int, int,int, int>> edgeQ; // position (i, j), direction, distance, islandNum
    for(auto e : lands){
        int islandNum = map_mat[e.first][e.second];
        for(int dir = 0; dir <4; dir++)
            edgeQ.push({e.first, e.second, dir, 0, islandNum});
    }
    
    while(edgeQ.empty()==false){
        auto cur = edgeQ.front(); edgeQ.pop();
        int i, j, dir, dist, islandNum;
        tie(i,j,dir,dist,islandNum) = cur;
        
        int ni = i + dy[dir];
        int nj = j + dx[dir];
        if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
        if(vis_edge_q[ni][nj][dir][islandNum]) continue;
        if(map_mat[ni][nj] == islandNum) continue;
        else if(map_mat[ni][nj]){
            //other island
            vis_edge_q[ni][nj][dir][islandNum] = true;
            
            if(dist > 1){
                adj.push_back({dist, {  map_mat[ni][nj], islandNum}});
            }
            continue;
        }
        vis_edge_q[ni][nj][dir][islandNum] = true;
        edgeQ.push({ni,nj,dir,dist + 1, islandNum});
    }
    
    // cout << "==========Adjacent list ==============\n";
    // for(auto e :adj){
    //     cout << e.second.first << ", " << e.second.second << "::" << e.first <<"\n";
    // }
    // cout << "==========Adjacent list ==============\n";
    
    //4. 간선을 찾은 후 간선들을 이용해서 최소 신장 트리를 만든다.
    //최소 신장트리 만들기 위해서 먼저 우선순위 큐를 만듬 
    //우선순위 큐에서 간선의 최소값을 찾아옴 -> minHeap 
    //간선들이 다른그룹이면 연결, 같은그룹이면 다음 간선 확인
    //모든 간선 확인 후 연결된 갯수가 n - 1이면 모든 섬이 연결됨 (트리의 연결 공식 : 간선이 n - 1)
    
    sort(adj.begin(), adj.end());
    int sum = 0;
    int cnt = 0;
    for(auto e : adj){
        int dist = e.first;
        int from = e.second.first;
        int to = e.second.second;
        if(is_diff_group_else_union(from, to)){
            // cout << from <<" connect to " << to << " - cost : "<< dist << "\n";
            cnt++;
            sum += dist;
        }
        if(cnt == island -1) break;
    }
    cout << ((cnt == island - 1) ? sum : -1);
    return 0;
}

