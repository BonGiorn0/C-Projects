typedef struct item stack;
typedef struct ItemOfDouble StackOfDouble;
struct node{
	struct item *first; 
	struct item *last;
};
typedef struct node queue;

void StackInit(stack **s);
void StackPush(stack **s, const char* str);
char* StackTop(stack *s);
void StackPop(stack **s, char res[]);
int StackIsEmpty(stack *s);
void PrintStack(stack *s);

void SODInit(StackOfDouble **s);
void SODPush(StackOfDouble **s, double n);
double SODPop(StackOfDouble **s);
double SODTop(StackOfDouble *s);
int SODIsEmpty(StackOfDouble *s);

void QueueInit(queue *q);
void QueuePut(queue *q, char *n);
void QueueGet(queue *q, char res[]);
int QueueIsEmpty(queue q);
void PrintQueue(queue q);
void PrintReverseQueue(struct item *qFirst);
