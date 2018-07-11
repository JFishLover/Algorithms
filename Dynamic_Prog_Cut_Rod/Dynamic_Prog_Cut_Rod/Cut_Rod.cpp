#include<iostream>
#include<stdlib.h>

using namespace std;
int max(int a,int b){
	if(a>b)
		return a;
	return b;
}
//�ݹ鷽ʽ����������
//���ַ������൱����������Ϊ�ݹ�Ĺ��̲�û�б����������Ľ��ֵ���ܶ���������Ҫ�ظ����㣬�˷���ʱ�䡣
int cut_Rod(int p[],int n){
	if(n==0)
		return 0;
	int q=-1;
	for(int i=1;i<=n;++i){
		q=max(q,p[i]+cut_Rod(p,n-i));
	}
	return q;
}
//������¼���Զ����·����ĸ��������������������֮��Ҫ��¼
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
//������¼���Զ����·���,��������������ǽ��г�ʼ��
int memoized_Cut_Rod(int p[],int n){
	int *r=new int [n+1];
	//�½���¼���飬��ÿ������������������м�¼�������Ƚ��г�ʼ��
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
		//�����i֮ǰ����������������Ѿ���������洢��r��������
		for(int j=1;j<=i;++j){
			q=max(q,p[j]+r[i-j]);
		}
		r[i]=q;
	}
	return r[n];
}

int main(){
	int p[11]={0,1,5,8,9,10,17,17,20,24,30};
	cout<<"�򵥵ݹ���⣺"<<cut_Rod(p,7)<<endl;
	cout<<"������¼���Զ����·������:"<<memoized_Cut_Rod(p,7)<<endl;
	cout<<"�Ե����Ϸ�����⣺"<<bottom_Up_Cut_Rod(p,7)<<endl;
	cout<<"һ��ɹ�������"<<endl;
	system("pause");
	return 0;
}