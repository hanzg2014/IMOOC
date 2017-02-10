#include <iostream>

using namespace std;

class BST{
private:
	struct Node{
		Key key;
		Value value;
		Node *left;
		Node *right;

		Node(Key key, Value value){
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}
	};

	Node *root;
	int count;

public:
	BST(){
		root = NULL;
		count = 0
	}
	~BST(){
		//TODO: ~BST()
	}

	int size(){
		return count;
	}

	bool isEmpty(){
		return count == 0;
	}

	void insert(Key key, Value value){
		root = insert(root, key, value);
	}

private:
	//以node為根的二叉搜索樹中插入節點(key, value)
	//返回插入之後的新節點的根
	Node * insert(Node *node, Key key, Value value){

		if(node == NULL){	//插入一個新元素
			count ++;
			return new node(key, value);
		}
		
		if(key == node->key)
			node->value = value;
		else if(key < node->key)
			node->left = insert(node->left, key, value);
		else if(key > node->key)
			node->right = insert(node->right, key, value);
	}
};


int main(){
	cout<<"Hellow world"<<endl;
	return 0;

}