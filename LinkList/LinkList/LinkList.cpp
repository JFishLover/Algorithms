#include<iostream>
#include<stdlib.h>

using namespace std;
//没有哨兵的双向链表
//惊了，终于对了，指针千万不要图省事用相同的名字！！！！！！
struct Node{
	Node *prev;
	Node *next;
	int val;
};
class LinkList{
public:
	Node * head;
public:
	LinkList(){
		head=new Node();
		head=NULL;
	}
	Node* link_search(int key){
		Node * node4=head;
		while(node4!=NULL&&node4->val!=key)
			node4=node4->next;
		return node4;
	}
	//传进来的参数应该是指针，指针只能用->，不能用.
	void link_insert(Node * node){
		node->next=head;
		//cout<<"1111111111"<<endl;
		if(head!=NULL)
			head->prev=node;
		head=node;
		node->prev=NULL;
		//cout<<"33333"<<endl;
	}
	void link_delete(Node * node){
		if(node->prev!=NULL){
			node->prev->next=node->next;
		}else{
			head=node->next;
		}
		if(node->next!=NULL){
			node->next->prev=node->prev;		
		}
	}
};

int main(){;
	LinkList *linklist=new LinkList();

	//linklist.head=NULL;
	Node * node=new Node();
	Node * node1=new Node();
	node->val=1;
	linklist->link_insert(node);
	cout<<"head指向谁     答案是："<<linklist->head->val<<endl;
	node1->val=2;
	linklist->link_insert(node1);
	Node *temp=linklist->head;
	cout<<"head指向谁     答案是："<<temp->val<<endl;
	cout<<"插入两个值之后："<<endl;
	while(temp!=NULL){
		cout<<"结点的值为："<<temp->val<<endl;
		temp=temp->next;
		//if(temp!=NULL)
			//cout<<"22222222"<<endl;
	}
	int key=3;
	cout<<"寻找值为"<<key<<"的元素,下一行是"<<key<<"就对了，否则就错了"<<endl;
	if(linklist->link_search(key)!=NULL)
		cout<<linklist->link_search(key)->val<<endl;
	else
		cout<<"您要找的元素没有啊"<<endl;
	cout<<"删除一个元素之后："<<endl;
	Node * node2=linklist->head;
	linklist->link_delete(node2);
	Node * node3=linklist->head;
	while(node3!=NULL){
		cout<<"结点的值为："<<node3->val<<endl;
		node3=node3->next;
	}
	system("pause");
	return 0;
}