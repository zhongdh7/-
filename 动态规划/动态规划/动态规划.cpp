#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<ctime>
using namespace std;
typedef long long ll;
//台阶问题的DP方法


//const int N = 100000;
//int n;
//ll mem[N];//存储一下已经算好了的一个递归搜索出来的数据
////这样就可以不会重复多次调用相同的递归了
//ll dfs(int x)
//{
//	if (mem[x])return mem[x];
//	if (x == 1)return 1;
//	if (x == 2)return 2;
//	mem[x] = dfs(x - 1) + dfs(x - 2);
//	return mem[x];
//}
//
//int main()
//{
//	cin >> n;
//	memset(mem, 0, sizeof(mem));
//	double first = clock();
//	ll res = dfs(n);
//	double end = clock();
//	cout << res << endl;
//	cout << (end - first)/1000.0 << endl;
//	return 0;
//}

//递推跳台阶


//const int N = 100;
//int n;
//int f[N];
//int main()
//{
//	cin >> n;
//	f[1] = 1, f[2] = 2;
//	for (int i = 3; i <= n; i++)
//	{
//		f[i] = f[i - 1] + f[i - 2];//就是把dfs的一比一的抄过来就好了
//	}
//	cout << f[n] << endl;
//	return 0;
//}


//记忆化搜索=dfs+记录答案
//递推的公式=dfs的向下递推的公式
//地推数组的初始值=递归的边界值



//P1216 [IOI 1994 / USACO1.5] 数字三角形 Number Triangles


//普通dfs版本

//const int N = 1000 + 10;
//int a[N][N];
//int st[N];//0的时候向左，1向右
//int n;
//vector<int>result;
//bool cmp(int x, int y)
//{
//	return x > y;
//}
//void dfs(int x)
//{
//	if (x > n)
//	{
//		int temp = 0;
//		int j = 1;
//		for (int i = 1; i <= n; i++)
//		{
//			j += st[i];
//			temp += a[i][j];
//		}
//		result.push_back(temp);
//		return;
//	}
//	st[x] = 0;
//	dfs(x + 1);
//
//	st[x] = 1;
//	dfs(x + 1);
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			cin >> a[i][j];
//		}
//	}
//	dfs(1);
//	sort(result.begin(), result.end(), cmp);
//	cout << result[0] << endl;
//	return 0;
//}

//dp版本

//const int N = 1010;
//int g[N][N];
//int mem[N][N];
//int n;
//int f[N][N] = {};
//int dfs(int x1, int y1)
//{
//	if (mem[x1][y1])return mem[x1][y1];
//	int sum = 0;
//	if (x1 > n || y1 > n)return 0;
//	else sum=max(dfs(x1 + 1, y1), dfs(x1 + 1, y1 + 1)) + g[x1][y1];//这里是从最下面网上推导所以下面的递推也只能从下往上
//	mem[x1][y1] = sum;
//	return mem[x1][y1];
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			cin >> g[i][j];
//		}
//	}
//	memset(mem, 0, sizeof(mem));
//	/*int res = dfs(1, 1);
//	cout << res << endl;*/
//
//	//递推
//	for (int i = n; i >= 1; i--)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			f[i][j] = max(f[i + 1][j + 1], f[i + 1][j]) + g[i][j];
//		}
//	}
//	cout << f[1][1] << endl;
//	return 0;
//}

//2. 01背包问题

const int N = 1000 + 10;
int v[N], w[N];
int n, V;
int mem[N][N];//对应为第x个位置，然后剩余容量spV的时候的最佳方案

int dfs(int x, int spV)
{
	if (mem[x][spV])return mem[x][spV];
	if (x > n)return 0;
	if (spV < v[x])
	{
		mem[x][spV]=dfs(x + 1, spV);
	}
	else
	{
		if (spV >= v[x])
		{
			mem[x][spV]= max(dfs(x + 1, spV), dfs(x + 1, spV-v[x]) + w[x]);
		}
	}
	return mem[x][spV];
}
int f[N][N];
int main()
{
	memset(mem, 0, sizeof(mem));
	cin >> n >> V;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i] >> w[i];
	}
	int res = dfs(1, V);
	cout << res << endl;

	//递归搜索树
	for (int i = n; i >= 1; i--)
	{
		for (int j = 0; j <= V; j++)
		{
			if (j < v[i])
			{
				f[i][j] = f[i + 1][j];
			}
			else
			{
				f[i][j] = max(f[i + 1][j], f[i + 1][j - v[i]] + w[i]);
			}
		}
	}
	cout << f[1][V] << endl;
	return 0;
}