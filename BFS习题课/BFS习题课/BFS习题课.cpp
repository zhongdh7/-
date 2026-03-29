#include<iostream>
#include<utility>
#include<queue>
#include<cstring>
using namespace std;

//P1746 离开中山路

//const int N = 1000 + 90;
//int g[N][N];//这个数据用于存储地图
//int dist[N][N];
//int n;
//
//typedef pair<int, int> PII;
//PII dxy[4];
//queue<PII>q;
//int bfs(int x1,int y1,int x2,int y2)
//{
//	memset(dist, -1, sizeof(dist));
//	dist[x1][y1] = 0;
//	q.push({ x1,y1 });
//
//	while (q.size())
//	{
//		auto temp = q.front();
//		q.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			int a = temp.first + dxy[i].first, b = temp.second + dxy[i].second;
//			if (a<1 || a>n || b<1 || b>n)continue;
//			if (dist[a][b] >= 0)continue;
//			if (g[a][b] == 1)continue;
//			if (a == x2 && b == y2)
//			{
//				dist[a][b] = dist[temp.first][temp.second] + 1;
//				return dist[x2][y2];
//			}
//			dist[a][b] = dist[temp.first][temp.second] + 1;
//			q.push({ a,b });
//		}
//	}
//	return dist[x2][y2];
//}
//int main()
//{
//	cin >> n;
//	while (getchar() != '\n');
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			char temp;
//			temp = getchar();
//
//			g[i][j] = temp - '0';
//		}
//		while (getchar() != '\n');
//
//	}
//	int x1, y1, x2, y2;
//	cin >> x1 >> y1 >> x2 >> y2;
//	dxy[0] = make_pair(0, 1);//向右移动一格
//	dxy[1] = make_pair(1, 0);//向下
//	dxy[2] = make_pair(0, -1);
//	dxy[3] = make_pair(-1, 0);
//	int res = bfs(x1, y1, x2, y2);
//	cout << res << endl;
//	return 0;
//}


//P1644 跳马问题

//#include<iostream>
//#include<queue>
//#include<utility>
//using namespace std;
//typedef pair<int, int>PII;
//const int N = 30;
//int g[N][N] = {};
//int dx[4] = { 1,2,1,2 };
//int dy[4] = { 2,1,-2,-1 };
//int n, m;
//queue<PII>q;
//void bfs(int x1, int y1)
//{
//	g[x1][y1]++;
//	q.push({ x1,y1 });
//	while (q.size())
//	{
//		auto temp = q.front();
//		q.pop();
//		for (int i = 0; i < 4; i++)
//		{
//			int a = temp.first + dx[i], b = temp.second + dy[i];
//			if (b<0 || b>n || a > m)continue;
//			g[a][b]++;
//			q.push({ a,b });
//		}
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	bfs(0, 0);
//	cout << g[m][n] << endl;
//	return 0;
//}

//P1332 血色先锋队

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int> PII;
const int N = 1e3;
int g[N][N] = {};
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };
queue<PII>q;//源头
//vector<PII>q_l;//领主 
int n, m, a, b;
int bfs(int x, int y)
{
	while (q.size())
	{
		auto temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int a = temp.first + dx[i], b = temp.second + dy[i];
			if (a > n || b > m || a < 0 || b < 0)continue;
			if (g[a][b] >= 0)continue;
			g[a][b] = g[temp.first][temp.second] + 1;
			q.push(make_pair(a, b));
		}
	}
	return g[x][y];

}
int main()
{
	memset(g, -1, sizeof(g));
	cin >> n >> m >> a >> b;
	for (int i = 1; i <= a; i++)
	{
		int x, y;
		cin >> x >> y;
		q.push({ x,y });
		g[x][y] = 0;
	}
	for (int i = 1; i <= b; i++)
	{
		int x, y;
		cin >> x >> y;
		int res = bfs(x, y);
		cout << res << endl;
	}
	return 0;
}