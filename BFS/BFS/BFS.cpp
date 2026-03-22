#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
const int N = 110;
char arr[N][N];//记录地图
int dist[N][N];//距离
typedef pair<int, int>PII;
int l, r;
int dx[3] = { -1,0,1 };//代表列方向上的向量数组
int dy[3] = { -1,0,1 };//代表行方向上的向量数组
queue<PII>q;//队列存储坐标
int bfs(int x, int y)
{
	return 0;
}
int main()
{
	cin >> l >> r;
	for (int i = 1; i <= l; i++)
	{
		for (int j = 1; j <= r; j++)
		{
			cin >> arr[i][j];
		}
	}
	bfs(1, 1);//开始的参数，开始的坐标
	return 0;
}