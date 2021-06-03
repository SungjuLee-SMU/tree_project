#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct node {
	int data;
	struct node* link;
}node;

node* head = NULL;

node* Create(int data) {
	node* Nptr = new node;
	Nptr->data = data;
	Nptr->link = NULL;

	return Nptr;
}

bool IsEmpty() {
	if (head == NULL)
		return true;
	else
		return false;
}

void Destroy() {
	if (IsEmpty()) {
		cout << "Empty." << endl;
		return;
	}
	else {
		node* temp;
		while (head) {
			temp = head;
			head = head->link;
			free(temp);
		}
	}
}

void Add(int data) {
	node* newnode = Create(data);
	node* curr;

	curr = head;
	if (IsEmpty()) {
		head = newnode;
		return;
	}
	else if (head->data < newnode->data) {
		newnode->link = head;
		head = newnode;
		return;
	}
	else
	{
		while (curr->link != NULL) {
			if (curr->link->data < newnode->data) {
				newnode->link = curr->link;
				curr->link = newnode;
				return;
			}
			curr = curr->link;
		}
	}
	curr->link = newnode;
}

void Remove() {
	if (IsEmpty()) {
		cout << "Empty." << endl;
		return;
	}
	else {
		node* temp;
		temp = head;
		head = head->link;
		free(temp);
	}
}

int main() {

	Add(100);
	Add(30);
	Add(50);
	Add(150);

	Destroy();

	Add(70);
	Add(60);
	Add(25);
	Add(90);

	Remove();

	Add(85);

	node* PQ;
	PQ = head;
	while (PQ->link != NULL) {
		cout << PQ->data << endl;
		PQ = PQ->link;
	}
	cout << PQ->data << endl;

	return 0;
}