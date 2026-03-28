#include<iostream>
using namespace std;
bool is_blue(int x)
{
	return x <= 5;
}
//只需要找到分界位置的数据情况就可以了
//返回最后一个大于等于五的数据的下标
//l要比左分界线小1，r比右分界线大1
int check(int* a, int l,int r)
{
	int mid = (l + r) / 2;
	while (l + 1 != r)//这个循环的条件都不变都是这个条件
	{
		if (is_blue(a[mid]))
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
	return l;
}
int main()
{
	int a[] = { 1,4,4,5,5,5,6,7 };
	int pos=check(a, -1, sizeof(a) / sizeof(int));//这种二分的查找写法不需要考虑加一减一的情况
	cout << pos << endl;
	return 0;
}