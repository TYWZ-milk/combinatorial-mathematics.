#include<iostream>
#include<time.h>
using namespace std;
int farmer, k = 0,ans=0; //farmer为总人数2n,k用于记录$50的张数,ans为排队方案数
void search(int count, int &k, int &ans, int farmer){
	if (count == farmer){
		if (!k)
			ans++;//k为0，则证明$50均被用完。该排队方法可行，否则不行
		return ; 
	}
	if (k){//$50并未被用完
		k--;//可以使用$100
		search(count + 1, k,ans, farmer);//继续递归，当前人数加一
		k++;
	}
	k++;
	search(count + 1, k,ans, farmer);
	k--;
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
		search(0, k, ans, farmer);//起始人数为0，k、ans计数器为0
		finish = clock();
		totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
		cout << "共需" << totaltime << "s"<<endl;
		cout << "共有" << ans << "种排队的方案数。" << endl<<endl;
		ans = 0;
		cout << "请输入排队购票的人数（人数需为偶数，输入0则退出程序）：";
		cin >> farmer;
	}
	system("pause");
}