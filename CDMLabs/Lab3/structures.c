#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item{
	char data[50];
	struct item *next;
};

struct ItemOfDouble{
	double data;
	struct ItemOfDouble *next;
};

struct node{
	struct item *first; 
	struct item *last;
};

typedef struct item stack;
typedef struct ItemOfDouble StackOfDouble;
typedef struct node queue;

/*======= Stack =======*/

void StackInit(stack **s)
{
	*s = NULL;
}


void StackPush(stack **s, const char* str)
{
	stack *tmp = malloc(sizeof(stack));
	strcpy(tmp->data, str);
	tmp->next = *s;
	*s = tmp;
}


char* StackTop(stack *s)
{
	return s->data;
}

void StackPop(stack **s, char res[])
{
	strcpy(res, (*s)->data);
	stack *tmp = *s;
	*s = (*s)->next;
	free(tmp);
}

int StackIsEmpty(stack *s)
{
	return !s;
}

void PrintStack(stack *s)
{
	stack *tmp = s;
	while(tmp){
		printf("%s ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

/*======= StackOfDouble =======*/

void SODInit(StackOfDouble **s)
{
	*s = NULL;
}

void SODPush(StackOfDouble **s, double n)
{
	StackOfDouble *tmp = malloc(sizeof(StackOfDouble));
	tmp->data = n;
	tmp->next = *s;
	*s = tmp;
}

double SODTop(StackOfDouble *s)
{
	return s->data;
}

double SODPop(StackOfDouble **s)
{
	double res = (*s)->data;
	StackOfDouble *tmp = *s;
	*s = (*s)->next;
	free(tmp);
	return res;
}


int SODIsEmpty(StackOfDouble *s)
{
	return !s;
}

/*======= Queue =======*/

#if 0
void QueueInit(queue **q)
{
	(*q)->first = NULL;
	(*q)->last = NULL;
}
#else
void QueueInit(queue *q)
{
	q->first = NULL;
	q->last = NULL;
}
#endif

void QueuePut(queue *q, const char *str)
{
	if(!q->first){
		q->first = malloc(sizeof(struct item));
		q->last = q->first;
	}else{
		q->last->next = malloc(sizeof(struct item));
		q->last = q->last->next;
	}
	strcpy(q->last->data, str);
	q->last->next = NULL;
}

void QueueGet(queue *q, char res[])
{
	strcpy(res, q->first->data);
	struct item *tmp = q->first;
	q->first = q->first->next;
	if (!q->first)
		q->last = NULL;
	free(tmp);
}

int QueueIsEmpty(queue q)
{
	return !q.first;
}

void PrintQueue(queue q)
{
	struct item *tmp = q.first;
	while(tmp){
		printf("%s ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

void PrintReverseQueue(struct item *qFirst)
{
	if (!qFirst)
		return;
	PrintReverseQueue(qFirst->next);
	printf("%s ", qFirst->data);
}
