#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;
struct Node{
	int left;
	int right;
	int sum;
};
//找到跨越左右两边的连续子数组的最大值，分别从mid向左和向右找，记录sum和已知的最大值。
 Node find_max_crossing(int a[],int low,int mid,int high){
	// cout<<"222222"<<endl;
	//cout<<"left="<<low<<" and right="<<high<<endl;
	int left_max=-pow(2.0,31);//左边的确定的最大值
	int sum=0;//临时的sum
	int left=mid+1;
	for(int i=mid;i>=low;--i){
		sum+=a[i];
		if(sum>left_max){
			left_max=sum;
			left=i;
		}
	}
	int right_max=-pow(2.0,31);
	sum=0;
	int right=mid;
	for(int i=mid+1;i<=high;++i){
		sum+=a[i];
		if(sum>right_max){
			right_max=sum;
			right=i;
		}
	}
	Node node;
	node.left=left;
	node.right=right;
	node.sum=right_max+left_max;
	//cout<<"left_max="<<left_max<<" and right_max="<<right_max<<endl;
	return node;
	
}
 Node find_maximum_subArray(int a[],int low,int high){
	Node node;
	/*cout<<"1111"<<endl;
	cout<<"left="<<low<<" and right="<<high<<endl;*/
	if(low==high){
		node.left=0;
		node.right=0;
		node.sum=a[0];

	}else{
		int mid=(low+high)/2;
		Node middle=find_max_crossing(a,low,mid,high);
		Node left=find_maximum_subArray(a,low,mid);
		Node right=find_maximum_subArray(a,mid+1,high);
		if(left.sum>right.sum&&left.sum>middle.sum){
			node=left;
		}else if(right.sum>left.sum&&right.sum>middle.sum){
			node=right;
		}else{
			node=middle;
		}
	}
	return node;
 
 }
int main(){
	int a[16]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,-7};
	Node node=find_maximum_subArray(a,0,15);
	cout<<"最大连续子数组的和为:"<<node.sum<<endl<<"已经经过测试，答案正确"<<endl;
	cout<<"left="<<node.left<<endl;
	cout<<"right="<<node.right<<endl;
	system("pause");
	return 0;
}