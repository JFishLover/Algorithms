#include<iostream>
#include<stdlib.h>

using namespace std;
//û���ڱ���˫������
//���ˣ����ڶ��ˣ�ָ��ǧ��Ҫͼʡ������ͬ�����֣�����������
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
	//�������Ĳ���Ӧ����ָ�룬ָ��ֻ����->��������.
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
	cout<<"headָ��˭     ���ǣ�"<<linklist->head->val<<endl;
	node1->val=2;
	linklist->link_insert(node1);
	Node *temp=linklist->head;
	cout<<"headָ��˭     ���ǣ�"<<temp->val<<endl;
	cout<<"��������ֵ֮��"<<endl;
	while(temp!=NULL){
		cout<<"����ֵΪ��"<<temp->val<<endl;
		temp=temp->next;
		//if(temp!=NULL)
			//cout<<"22222222"<<endl;
	}
	int key=3;
	cout<<"Ѱ��ֵΪ"<<key<<"��Ԫ��,��һ����"<<key<<"�Ͷ��ˣ�����ʹ���"<<endl;
	if(linklist->link_search(key)!=NULL)
		cout<<linklist->link_search(key)->val<<endl;
	else
		cout<<"��Ҫ�ҵ�Ԫ��û�а�"<<endl;
	cout<<"ɾ��һ��Ԫ��֮��"<<endl;
	Node * node2=linklist->head;
	linklist->link_delete(node2);
	Node * node3=linklist->head;
	while(node3!=NULL){
		cout<<"����ֵΪ��"<<node3->val<<endl;
		node3=node3->next;
	}
	system("pause");
	return 0;
}