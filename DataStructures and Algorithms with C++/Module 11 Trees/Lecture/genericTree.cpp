#include<bits/stdc++.h>
using namespace std;
#include "TreeNode.h"

//insert node level wise
Node<int>* inputLevelWiseTree()
{
	int data;
	cout << "Input root data : \n";
	cin>>data;
	Node<int> *root =  new Node<int>(data);
	queue< Node<int>* > q;
	q.push(root);
	while(!q.empty())
	{
		Node<int>* node = q.front();
		q.pop();
		int num;
		cout << "Enter number of children for node " << node->data << " : \n";
		cin>>num;
		for(int i=0;i<num;i++){
			cout << "Enter " << (i+1) << "child of " << node->data << " : \n";
			cin>>data;
			Node<int>* child = new Node<int>(data);
			node->children.push_back(child);
			q.push(child);
		}
	}
	return root;
}

//print tree level order wise
void printTreeLevelOrder(Node<int>* root)
{
	cout << "Print Tree levelwise : \n";
	if(root == NULL){
		return;
	}
	queue< Node<int>* > q;
	q.push(root);
	while(!q.empty()){
		Node<int>* node = q.front();
		q.pop();
		cout << node->data << " : ";
		for(int i=0;i<node->children.size();i++)
		{
			cout << node->children.at(i)->data << ", ";
			q.push(node->children.at(i));
		}
		cout << "\n";
	}
}


//print all the nodes at level\depth K 
void printAtDepthK(Node<int>* root, int k)
{
	if(root == NULL)
	{
		return;
	}
	if(k == 0){
		cout << root->data << " ";
		return;
	}
	for(int i=0;i<root->children.size();i++){
		printAtDepthK(root->children.at(i), k-1);
	}
}

void preOrder(Node<int>* root){
	if(root == NULL){
		return;
	}
	cout << root->data << " ";
	for(int i=0;i<root->children.size();i++)
	{
		preOrder(root->children.at(i));
	}
}


// 10 3 20 30 40 2 50 60 0 0 1 70 0 0
int main()
{
	Node<int>* root = inputLevelWiseTree(); //take input levelwise
	printTreeLevelOrder(root);
	int k = 2;
	cout << "print all the nodes at depth : " << k << "\n";
	printAtDepthK(root, k);
	cout << "\nPreOrder traversal of generic tree :\n";
	preOrder(root);
	cout << "\n";
	cout << "Now deleting Generic Tree....\n";
	delete root; //work in done in destructor of root tree node
	return 0;
}