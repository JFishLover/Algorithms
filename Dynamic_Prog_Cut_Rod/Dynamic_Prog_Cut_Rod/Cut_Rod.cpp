#include<iostream>
#include<stdlib.h>

using namespace std;
int max(int a,int b){
	if(a>b)
		return a;
	return b;
}
//递归方式求解最大收益
//这种方法是相当的慢，是因为递归的过程并没有保存计算出来的结果值，很多子问题需要重复计算，浪费了时间。
int cut_Rod(int p[],int n){
	if(n==0)
		return 0;
	int q=-1;
	for(int i=1;i<=n;++i){
		q=max(q,p[i]+cut_Rod(p,n-i));
	}
	return q;
}
//带备忘录的自顶向下方法的辅助函数，算出来子问题之后要记录
int memoized_Cut_Rod_Aux(int p[],int r[],int n){
	if(r[n]>=0)
		return r[n];
	int q=-1;
	if(n==0)
		q=0;
	else
		for(int i=1;i<=n;++i){
			q=max(q,p[i]+memoized_Cut_Rod_Aux(p,r,n-i));
		}
	r[n]=q;
	return q;
}
//带备忘录的自顶向下方法,这个主函数仅仅是进行初始化
int memoized_Cut_Rod(int p[],int n){
	int *r=new int [n+1];
	//新建记录数组，对每个子问题的最大收益进行记录，这里先进行初始化
	for(int i=0;i<n+1;i++){
		r[i]=-1;
	}
	return memoized_Cut_Rod_Aux(p,r,n);
}
int bottom_Up_Cut_Rod(int p[],int n){
	int *r=new int[n+1];
	r[0]=0;
	for(int i=1;i<=n;++i){
		int q=-1;
		//在这里，i之前的子问题最大收益已经计算出来存储到r数组中了
		for(int j=1;j<=i;++j){
			q=max(q,p[j]+r[i-j]);
		}
		r[i]=q;
	}
	return r[n];
}

int main(){
	int p[11]={0,1,5,8,9,10,17,17,20,24,30};
	cout<<"简单递归求解："<<cut_Rod(p,7)<<endl;
	cout<<"带备忘录的自顶向下方法求解:"<<memoized_Cut_Rod(p,7)<<endl;
	cout<<"自底向上方法求解："<<bottom_Up_Cut_Rod(p,7)<<endl;
	cout<<"一遍成功哈哈哈"<<endl;
	system("pause");
	return 0;
}