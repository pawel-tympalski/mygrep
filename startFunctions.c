#include <stdio.h>
#include <string.h>
#include <regex.h>
#include <stdlib.h>
#include <dirent.h>
#include "listFile.h"
#include "listFileName.h"
#include <omp.h>

void iterateThroughFile(FILE *f,char *path,char *name,struct LinkedListNodeThread *nodes,char *pattern,int id ){
	char c;
	char *line = (char *)malloc(sizeof(char)*500);
	strcpy(line,"");
	int status;
	regex_t re ;
	int maxmatch = 20;
	regmatch_t matches[20];
	char charContainer[2];
	charContainer[1]='\0';
	
	regcomp(&re,pattern,REG_EXTENDED);
	
	int count = 1;
	while((c=getc(f))!= EOF ){
		if(c == '\n'){
		status = regexec(&re,line,maxmatch,matches,0);
			if(status == 0){
				
				struct Node  *node= (struct Node*)malloc(sizeof (struct Node));
				node->lineNumber=count;
				strcpy(node->text,line);
				strcpy(node->filePath,path);
				strcpy(node->fileName,name);
				node->next = NULL;
			
				struct NodeThread *start = nodes->head;
				
				for(int j = 0;j <omp_get_num_threads();j++){
					if(start->threadNumber == id){
						
						if(start->nodeList->head == NULL){
							start->nodeList->head = node;
							start->nodeList->current = node;
						}

						else{
							start->nodeList->current->next = node;
							start->nodeList->current = node;	
						}
						break;
					}
					else{
						start = start->next;
					}


				}

			}
			
			memset(line,0, sizeof line);
			count++;
		}
		else{
			charContainer[0] = c;
			strcat(line,charContainer);
		}
	}
	free(line);

};



void goThroughDirectory(DIR *directory,struct LinkedListFileName *files, char *path){

	
	char *firstPart = (char *)malloc(sizeof(char)*150);
	struct dirent *ent ;
	while( (ent = readdir(directory)) != NULL){
		
		if(strcmp(ent->d_name, ".") == 0  || strcmp(ent->d_name,"..") == 0){
			continue;

		}
	
		strcpy(firstPart,path);
		strcat(firstPart,"/");
		strcat(firstPart,ent->d_name);
		struct NodeFileName  *node= (struct NodeFileName*)malloc(sizeof (struct NodeFileName));
		strcpy(node->fileName,ent->d_name);
		strcpy(node->pathFile,firstPart);
		node->next = NULL;
		addNodeFileName(files,node);
		
		
		strcpy(firstPart, path);

		
	}
	free(firstPart);
};


