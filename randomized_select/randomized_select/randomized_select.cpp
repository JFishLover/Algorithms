#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;
int randomized_partition(int a[],int p,int r){
	srand(time(NULL));
	int k=p+rand()%(r-p+1);
	//cout<<"2222222222    k="<<k<<"p="<<p<<"r="<<r<<endl;
	int temp=a[k];
	a[k]=a[r];
	a[r]=temp;

	int i=p-1;
	for(int j=p;j<r;++j){
		if(a[j]<a[r]){
			i++;
			int temp1=a[i];
			a[i]=a[j];
			a[j]=temp1;
		}
	}
	temp=a[r];
	a[r]=a[i+1];
	a[i+1]=temp;
	
	//卧槽，返回值应该是下标，我TM居然把元素值返回了，惊了！！！！！！
	return i+1;
}
int randomized_select(int a[],int p,int r,int i){
	if(p==r){
		return a[p];
	}
	int q=randomized_partition(a,p,r);
	//cout<<"111111"<<endl;
	//cout<<"q="<<q<<endl;
	int count=q-p+1;
	if(count==i){
		//惊了，我尼玛怕是个智障，返回的应该是pivot这个元素啊！！！！！！！！！！，我尼玛，我居然写的a[i]
		return a[q];
	}else if(count>i){
		return randomized_select(a,p,q-1,i);
	}else{
		return randomized_select(a,q+1,r,i-count);
	}
}
int main(){
	int a[12]={23,4,1,5,7,1,3,2,90,76,56,8};
	int ele=randomized_select(a,0,11,5);
	cout<<ele<<endl;
	system("pause");
	return 0;
}