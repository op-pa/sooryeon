/* 10844- DP
쉬운 계단 수 풀이
문제집 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	13601	4250	3155	29.919%
문제
45656이란 수를 보자.

이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.

세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.

N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)

입력
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

출력
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.

예제 입력  복사
1
예제 출력  복사
9
예제 입력 2  복사
2
예제 출력 2  복사
17

*/

/*
 점화식 = DP(n,i)	= DP(n-1,i+1) (i= 0)
 				  	DP(n-1,i-1) (i=9)
				  	DP(n-1,i-1)+DP(n-1,i+1)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int arr[101][10];

void solve(int N)
{
	for(int i=1;i<10;i++)
		arr[1][i]=1;
	
	arr[2][0]= arr[2][1] = arr[2][9] = 1;
	
	for(int i=2;i<9;i++)
		arr[2][i]=2;

	for(int i=3;i<=100;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(j>0 && j<9)
				arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1]) % 1000000000;
			else if(j==0)
				arr[i][j] = arr[i-1][j+1] % 1000000000;
			else if(j==9)
				arr[i][j] = arr[i-1][j-1] % 1000000000;

		}
	}
}

int main()
{
	int N=0;
	
	cin >> N;
	
	solve(N);
	
	int ans=0;
	
	for(int i=0;i<10;i++)
		ans = (arr[N][i] + ans) % 1000000000;
		
	cout << ans << endl;
	
	return 0;
}