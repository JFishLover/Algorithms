#include<iostream>
#include<stdlib.h>

using namespace std;
int partition(int a[],int p,int r){
	int x=a[r];
	int i=p-1;
	int temp;
	for(int j=p;j<r;++j){
		if(a[j]<x){
			i++;
			//½»»»
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[i+1];
	a[i+1]=x;
	a[r]=temp;
	return i+1;
}
void quick_Sort(int a[],int p,int r){
	if(p<r){
		int q=partition(a,p,r);
		quick_Sort(a,p,q-1);
		quick_Sort(a,q+1,r);
	}
}
int main(){
	int a[12]={23,4,1,5,7,1,3,2,90,76,56,8};
	quick_Sort(a,0,11);
	cout<<"¿ìËÙÅÅÐò£¡"<<endl;
	for(int i=0;i<12;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	system("pause");
	return 0;
}