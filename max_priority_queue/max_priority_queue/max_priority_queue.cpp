#include<iostream>
#include<stdlib.h>
#include<math.h>
#define error -pow(2.0,31)
using namespace std;
int heap_size;
void max_heapify(int a[],int i){
	int left=2*i+1;
	int right=2*i+2;
	int max_index=i;
	if(left<heap_size&&a[left]>a[i]){
		max_index=left;
	}
	if(right<heap_size&&a[right]>a[max_index]){
		max_index=right;
	}	
	if(max_index!=i){
		//����
		int temp=a[i];
		a[i]=a[max_index];
		a[max_index]=temp;

		max_heapify(a,max_index);
	}
}
//����������������ѵ�Ҫ��
void build_max_heap(int a[],int length){
	heap_size=length;
	for(int i=length/2-1;i>=0;--i){
		max_heapify(a,i);
	}
}
void heap_Sort(int a[],int length){
	
}
int heap_maximum(int a[]){
	return a[0];
}
int heap_extract_max(int a[]){
	if(heap_size!=0){
		int max=a[0];
		a[0]=a[heap_size-1];
		heap_size--;
		//ά�����ѵĽṹ
		max_heapify(a,0);
		return max;
	}else{
		return error;
	}
	
}
int heap_increase_key(int a[],int i,int k){
	if(k<=a[i])
		return error;
	a[i]=k;
	while(i>0&&a[(i-1)/2]<a[i]){
		int temp=a[(i-1)/2];
		a[(i-1)/2]=a[i];
		a[i]=temp;
		//���ϵ������жϸ��ڵ���Ƿ��������ѵ�Ҫ��
		i=(i-1)/2;
	}
	return 1;
}
void insert_heap(int a[],int key){
	a[heap_size]=error;
	heap_size++;
	heap_increase_key(a,heap_size-1,key);
}
int main(){
	int a[12]={23,4,1,5,7,1,3,2,90,76,56,8};
	build_max_heap(a,12);
	cout<<"ԭʼ�����ȶ���Ԫ����:"<<endl;
	for(int i=0;i<12;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<"���ȶ������Ԫ����:"<<heap_maximum(a)<<endl;
	cout<<heap_extract_max(a);
	cout<<"ɾ�����Ԫ��֮��"<<endl;
	for(int i=0;i<11;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	heap_increase_key(a,10,100);
	cout<<"ĳ��Ԫ�����ӵ�100֮��"<<endl;
	for(int i=0;i<11;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	insert_heap(a,900);
	cout<<"����һ��900��Ԫ��֮��"<<endl;
	for(int i=0;i<12;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;

	system("pause");
	return 0;
}