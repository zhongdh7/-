#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
#include<cstring>
using namespace std;

//迷宫问题找出口的最短路线

//const int N = 110;
//char arr[N][N];//记录地图
//int dist[N][N];//存每个点到起点的距离
//typedef pair<int, int>PII;//存储坐标
//int l, r;
//PII xy[4];
//queue<PII>q;//队列存储坐标
//
//int bfs(int x1, int y1)
//{
//	memset(dist, -1, sizeof(dist));//就说明这个点无法到起点都初始化为-1
//	q.push({ x1,y1 });//让一个坐标入列
//	dist[x1][y1] = 1;//把起点入队，起点到自己肯定是0
//
//	while (!q.empty())//如果队列不空
//	{
//		auto t = q.front();//取出队列头
//		q.pop();
//		for (int i = 0; i < 4; i++)
//		{
//			int a = t.first + xy[i].first, b = t.second + xy[i].second;
//			
//			if (a<1 || a>l || b<1 || b>r)continue;//跃出地图边界
//			if (arr[a][b] != '.')continue;
//			if (dist[a][b] > 0)continue;
//			q.push(make_pair(a, b));//如果a,b通过了上面的考验那么就加入队列
//			dist[a][b] = dist[t.first][t.second] + 1;
//		}
//	}
//	return dist[l][r];
//}
//int main()
//{
//	cin >> l >> r;
//	xy[0] = make_pair(-1, 0);//第一个位置代表向上平移
//	xy[1] = make_pair(0, 1);//这个代表向右平移
//	xy[2] = make_pair(1, 0);//这个代表向下平移
//	xy[3] = make_pair(0, -1);//这个代表向左平移
//	for (int i = 1; i <= l; i++)
//	{
//		for (int j = 1; j <= r; j++)
//		{
//			cin >> arr[i][j];
//		}
//	}
//	int res=bfs(1, 1);//开始的参数，开始的坐标
//	cout << res << endl;
//	return 0;
//}

//存粹的BFS

//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//// 使用邻接表存储图
//vector<vector<int>> adj;
//
//// BFS 函数，从起点 start 开始遍历
//void bfs(int start) {
//    int n = adj.size();               // 顶点个数
//    vector<bool> visited(n, false);  // 标记是否访问过
//    queue<int> q;                    // BFS 队列
//
//    visited[start] = true;
//    q.push(start);
//
//    cout << "BFS traversal order: ";
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        cout << u << " ";            // 访问当前节点
//
//        // 遍历所有邻接点
//        for (int v : adj[u]) {
//            if (!visited[v]) {
//                visited[v] = true;
//                q.push(v);
//            }
//        }
//    }
//    cout << endl;
//}
//
//int main() {
//    int n, m; // n 个顶点，m 条边
//    cout << "Enter number of vertices and edges: ";
//    cin >> n >> m;
//
//    adj.resize(n);
//
//    cout << "Enter edges (u v):" << endl;
//    for (int i = 0; i < m; ++i) {
//        int u, v;
//        cin >> u >> v;
//        adj[u].push_back(v);
//        adj[v].push_back(u); // 无向图，双向添加
//    }
//
//    int start;
//    cout << "Enter start vertex: ";
//    cin >> start;
//
//    bfs(start);
//
//    return 0;
//}

//马的遍历

const int N = 1000;
int g[N][N] = {};//存储地图
typedef pair<int, int>PII;
PII dxy[8];
int main()
{
	dxy[0] = make_pair(1, 2);//向下1格向右两格
	dxy[1] = make_pair(1, -2);//向下1格向左两个
	dxy[2] = make_pair(-1, 2);//向上1格向右两格
	dxy[3] = make_pair(-1, -2);//向上1格向左两格
	dxy[4] = make_pair(2, 1);//向下2格向右1格
	dxy[5] = make_pair(2, -1);//向下2格向左1格
	dxy[6] = make_pair(-2, 1);//向上2格向右1格
	dxy[7] = make_pair(-2, -1);//向上2格向左1格
	return 0;
}