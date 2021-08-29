#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
 
vector<int> v[10001];
int visited[10001];
int cnt;
 
void dfs(int x){
    if(visited[x]) return;
    visited[x] = true;
    cnt++;
    for(int i = 0; i < v[x].size(); i++){
        int y = v[x][i];
        dfs(y);
    }
}
 
int main(int argc, const char * argv[]) {
    int N, M;
    cin >> N >> M;
    
    int a, b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        v[b].push_back(a);
    }
    
    int depth[10001];
    for(int i = 1; i <= N; i++){
        memset(visited, 0, sizeof(visited));
        cnt = 0;
        dfs(i);
        depth[i] = cnt;
    }
    
    int max = 0;
    for(int i = 1; i <= N; i++){
        if(max < depth[i])
            max = depth[i];
    }
    
    for(int i = 0; i <= N; i++){
        if(max == depth[i])
            cout << i <<' ';
    }
        
    
    return 0;
}
 
