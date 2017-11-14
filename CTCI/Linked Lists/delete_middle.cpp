#include <iostream>

using namespace std;

struct Node {
	int data;
	Node * next;
};

void print_list(Node*);
void delete_list(Node*);
void delete_middle(Node*, int);

int main() {

	Node * Node0 = new Node();
	Node * Node1 = new Node();
	Node * Node2 = new Node();
	Node * Node3 = new Node();
	Node * Node4 = new Node();
	Node * Node5 = new Node();
	Node * Node6 = new Node();

	Node0->data = 7;
	Node0->next = Node1;

	Node1->data = 6;
	Node1->next = Node2;	

	Node2->data = 5;
	Node2->next = Node3;	

	Node3->data = 4;
	Node3->next = Node4;

	Node4->data = 3;
	Node4->next = Node5;		

	Node5->data = 2;
	Node5->next = Node6;	

	Node6->data = 1;
	Node6->next = nullptr;	

	cout << "Original List: ";

	print_list(Node0);

	cout << "Please enter a middle node you would like to delete: ";

	int data;
	cin >> data;

	while (Node0->data == data) {

		cout << endl;
		cout << "Invalid choice. Please enter a middle node: ";
		cin >> data;

	} // while

	cout << endl;

	delete_middle(Node0, data);

	cout << "New list: ";

	print_list(Node0);

	delete_list(Node0);

	return 0;

} // main()

void print_list(Node * head) {

	while (head != nullptr) {

		cout << head->data << " ";
		head = head->next;

	} // while

	cout << endl << endl;

} // print_list()

void delete_list(Node * head) {

	if (head == nullptr) { return; }

	delete_list(head->next);

	delete head;

} // delete_list()

void delete_middle(Node * head, int data) {

	Node * prev = nullptr;

	while (head != nullptr) {

		if (head->data == data) {

			prev->next = head->next;
			delete head;

		} // if

		prev = head;
		head = head->next;

	} // while

} // delete_middle()