#include <iostream>
#include <cstdio>
#include <cstring>
#include<time.h>
#include <stack>
using namespace std;
int farmer = 0;
int a[1000];
long long ans = 0;
bool test_stack(int n);

void print(int l, int r, int n) {
	if (l == r) {
		if (test_stack(n)) {
			ans++;
		}
		return;
	}
	//1~N个数的全排列
	else {
		for (int i = l; i < r; i++) {
			swap(a[i], a[l]);
			print(l + 1, r, n);
			swap(a[i], a[l]);
		}
	}
};
bool test_stack(int n)                     //通过模拟入栈、出栈的过程来判断满足条件 
{
	stack <int> s;
	int test = 1, i;
	for (i = 0; i < n;) {
		if (test > n)
			return false;
		if (test != a[i]) {
			s.push(test);
			test++;
		}
		else {
			test++;
			i++;
			while (!s.empty() && s.top() == a[i]) {
				s.pop();
				i++;
			}
		}
	}
	return true;
};

int main(){
	cout << "请输入排队购票的人数（人数需为偶数，输入0则退出程序）：";
	cin >> farmer;
	while (farmer != 0)
	{
		while (farmer % 2 != 0){  //容错操作
			cout << "输入有误，请重新输入：";
			cin >> farmer;
		}
		clock_t start, finish;
		double totaltime;

		start = clock();   //计算时间
		for (int i = 0; i < farmer; i++) {
			a[i] = i + 1;
		}
		print(0,farmer/2,farmer/2);
		finish = clock();
		totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
		cout << "共需" << totaltime << "s" << endl;
		cout << "共有" << ans << "种排队的方案数。" << endl << endl;
		ans = 0;
		cout << "请输入排队购票的人数（人数需为偶数，输入0则退出程序）：";
		cin >> farmer;
	}
	system("pause");
}