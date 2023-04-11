/****************************************
 ** Program Filename: list.c
 ** Author: Juichi Lee
 ** Description: .c file for assignment 5
 ** Date: 11/30/18
 * *************************************/
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int length(struct node* head){

	int count = 0;

	struct node* current = head;

	while(current != NULL){

		count ++;

		current = current->next;

	}

	return count;

} //get the length of the list

void print(struct node* head, int num){

	struct node* current = head;

	int i = 0;

	printf("Your Linked list is: ");

	for(i = 0; i < num; i++){

		printf("%d", current->val);
		
		printf(" ");

		current = current->next;

	}

	printf("\n");
	
} //print a certain number of elements from the list starting from the first node.

struct node* push(struct node* a, int value){

	struct node* new_node = (struct node*)malloc(sizeof(struct node));

	new_node->val = value;

	new_node->next = a;

	return new_node;

} //put at front

struct node* sort_ascending(struct node* head){

	struct node *prevNode, *currNode, *tempNode;

	int count = length(head);

	int i = 0; 

	if(head == NULL || head->next == NULL){

		return head;

	}	

	currNode = head;

	for(i = 1; i < count; i++){

		currNode = prevNode = head;

		while(currNode != NULL && currNode->next != NULL){

			if(currNode->val > currNode->next->val){

				tempNode = currNode->next;

				currNode->next = currNode->next->next;

				tempNode->next = currNode;

				if(head == currNode){

					head = prevNode = tempNode;

				}else{

					prevNode->next = tempNode;

					currNode = tempNode;

				}

			}

			prevNode = currNode;

			currNode = currNode->next;

		}

	}	

	return head;

} //sort the nodes in ascending order

struct node* sort_descending(struct node* head){

	struct node *prevNode, *currNode, *tempNode;

	int count = length(head);

	int i = 0; 

	if(head == NULL || head->next == NULL){

		return head;

	}	

	currNode = head;

	for(i = 1; i < count; i++){

		currNode = prevNode = head;

		while(currNode->next != NULL){

			if(currNode->val < currNode->next->val){

				tempNode = currNode->next;

				currNode->next = currNode->next->next;

				tempNode->next = currNode;

				if(head == currNode){

					head = prevNode = tempNode;

				}else{

					prevNode->next = tempNode;

					currNode = tempNode;

				}

			}

			prevNode = currNode;

			currNode = currNode->next;

		}

	}	

	return head;

} //sort the nodes in descending order

struct node* clear(struct node* head){

	struct node* removeptr;

	while(head != NULL){

		removeptr = head;

		head = head->next;

		free(removeptr);

	}

	head = NULL;

	return head;
} //delete entire list

