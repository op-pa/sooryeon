#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, ans, col[10], inc[20], decc[20];

void solve(int r)
{
	if (r > n)
	{
		ans++;
		return;
	}

	for (int i = 1; i <= n;i++)
		if (!col[i] && !inc[r + i] && !decc[n + (r - i) + 1])
		{
			col[i] = inc[r + i] = decc[n + (r - i) + 1] = 1;
			solve(r + 1);
			col[i] = inc[r + i] = decc[n + (r - i) + 1] = 0;
		}
}


int main()
{
	cin >> n;
	solve(1);
	cout << ans << endl;
	
	return 0;
}