#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;
//差点又忘记了引用
void greedy_Activity_Selector(vector<int> &a,int n,int s[],int f[]){
	a.push_back(1);
	int k=1;//记录最后一个加入的活动
	for(int i=2;i<=n;++i){
		if(s[i]>=f[k]){
			a.push_back(i);
			k=i;
		}
	}
}
int main(){
	//活动默认按照结束时间升序排列
	int s[12]={0,1,3,0,5,3,5,6,8,8,2,12};
	int f[12]={0,4,5,6,7,9,9,10,11,12,14,16};
	vector<int> a;
	greedy_Activity_Selector(a,11,s,f);
	cout<<"最多可容纳的活动个数为："<<a.size()<<endl;
	cout<<"选择的活动序号分别是:"<<endl;
	for(int i=0;i<a.size();++i){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	system("pause");
	return 0;
}