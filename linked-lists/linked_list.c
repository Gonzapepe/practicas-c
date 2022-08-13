// node of the linked list
#include <stddef.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};

void printList(struct Node*);

// Function to print the linked list
void printList(struct Node* n) {
	while (n != NULL) {
		printf("%d ", n->data);
		n = n->next;
	}
}

// inserts item at the beginning
void push_front(struct Node** head_ref, int new_data) {
	// Allocate memory to new node
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	
	if (new_node) {
		// Put in the data
		new_node->data = new_data;

		// Make next of new node as head
		new_node->next = (*head_ref);
	}
	


	// move the head to point to the new node
	(*head_ref) = new_node;
}

// Inserts item at the end
void append(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  
    struct Node* last = *head_ref;  /* used in step 5*/
  
    /* 2. put in the data  */
	if (new_node) {
		new_node->data = new_data;

		/* 3. This new node is going to be the last node, so make next of
			  it as NULL*/
		new_node->next = NULL;
	}
    
  
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }
  
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
  
    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}

void insert_after(struct Node* prev_node, int new_data) {
	if (prev_node == NULL) {
		printf("The given previous node cannot be NULL");
		return;
	}

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	if (new_node) {
		new_node->data = new_data;

		new_node->next = prev_node->next;
	}
	

	prev_node->next = new_node;
}

void test_print() {
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));

	struct Node* second = (struct Node*)malloc(sizeof(struct Node));

	struct Node* third = (struct Node*)malloc(sizeof(struct Node));

	// checking if it exists to avoid warnings
	if (head) {
		head->data = 1;
		head->next = second;

	}
	if (second) {
		second->data = 2;
		second->next = third;

	}
	
	if (third) {
		third->data = 3;
		third->next = NULL;
	}

	printList(head);
}

void test_push() {
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	if (head) {
		head->data = 1;
		head->next = NULL;
	}

	push_front(&head, 5);

	printList(head);
}

void test_append() {
	struct Node* head = NULL;

	append(&head, 5);
	append(&head, 6);
	append(&head, 7);

	printList(head);
}

void test_insert_after() {
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	struct Node* second = (struct Node*)malloc(sizeof(struct Node));
	if (head) {
		head->data = 1;
		head->next = second;
	}
	if (second) {
		second->data = 2;
		second->next = NULL;
	}
	insert_after(head, 5);

	printList(head);
}