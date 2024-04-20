#include <iostream>
using namespace std;

class stack{
	
	public:
		int size = 0;
		int top = -1;
		char *items;
		
		stack(int stacksize){ //constructor
			size = stacksize;
			items = new char[size];
		}
		
		void push(char item){
			if (top==size-1){ //jika stack penuh
			cout << "ERROR: Stack Overflow, Stack is Full" << endl;
			} else {
				top++; //top=top+1;
				items[top] = item;
			}
		}
		
		char pop(){
			char item;
			
			if (top==-1){ //jika stack kosong
			cout << "ERROR: Stack is empty" << endl;
			} else {
				item = items[top];
				//items[top] = '';
				top--;
			}
			
			return item;
		}
};

int main(int argc, char** argv){
	
	stack kantong1(5);
	
	kantong1.push('J');
	kantong1.push('K');
	kantong1.push('L');
	kantong1.push('M');
	kantong1.push('N');
	kantong1.push('O');
	
	cout << kantong1.pop() << endl;
	cout << kantong1.pop() << endl;
	cout << kantong1.pop() << endl;
	cout << kantong1.pop() << endl;
	cout << kantong1.pop() << endl;
	cout << kantong1.pop() << endl;
	
	return 0;
}
