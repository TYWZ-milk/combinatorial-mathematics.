#include<iostream>
#include<time.h>
using namespace std;
int main(){
	long int farmer; //farmer为总人数2n,ans为排队方案数
	double ans = 1;
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
		long int n = farmer / 2;
		start = clock();   //计算时间
		float tmp_1=farmer, tmp_2=farmer/2;//tmp_1为每一项的分子位置，tmp_2为分母
		for (int iX = 0; iX < n; iX++){//对阶乘的每一步进行计算，方便显示更多人数时对应的方案数
			ans = tmp_1/tmp_2*ans;
			tmp_1--, tmp_2--;
		}
		ans = ans / (n + 1);//由公式得到答案
		finish = clock();
		totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
		cout << "共需" << totaltime << "s" << endl;
		cout << "共有" << ans<< "种排队的方案数。" << endl << endl;
		cout << "请输入排队购票的人数（人数需为偶数，输入0则退出程序）：";
		cin >> farmer;
		ans = 1;
	}
	system("pause");
}