#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <regex.h>
#include <stdlib.h>
#include <omp.h>
#include "listFile.h"
#include "listFileName.h"
#include "startFunctions.h"

#define ARGUMENTS 3
#define THREADS 3

int main(int argc, char *argv[]){
	
	DIR *dir;
	
	if(argc != ARGUMENTS){
		printf("incorrect number of parameters");
		return -1;
	}

	dir = opendir(argv[1]);
	

	if(dir == NULL){
		printf("directory not found");
		return -1;
	}


	struct LinkedListFileName *filesName = (struct LinkedListFileName*)malloc(sizeof(struct LinkedListFileName));
	filesName->head = NULL;
	filesName->current = filesName->head;	
	filesName->size = 0;	


	struct LinkedListNodeThread *listThread = (struct LinkedListNodeThread*)malloc(sizeof(struct LinkedListNodeThread));
	listThread->head = NULL;
	listThread->current = listThread->head;

	goThroughDirectory(dir,filesName,argv[1]);
	
	int numberOfFiles = getListSize(filesName); 
	
	omp_set_num_threads(THREADS);

	for(int i=0; i<THREADS;i++){

		struct NodeThread *thread = (struct NodeThread*)malloc(sizeof(struct NodeThread));
		thread->threadNumber = i;
		thread->next = NULL;		

		struct LinkedList *nodes = (struct LinkedList*)malloc(sizeof(struct LinkedList));
		nodes->head = NULL;
		nodes->current = nodes->head; 

		thread->nodeList = nodes;		

		if(listThread->head == NULL){
			listThread->head = thread;
			listThread->current = thread;
		}
		else{
			listThread->current->next = thread;
			listThread->current = thread;

		}

	}




#pragma omp parallel shared(numberOfFiles, filesName, listThread)
	{
		int id = omp_get_thread_num();
		
		int threads = omp_get_num_threads();
		
		int istart = id * numberOfFiles / threads;
		int iend = (id + 1)*numberOfFiles / threads;

		if(id == threads - 1){
			iend = numberOfFiles;
		}
		
		struct NodeFileName *first = filesName->head;
		struct NodeFileName *another = first;
		
		int k = 0;
		
		while(another != NULL){
			
			if(k >= istart && k < iend ){
				FILE *fp = fopen(another->pathFile, "r");
				
				iterateThroughFile(fp,argv[1],another->fileName,listThread,argv[2],id);
				fclose(fp);
			}

			another = another->next;
			k++;
		}
	
	}


	print(listThread);
	freeMemoryNodeThread(listThread->head);
	free(listThread);
	closedir(dir);

	return 0;

}












