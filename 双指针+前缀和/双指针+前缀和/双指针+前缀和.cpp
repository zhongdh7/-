#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<map>
using namespace std;



//寻找最大无相同连续数字的最大连续子序列长度
//双指针

//const int N = 100010;
//int n;
//int q[N];
//int s[N] = {};
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", q + i);
//	}
//	sort(q + 1, q + n + 1);
//	for (int i = 1; i <= n; i++)
//	{
//		cout << q[i] << ' ';
//	}
//	cout << endl;
//	int res = 1;
//	for (int i = 1, j = 1; i <= n; i++)
//	{
//		s[q[i]]++;
//		while (s[q[i]] > 1)
//		{
//			s[q[j]]--;
//			j++;
//		}
//		res = max(res, i - j + 1);
//	}
//	cout << res << endl;
//	
//
//	/*int begin = clock();
//	long long res = 0;
//	for (long long i = 0; i <= 1e9; i++)
//	{
//		res++;
//	}
//	int end = clock();
//	cout << (double)(end - begin) / 1000.0 << endl;*/
//	return 0;
//}

//前缀和


//一维前缀和

//const int N = 1e6 + 10;
//int a[N];
//int f[N];
//int n, m;
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		int temp;
//		scanf("%d", &temp);
//		f[i] = f[i - 1] + temp;//计算前缀和
//
//		//使用前缀和可以快速的计算两端区间之间的数据和
//	}
//	
//	while (m--)
//	{
//		int l, r;
//		cin >> l >> r;
//		cout << f[r] - f[l] << endl;
//	}
//
//	return 0;
//}

//二维前缀和
//这里计算x1,y1,x2,y2这个范围内的数据和类似于概统计里面的计算两个范围内的公式
const int N = 1e3 + 10;
int f[N][N];

int n, m;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int temp;
			cin >> temp;
			f[i][j] = temp + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
		}
	}
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	cout << f[x2][y2] - f[x1 - 1][y2] - f[x2][y1 - 1] + f[x1 - 1][y1 - 1];

	return 0;
}