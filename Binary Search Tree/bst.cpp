#include <iostream> 
using namespace std;

class Node{ 
	public: 
		Node *left; 
		Node *right; 
		int key; 
		Node(){ 
			left = right = NULL; 
		} 
};

class BST{ 
	public: 
		Node *root;

   		BST(){
       		root = NULL;
   		}
   
   		Node* insertRecursive(int newKey, Node *currentRoot){
       		if (currentRoot==NULL){
           		Node *newNode = new Node();
           		newNode->key = newKey;
          	 	return newNode;
       		}
       		
       		if(newKey < currentRoot->key){
           		currentRoot->left = insertRecursive(newKey, currentRoot->left);	
       		}else if (newKey > currentRoot->key){
             	currentRoot->right = insertRecursive(newKey, currentRoot->right);
       		}
       		
       		return currentRoot;
   		}
   
   		void insert(int newKey){
       		root = insertRecursive(newKey, root);
   		}
   
   		void preOrderRecursive(Node *currentRoot){
       		if (currentRoot!=NULL){
           		cout << currentRoot->key <<" ";
          		preOrderRecursive(currentRoot->left);
           		preOrderRecursive(currentRoot->right);
       		}
   		}
   		
   		void inOrderRecursive(Node *currentRoot){
       		if (currentRoot!=NULL){
           		inOrderRecursive(currentRoot->left);
           		cout << currentRoot->key <<" ";
           		inOrderRecursive(currentRoot->right);
       		}
  		}
   
   		void postOrderRecursive(Node *currentRoot){
       		if (currentRoot!=NULL){
           		postOrderRecursive(currentRoot->left);
           		postOrderRecursive(currentRoot->right);
           		cout << currentRoot->key <<" ";
       		}
   		}
   
   		void preOrderTraversal(){
       		preOrderRecursive(root);
       		cout << endl;
   		}
   
  		void inOrderTraversal(){
       		inOrderRecursive(root);
       		cout << endl;
   		}
   
   		void postOrderTraversal(){
       		postOrderRecursive(root);
       		cout << endl;
   		}
};

int main(int argc, char** argv) {

	BST *bin1 = new BST();

	bin1->insert(6);
	bin1->insert(7);
	bin1->insert(4);
	bin1->insert(6); // Angka yang sama
	bin1->insert(5);
	bin1->insert(3);

	// Print Pre-order traversal
	bin1->preOrderTraversal(); // OUTPUT 6 4 3 7 5

	// Print In-order traversal
	bin1->inOrderTraversal(); // OUTPUT 3 4 5 6 7

	// Print Post-order traversal
	bin1->postOrderTraversal(); // OUTPUT 3 5 4 7 6

	return 0;
}
