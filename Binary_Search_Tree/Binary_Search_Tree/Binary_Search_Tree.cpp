#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node{
	Node * parent;
	int value;
	Node * left;
	Node * right;
};
class BinaryTree{
public:
	Node * head;
public:
	BinaryTree(){
		head=NULL;
	}
	//前序
	void tree_Preorder(Node * node){
		if(node!=NULL){
			cout<<node->value<<" ";
			tree_Preorder(node->left);			
			tree_Preorder(node->right);
		}	
	}
	//中序
	void tree_Inorder(Node * node){
		if(node!=NULL){
			tree_Inorder(node->left);
			cout<<node->value<<" ";
			tree_Inorder(node->right);
		}	
	}
	//后序
	void tree_Postorder(Node * node){
		if(node!=NULL){
			tree_Postorder(node->left);
			tree_Postorder(node->right);
			cout<<node->value<<" ";
		}	
	}
	//查找
	Node * tree_Search(Node * node1,int x){
		while(node1!=NULL&&node1->value!=x){
			if(node1->value<x)
				node1=node1->left;
			else
				node1=node1->right;
		}
		return node1;
	}
	//最小值
	Node * tree_Minimum(Node * node2){
		while(node2->left!=NULL){
			node2=node2->left;
		}
		return node2;
	}
	//最大值
	Node * tree_Maximum(Node * node3){
		while(node3->right!=NULL){
			node3=node3->right;
		}
		return node3;
	}
	//后继节点
	Node * tree_Successor(Node * node4){
		if(node4->right!=NULL)
			return tree_Minimum(node4->right);
		Node * node5=node4->parent;
		while(node5!=NULL&&node5->right==node4){
			node4=node5;
			node5=node5->parent;
		}
		return node5;
	}
	//前驱结点
	Node * tree_Predecessor(Node * node6){
		if(node6->left!=NULL){
			return tree_Maximum(node6->left);
		}
		Node * node7=node6->parent;
		while(node7!=NULL&&node7->left==node6){
			node6=node7;
			node7=node7->parent;
		}
		return node7;
	}
	//插入新结点
	void tree_Insert(Node * node8){
		Node * node9=NULL;
		Node * node10=head;
		while(node10!=NULL){
			node9=node10;//先记录下不空的结点
			if(node8->value<node10->value)
				node10=node10->left;
			else
				node10=node10->right;
		}
		node8->parent=node9;
		//分情况给子结点赋值,node9可能为空
		if(node9==NULL){
			head=node8;
		}else if(node8->value>node9->value)
			node9->right=node8;
		else
			node9->left=node8;
	}
	//取代函数，delete要用到
	//v取代u的位置，只改变和父节点的关系，这里V可能是NULL
	void tree_Transplant(Node * u,Node * v){
		if(u->parent==NULL){
			head=v;
		}else if(u==u->parent->left)
			v=u->parent->left;
		else
			v=u->parent->right;
		//前面的工作是关联了父节点的孩子，下面指出孩子的父节点，这是一个双向关系
		if(v!=NULL)
			v->parent=u->parent;
		
	}
	void tree_Delete(Node * node){
		if(node->left==NULL){
			tree_Transplant(node,node->right);			
		}else if(node->right==NULL){
			tree_Transplant(node,node->left);
		}else{
			Node * succ=tree_Successor(node);
			if(node->right!=succ){//后继不是右节点
				tree_Transplant(succ,succ->right);
				succ->right=node->right;
				node->right->parent=succ;
			}
			//后继不管是不是右节点通用代码
			tree_Transplant(node,succ);
			succ->left=node->left;
			node->left->parent=succ;
		}
	}
};
int main(){
	BinaryTree *tree=new BinaryTree();
	Node *node1=new Node();
	Node *node2=new Node();
	Node *node3=new Node();
	Node *node4=new Node();
	Node *node5=new Node();
	node1->value=3;
	node2->value=4;
	node3->value=2;
	node4->value=1;
	node5->value=6;
	tree->tree_Insert(node1);
	tree->tree_Insert(node2);
	tree->tree_Insert(node3);
	tree->tree_Insert(node4);
	tree->tree_Insert(node5);
	cout<<"前序遍历"<<endl;
	tree->tree_Preorder(tree->head);
	cout<<endl;
	cout<<"中序遍历"<<endl;
	tree->tree_Inorder(tree->head);
	cout<<endl;
	cout<<"后序遍历"<<endl;
	tree->tree_Postorder(tree->head);
	cout<<endl;
	cout<<"head指向"<<tree->head->value<<endl;
	cout<<"head的前趋是"<<tree->tree_Predecessor(tree->head)->value<<endl;
	cout<<"head的后继是"<<tree->tree_Successor(tree->head)->value<<endl;
	cout<<"该树的最大值为"<<tree->tree_Maximum(tree->head)->value<<endl;
	cout<<"该树的最小值为"<<tree->tree_Minimum(tree->head)->value<<endl;
	cout<<"寻找值为5的结点,后边输出就对了啊"<<endl;
	if(tree->tree_Search(tree->head,5)!=NULL){
		cout<<tree->tree_Search(tree->head,5)->value;
		cout<<"哈哈哈，找到了"<<endl;
	}else
		cout<<"对不起，您要找的值不存在，请检查参数。"<<endl;
	cout<<"删除node1对应的3之后"<<endl;
	tree->tree_Delete(node1);
	cout<<"前序遍历"<<endl;
	tree->tree_Preorder(tree->head);
	cout<<endl;
	cout<<"中序遍历"<<endl;
	tree->tree_Inorder(tree->head);
	cout<<endl;
	cout<<"后序遍历"<<endl;
	tree->tree_Postorder(tree->head);
	cout<<endl;
	cout<<"测试通过哈哈哈哈"<<endl;
	system("pause");
	return 0;
}