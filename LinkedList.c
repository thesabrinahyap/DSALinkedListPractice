#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


typedef struct node {
	DATA data;
	struct node *next;
} NodeType, *NodePtr, *List;

void initList(List *list){
	*list = NULL;
}

List newList(){
	List l;
	
	l = NULL;
	
	return l;
}
NodeType createNode(DATA data){
	NodeType node;
	node.data = data;
	node.next = NULL;
}
NodePtr createNodePtr (DATA data){
	NodePtr nptr = (NodePtr) malloc (sizeof(struct node));
	if(*nptr != NULL){
		nptr->data = data;
	}
	return nptr;
}

void displayList(List list){
	for (List trav = list; trav!=NULL; trav=trav->next){
		printf("%d -> ",trav->data);
	}
}

bool insertFront(List *list, DATA item){
	List temp = createNodePtr(item);
	temp->next = *list;
	*list = temp;
	
	return (temp != NULL)? true:false;
}

bool insertRear(List *list, DATA item){
	List temp, *trav;
	
	for(trav=list; *trav!=NULL; trav = &(*trav)->next){
		temp = createNodePtr(item);
		temp->next = NULL;
		*trav = temp;
	}
	return (temp != NULL)? true:false;
}

bool insertAt(List *list, DATA item, int loc){

	NodePtr newNode = createNodePtr(item);
	if(loc == 0){
		//apply insert first
		newNode->next = *list;
		*list = newNode;
	}else{
		newNode->next = NULL;
		List trav = *list;
		for(int ctr=0; ctr!=NULL && count<loc-1; trav=trav->next,ctr++){
			if(trav != NULL){
				newNode->next = trav->next;
				trav->next = newNode;
			}
		}
	}
	return(newNode!= NULL && trav !=NULL)? true:false;
}

bool insertSorted(List *list, DATA data){
	List temp, *trav;
	
	temp = (List) malloc(sizeof(struct node));
	
	if(temp != NULL){
		for(trav = list; trav != NULL && (*trav)->data <= data; trav = &(*trav)->next){}
		temp->data = data;
		temp->next= *trav;
		*trav = temp;
	}
	return(temp != NULL)? true:false;
}

bool searchItem(List list, DATA key){
	List trav;
	for(trav = list; trav != NULL && trav->data != key; trav = trav->next){}
	return(trav == NULL)? false: true;
}

int getItem(List list, DATA key);

bool deleteFront(List *list){
	bool b = false;
	List temp = list;
	if(*list != NULL){
		*list = temp->next;
		free(temp);
		b = true;	
	}
	return b;
}

bool deleteRear(List *list){
	List temp, *trav;
	for(trav = list; *trav != NULL; trav = &(*trav)->next){}
	
	temp = *trav;
	*trav = temp->next;
	free(temp);
	
	return(*trav != NULL)? true:false;
}

int deleteAt(List *list, int loc){
	List trav = *list, temp = NULL;
	int ctr=0;
	
	if(*list != NULL){
		if(loc == 0){
			*list = trav->next;
			free(trav);
		}
	}
	while(trav!= NULL && ctr<loc){
		temp = trav;
		trav = trav->next;
		ctr++;
	}
	temp->next = trav->next;
	free(trav);
	
	return(*list != NULL && trav != NULL)? true:false;
}

bool deleteItem(List *list, DATA key){
	bool b = false;
	List temp, *trav;
	for(trav = list; *trav != NULL && (*trav)->data = key; trav = &(*trav)->next){}
	if(*trav != NULL){
		temp = *trav;
		*trav = temp->next;
		free(temp);
		b = true;
	}
	return b;
}

int deleteAllItem(List *list, DATA key){
	List temp, *trav;
	int count=0;
	
	for(trav=list; *trav!= NULL;){
		if((*trav)->data = key){
			temp = *trav;
			*trav = temp->next;
			free(temp);
			count++;
		}else{
			trav = &(*trav)->next;
		}
	}
	return count;
}
