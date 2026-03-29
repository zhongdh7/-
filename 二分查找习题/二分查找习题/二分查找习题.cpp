#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

//const int N = 200010;
//
//int n, C;
//int q[N];
//typedef long long ll;
//ll cnt = 0;
//
////A-B数对
//int binary_search1(int key)//这个用于寻找第一个A的位置
//{
//	int l = 0, r = n + 1;
//	int mid = (l + r) / 2;
//	while (l + 1 != r)
//	{
//		if (q[mid] < key)
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
//	if (q[r] != key)return-1;
//	return r;
//}
//int binary_search2(int key)
//{
//	int l = 0, r = n + 1;
//	int mid = (l + r) / 2;
//	while (l + 1 != r)
//	{
//		if (q[mid] <= key)
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
//	if (q[l] != key)return-1;
//	return l;
//}
//int main()
//{
//	scanf("%d%d", &n, &C);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", q + i);
//	}
//	sort(q + 1, q + n + 1);
//	for (int i = 1; i<=n; i++)
//	{
//		int B = q[i];
//		int l = binary_search1(B + C);
//		if (l == -1)continue;
//		int r = binary_search2(B + C);
//		
//		cnt += (r - l + 1);
//	}
//	cout << cnt << endl;
//	printf("%lld\n", cnt);
//	return 0;
//}

//P1873 [COCI 2011/2012 #5] EKO / 砍树

//const int N = 1e6 + 10;
//int tree[N];
//int n, m;//m是需要的木头的总长度
//bool is_blue(int height)
//{
//	long long sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (height <= tree[i])
//		{
//			sum += (tree[i] - height);
//		}
//	}
//	return sum < m;
//}
//int binary_search()
//{
//	int l = 0;
//	int r = tree[n] + 1;
//	int mid = (l + r) / 2;
//	while (l + 1 != r)
//	{
//		if (is_blue(mid))
//		{
//			r = mid;
//			mid = (l + r) / 2;
//		}
//		else
//		{
//			l = mid;
//			mid = (l + r) / 2;
//		}
//	}
//	return l;
//}
//int main()
//{
//	scanf("%d%d", &n, &m);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", tree + i);
//	}
//	sort(tree + 1, tree + n + 1);
//	int height = binary_search();
//	printf("%d\n", height);
//	return 0;
//}

//P2440 木材加工

using namespace std;
const int N = 1e5 + 100;
int tree[N];
int n, k;
bool is_blue(int length)
{
	long long total = 0;
	for (int i = 1; i <= n; i++)
	{
		total += (tree[i] / length);
	}
	return total < k;
}
int binary_search()
{
	int l = 0;
	int r = tree[n] + 1;
	int mid = (l + r) / 2;
	while (l + 1 != r)
	{
		if (is_blue(mid))
		{
			r = mid;
			mid = (r + l) / 2;
		}
		else
		{
			l = mid;
			mid = (r + l) / 2;
		}
	}
	return l;
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", tree + i);
	}
	sort(tree + 1, tree + n + 1);
	int res = binary_search();
	cout << res << endl;
	return 0;
}