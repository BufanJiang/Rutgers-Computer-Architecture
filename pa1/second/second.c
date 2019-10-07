#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
} node;

void insertNode(node* head, int value);
void deleteNode(node* head, int value);
void printNode(node* head);
void freeNode(node* head);

void insertNode(node* head, int value){
	node *prev, *curr;
	node *target = (node*) malloc(sizeof(node));
	target->data = value;
	target->next = NULL;
	prev = head;
	curr = head->next;
	
	while(curr != NULL){
		if(curr->data < value){
			prev = curr;
			curr = curr->next;
		}
		else
		{
			prev->next = target;
			target->next = curr;
			return;
		}
	}
	prev->next = target;
}

void deleteNode(node* head, int value){
	node *prev, *curr;
		prev = head;
		curr = head->next;

	while(curr != NULL){
		if(curr->data == value){
			prev->next = curr->next;
			return;
		}
		else
		{
		prev = curr;
		curr = curr->next;
		}
	}
}

void printNode(node* head){
	node *p, *q;
	p = head->next;
	int num = 0;
	while(p != NULL){
		num++;
		p = p->next;
	}
	printf("%d\n", num);
	p = head->next;
	if(p != NULL)
	{
		printf("%d", p->data);
		q = p->next;
		while(q != NULL){
			if(p->data != q->data){
				printf("\t%d", q->data);
			}
			p = q;
			q = q->next;
		}
	}
	printf("\n");		
}
			
void freeNode(node* head){
	node *p, *q;
	p = head;
	q = head->next;
	while(q != NULL){
		p = q;
		q = q->next;
		free(p);
	}
}


int main(int argc, char* argv[]){
	FILE* fp;
	char c;
	int num;
	node* LL_head;
 	LL_head = (node*) malloc(20*sizeof(node));


	LL_head->data = 0;
	LL_head->next = NULL;

	if(argc < 2)
	{
		printf("Please input file\n");
		return 1;
	}
	
	fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		printf("error\n");
		return 1;
	}

	while(!feof(fp))
	{
		if(fscanf(fp, "%c\t%d\n", &c, &num) == 2)
		{
			if(c == 'i')
				insertNode(LL_head, num);
			else if(c == 'd')
				deleteNode(LL_head, num);
		}
	}

	fclose(fp);
	printNode(LL_head);
	freeNode(LL_head);
	return 0;
} 	

