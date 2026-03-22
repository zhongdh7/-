#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
//跳台阶

//int stage(int x)
//{
//    if (x == 1)return 1;
//    if (x == 2)return 2;
//    else return stage(x - 1) + stage(x - 2);
//}
//int main()
//{
//    int n;
//    cin >> n;
//    cout << stage(n) << endl;
//    return 0;
//}

//递归实现指数级枚举
//类似集合找子集
//DFS搜索

//const int N = 200;
//int n;
//int st[N];//状态0是还没考虑，1表示选择这个数，2表示不选择这个数
//void dfs(int x)//表示现在枚举到了哪个位置
//{
//	//枚举到最后一个之后再输出
//	if (x > n)
//	{
//		for (int i = 1; i < x; i++)
//		{
//			if (st[i] == 1)printf("%d ", i);
//		}
//		cout << endl;
//		return;
//	}
//	
//	//选这个
//	st[x] = 1;//先选第一个位置
//	dfs(x + 1);//看看下一个位置
//	st[x] = 0;//恢复原来的状态
//
//	//不选
//	st[x] = 2;
//	dfs(x + 1);
//	st[x] = 0;
//}
//int main()
//{
//	scanf("%d", &n);
//	dfs(1);
//	return 0;
//}

//递归实现全排列问题

//const int N = 100;
//bool st[N] = {};//true表示选过，false表示没有选
//int arr[N];//存储的是答案
//int n;
//void dfs(int x)//以第x个位置为根向下枚举
//{
//	if (x > n)
//	{
//		for (int i = 1; i < x; i++)
//		{
//			printf("%5d", arr[i]);
//		}
//		cout << endl;
//		return;
//	}
//	//对于这个位置的这个数据进行一次枚举，让所有的数据都可能在这个位置排上
//	for (int i = 1; i <= n; i++)
//	{
//		if (!st[i])//如果没有选过则选择
//		{
//			//选择这个数据
//			st[i] = true;
//			arr[x] = i;
//			dfs(x + 1);
//			//选择的分支走完了之后走没有选择的分支
//			st[i] = false;
//			arr[x] = 0;
//		}
//	}
//
//
//}
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	scanf("%d",&n);
//	dfs(1);
//	return 0;
//}

//递归实现n个数r次排列的问题

//#include<iostream>
//#include<cstdio>
//using namespace std;
//const int N = 100;
//bool st[N] = {};//这个用于记录每一个数据是否用于排列的判断
//int arr[N] = {};//用于存放每个数据
//int n, r;//一共n个树蕨，进行r次排列
//int all = 0;
//void dfs(int x)//x代表这个树的深度 
//{
//	if (x > r)
//	{
//		for (int i = 1; i <= r; i++)
//		{
//			printf("%3d", arr[i]);
//		}
//		cout << endl;
//		all++;
//		return;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (!st[i])//这个的状态如果没有被选择
//		{
//			st[i] = true;
//			arr[x] = i;
//			dfs(x + 1);//往下遍历
//			st[i] = false;
//			arr[x] = 0;
//		}
//	}
//}
//int main()
//{
//	cin >> n >> r;
//	dfs(1);
//	cout << endl << endl << all;
//	return 0;
//}

//递归组合的输出

//const int N = 30;
//int n, r;//分别代表一共有多少个数和需要组合多少个数
//bool st[N] = {};//代表每个数有没有被选中false为没有被选中，true代表被选中
//int arr[N] = {};//代表一共有多少个存放数据的位置
//int all = 0;//代表目前可以输出的数据数量
//void dfs(int x,int start)//x是指树的深度，start是指目前所在的根节点
//{
//	if (x > r)
//	{
//		for (int i = 1; i <= r; i++)
//		{
//			printf("%3d", arr[i]);
//		}
//		printf("\n");
//		return;
//	}
//	for (int i = start; i <= n; i++)
//	{
//		arr[x] = i;
//		dfs(x + 1, i + 1);//这里是之枚举i+1之后的数据了，因为前面的数据已经排列过了
//		arr[x] = 0;
//	}
//}
//int main()
//{
//	cin >> n >> r;
//	dfs(1,1);
//	return 0;
//}


//选数
//需要减枝的dfs

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<ctime> 
#include<vector>
using namespace std;
const int N = 100;
int Data[N];//存放数据的容器
bool st[N] = {};//存放第i个数据状态的容器
int arr[N] = {};//最后存放组合数据的容器 
int n, r;
int all = 0;//记录为素数的数据
vector<int>result;//用这个来存储最后的组合数相加的结果
bool isprime(int x)
{
	if (x == 1)return false;
	if (x == 2)return true;
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)return false;
	}
	return true;
}
void dfs(int x, int start)
{
	if (x - 1 + (n - start) < r)return;//这一步是用来剪枝的，即从第start1位开始后面没有足够的数据可以组合出r位数据了

	if (x > r)
	{
		int temp = 0;
		for (int i = 1; i <= r; i++)
		{
			temp += arr[i];
		}
		result.push_back(temp);
		return;
	}
	for (int i = start; i <= n; i++)
	{
		if (!st[i])
		{
			st[i] = true;
			arr[x] = Data[i];
			dfs(x + 1, i);
			arr[x] = 0;
			st[i] = false;
		}
	}
}
int main()
{
	cin >> n >> r;
	for (int i = 1; i <= n; i++)
	{
		cin >> Data[i];
	}
	sort(Data + 1, Data + n + 1);
	dfs(1, 1);//分别代表数的深度和从哪个数据开始往后搜索 
	for (auto it = result.begin(); it != result.end(); it++)
	{
		if (isprime(*it))all++;
	}
	cout << all << endl;

	return 0;
}