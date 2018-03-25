#include <stdio.h>
#include <stdlib.h>
#include "listFileName.h"

void addNodeFileName(struct LinkedListFileName *list,struct NodeFileName *item){
	if(list->head == NULL){
		list->head = item;
		list->current = list->head;
	}
	else{
		list->current->next = item;
		list->current = item;
		
	}
	list->size = list->size + 1;
};


void freeMemoryNodeFileName(struct NodeFileName *node){
	struct NodeFileName *tmp;
	while(node != NULL){
		tmp = node;
		node = node->next;
		free(tmp);
	}
	
	
};





int getListSize(struct LinkedListFileName *list){

	return list->size;
};
