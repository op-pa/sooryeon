#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <queue>
using namespace std;

/* 2583 BFS
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	4262	2350	1930	57.134%
문제
눈금의 간격이 1인 M×N(M,N≤100)크기의 모눈종이가 있다. 이 모눈종이 위에 눈금에 맞추어 K개의 직사각형을 그릴 때, 이들 K개의 직사각형의 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어진다.

예를 들어 M=5, N=7 인 모눈종이 위에 <그림 1>과 같이 직사각형 3개를 그렸다면, 그 나머지 영역은 <그림 2>와 같이 3개의 분리된 영역으로 나누어지게 된다.



<그림 2>와 같이 분리된 세 영역의 넓이는 각각 1, 7, 13이 된다.

M, N과 K 그리고 K개의 직사각형의 좌표가 주어질 때, K개의 직사각형 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어지는지, 그리고 분리된 각 영역의 넓이가 얼마인지를 구하여 이를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 M과 N, 그리고 K가 빈칸을 사이에 두고 차례로 주어진다. M, N, K는 모두 100 이하의 자연수이다. 둘째 줄부터 K개의 줄에는 한 줄에 하나씩 직사각형의 왼쪽 아래 꼭짓점의 x, y좌표값과 오른쪽 위 꼭짓점의 x, y좌표값이 빈칸을 사이에 두고 차례로 주어진다. 모눈종이의 왼쪽 아래 꼭짓점의 좌표는 (0,0)이고, 오른쪽 위 꼭짓점의 좌표는(N,M)이다. 입력되는 K개의 직사각형들이 모눈종이 전체를 채우는 경우는 없다.

출력
첫째 줄에 분리되어 나누어지는 영역의 개수를 출력한다. 둘째 줄에는 각 영역의 넓이를 오름차순으로 정렬하여 빈칸을 사이에 두고 출력한다.

예제 입력  복사
5 7 3
0 2 4 4
1 1 2 5
4 0 6 2
예제 출력  복사
3
1 7 13
*/



int arr[100][100];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
vector<int> v;
int vv[10000];
int M,N,K;
int cnt=1;
int countt=0;

bool isSafe(int a,int b)
{
	return (a>=0&& a<N && b>=0 && b<M);
}

struct TV
{
	int a;
	int b;
};

void bfs(int a,int b)
{
	queue<TV> Q;
	Q.push({a,b});arr[a][b]=cnt;
	
	while(!Q.empty())
	{
		TV curr=Q.front();
		Q.pop();
		for(int i=0;i<4;i++)
		{
			if(isSafe(curr.a+dx[i],curr.b+dy[i]) && arr[curr.a+dx[i]][curr.b+dy[i]] ==0)
			{
			arr[curr.a+dx[i]][curr.b+dy[i]]=cnt;
			Q.push({curr.a+dx[i],curr.b+dy[i]});

			}
		}
			
	}
			for(int j=0;j<N;j++)
		{for(int k=0;k<M;k++)
			{
				cout << arr[j][k] <<" ";
			}
		 cout <<"\n";
		}
}


void solve()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(arr[i][j]==0)
			{
				cnt++;
				bfs(i,j);
			}
		}
	}

}

int main()
{
	int a,b,c,d;
	
	cin >> M >> N >> K;
	for(int i=0;i<K;i++)
	{
		cin >> a >> b >> c >> d;
		for(int j=a;j<c;j++)
			for(int k=b;k<d;k++)
			{
				arr[j][k]=1;
			}
	}
		
		for(int j=0;j<N;j++)
		{for(int k=0;k<M;k++)
			{
				cout << arr[j][k] <<" ";
			}
		 cout <<"\n";
		}
	
	solve();
	
	for(int j=0;j<N;j++)
		{
		for(int k=0;k<M;k++)
			{
				if(arr[j][k]>1)
					vv[arr[j][k]-2]++;
			}
		}
	
	sort(vv,vv+cnt-1);
	cout << cnt -1 <<endl;
	for(int i=0;i<cnt-1;i++)
		cout << vv[i] <<" ";
	return 0;
}