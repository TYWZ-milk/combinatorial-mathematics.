#include<iostream>
#include<time.h>
using namespace std;
int farmer, k = 0,ans=0; //farmerΪ������2n,k���ڼ�¼$50������,ansΪ�Ŷӷ�����
void search(int count, int &k, int &ans, int farmer){
	if (count == farmer){
		if (!k)
			ans++;//kΪ0����֤��$50�������ꡣ���Ŷӷ������У�������
		return ; 
	}
	if (k){//$50��δ������
		k--;//����ʹ��$100
		search(count + 1, k,ans, farmer);//�����ݹ飬��ǰ������һ
		k++;
	}
	k++;
	search(count + 1, k,ans, farmer);
	k--;
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
		search(0, k, ans, farmer);//��ʼ����Ϊ0��k��ans������Ϊ0
		finish = clock();
		totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
		cout << "����" << totaltime << "s"<<endl;
		cout << "����" << ans << "���Ŷӵķ�������" << endl<<endl;
		ans = 0;
		cout << "�������Ŷӹ�Ʊ��������������Ϊż��������0���˳����򣩣�";
		cin >> farmer;
	}
	system("pause");
}