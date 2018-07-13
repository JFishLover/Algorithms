#include<iostream>
#include<stdlib.h>

using namespace std;
void optimal_BST(float p[],float q[],int length,float e[][100],float w[][100],int root[][100]){
	for(int i=1;i<=length+1;++i){
		e[i][i-1]=q[i-1];
		w[i][i-1]=q[i-1];
	}
	//这个三重循环跟矩阵乘法链很像，分别是长度，起点和分割点
	for(int l=1;l<=length;++l){
		for(int i=1;i<=length-l+1;++i){
			int j=i+l-1;
			e[i][j]=pow(2.0,31)-1;
			w[i][j]=w[i][j-1]+p[j]+q[j];
			for(int k=i;k<=j;++k){
				float t=e[i][k-1]+e[k+1][j]+w[i][j];
				if(t<e[i][j]){
					e[i][j]=t;
					root[i][j]=k;
				}
			}
		}
	}
}
int main(){
	float p[6]={0,0.15,0.1,0.05,0.1,0.2};
	float q[6]={0.05,0.1,0.05,0.05,0.05,0.1};
	int root[100][100];//存储子树的根节点
	float w[100][100];//存储子树的概率和
	float e[100][100];//存储最优二叉搜索树的最优值
	optimal_BST(p,q,5,e,w,root);
	cout<<"构造optimal_BST的最小代价为："<<e[1][5]<<endl;
	cout<<"根节点为"<<root[1][5]<<endl;
	system("pause");
	return 0;
}