#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
//P2089 烤鸡

//const int N = 20;
//int n; //代表最终需要的评分 
//int arr[N] = {};//每个位置放的状态 
////int st[N]={};//表示每个调料的加入的量是多少
//int all = 0;
//int num = 0;
//vector<vector<int>>result;
//void dfs(int x)
//{
//	if (x > 10)
//	{
//		for (int i = 1; i <= 10; i++)
//		{
//			all += arr[i];
//		}
//		if (all == n)
//		{
//			result.push_back(vector<int>(arr + 1, arr + 11));
//			num++;
//		}
//		all = 0;
//		return;
//	}
//	arr[x] = 1;
//	dfs(x + 1);
//	arr[x] = 0;
//
//	arr[x] = 2;
//	dfs(x + 1);
//	arr[x] = 0;
//
//	arr[x] = 3;
//	dfs(x + 1);
//	arr[x] = 0;
//}
//int main()
//{
//	cin >> n;
//	dfs(1);
//	cout << num << endl;
//	for (auto e : result)
//	{
//		for (auto j : e)
//		{
//			cout << j << ' ';
//		}
//		cout << endl;
//	}
//	return 0;
//}

//P1088 [NOIP 2004 普及组] 火星人

//using namespace std;
//const int N = 10000 + 100;
//int hot[N] = {};//火星人手指的数目
//int n, m;
//int arr[N] = {};
//bool st[N] = {};
//int res = 0;
//void dfs(int x)
//{
//	if (res > m + 1)return;
//	if (x > n)
//	{
//		res++;
//
//		if (res == m + 1)
//		{
//			for (int i = 1; i <= n; i++)
//			{
//				cout << arr[i] << ' ';
//			}
//			return;
//		}
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		if (!res)
//		{
//			i = hot[x];//对于如果当前没有输出一个res的情况下就需要把i调整到当前的字典序的位置
//			//只要第一次输出成功了之后的代码操作就不执行这一步了相当于第一次输出的位置就调整成为了火星人给出手指的位置 
//		}
//		if (!st[i])
//		{
//			st[i] = true;
//			arr[x] = i;
//			dfs(x + 1);
//			st[i] = false;
//			arr[x] = 0;
//		}
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> hot[i];
//	}
//	dfs(1);
//
//	return 0;
//}