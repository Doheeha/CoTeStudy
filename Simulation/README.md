# 정의
## Simulation 
> 알고리즘을 풀 때 모든 과정이 제시되어, 그 과정을 거쳐 나온 결과를 추론하는 문제

<br>

### 쉽게 푸는 방법
> 1. 많이 풀어보기
> 2. 다른 사람 코드 찾아보기
> 3. 문제 순서 이해하기
> 4. [JAVA 코딩 Tip!](https://myeongmy.tistory.com/9)

<br>

### 상하좌우 문제

![image](https://user-images.githubusercontent.com/45910064/128274228-5299a43f-eed3-4c5d-a7e0-4786abefe095.png)
![image](https://user-images.githubusercontent.com/45910064/128274249-cdf183ee-2b37-4aa7-9e9e-843dc1887029.png)

> 도히 풀이

```{.python3}
N = int(input())
way = list(input().split())

row, col = 1, 1

for go in way:
 
  if go == 'L':
    if col != 1:
      col -= 1
     
  elif go == 'R':
    if col != n:
      col += 1

  elif go == 'U':
    if row != 1:
      row -= 1

  elif go == 'D':
    if row != n:
      row += 1

print(row, col)
```

> 책 기준 풀이

```{.python3}
#N 입력 받기
n = int(input())
x, y = 1, 1
plans = input(),split()

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
move_types = ['L', 'R', 'U', 'D']

# 이동 계획을 하나씩 확인하기
for plan in plans:
  # 이동 후 좌표 구하기
  for i in range(len(move_types)):
    nx = x + dx[i]
    ny = y + dy[i]
  
  # 공간을 벗어나는 경우 무시
  if nx < 1 or ny < 1 or nx > n or ny > n:
    continue
  x, y = nx, ny

print(x, y)
```

<br>

### 풀어보면 도움이 될 문제들
#### [백준 20058번 마법사 상어와 파이어스톰](https://www.acmicpc.net/problem/20058)
> ![image](https://user-images.githubusercontent.com/45910064/128275072-a465e2db-d9af-4702-89a0-fa2ee862f2b6.png)
>
#### [백준 1182번 부분 수열의 합](https://www.acmicpc.net/problem/1182)
>![image](https://user-images.githubusercontent.com/45910064/128275084-84bc43fd-91cc-4447-9fcf-610e6576333e.png)
>
#### [백준 3190번 뱀](https://www.acmicpc.net/problem/3190)
> ![image](https://user-images.githubusercontent.com/45910064/128275101-4e572a9d-091d-4539-a067-ec2367863f54.png)

<br>

> 골드 문제

https://www.acmicpc.net/problem/14503 

https://www.acmicpc.net/problem/14890 

https://www.acmicpc.net/problem/12100

> 실버 문제

https://www.acmicpc.net/problem/2947

https://www.acmicpc.net/problem/1244

https://www.acmicpc.net/problem/1331

<br>

### 알고리즘 풀이가 어려울 때

[시뮬레이션이 이해가 안됩니다...](https://blog.encrypted.gg/948)

[카카오코테 나도 한다](https://tech.kakao.com/2021/02/16/2021-kakao-recruitment-round-2/)

[알고리즘 정복하자!](https://myeongmy.tistory.com/55)
