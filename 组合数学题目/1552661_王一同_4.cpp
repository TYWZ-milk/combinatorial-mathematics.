#include<iostream>
#include<time.h>
#define MAX 1000
using namespace std;
int farmer;
double ans[MAX][MAX]; //farmerΪ������2n,ansΪ�Ŷӷ������Ķ�ά����
void recursion_search(){
	for (int iX = 0; iX < farmer / 2; iX++){
		for (int iJ = 0; iJ < farmer / 2; iJ++){
			if (iX < iJ)//iX<iJ��$50����$100������
				ans[iX][iJ]=0;
			else if (iJ == 0)//�õĶ���$50
				ans[iX][iJ] = iX+1;
			else{//�������
				ans[iX][iJ] = ans[iX - 1][iJ] + ans[iX][iJ - 1];
			}
		}
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
		recursion_search();
		finish = clock();
		totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
		cout << "����" << totaltime << "s" << endl;
		cout << "����" << ans[farmer / 2 - 1][farmer / 2 - 1] << "���Ŷӵķ�������" << endl << endl;
		cout << "�������Ŷӹ�Ʊ��������������Ϊż��������0���˳����򣩣�";
		cin >> farmer;
		memset(ans, 0, sizeof(ans));
	}
	system("pause");
}