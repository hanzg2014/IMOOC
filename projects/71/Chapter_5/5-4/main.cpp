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
		count = 0;
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
 
	//調用 private 函數 insert
	void insert(Key key, Value value){
		root = insert(root, key, value);	
	}

	bool contain(Key key){
		return contain(root, key);
	}

	Value* search(Key key){
		return search(root, key);
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

	bool contain(Node *node, Key key){
		if(node == NULL)
			return false;
		if(key == node->key)
			return true;
		else if(key < node->key)
			return contain(node->left, key);
		else
			return contain(node->right, key);
	}

	bool search(Node* node, Key key){
		if (node == NULL)
			return NULL;
		if(key == node->key)
			return &(node->value);
		else if(key < node->key)
			return search(node->left, key);
		else
			return search(node->right, key);
	}
};


int main(){
	cout<<"Hello world"<<endl;
	return 0;
}