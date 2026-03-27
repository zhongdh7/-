#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

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

const int N = 1010;
int g[N][N];
int mem[N][N];
int n;
int f[N][N] = {};
int dfs(int x1, int y1)
{
	if (mem[x1][y1])return mem[x1][y1];
	int sum = 0;
	if (x1 > n || y1 > n)return 0;
	else sum=max(dfs(x1 + 1, y1), dfs(x1 + 1, y1 + 1)) + g[x1][y1];
	mem[x1][y1] = sum;
	return mem[x1][y1];
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> g[i][j];
		}
	}
	memset(mem, 0, sizeof(mem));
	/*int res = dfs(1, 1);
	cout << res << endl;*/

	//递推
	for (int i = n; i >= 1; i--)
	{
		for (int j = 1; j <= n; j++)
		{
			f[i][j] = max(f[i + 1][j + 1], f[i + 1][j]) + g[i][j];
		}
	}
	cout << f[1][1] << endl;
	return 0;
}