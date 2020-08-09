#include<iostream>
#include<sstream>
#include<string.h>

using namespace std;

class heap;

class node {
public:
	node(int cakeNums) //constructor: init
	:pancakeNums(cakeNums), g(0), previousAction(0)
	{
		int i;
		for (i = 0; i < pancakeNums; i++) {
			cin >> state[i];
		}
		h = gapNumber();
		f = g + h;
	}

	node(int cakeNums, int sG, int* previousState) //constructor: successor
	:pancakeNums(cakeNums), g(sG)
	{
		int i;
		for (i = 0; i < pancakeNums; i++) {
			state[i] = previousState[i];
		}
	}

	node()
		:f(0), h(0)
	{

	}

	~node() {}

	bool isGoal() {
		int i;
		for (i = 0; i < pancakeNums; i++) {
			if (state[i] != i)
				return false;
		}
		return true;
	}

	int gapNumber() {
		int count = 0, i;
		for (i = 0; i < pancakeNums - 1; i++) {
			if (state[i + 1] != state[i] + 1 && state[i + 1] != state[i] - 1) //�`�O�|�V���V��gap=>�ڲq�o�˷|���I�F�ӥB�p�Gcontinue�g�bif���U�A�i�ण�|�Q�w�B�z
				count++;
		}
		return count;
	}

	void generateState(int action, node* sLast){
		int i;
		for(i = 0; i < action / 2; i++){
			int tmp = state[i];
			state[i] = state[action - i -1];
			state[action - i -1] = tmp;
		}
		h = gapNumber();
		f = g + h;
		previousAction = action;
		last = sLast;
	}

	void printNode(){
		int i;
		cout << '(' << previousAction << ") [" << state[0];
		for(i = 1; i < pancakeNums; i++){
			cout << ' ' <<state[i];
		}
		cout << "]" << endl;
	}

	void constructSuccessor(heap*);

	int getF(){
		return f;
	}

	int getOrder() {
		return order;
	}

	int getH() {
		return h;
	}

	void setOrder(int counter) {
		order = counter;
	}

	int getG() {
		return g;
	}

	bool isComplete() {
		return (h == 0 && state[0] == 0);
	}

	node* getLast() {
		return last;
	}

private:
	int pancakeNums;
	int state[300];
	int g;//actual cost
	int h;//huristic
	int f;//g + h
	int previousAction;
	int order;
	node* last;
};

class heap {
public:
	heap()
	:lastLeaf(0), orderCounter(0)
	{
		nodes[0] = new node; //f = 0;
	}

	~heap() {
		while (lastLeaf >= 0) {
			delete nodes[lastLeaf--];
		}
	}

	void insert(node *insertNode){
		int i;
		for(i = ++lastLeaf; insertNode->getF() < nodes[i / 2]->getF(); i /= 2){
			nodes[i] = nodes[i /2];
		}
		nodes[i] = insertNode;
		nodes[i]->setOrder(++orderCounter);
	}

	void heapify(){
		node * lastNode = nodes[lastLeaf--];
		int i;
		for(i = 1; i * 2 <= lastLeaf;){
			int child = i * 2;
			if (child + 1 <= lastLeaf) {
				if(nodes[child + 1]->getF() < nodes[child]->getF() || (nodes[child + 1]->getF() == nodes[child]->getF() && nodes[child + 1]->getOrder() < nodes[child]->getOrder()))
					child++;
			}
			if (nodes[child]->getF() < lastNode->getF() || (nodes[child]->getF() == lastNode->getF() &&nodes[child]->getOrder() < lastNode->getOrder())) {
				nodes[i] = nodes[child];
			}
			else
				break;
			i = child;
		}
		nodes[i] = lastNode;
	}

	node* pop(){
		node* min = nodes[1];
		heapify();
		return min;
	}

	int isEmpty(){
		return lastLeaf;
	}
	
	void printAll() {
		int i;
		for (i = 1; i <= lastLeaf; i++) {
			nodes[i]->printNode();
		}
	}

private:
	node** nodes = (node**)malloc(sizeof(node*) * 2000000);
	int lastLeaf;
	int orderCounter;
};

void node::constructSuccessor(heap *nodeHeap) {
	int i;
	for (i = 2; i <= pancakeNums; i++) {
		if (i == previousAction) //prevent from go back to previos state
			continue;
		node * nodeT = new node(pancakeNums, g + 1, state);
		nodeT->generateState(i, this);
		nodeHeap->insert(nodeT);
	}
}


int main() {
	int s, e, steps;
	heap nodeHeap;
	int cakeNums;
	cin >> cakeNums;
	node * nodeP = new node(cakeNums);
	node * nodesPath[100];
	do {
		nodeP->constructSuccessor(&nodeHeap);
		nodeP = nodeHeap.pop();
	} while (!nodeP->isComplete());
	e = nodeP->getG();
	node* nodeT = nodeP;
	while (e) {
		nodesPath[e--] = nodeP;
		nodeP = nodeP->getLast();
	}
	for (e = 1; e <= nodeT->getG(); e++) {
		nodesPath[e]->printNode();
	}
	double h = 0;
	/*while (h < 2000000000) {//2000000000
		h++;
	}*/
	return 0;
}
