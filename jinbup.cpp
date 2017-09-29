#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <queue>
using namespace std;

char n20[20]="0123456789ABCDEFGH";

int f(int n,int k)
{
if(n<k) {cout << n20[n];return 0;}
 f(n/k, k), cout << n20[n%k];

}

int main()
{
	int n,k;
	cin >> n >> k;
	
	int ans = f(n,k);
	
	return 0;	
}