#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>
 
#define MAX_SIZE 25
 
using namespace std;
 
int n;
int houses[MAX_SIZE * MAX_SIZE] = { 0, };
int houseNumber = 0;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
 
 
// 우,하,좌,상
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
 
 
// BFS
void bfs(int y, int x) {
 
    queue< pair<int, int> > q; // 이용할 큐, (x,y) -> (행, 열)
    q.push(make_pair(y, x)); // pair를 만들어서 queue에 넣습니다.
 
    // 처음 x,y를 방문 했기때문에
    visited[y][x] = true;
    houses[houseNumber]++;
 
    while (!q.empty()) {
 
        // 큐의 현재 원소를 꺼내기
        y = q.front().first;
        x = q.front().second;
        q.pop();
 
        // 해당 위치의 주변을 확인
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            // 지도를 벗어나지 않고
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                // 집이면서 방문하지 않았다면 -> 방문
                if (map[ny][nx] == 1 && visited[ny][nx] == false) {
                    visited[ny][nx] = true;
 
                    // 해당 단지의 집의 수를 증가시킴
                    houses[houseNumber]++;
 
                    // 큐에 현재 nx,ny를 추가
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
}
 
int main() {
    scanf("%d", &n);
 
    // 지도 데이터 입력
    for (int col = 0; col < n; col++) {
        for (int raw = 0; raw < n; raw++) {
            scanf("%1d", &map[col][raw]);
        }
    }
 
    // 전체의 지도 데이터를 하나하나 체크
    for (int col = 0; col < n; col++) {
        for (int raw = 0; raw < n; raw++) {
            // 집이 존재하고, 방문하지 않았을 때,
            if (map[col][raw] == 1 && visited[col][raw] == false) {
                houseNumber++;
 
                // bfs 탐색 진행
                bfs(col, raw);
            }
        }
    }
 
    // 오름차순으로 정렬
    sort(houses + 1, houses + houseNumber + 1);
 
    // 출력
    printf("%d\n", houseNumber);
    for (int i = 1; i <= houseNumber; i++) {
        printf("%d\n", houses[i]);
    }
    return 0;
}