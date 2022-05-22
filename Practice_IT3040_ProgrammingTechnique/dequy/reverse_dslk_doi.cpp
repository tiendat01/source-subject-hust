// de bai: reverse ds lk doi
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next, *pre;
};

Node* append(Node *head, int d) {
	Node *newNode = new Node;
	newNode->data = d;
	newNode->pre = NULL;
	newNode->next = NULL;
	if (head == NULL) {
		head = newNode;	
	}
	else {
		Node *tmp = head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = newNode;
		newNode->pre = tmp;
	}
	return head;
}

Node* reverse_loop(Node *head) {
	Node *cur = head, *pre = NULL;
	while (cur != NULL) {
		Node *next = cur->next;
		cur->next = pre;
		cur->pre = next;
		pre = cur;
		cur = next;
	}
	head = pre;
	return head;
}

Node* reverse_recursion(Node *head) {
	if (head == NULL) return NULL;
	if (head->next == NULL) return head; 

	Node *tmp = reverse_recursion(head->next);
	(head->next)->next = head;
	head->pre = head->next;
	head->next = NULL;

	head = tmp;
	return head;
}

void inds(Node *head) {
	Node *tmp = head;
	cout << "Danh sach: \n";
	while (tmp != NULL) {
		cout << (tmp->data) << " ";
		tmp = tmp->next;
	}
}

int main() {
	Node *ds = NULL;
	ds = append(ds, 1);
	ds = append(ds, 2);
	ds = append(ds, 3);
	ds = append(ds, 4);
	ds = append(ds, 5);
	inds(ds);
	// cout << endl;
	// inds(ds = reverse_loop(ds));
	cout << endl;
	inds(reverse_recursion(ds));

}


// de bai: 
// int y(int n);
// int x(int n) {
// 	if (n < 5) return n;
// 	return x(n-1) + y(n-2) + x(n-3) + y(n-4); 
// }
// int y(int n) {
// 	if (n < 5) return 2*n;
// 	return y(n-1) + x(n-3) + 
// }
