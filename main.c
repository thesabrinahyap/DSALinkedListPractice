#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


int main(int argc, char *argv[]) {

	List myList = NULL;
    insertAt(&myList, 10, 0);   
    insertAt(&myList, 20, 1);   
    insertAt(&myList, 30, 1);   
    insertAt(&myList, 40, 3);   

    printf("Linked List: ");
    printList(myList);

    deleteAt(&myList, 2);   

    printf("Linked List after deletion: ");
    printList(myList);
	return 0;
}
