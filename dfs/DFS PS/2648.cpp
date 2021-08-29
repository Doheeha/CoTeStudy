using namespace std;

int array[101][101];
int visit[101][101];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int N;
 
void dfs(int x, int y, int high) {
    visit[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        //0보다 작거나 N보다 크다        
        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

        //방문했 최고 높이보다 작거나 같으면
        if (visit[nx][ny] || array[nx][ny] <= high) continue;

        dfs(nx, ny, high);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int maxi = 0;
    int mini = 101;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> array[i][j];
            maxi = max(maxi, array[i][j]);
            mini = min(mini, array[i][j]);
        }
    }
    int res = 1;
    for (int i = mini; i <= maxi; i++) {
        int cnt = 0;
        memset(visit, 0, sizeof(visit));
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (!visit[x][y] && array[x][y] > i) {
                    dfs(x, y, i);
                    cnt++;                    
                }
            }
        }
        res = max(res, cnt);
    }
    cout << res;
}
