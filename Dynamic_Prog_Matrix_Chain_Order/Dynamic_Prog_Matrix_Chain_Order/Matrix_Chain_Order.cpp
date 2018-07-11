#include<iostream>
#include<stdlib.h>

using namespace std;

void Matrix_Chain_Order(int p[],int length,int m[][100],int s[][100]){
	int n=length-1;
	for(int i=1;i<=n;++i){
		m[i][i]=0;
	}
	for(int l=2;l<=n;++l){
		for(int i=1;i<=n-l+1;++i){
			int j=i+l-1;
			m[i][j]=pow(2.0,31)-1;
			for(int k=i;k<j;++k){
				int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(m[i][j]>q){
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
}
void print_Parens(int s[][100],int i,int j){
	if(i==j)
		cout<<"A"<<i;
	else{
		cout<<"(";
		print_Parens(s,i,s[i][j]);
		print_Parens(s,s[i][j]+1,j);
		cout<<")";
	}
}
int main(){
	int p[7]={30,35,15,5,10,20,25};
	int m[100][100],s[100][100];
	Matrix_Chain_Order(p,7,m,s);
	print_Parens(s,1,6);
	cout<<endl;
	cout<<"矩阵链的最小乘法次数是："<<endl;
	cout<<m[1][6]<<endl;
	system("pause");
	return 0;
}