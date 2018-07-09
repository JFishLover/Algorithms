#include<iostream>
#include<stdlib.h>

using namespace std;
//����ʱ��������򣬺ܺ��ã�����Ҫ��ȽϿ��̣�Ҫ��ȡֵ��ΧΪ0-k������k=O(a.length)�����ǿ��Կ��ǵ�
void counting_Sort(int a[],int b[],int length,int k){
	int *c=new int[k+1];
	for(int i=0;i<k+1;++i){
		c[i]=0;
	}
	for(int i=0;i<length;++i){
		c[a[i]]++;
	}
	for(int i=0;i<k;++i){
		c[i+1]=c[i]+c[i+1];
	}
	for(int i=length-1;i>=0;--i){
		b[c[a[i]]-1]=a[i];
		c[a[i]]--;
	}
	
}
int main(){
	int a[12]={23,4,1,5,7,1,3,2,90,76,56,8};
	int b[12]={0};
	counting_Sort(a,b,12,100);
	for(int i=0;i<12;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;
	system("pause");
	return 0;
}