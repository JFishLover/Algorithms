#include<iostream>
#include<stdlib.h>

using namespace std;
//堆排序中的标号指的都是数组下标，建的都是最大堆
int heap_size;
//维护最大堆的性质
void max_heapify(int a[],int i){
	//cout<<"33333"<<endl;
	//cout<<"i="<<i<<endl;
	int left=2*i+1;
	int right=2*i+2;
	int large_index=i;//这里忘记初始化，报错，开始赋值为i，要是孩子结点有比他大的就会重新赋值，否则就是i，不会交换。
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
		//递归
		max_heapify(a,large_index);
	}
}
//建立最大堆，需要从底向上建立，确保a[0]是最大的
void build_max_heap(int a[],int length){
	//cout<<"22222"<<endl;

	//cout<<"length="<<length<<endl;
	heap_size=length;
	for(int i=length/2-1;i>=0;--i){
		//cout<<"i=length/2-1="<<i<<endl;
		max_heapify(a,i);
	}
}
//最大堆排序
void heap_Sort(int a[],int length){
	//数组传递参数只是传递了第一个元素的指针，要是需要长度的话需要传递参数
	//cout<<"11111"<<endl;
	build_max_heap(a,length);	
	int temp;
	for(int i=length-1;i>=1;--i){
		//先交换
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;

		heap_size--;
		//递归
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