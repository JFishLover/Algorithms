#include<iostream>
#include<stdlib.h>
#include<math.h>
#define error -pow(2.0,31)
using namespace std;
struct Queue{
	int a[100];
	int head;
	int tail;
	int length;
};
bool queue_empty(Queue queue){
	if(queue.head==queue.tail)
		return true;
	return false;
}
int enqueue(Queue &queue,int ele){
	if((queue.tail+1)%queue.length==queue.head)
		return error;
	queue.a[queue.tail]=ele;
	queue.tail=(queue.tail+1)%queue.length;
	return ele;
}
int dequeue(Queue &queue){
	if(queue_empty(queue))
		return error;
	int x=queue.a[queue.head];
	queue.head=(queue.head+1)%queue.length;
	return x;
}
int main(){
	Queue queue;
	queue.head=0;
	queue.tail=0;
	queue.length=100;
	cout<<"开始："<<endl;
	cout<<"queue.head="<<queue.head<<endl;
	cout<<"queue.tail="<<queue.tail<<endl;
	cout<<"压入1和2"<<endl;
	enqueue(queue,1);
	enqueue(queue,2);
	cout<<"queue.head="<<queue.head<<endl;
	cout<<"queue.tail="<<queue.tail<<endl;
	for(int i=queue.head;i<queue.tail;++i){
		cout<<queue.a[i]<<" "<<endl;
	}
	cout<<endl;
	dequeue(queue);
	cout<<"出来一个"<<endl;
	cout<<"queue.head="<<queue.head<<endl;
	cout<<"queue.tail="<<queue.tail<<endl;
	for(int i=queue.head;i<queue.tail;++i){
		cout<<queue.a[i]<<" "<<endl;
	}
	cout<<endl;
	system("pause");
	return 0;
}