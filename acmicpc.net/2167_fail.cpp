/* 2167
2차원 배열의 합 풀이
문제집 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	6919	3921	3155	59.472%
문제
2차원 배열이 주어졌을 때 (i, j) 위치부터 (x, y) 위치까지에 저장되어 있는 수들의 합을 구하는 프로그램을 작성하시오. 배열의 (i, j) 위치는 i행 j열을 나타낸다.

입력
첫째 줄에 배열의 크기 N, M(1≤N, M≤300)이 주어진다. 다음 N개의 줄에는 M개의 정수로 배열이 주어진다. 그 다음 줄에는 합을 구할 부분의 개수 K(1≤K≤10,000)가 주어진다. 다음 K개의 줄에는 네 개의 정수로 i, j, x, y가 주어진다(i≤x, j≤y).

출력
K개의 줄에 순서대로 배열의 합을 출력한다. 배열의 합은 32bit-int 범위를 초과하지 않는다.

예제 입력  복사
2 3
1 2 4
8 16 32
3
1 1 2 3
1 2 1 2
1 3 2 3


3 2
1 2 4
8 16 32
3
1 1 3 2
2 1 2 1
3 1 3 2
예제 출력  복사
63
2
36
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

unsigned int arr[301][301];
unsigned int sum[301][301];


void solve(int a,int b)
{
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			cin >> arr[i][j];
		
		}
	}
	
	
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
		{
			sum[i][j]=sum[i-1][j] + sum[i][j-1]+arr[i][j]-sum[i-1][j-1];
		}
}

int main()
{
	int T,n,m;
	int arrA, arrB;
	int startX,startY,endX,endY;
	
	cin >> arrA >> arrB;
	solve(arrA,arrB);
	
	cin >> T;
	
	for(int i=0;i<T;i++)
	{
		cin >> startX >> startY >> endX >> endY;
	/*	if(startX==endX && startY == endY)
		{
			cout << arr[startX][startY] <<endl;
			continue;
		}*/
		cout << sum[endX][endY] -sum[startY-1][endX] -sum[endY][startX-1] + sum[startX-1][startY-1]<<endl;
		//cout << sum[endX][endY] << " " << sum[startX][endY] <<" " << sum[endX][startY] << " " << sum[startX][startY] <<endl;
	}
		return 0;
}
