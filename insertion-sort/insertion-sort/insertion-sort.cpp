#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
	int a[12]={7,5,9,6,8,42,3,1,9,2,55,1};
	for(int i=1;i<12;++i){
		int key=a[i];//保存将要插入的值
		int j=i-1;//向前看
		while(j>=0&&a[j]>key){
			a[j+1]=a[j];//后移
			j=j-1;
		}
		a[j+1]=key;
	}
	for(int i=0;i<12;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	system("pause");
	return 0;
}