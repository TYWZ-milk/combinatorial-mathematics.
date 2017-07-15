#include<iostream>
#include<time.h>
using namespace std;
int farmer,ans = 0; //farmer为总人数2n,ans为排队方案数
void recursion_search(int m, int n){//m为手持$50的人，n为手持$100的人
	if (m < n)//所有的$50找出去也存在无法找开的情况
		return;
	if (n == 0){//拿的都是$50
		ans++;
		return;
	}
	else{//两种情况，第m+n个人手持的是$50或是$100的两种情况
		recursion_search(m, n - 1);
		recursion_search(m - 1, n);
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
		recursion_search(farmer/2, farmer/2);//起始人数为n，即总人数的一半
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