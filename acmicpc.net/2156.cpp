/* 2156
포도주 시식 풀이
문제집 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	14273	5072	3687	34.410%
문제
효주는 포도주 시식회에 갔다. 그 곳에 갔더니, 테이블 위에 다양한 포도주가 들어있는 포도주 잔이 일렬로 놓여 있었다. 효주는 포도주 시식을 하려고 하는데, 여기에는 다음과 같은 두 가지 규칙이 있다.

포도주 잔을 선택하면 그 잔에 들어있는 포도주는 모두 마셔야 하고, 마신 후에는 원래 위치에 다시 놓아야 한다.
연속으로 놓여 있는 3잔을 모두 마실 수는 없다.
효주는 될 수 있는 대로 많은 양의 포도주를 맛보기 위해서 어떤 포도주 잔을 선택해야 할지 고민하고 있다. 1부터 n까지의 번호가 붙어 있는 n개의 포도주 잔이 순서대로 테이블 위에 놓여 있고, 각 포도주 잔에 들어있는 포도주의 양이 주어졌을 때, 효주를 도와 가장 많은 양의 포도주를 마실 수 있도록 하는 프로그램을 작성하시오. 

예를 들어 6개의 포도주 잔이 있고, 각각의 잔에 순서대로 6, 10, 13, 9, 8, 1 만큼의 포도주가 들어 있을 때, 첫 번째, 두 번째, 네 번째, 다섯 번째 포도주 잔을 선택하면 총 포도주 양이 33으로 최대로 마실 수 있다.

입력
첫째 줄에 포도주 잔의 개수 n이 주어진다. (1≤n≤10,000) 둘째 줄부터 n+1번째 줄까지 포도주 잔에 들어있는 포도주의 양이 순서대로 주어진다. 포도주의 양은 1,000 이하의 정수이다.

출력
첫째 줄에 최대로 마실 수 있는 포도주의 양을 출력한다.

예제 입력  복사
6
6
10
13
9
8
1
예제 출력  복사
33
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int wine[10000];
int maxWine[10000];

int is_max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

void solve(int n)
{
	maxWine[0]=wine[0];
	maxWine[1]=(maxWine[0]+wine[1]);
	maxWine[2]= is_max(is_max(maxWine[1],wine[0]+wine[2]),wine[1]+wine[2]);
	for(int i=3;i<n;i++)
	{
		maxWine[i] = is_max(is_max(maxWine[i-3]+wine[i-1]+wine[i],maxWine[i-2]+wine[i]),maxWine[i-1]);
	}
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> wine[i];
	}
	solve(n);
	cout << maxWine[n-1]<<endl;
}