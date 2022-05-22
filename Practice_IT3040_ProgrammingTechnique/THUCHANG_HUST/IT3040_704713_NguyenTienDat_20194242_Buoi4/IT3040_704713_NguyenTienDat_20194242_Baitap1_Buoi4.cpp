#include <iostream> 
using namespace std;
struct Node { 
    int data; 
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    Node *new_node = new Node(data);
    new_node->next = head;
    
    head = new_node;
    return head;
}

// print the list content on a line
void print(Node* head) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    Node *tmp = head;
    while (tmp != NULL) {
    	cout << tmp->data << " ";
    	tmp = tmp->next;
	}
}

// return the new head of the reversed list
Node* reverse(Node* head) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    Node *cur = head, *pre = NULL; // pre tro toi node lien truoc cua node tro boi cur
    while (cur != NULL) {
    	Node* next = cur->next;
        
    	cur->next = pre;
    	pre = cur;
    	cur = next;
	}
	head = pre;
	return head;
}

// tra ve con tro dau cua ds da duoc dao nguoc
Node* reverse_recursive(Node *head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    
    Node* tmp = reverse_recursive(head->next);
    cout << "count ";
    (head->next)->next = head;        
    head->next = NULL;
    head = tmp;
    return head;
}
  
int main() {
    cout << "Ho ten: Nguyen Tien Dat\n" << "MSSV: 20194242\n";
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;
        head = prepend(head, u);
    } 
    
    cout << "Original list: ";
    print(head);
    cout << endl;

    //head = reverse(head);
    head = reverse_recursive(head);
    cout << "Reversed list: ";
    print(head);

    return 0; 
}
