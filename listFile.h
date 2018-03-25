

struct Node{
	int lineNumber;
	char text[500];
	char filePath[50];
	char fileName[30];
	struct Node *next;

}; 

struct LinkedList{

	struct Node *head;
	struct Node *current;
	
};



struct NodeThread{
	int threadNumber;
	struct LinkedList *nodeList;
	struct NodeThread *next;
};



struct LinkedListNodeThread{

	struct NodeThread *head;
	struct NodeThread *current;


};



void print(struct LinkedListNodeThread *list);
void freeMemoryNodeThread(struct NodeThread *node);
