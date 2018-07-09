#include<iostream>
#include<stdlib.h>

//using namespace std;
//找到最小值和最大值，先两两比较，小的和min比较，大的和max比较，两个元素只需要三次比较
int max,min;

void max_min(int a[],int length){
	if(length%2==1){
		min=a[0];
		max=a[0];
		for(int i=1;i<length;i=i+2){
			if(a[i]<a[i+1]){
				if(a[i]<min)
					min=a[i];
				if(a[i+1]>max)
					max=a[i+1];
			}else{
				if(a[i]>max)
					max=a[i];
				if(a[i+1]<min)
					min=a[i+1];				
			}
		}
	}else{
		if(a[0]<a[1]){
			min=a[0];
			max=a[1];
		}else{
			min=a[1];
			max=a[0];
		}
		for(int i=2;i<length;i=i+2){
			if(a[i]<a[i+1]){
				if(a[i]<min)
					min=a[i];
				if(a[i+1]>max)
					max=a[i+1];
			}else{
				if(a[i]>max)
					max=a[i];
				if(a[i+1]<min)
					min=a[i+1];				
			}
		}
	}
}
int main(){
	int a[12]={23,4,1,5,7,1,3,2,90,76,56,8};
	max_min(a,12);
	std::cout<<"min="<<min<<" and max="<<max<<std::endl;
	system("pause");
	return 0;
}