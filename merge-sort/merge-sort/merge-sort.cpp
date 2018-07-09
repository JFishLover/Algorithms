#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;

//合并算法，新开辟两个数组，设置哨兵，比较，插入
void merge(int a[],int p,int q,int r){
	int n1=q-p+1;
	int n2=r-q;
	int *L=new int[n1+1];
	int *R=new int[n2+1];
	for(int i=0;i<n1;++i){
		L[i]=a[p+i];
	}
	for(int i=0;i<n2;++i){
		R[i]=a[q+1+i];
	}
	L[n1]=(int)pow(2.0,31)-1;
	R[n2]=(int)pow(2.0,31)-1;
	int left=0,right=0;
	for(int i=p;i<=r;++i){
		if(L[left]<R[right]){
			a[i]=L[left];
			left++;
		}else{
			a[i]=R[right];
			right++;
		}		
	}
}
void merge_sort(int a[],int p,int r){
	if(p<r){//直到分到单个元素为止
		int q=(p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);  
		merge(a,p,q,r);//合并算法
	}
}
int main(){
	int a[12]={4,1,5,3,86,95,7,4,6,12,5,63};
	merge_sort(a,0,11);
	for(int i=0;i<12;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	system("pause");
	return 0;
}