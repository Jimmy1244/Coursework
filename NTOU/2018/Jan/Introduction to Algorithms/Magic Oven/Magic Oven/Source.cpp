#include<iostream>
#include<string>

using namespace std;

class Node {
public:
	Node():weight(0),serial(0), next(0) {}
	~Node() {}
	Node * BST(const int key);
	int weight;
	int serial;
	Node *next;
};

Node* Node::BST(const int key) {//回傳新位置的上一個

}

int main() {
	int instructNum, i, count = 0, ovenSize = 0;
	Node *head, *ptr;
	string instruct;
	cin >> instructNum;
	for (i = 0; i < instructNum; i++) {
		cin >> instruct;
		if (instruct == "DIOU") {
			int weight;
		}
		else if (instruct == "MUMIMUMI") {

		}
		else if (instruct == "<3DONGDONG") {

		}
	}
	return 0;
}