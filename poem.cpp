#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


/*
네가 나를 떠나고 하루도 빠짐없이, 하루의 끝에서 네 없는 날들을 돌아보곤 해.
그럴 때 마다 내 삶을 표현할 단어가 없었는데, 오늘 너와의 사진을 지우면서 떠오르더라. 옅다.
 삶의 색이 너무 옅다. 함께 낯선 공간에서 어색하게 손 잡고 있던 순간들의 사진들도 너무 아름다운데, 그 이유가 너였더라. 내 삶에서 
'너'라는 필터가 사라지니까, 지금의 내 삶을 보니까, 옅어.
 내 삶이 네 삶으로 가려졌을 때, 그 때가 더 아름다웠었다는 걸 조금은 늦게 알아버린 스스로에게는 하늘에서 내 삶을 흑백 필터로 덮었나보다.
 매일 잠에서 깰 때마다 가을이 다가오는 것을 너도 느끼고 있겠구나. 햇살도 우리에게 살갑게 굴었던 그 때가 미안했던지, 


 얼마만일까요. 적당히 아늑해진 밤 잠을 청하려 할 때 풀벌레 소리가 나를 재워준 때가.
 예전처럼 매일 당신의 목소리를 듣고 싶을 뿐인데, 당신이 불러주는 스티비 원더 노래에 맞춰서 잠에 들고 싶을 뿐인데.
 은색 잔에 당신의 목소리를 담아 놓고 매일 마시고 있으면 어느샌가 취해서는, 당신의 말투를 따라하곤 했었습니다. 밤공기마저 좋아 당신의 목소리 조금 더 마시고나면,  당신의 숨결이 잠시 머물다 간 듯한 착각이 들어 당신을 찾기도 했었습니다.
 그대의 품 속에서 희미하게 들려오는 새소리에 눈을 지그시 뜨면, 추억에 잠시 기댄 시간을 빌려준 누군가가 눈에 이슬 두 방울을 함께 놓고 가버렸습니다.
 부스스한 머리를 정리하고 나갈 준비를 마쳤습니다. 하늘은 여전히 맑고, 햇살은 여전히 따스합니다. 그대 목소리도 여전하겠지만, 이젠 다른이의 잔에 담겨있겠지요.
 이젠 비웠습니다. 당신이 머물던 나의 잔.
*/
/**********
algorithm_md 
DFS로 굴 갯수와 크기 찾고 내림차순 정렬하기
***********/

short int cave[101][101];
int GVn;
int Seq=1;
int v[101*101];
int temp;
int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};

bool is_Safe(int a,int b)
{
	return ( a>0 && a<=101 && b<=101 && b>0);
}

void dfs(int a,int b)
{	
	cave[a][b]=Seq;
	
	for(int i=0;i<4;i++)
		if(is_Safe(a+dx[i],b+dy[i]) && (cave[a+dx[i]][b+dy[i]] ==1))
			dfs(a+dx[i],b+dy[i]);
}

void algo()
{
	for(int i=1;i<=GVn;i++)
	{
		for(int j=1;j<=GVn;j++)
		{
			if(cave[i][j]==1)
			{
				Seq++;
				dfs(i,j);
			}
		}
	}
	for(int i=1;i<=GVn;i++)
	{
		for(int j=1;j<=GVn;j++)
		{
			if(cave[i][j])
			{
				v[cave[i][j]]++;
			}
		}
	}
	sort(v,v+Seq);
}

int main(int argc, char* argv[]) {
	
	vector<int> storeVec;
	int num;
	cin >> GVn;
	
	for(int i=1;i<=GVn;i++)
	{
		for(int j=1;j<=GVn;j++)
		{
			cin >> cave[i][j];
		}
	}
	algo();
	cout << Seq - 1 <<endl;
	for(int i=Seq;i>=2;i--)
	{
		cout << v[i] <<endl;
	}
	return 0;
}