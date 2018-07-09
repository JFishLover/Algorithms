#include<iostream>
#include<stdlib.h>
#include<math.h>
#define error -pow(2.0,31)
using namespace std;

//震惊，引用都忘记了！
struct Stack{
	int a[100];
	int top;
	int capicity;
};
int stack_empty(Stack stack){
	if(stack.top==-1){
		return 1;
	}
	return 0;
}
int stack_push(Stack &stack,int ele){
	if(stack.top+1==stack.capicity)
		return error;
	stack.top=stack.top+1;
	cout<<"top="<<stack.top<<endl;
	stack.a[stack.top]=ele;
	cout<<stack.a[stack.top]<<endl;
	return ele;
}
int stack_pop(Stack &stack){
	if(stack_empty(stack))
		return error;
	stack.top--;
	return stack.a[stack.top+1];
}
int main(){
	Stack stack;
	stack.top=-1;
	stack.capicity=100;
	cout<<"top="<<stack.top<<endl;
	cout<<"刚开始:"<<endl;
	if(stack_empty(stack))
		cout<<"啥也没有哈哈哈"<<endl;
	else{
		cout<<"现在栈中有这几个元素："<<endl;
		for(int i=0;i<=stack.top;i++){
			cout<<stack.a[stack.top]<<" ";
		}
		cout<<endl;
	}
	cout<<"接下来放进去1、2和3。。。"<<endl;
	stack_push(stack,1);
	stack_push(stack,2);
	stack_push(stack,3 );
	if(stack_empty(stack))
		cout<<"啥也没有哈哈哈"<<endl;
	else{
		cout<<"现在栈中有这几个元素："<<endl;
		for(int i=0;i<=stack.top;i++){
			cout<<stack.a[i]<<" ";
		}
		cout<<endl;
	}
	cout<<"弹出一个元素"<<endl;
	stack_pop(stack);
	if(stack_empty(stack))
		cout<<"啥也没有哈哈哈"<<endl;
	else{
		cout<<"现在栈中有这几个元素："<<endl;
		for(int i=0;i<=stack.top;i++){
			cout<<stack.a[i]<<" ";
		}
		cout<<endl;
	}

	system("pause");
	return 0;
}