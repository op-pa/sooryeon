#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int arr[101][101];

int cnt=1;
int n;

struct twoval
{
	int a;
	int b;
};

bool isSafe(int a,int b)
{
	return (a >0 && a<=n && b >0 && b<=n);
}

void bfs(int a,int b)
{
	queue<twoval> Q;
	Q.push({a,b}); arr[a][b] =cnt;
	while(!Q.empty())
	{
		twoval curr = Q.front(); Q.pop();
		
		for(int i=0;i<4;i++)
		{
			if(isSafe(curr.a+dx[i],curr.b+dy[i]) && arr[curr.a+dx[i]][curr.b+dy[i]] ==1)
			{
				Q.push({curr.a+dx[i],curr.b+dy[i]});
				arr[curr.a+dx[i]][curr.b+dy[i]] = cnt;
			}
				
		}
		
	}
}

void solve()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(arr[i][j]==1){cnt++;
				bfs(i,j);}
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin >> arr[i][j];
	
	solve();
	cout << cnt <<endl;
		cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout << arr[i][j];
	cout <<endl;}
	
}