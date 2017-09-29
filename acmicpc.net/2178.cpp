/* 2178번 문제
미로 탐색 풀이
문제집 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	24932	7647	4691	29.233%
문제
N×M크기의 배열로 표현되는 미로가 있다.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오.

위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

입력
첫째 줄에 두 정수 N, M(2≤N, M≤100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

출력
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

예제 입력  복사
4 6
101111
101010
101011
111011
예제 출력  복사
15
예제 입력 2  복사
4 6
110110
110110
111111
111101
예제 출력 2  복사
9

*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100][100];
int check[100][100];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int cnt=1;
int M,N;
struct AB{
	int a;
	int b;
};
queue<AB> Q;
bool _safe(int a,int b)
{
	return (a>=0 && a<N && b>=0 && b<M);
}

void bfs(int a,int b)
{
	Q.push({a,b});
	
	while(!Q.empty())
	{
		AB tmp = Q.front();Q.pop();
		
		for(int i=0;i<4;i++)
		{
			if(_safe(tmp.a+dx[i],tmp.b+dy[i]) && arr[tmp.a+dx[i]][tmp.b+dy[i]] !=0)
			{
				if(arr[tmp.a+dx[i]][tmp.b+dy[i]]==1)
				{
				arr[tmp.a+dx[i]][tmp.b+dy[i]]=arr[tmp.a][tmp.b]+1;
				Q.push({tmp.a+dx[i],tmp.b+dy[i]});
				}
				else
				{
					if(arr[tmp.a+dx[i]][tmp.b+dy[i]] <= arr[tmp.a][tmp.b])
						continue;
				}
			arr[a][b]=0;
			}
		}
	}
}

void solve()
{
	bfs(0,0);
	cout << arr[N-1][M-1] <<endl;
}

int main()
{
	char ch[100];
	cin >> N >> M;
for(int i=0;i<N;i++)
{
	cin >> ch;
	for(int j=0;j<M;j++)
	{
		if(ch[j]%2==0)
		{
			arr[i][j]=0;
		}
		else
			arr[i][j]=1;
	}
}

solve();
return 0;
}