/* 1260
DFS와 BFS 실패 풀이
문제집 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
5 초	128 MB	23110	7263	4342	29.590%
문제
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다.

입력
첫째 줄에 정점의 개수 N(1≤N≤1,000), 간선의 개수 M(1≤M≤10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 한 간선이 여러 번 주어질 수도 있는데, 간선이 하나만 있는 것으로 생각하면 된다. 입력으로 주어지는 간선은 양방향이다.

출력
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.

예제 입력  복사
4 5 1
1 2
1 3
1 4
2 4
3 4
예제 출력  복사
1 2 4 3
1 2 3 4
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, V;
vector<int> vecDfs;
vector<int> vecBfs;

int arr[1001][1001];
bool checkDfs[1001];
bool checkBfs[1001];

void bfs(int V)
{
	queue<int> que;
	checkBfs[V]=1;
	vecBfs.push_back(V);
	for(int i=0;i<N+1;i++)
	{
		if(arr[V][i]==1)
		{
			que.push(i);
			checkBfs[i]=1;
			vecBfs.push_back(i);
		}
	}
	while(!que.empty())
	{
		int temp = que.front();que.pop();
		for(int i=0;i<N+1;i++)
		{
			if(arr[temp][i] == 1 && checkBfs[i] ==0)
			{
				checkBfs[i] =1;
				que.push(i);
				vecBfs.push_back(i);
			}
		}
	}
}

void dfs(int V)
{
	checkDfs[V]=1;
	vecDfs.push_back(V);
	for(int i=0;i<N+1;i++)
	{
		if(arr[V][i]==1 && checkDfs[i]==0)
		{
			dfs(i);
		}
	}
}

int main()
{
	int a,b;
	
	cin >> N >> M >>V;
	
	for(int i=0;i<M;i++)
	{
		cin>> a >> b;
		arr[a][b]=1;
		arr[b][a]=1;
	}
	dfs(V);
	bfs(V);

	vector<int>::iterator iter;
	for(iter=vecDfs.begin();iter!=vecDfs.end();iter++)
		cout<< *iter <<" ";
	cout <<"\n";
	for(iter = vecBfs.begin();iter!=vecBfs.end();iter++)
		cout<< *iter <<" ";
	cout <<"\n";
	
	return 0;
}