#include<iostream>
#include<time.h>
#define MAX 1000
using namespace std;
int farmer;
double ans[MAX][MAX]; //farmer为总人数2n,ans为排队方案数的二维数组
void recursion_search(){
	for (int iX = 0; iX < farmer / 2; iX++){
		for (int iJ = 0; iJ < farmer / 2; iJ++){
			if (iX < iJ)//iX<iJ即$50少于$100的人数
				ans[iX][iJ]=0;
			else if (iJ == 0)//拿的都是$50
				ans[iX][iJ] = iX+1;
			else{//其他情况
				ans[iX][iJ] = ans[iX - 1][iJ] + ans[iX][iJ - 1];
			}
		}
	}
}
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
		recursion_search();
		finish = clock();
		totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
		cout << "共需" << totaltime << "s" << endl;
		cout << "共有" << ans[farmer / 2 - 1][farmer / 2 - 1] << "种排队的方案数。" << endl << endl;
		cout << "请输入排队购票的人数（人数需为偶数，输入0则退出程序）：";
		cin >> farmer;
		memset(ans, 0, sizeof(ans));
	}
	system("pause");
}