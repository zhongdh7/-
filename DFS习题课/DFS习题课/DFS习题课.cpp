#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
//P2089 烤鸡

const int N = 20;
int n; //代表最终需要的评分 
int arr[N] = {};//每个位置放的状态 
//int st[N]={};//表示每个调料的加入的量是多少
int all = 0;
int num = 0;
vector<vector<int>>result;
void dfs(int x)
{
	if (x > 10)
	{
		for (int i = 1; i <= 10; i++)
		{
			all += arr[i];
		}
		if (all == n)
		{
			result.push_back(vector<int>(arr + 1, arr + 11));
			num++;
		}
		all = 0;
		return;
	}
	arr[x] = 1;
	dfs(x + 1);
	arr[x] = 0;

	arr[x] = 2;
	dfs(x + 1);
	arr[x] = 0;

	arr[x] = 3;
	dfs(x + 1);
	arr[x] = 0;
}
int main()
{
	cin >> n;
	dfs(1);
	cout << num << endl;
	for (auto e : result)
	{
		for (auto j : e)
		{
			cout << j << ' ';
		}
		cout << endl;
	}
	return 0;
}