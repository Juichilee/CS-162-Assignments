#ifndef LIST_H
#define LIST_H

struct node{
	int val;
	struct node* next;
};

int length(struct node*); //get the length of the list
void print(struct node*, int); //print a certain number of elements from the list starting from the first node.
struct node* push(struct node*, int); //put at front
struct node* append(struct node*, int); //put at back
struct node* clear(struct node*); //delete entire list
struct node* remove_node(struct node*, int); //delete a particular node
struct node* sort_ascending(struct node*); //sort the nodes in ascending order
struct node* sort_descending(struct node*); //sort the nodes in descending order
struct node* insert_middle(struct node*, int val, int idx); //insert into specific location in the list. 
#endif
