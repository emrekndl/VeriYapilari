#ifndef stackLinkedlist
#define stackLinkedlist

struct n{
	n * next;
	int data;
};
typedef n node;
int pop(node *);
node * push(node *,int);
void bastir(node *);

#endif
