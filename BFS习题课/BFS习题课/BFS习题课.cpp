#include<iostream>
#include<utility>
#include<queue>
#include<cstring>
using namespace std;

//P1746 离开中山路

const int N = 1000 + 90;
int g[N][N];//这个数据用于存储地图
int dist[N][N];
int n;

typedef pair<int, int> PII;
PII dxy[4];
queue<PII>q;
int bfs(int x1,int y1,int x2,int y2)
{
	memset(dist, -1, sizeof(dist));
	dist[x1][y1] = 0;
	q.push({ x1,y1 });

	while (q.size())
	{
		auto temp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int a = temp.first + dxy[i].first, b = temp.second + dxy[i].second;
			if (a<1 || a>n || b<1 || b>n)continue;
			if (dist[a][b] >= 0)continue;
			if (g[a][b] == 1)continue;
			if (a == x2 && b == y2)
			{
				dist[a][b] = dist[temp.first][temp.second] + 1;
				return dist[x2][y2];
			}
			dist[a][b] = dist[temp.first][temp.second] + 1;
			q.push({ a,b });
		}
	}
	return dist[x2][y2];
}
int main()
{
	cin >> n;
	while (getchar() != '\n');
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			char temp;
			temp = getchar();

			g[i][j] = temp - '0';
		}
		while (getchar() != '\n');

	}
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	dxy[0] = make_pair(0, 1);//向右移动一格
	dxy[1] = make_pair(1, 0);//向下
	dxy[2] = make_pair(0, -1);
	dxy[3] = make_pair(-1, 0);
	int res = bfs(x1, y1, x2, y2);
	cout << res << endl;
	return 0;
}
