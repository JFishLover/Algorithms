#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
//����������ÿһλ�õ��������㷨�������ȶ��ģ�����������Ľ���ǲ��Ե�
void radix_Sort(int a[],int length,int d){
	for(int k=0;k<d;++k){
		//�ڲ������õĲ��������ȶ�����
		for(int i=1;i<length;++i){
			int key=a[i];
			int key1=(int)(a[i]/pow(10.0,k))%10;
			int j=i-1;
			while(j>=0&&(int)(a[j]/pow(10.0,k))>key1){
				a[j+1]=a[j];
				j=j-1;
			}
			a[j+1]=key;
		}
	}	
}
int main(){
	int a[12]={23,4,1,5,7,1,3,2,90,76,56,8};
	radix_Sort(a,12,2);
	for(int i=0;i<12;++i){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	system("pause");
	return 0;
}