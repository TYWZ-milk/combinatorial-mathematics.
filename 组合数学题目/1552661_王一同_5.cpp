#include<iostream>
#include<time.h>
using namespace std;
int main(){
	long int farmer; //farmerΪ������2n,ansΪ�Ŷӷ�����
	double ans = 1;
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
		long int n = farmer / 2;
		start = clock();   //����ʱ��
		float tmp_1=farmer, tmp_2=farmer/2;//tmp_1Ϊÿһ��ķ���λ�ã�tmp_2Ϊ��ĸ
		for (int iX = 0; iX < n; iX++){//�Խ׳˵�ÿһ�����м��㣬������ʾ��������ʱ��Ӧ�ķ�����
			ans = tmp_1/tmp_2*ans;
			tmp_1--, tmp_2--;
		}
		ans = ans / (n + 1);//�ɹ�ʽ�õ���
		finish = clock();
		totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
		cout << "����" << totaltime << "s" << endl;
		cout << "����" << ans<< "���Ŷӵķ�������" << endl << endl;
		cout << "�������Ŷӹ�Ʊ��������������Ϊż��������0���˳����򣩣�";
		cin >> farmer;
		ans = 1;
	}
	system("pause");
}