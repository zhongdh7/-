#include<iostream>
#include<queue>
using namespace std;
int main()
{
	//优先队列出队的时候，优先级高的先出队，如果优先级相同，先进先出
	//一般优先队列的默认优先级是从大到小的
	//如果想要改变优先级的顺序，可以在定义优先队列的时候，指定第三个参数为
	priority_queue<int, vector<int>, greater<int>> q;//这里greater<int>表示优先级从小到大

	//优先队列的操作
	q.push(3);
	q.push(1);
	q.push(2);
	q.push(4);
	q.push(5);
	q.push(6);
	q.push(7);

	//size()函数可以返回优先队列中元素的个数
	cout << "优先队列中元素的个数为：" << q.size() << endl;

	//top()函数可以返回优先队列中优先级最高的元素
	cout << "优先队列中优先级最高的元素为：" << q.top() << endl;

	//pop()函数可以删除优先队列中优先级最高的元素
	q.pop();
	cout << "删除优先级最高的元素后，优先队列中优先级最高的元素为：" << q.top() << endl;

	priority_queue<int> q1;//默认优先级从大到小,这里的比较函数是less<int>,这个自动调用的是小于号，然后如果小于为true就往后放，如果小于为false就往前放

	for(int i= 0; i < 10; i++)
	{
		q1.push(i);
	}
	while(!q1.empty())
	{
		cout << q1.top() << " ";
		q1.pop();
	}
	cout << endl;
	return 0;
}