#include <stdlib.h>
#include <check.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>
#include <time.h>
#include <omp.h> 
#include "../listFile.h"
#include "../listFileName.h"
#include "../startFunctions.h"

START_TEST(test1){

	char *argv[]={"./test_start","./text3","sapien"};

	DIR *dir = opendir(argv[1]);
	
	printf("Test nr 1\n");
	
	printf("Number of Threads : 1\n");
	

	struct LinkedListFileName *filesName = (struct LinkedListFileName*)malloc(sizeof(struct LinkedListFileName));
	filesName->head = NULL;
	filesName->current = filesName->head;	
	filesName->size = 0;	

	

	struct LinkedListNodeThread *listThread = (struct LinkedListNodeThread*)malloc(sizeof(struct LinkedListNodeThread));
	listThread->head = NULL;
	listThread->current = listThread->head;

	goThroughDirectory(dir,filesName,argv[1]);
	int numberOfFiles = getListSize(filesName); 
	
	int numberOfThreads = 1;
	omp_set_num_threads(numberOfThreads);

	

	for(int i=0; i<numberOfThreads;i++){

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
		double begin = omp_get_wtime();

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

		double end = omp_get_wtime();
		double duration = end - begin;
		printf("Duration %f",duration);
		
		printf("	Number of thread %d\n",id);
		
	}



	freeMemoryNodeThread(listThread->head);
	free(listThread);
	closedir(dir);
}
END_TEST


START_TEST(test2){

	char *argv[]={"./test_start","./text3","sapien"};

	DIR *dir = opendir(argv[1]);
	
	printf("Test nr 2\n");
	
	printf("Number of Threads : 2\n");
	

	struct LinkedListFileName *filesName = (struct LinkedListFileName*)malloc(sizeof(struct LinkedListFileName));
	filesName->head = NULL;
	filesName->current = filesName->head;	
	filesName->size = 0;	

	

	struct LinkedListNodeThread *listThread = (struct LinkedListNodeThread*)malloc(sizeof(struct LinkedListNodeThread));
	listThread->head = NULL;
	listThread->current = listThread->head;

	goThroughDirectory(dir,filesName,argv[1]);
	int numberOfFiles = getListSize(filesName); 
	
	int numberOfThreads = 2;
	omp_set_num_threads(numberOfThreads);

	

	for(int i=0; i<numberOfThreads;i++){

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
		double begin = omp_get_wtime();

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

		double end = omp_get_wtime();
		double duration = end - begin;
		printf("Duration %f",duration);
		
		printf("	Number of thread %d\n",id);
		
	}



	freeMemoryNodeThread(listThread->head);
	free(listThread);
	closedir(dir);
}
END_TEST


START_TEST(test3){

	char *argv[]={"./test_start","./text3","sapien"};

	DIR *dir = opendir(argv[1]);
	
	printf("Test nr 3\n");
	
	printf("Number of Threads : 3\n");
	

	struct LinkedListFileName *filesName = (struct LinkedListFileName*)malloc(sizeof(struct LinkedListFileName));
	filesName->head = NULL;
	filesName->current = filesName->head;	
	filesName->size = 0;	

	

	struct LinkedListNodeThread *listThread = (struct LinkedListNodeThread*)malloc(sizeof(struct LinkedListNodeThread));
	listThread->head = NULL;
	listThread->current = listThread->head;

	goThroughDirectory(dir,filesName,argv[1]);
	int numberOfFiles = getListSize(filesName); 
	
	int numberOfThreads = 3;
	omp_set_num_threads(numberOfThreads);

	

	for(int i=0; i<numberOfThreads;i++){

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
		double begin = omp_get_wtime();

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

		double end = omp_get_wtime();
		double duration = end - begin;
		printf("Duration %f",duration);
		
		printf("	Number of thread %d\n",id);
		
	}


	freeMemoryNodeThread(listThread->head);
	free(listThread);
	closedir(dir);
}
END_TEST


START_TEST(test4){

	char *argv[]={"./test_start","./text3","sapien"};

	DIR *dir = opendir(argv[1]);
	
	printf("Test nr 4\n");
	
	printf("Number of Threads : 4\n");
	

	struct LinkedListFileName *filesName = (struct LinkedListFileName*)malloc(sizeof(struct LinkedListFileName));
	filesName->head = NULL;
	filesName->current = filesName->head;	
	filesName->size = 0;	

	

	struct LinkedListNodeThread *listThread = (struct LinkedListNodeThread*)malloc(sizeof(struct LinkedListNodeThread));
	listThread->head = NULL;
	listThread->current = listThread->head;

	goThroughDirectory(dir,filesName,argv[1]);
	int numberOfFiles = getListSize(filesName); 
	
	int numberOfThreads = 4;
	omp_set_num_threads(numberOfThreads);

	

	for(int i=0; i<numberOfThreads;i++){

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
		double begin = omp_get_wtime();

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

		double end = omp_get_wtime();
		double duration = end - begin;
		printf("Duration %f",duration);
		
		printf("	Number of thread %d\n",id);
		
	}


	
	freeMemoryNodeThread(listThread->head);
	free(listThread);
	closedir(dir);
}
END_TEST






Suite *start_suite(void){
	Suite *s;
	TCase *tc_core;

	s = suite_create("Start");
	tc_core = tcase_create("Core");

	tcase_add_test(tc_core,test1);
	tcase_add_test(tc_core,test2);
	tcase_add_test(tc_core,test3);
	tcase_add_test(tc_core,test4);
	tcase_set_timeout(tc_core,30);
	suite_add_tcase(s,tc_core);

	return s;

}



int main(void){
	int number_failed;
	
	Suite *sm;
	SRunner *sr;

	sm = start_suite();

	sr = srunner_create(sm);

	srunner_run_all(sr,CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	
return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

}





