#include<iostream>
#include<stdlib.h>

using namespace std;
//�������еı��ָ�Ķ��������±꣬���Ķ�������
int heap_size;
//ά�����ѵ�����
void max_heapify(int a[],int i){
	//cout<<"33333"<<endl;
	//cout<<"i="<<i<<endl;
	int left=2*i+1;
	int right=2*i+2;
	int large_index=i;//�������ǳ�ʼ����������ʼ��ֵΪi��Ҫ�Ǻ��ӽ���б�����ľͻ����¸�ֵ���������i�����ύ����
	if(left<heap_size&&a[left]>a[i]){
		large_index=left;
	}
	if(right<heap_size&&a[right]>a[large_index]){
		large_index=right;
	}
	if(large_index!=i){
		int temp=a[i];
		a[i]=a[large_index];
		a[large_index]=temp;
		//�ݹ�
		max_heapify(a,large_index);
	}
}
//�������ѣ���Ҫ�ӵ����Ͻ�����ȷ��a[0]������
void build_max_heap(int a[],int length){
	//cout<<"22222"<<endl;

	//cout<<"length="<<length<<endl;
	heap_size=length;
	for(int i=length/2-1;i>=0;--i){
		//cout<<"i=length/2-1="<<i<<endl;
		max_heapify(a,i);
	}
}
//��������
void heap_Sort(int a[],int length){
	//���鴫�ݲ���ֻ�Ǵ����˵�һ��Ԫ�ص�ָ�룬Ҫ����Ҫ���ȵĻ���Ҫ���ݲ���
	//cout<<"11111"<<endl;
	build_max_heap(a,length);	
	int temp;
	for(int i=length-1;i>=1;--i){
		//�Ƚ���
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;

		heap_size--;
		//�ݹ�
		max_heapify(a,0);
	}
}
int main(){
	int a[12]={23,4,1,5,7,1,3,2,90,76,56,8};
	//cout<<sizeof(a)/sizeof(a[0])<<endl;
	heap_Sort(a,12);
	for(int i=0;i<12;++i){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	system("pause");
	return 0;
}