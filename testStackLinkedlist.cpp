#include <stdio.h>
#include <stdlib.h>
#include "stackLinkedlist.h"

int main(){
        node * s = NULL;
        s = push(s,10);
        s = push(s,20);
        printf("%d -> ",pop(s));
        s = push(s,30);
        printf("%d -> ",pop(s));
        printf("%d -> ",pop(s));

}

