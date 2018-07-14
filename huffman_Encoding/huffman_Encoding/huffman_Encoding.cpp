#include<iostream>
#include<stdlib.h>
#define error -pow(2.0,31);
using namespace std;
int heap_size;
struct Node{
	Node * left;
	Node * right;
	int freq;
};
//前序遍历
void tree_preorder(Node * root){
	while(root!=NULL){
		//cout<<root<<endl;
		//cout<<"cdcdc"<<endl;
		cout<<root->freq<<" "<<endl;
		tree_preorder(root->left);
		tree_preorder(root->right);
	}
}
//重新复习一遍最小优先队列，哈弗曼编码算法要用到
void min_heapify(Node a[],int i){
	int left=2*i+1;
	int right=2*i+2;
	int min_index=i;
	if(left<heap_size&&a[left].freq<a[i].freq)
		min_index=left;
	if(right<heap_size&&a[right].freq<a[min_index].freq)
		min_index=right;
	if(min_index!=i){
		Node temp=a[i];
		a[i]=a[min_index];
		a[min_index]=temp;

		min_heapify(a,min_index);
	}
}
void build_min_heap(Node a[],int length){
	heap_size=length;
	for(int i=length/2-1;i>=0;--i){
		min_heapify(a,i);
	}
}
Node heap_minimum(Node a[]){
	return a[0];
}
Node heap_extract_min(Node a[]){
	if(heap_size<=0){
		Node err;
		err.freq=-pow(2.0,31);
		return err;
	}
	Node min=a[0];
	a[0]=a[heap_size-1];
	heap_size--;
	min_heapify(a,0);
	return min;
}
int heap_decrease_key(Node a[],int i,int key){
	if(key>=a[i].freq)
		return error;
	a[i].freq=key;
	while(i>0&&a[(i-1)/2].freq>a[i].freq){
		Node temp=a[i];
		a[i]=a[(i-1)/2];
		a[(i-2)/2]=temp;
		i=(i-1)/2;
	}
	return key;
}
void insert_heap(Node a[],Node key){
	a[heap_size]=key;
	cout<<endl;
	cout<<"---------"<<endl;
	cout<<"key.left.freq="<<key.left->freq<<" and key.right.freq="<<key.right->freq<<endl;
	cout<<endl;
	heap_size++;
	build_min_heap(a,heap_size);
}

int partition(Node a[],int p,int r){
	int i=p-1;
	Node pivot=a[r];
	Node temp;
	for(int j=p;j<r;++j){
		if(a[j].freq<pivot.freq){
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[i+1];
	a[i+1]=pivot;
	a[r]=temp;
	return i+1;
}

//快速排序复习，哈夫曼编码要用到,好像没有用到。。。权当复习
void quick_Sort(Node a[],int p,int r){
	if(p<r){
		int q=partition(a,p,r);
		quick_Sort(a,p,q-1);
		quick_Sort(a,q+1,r);	
	}
}
Node* huffman_Encoding(Node a[],int length){
	Node *b=new Node[length];
	for(int i=0;i<length;++i){
		b[i]=a[i];
	}
	for(int i=0;i<length;++i){
		cout<<b[i].freq<<" ";
	}
	cout<<endl;
	for(int i=1;i<length;++i){
		Node temp;
		Node x=heap_extract_min(b);
		cout<<"x.freq="<<x.freq<<endl;
		Node y=heap_extract_min(b);
		cout<<"y.freq="<<y.freq<<endl;
		temp.left=&x;
		temp.right=&y;
		temp.freq=x.freq+y.freq;
		cout<<"temp.freq="<<temp.freq<<endl;
		insert_heap(b,temp);
	}
	return &heap_extract_min(b);
}

int main(){
	Node a[15];
	int b[12]={23,4,1,5,7,1,3,2,90,76,56,8};
	for(int i=0;i<12;++i){
		a[i].freq=b[i];
	}
	
	build_min_heap(a,12);
	/*huffman_Encoding(a,12);
	for(int i=0;i<12;++i){
		cout<<a[i].freq<<" ";
	}
	cout<<endl;*/
	tree_preorder(huffman_Encoding(a,12));

	/*
	//测试最小优先队列好用
	build_min_heap(a,12);
	cout<<"原始的优先队列元素是:"<<endl;
	for(int i=0;i<12;i++){
		cout<<a[i].freq<<" ";
	}
	cout<<endl;
	cout<<"优先队列最小元素是:"<<heap_minimum(a).freq<<endl;
	cout<<heap_extract_min(a).freq<<endl;
	cout<<"删除最小元素之后："<<endl;
	for(int i=0;i<11;i++){
		cout<<a[i].freq<<" ";
	}
	cout<<endl;
	heap_decrease_key(a,10,0);
	cout<<"某个元素减小到0之后："<<endl;
	for(int i=0;i<11;i++){
		cout<<a[i].freq<<" ";
	}
	cout<<endl;
	Node t;
	t.freq=1;
	insert_heap(a,t);
	cout<<"插入一个1的元素之后："<<endl;
	for(int i=0;i<12;i++){
		cout<<a[i].freq<<" ";
	}
	cout<<endl;*/
	system("pause");
	return 0;
}