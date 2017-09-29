/* 1010
다리 놓기 풀이
문제집 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	10241	4134	3396	43.069%
문제
재원이는 한 도시의 시장이 되었다. 이 도시에는 도시를 동쪽과 서쪽으로 나누는 큰 강이 흐르고 있다. 하지만 재원이는 다리가 없어서 시민들이 강을 건너는데 큰 불편을 겪고 있음을 알고 다리를 짓기로 결심하였다. 강 주변에서 다리를 짓기에 적합한 곳을 사이트라고 한다. 재원이는 강 주변을 면밀히 조사해 본 결과 강의 서쪽에는 N개의 사이트가 있고 동쪽에는 M개의 사이트가 있다는 것을 알았다. (N ≤ M)

재원이는 서쪽의 사이트와 동쪽의 사이트를 다리로 연결하려고 한다. (이때 한 사이트에는 최대 한 개의 다리만 연결될 수 있다.) 재원이는 다리를 최대한 많이 지으려고 하기 때문에 서쪽의 사이트 개수만큼 (N개) 다리를 지으려고 한다. 다리끼리는 서로 겹쳐질 수 없다고 할 때 다리를 지을 수 있는 경우의 수를 구하는 프로그램을 작성하라.


입력
입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다. 그 다음 줄부터 각각의 테스트케이스에 대해 강의 서쪽과 동쪽에 있는 사이트의 개수 정수 N, M (0 < N ≤ M < 30)이 주어진다.

출력
각 테스트 케이스에 대해 주어진 조건하에 다리를 지을 수 있는 경우의 수를 출력한다.

예제 입력  복사
3
2 2
1 5
13 29
예제 출력  복사
1
5
67863915
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int bridge[31][31];

int is_max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

void preprocess(int n,int m)
{	
	for(int i=1;i<=30;i++)
	{
		bridge[1][i] = i;
	}
	
	for(int i=1;i<=30;i++)
		for(int j=1;j<=30;j++)
		{
			if(i==j)
			{
				bridge[i][j]=1;
			}
		}
	
	for(int i=2;i<=30;i++)
		for(int j=1;j<=30;j++)
		{
			if(j>i)
			{
				bridge[i][j]= bridge[i-1][j-1] + bridge[i][j-1];
			}
		}

}
void solve(int n,int m)
{
		cout << bridge[n][m] <<endl;
}
int main()
{
	int T,n,m;
	cin >> T;
	preprocess(30,30);
	for(int i=0;i<T;i++)
	{
	cin >> n >> m;
	solve(n,m);
	}
	
	return 0;
}
