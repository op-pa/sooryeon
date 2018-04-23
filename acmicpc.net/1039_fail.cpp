/* 1039

교환
문제집 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	1490	175	140	17.094%
문제
0으로 시작하지 않는 정수 N이 주어진다. 이 때, M을 정수 N의 자릿수라고 했을 때, 다음과 같은 연산을 K번 수행한다.

1 ≤ i < j ≤ M인 i와 j를 고른다. 그 다음, i번 위치의 숫자와 j번 위치의 숫자를 바꾼다. 이 때, 바꾼 수가 0으로 시작하면 안된다
위의 연산을 K번 했을 때, 나올 수 있는 수의 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N과 K가 주어진다. N은 1,000,000보다 작거나 같은 자연수이고, K는 10보다 작거나 같은 자연수이다.

출력
첫째 줄에 문제에 주어진 정답을 K번 했을 때, 만들 수 있는 가장 큰 숫자를 출력한다. 만약 연산을 K번 할 수 없으면 -1을 출력한다.

예제 입력  복사
16375 1
예제 출력  복사
76315
예제 입력 2  복사
132 3
예제 출력 2  복사
312

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

#define TEN 10

int N,K;
int cant=-1;
	
void solve(int N,int K)
{
   	
}

int main()
{

	cin >> N >> K;
	if(N>9)
		solve(N,K);
	else
		cout << cant <<endl;
	
	return 0;
}