#ifndef stack
#define stack

struct s{
	int boyut;
	int tepe;
	int * dizi;
};
typedef s * stack;
stack * tanim();
int pop(stack *);
void push(int,stack *);
void bastir(stack *);

#endif
