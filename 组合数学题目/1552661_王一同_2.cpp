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
	//1~N������ȫ����
	else {
		for (int i = l; i < r; i++) {
			swap(a[i], a[l]);
			print(l + 1, r, n);
			swap(a[i], a[l]);
		}
	}
};
bool test_stack(int n)                     //ͨ��ģ����ջ����ջ�Ĺ������ж��������� 
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
	cout << "�������Ŷӹ�Ʊ��������������Ϊż��������0���˳����򣩣�";
	cin >> farmer;
	while (farmer != 0)
	{
		while (farmer % 2 != 0){  //�ݴ����
			cout << "�����������������룺";
			cin >> farmer;
		}
		clock_t start, finish;
		double totaltime;

		start = clock();   //����ʱ��
		for (int i = 0; i < farmer; i++) {
			a[i] = i + 1;
		}
		print(0,farmer/2,farmer/2);
		finish = clock();
		totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
		cout << "����" << totaltime << "s" << endl;
		cout << "����" << ans << "���Ŷӵķ�������" << endl << endl;
		ans = 0;
		cout << "�������Ŷӹ�Ʊ��������������Ϊż��������0���˳����򣩣�";
		cin >> farmer;
	}
	system("pause");
}