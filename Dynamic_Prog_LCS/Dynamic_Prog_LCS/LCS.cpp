#include<iostream>
#include<stdlib.h>
#define leftup 1;
#define left -1;
#define up 0;
using namespace std;
//定义左上-1
void lcs_Length(char x[],char y[],int length1,int length2,int b[][100],int c[][100]){
	int m=length1;
	int n=length2;
	//初始化，数组边缘赋值为0
	for(int i=0;i<=m;++i){
		c[i][0]=0;
	}
	for(int i=0;i<=n;++i){
		c[0][i]=0;
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			if(x[i]==y[j]){
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=leftup;
			}else if(c[i-1][j]>c[i][j-1]){
				c[i][j]=c[i-1][j];
				b[i][j]=up;
			}else{
				c[i][j]=c[i][j-1];
				b[i][j]=left;
			}
		}
	}
	
}
//重构最优解，输出
void print_Lcs(int b[][100],int i,int j,char x[]){
	if(i==0||j==0)
		return;
	if(b[i][j]==1){
		print_Lcs(b,i-1,j-1,x);
		cout<<x[i];
	}else if(b[i][j]==0){
		print_Lcs(b,i-1,j,x);
	}else{
		print_Lcs(b,i,j-1,x);
	}
}
int main(){
	char x[8]={' ','A','B','C','B','D','A','B'};
	char y[7]={' ','B','D','C','A','B','A'};
	int b[100][100];
	int c[100][100];
	lcs_Length(x,y,7,6,b,c);
	cout<<"两个序列的最长公共子序列长度为"<<c[7][6]<<endl;
	print_Lcs(b,7,6,x);
	cout<<endl;
	/*for(int i=1;i<=7;++i){
		for(int j=1;j<=6;++j){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}*/
	system("pause");
	return 0;
}