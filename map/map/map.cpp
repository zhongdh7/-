#include<iostream>
#include<map>
#include<utility>
#include<string>
using namespace std;
typedef pair<int, string> PIS;
ostream& operator<<(ostream& out, const PIS& p)
{
	out << "key:" << p.first << " value:" << p.second;
	return out;
}
int main()
{
	map<int, string>maps;//默认队key进行升序排序
	maps.insert(PIS(1, "one"));
	maps.insert(pair<int, string>(2, "two"));
	maps.insert(PIS(3, "小张"));
	maps.insert(map<int, string>::value_type(4, "小李"));
	maps[8] = "小王";
	maps[1] = "one one";//修改key为1的value
	
	int key = 5;
	string name;
	name = "小赵";
	pair<int,string> p(key, name);
	maps.insert(p);//插入一个pair对象

	map<int, string>::value_type v(key+1, name);
	maps.insert(v);//插入一个value_type对象

	maps.insert(make_pair(key + 2, name));//插入一个make_pair对象

	maps[9] = "小钱";//插入一个key为9的元素

	//迭代
	for(auto it=maps.begin(); it != maps.end(); it++)
	{
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
	cout << "-----------------------------" << endl;
	cout << "自定义输出" << endl;
	for(auto it = maps.begin(); it != maps.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}