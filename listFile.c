#include <stdio.h>
#include <stdlib.h>
#include "listFile.h"


void add(struct LinkedList *list,struct Node *item){
	if(list->head == NULL){
		list->head = item;
		list->current = list->head;
	}
	else{
		list->current->next = item;
		list->current = item;
		
	}

};

void print(struct LinkedListNodeThread *list){
	struct NodeThread *first = list->head;
	struct NodeThread *another = first;
	
	while(another != NULL){
		struct Node *available = another->nodeList->head;		
		while(available != NULL){		
			printf("%s ",available->filePath);
			printf("%s ",available->fileName);
			printf("%d ",available->lineNumber);
			printf("%s ",available->text);
			printf("\n");
			available = available -> next;
		}
		
		another = another->next;
	}
	
};


void freeMemoryNode(struct Node *node){
	struct Node *tmp;
	while(node != NULL){
		tmp = node;
		node = node->next;
		free(tmp);
	}
	
	
};

void freeMemoryNodeThread(struct NodeThread *nd){

	struct NodeThread *tmpNode;
	while(nd != NULL){
		freeMemoryNode(nd->nodeList->head);

		tmpNode = nd;
		nd = nd->next;
		free(tmpNode);


	}

};


