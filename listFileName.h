struct NodeFileName{
	
	char pathFile[150]; 
	char fileName[100];
	struct NodeFileName *next;

}; 

struct LinkedListFileName{
        int size;
	struct NodeFileName *head;
	struct NodeFileName *current;
	
};

void addNodeFileName(struct LinkedListFileName *list,struct NodeFileName *item);
void freeMemoryNodeFileName(struct NodeFileName *node);
int getListSize(struct LinkedListFileName *list);
