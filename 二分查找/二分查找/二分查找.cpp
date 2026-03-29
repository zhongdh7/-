#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

//举例

//bool is_blue(int x)
//{
//	return x <= 5;
//}
////只需要找到分界位置的数据情况就可以了
////返回最后一个大于等于五的数据的下标
////l要比左分界线小1，r比右分界线大1
//int check(int* a, int l,int r)
//{
//	int mid = (l + r) / 2;
//	while (l + 1 != r)//这个循环的条件都不变都是这个条件
//	{
//		if (is_blue(a[mid]))
//		{
//			l = mid;
//			mid = (l + r) / 2;
//		}
//		else
//		{
//			r = mid;
//			mid = (l + r) / 2;
//		}
//	}
//	return l;
//}
//int main()
//{
//	int a[] = { 1,4,4,5,5,5,6,7 };
//	int pos=check(a, -1, sizeof(a) / sizeof(int));//这种二分的查找写法不需要考虑加一减一的情况
//	cout << pos << endl;
//	return 0;
//}

//P2249 【深基13.例1】查找

//const int N = 1e6 + 10;
//int arr[N];
//int n, m;
//bool is_blue(int x, int key)
//{
//	return x < key;
//}
//int Find(int key)
//{
//	int l = 0, r = n + 1;
//	int mid = (l + r) / 2;
//	while (l + 1 != r)
//	{
//		if (is_blue(arr[mid], key))
//		{
//			l = mid;
//			mid = (l + r) / 2;
//		}
//		else
//		{
//			r = mid;
//			mid = (l + r) / 2;
//		}
//	}
//	return r;
//}
//int main()
//{
//	scanf("%d%d", &n, &m);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", arr + i);
//	}
//	for (int i = 0; i < m; i++)
//	{
//		int key;
//		scanf("%d", &key);
//		int res = Find(key);
//		if (arr[res] != key)printf("%d ", -1);
//		else
//		{
//			printf("%d ", res);
//		}
//	}
//	return 0;
//}


//789数的范围ACWING

//const int N = 10010;
//int n, q;
//int arr[N];
//int binary_search1(int x)
//{
//	int l = -1, r = n;
//	int mid = (l + r) / 2;
//	while (l + 1 != r)
//	{
//		if (arr[mid] < x)
//		{
//			l = mid;
//			mid = (l + r) / 2;
//		}
//		else
//		{
//			r = mid;
//			mid = (l + r) / 2;
//		}
//	}
//	return r;
//}
//int binary_search2(int x)
//{ 
//	int l = -1, r = n;
//	int mid = (l + r) / 2;
//	while (l + 1 != r)
//	{
//		if (arr[mid] <= x)
//		{
//			l = mid;
//			mid = (l + r) / 2;
//		}
//		else
//		{
//			r = mid;
//			mid = (l + r) / 2;
//		}
//	}
//	return l;
//}
//
//int main()
//{
//	cin >> n >> q;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	while (q--)
//	{
//		int x;
//		cin >> x;
//		int res = binary_search1(x);
//		if (arr[res] != x)
//		{
//			cout << -1 << ' ' << -1 << endl;
//		}
//		else
//		{
//			cout << res << ' ';
//			res = binary_search2(x);
//			cout << res << ' ' << endl;
//		}
//	}
//	return 0;
//}

//浮点数二分
//计算数的三次方根
//也是二分查找法
double n;
int main()
{
	scanf("%lf", &n);
	double l = -30, r = 30;
	double mid = (l + r) / 2;

	while (fabs(pow(mid, 3) - n) >= 1e-9)
	{
		if (pow(mid, 3) < n)
		{
			l = mid;
			mid = (l + r) / 2;
		}
		else
		{
			r = mid;
			mid = (l + r) / 2;
		}
	}
	printf("%f", mid);
	return 0;
}
