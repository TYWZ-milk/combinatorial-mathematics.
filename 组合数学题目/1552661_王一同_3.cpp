#include<iostream>
#include<time.h>
using namespace std;
int farmer,ans = 0; //farmerΪ������2n,ansΪ�Ŷӷ�����
void recursion_search(int m, int n){//mΪ�ֳ�$50���ˣ�nΪ�ֳ�$100����
	if (m < n)//���е�$50�ҳ�ȥҲ�����޷��ҿ������
		return;
	if (n == 0){//�õĶ���$50
		ans++;
		return;
	}
	else{//�����������m+n�����ֳֵ���$50����$100���������
		recursion_search(m, n - 1);
		recursion_search(m - 1, n);
	}
}
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
		recursion_search(farmer/2, farmer/2);//��ʼ����Ϊn������������һ��
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