#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	struct ListNode* Llink;
	int data;
	struct ListNode* Rlink;
} DLinklist;

DLinklist* createNode(void) {
	DLinklist* tmp;
	tmp = (DLinklist*)malloc(sizeof(DLinklist));
	tmp->Llink = NULL;
	tmp->Rlink = NULL;
}

void insert(DLinklist** head, int data) {
	if (!*head) {
		*head = createNode();
		(*head)->data = data;
		return;
	}
	insert(&(*head)->Rlink, data);
	(*head)->Rlink->Llink = *head;
}

void add(DLinklist** head, int data1, int data2) {
	DLinklist* tmp = NULL;
	if (!*head)
		printf("No data\n");
	else if ((*head)->data == data1) {
		insert(&tmp, data2);
		tmp->Llink = *head;
		tmp->Rlink = (*head)->Rlink;
		(*head)->Rlink->Llink = tmp;
		(*head)->Rlink = tmp;
	}
	else {
		add(&(*head)->Rlink, data1, data2);
	}
}

void delete(DLinklist** head, int data) {
	DLinklist* tmp = NULL;
	if ((*head)->data == data) {
		tmp = *head;
		if ((*head)->Rlink == NULL) {
			tmp = *head;
		}
		else {
			*head = (*head)->Rlink;
			(*head)->Llink = (*head)->Llink->Llink;
		}
		free(tmp);
	}
	else
		delete(&(*head)->Rlink, data);
}

void printList(DLinklist** head) {
	if (*head) {
		printf("%d\n", (*head)->data);
		printfList(&(*head)->Rlink);
	}
}

int main(void) {
	DLinklist* head = NULL;

	insert(&head, 10);
	insert(&head, 20);
	insert(&head, 30);
	printList(&head);
	getchar();
	printf("\n");

	add(&head, 10, 15);
	add(&head, 20, 25);
	printList(&head);
	getchar();
	printf("\n");

	delete(&head, 20);
	printList(&head);
	getchar();
	printf("\n");

	return 0;
}