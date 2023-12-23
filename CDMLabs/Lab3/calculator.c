#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

#if 0
struct operator{
	char* symbol;
	int precendence;
	int associativity; // 0 - left, 1 - right;
}
#endif

enum{
	OperatorNumber = 6
};

#if 0
void swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
#endif

void InvertString(char *res, const char *s)
{
	for(int i = 0, j = strlen(s) - 1; i < strlen(s); j--, i++){
		if (s[j] == ')'){
			res[i] = '(';
			continue;
		}
		if (s[j] == '('){
			res[i] = ')';
			continue;
		}
		res[i] = s[j];
	}
	res[strlen(s)] = '\0';
}

const char* OperatorList[] = {"-", "+", "*", "/", "(", ")"};

int isOperator(const char *token)
{
	for(int i = 0; i < OperatorNumber; ++i)
		if(!strcmp(token, OperatorList[i]))
				return 1;
	return 0;
}

int isVariable(const char *token)
{
	if(!strcmp(token, "a") ||
	   !strcmp(token, "b") ||
	   !strcmp(token, "c") ||
	   !strcmp(token, "d") )
		return 1;
	return 0;
}

int getPrecendence(const char *operator)
{
	switch(operator[0]){
	case '(': return 0;
	case '-': return 2;
	case '+': return 2;
	case '*': return 3;
	case '/': return 3;
	}
}

double CalcTwoNum(double a, double b, char* operator)
{
	switch(operator[0]){
	case '-': return a - b;
	case '+': return a + b;
	case '*': return a * b;
	case '/': return a / b;
	}

}

void ConvertToRPN(queue *rpn, const char *equasion)
{
	char str[300] = "";
	strcpy(str, equasion);
	stack *OperatorStack;
	StackInit(&OperatorStack);
	char* token = strtok(str, " ");
	do{
		if(!isOperator(token)){
			QueuePut(rpn, token);
			continue;
		}
		if(StackIsEmpty(OperatorStack) || !strcmp(token, "(")){
			StackPush(&OperatorStack, token);
			continue;
		}
		if(!strcmp(token, ")")){
			char tmp[50];
			while(strcmp(StackTop(OperatorStack), "(")){
				StackPop(&OperatorStack, tmp);
				QueuePut(rpn, tmp);
			}
			StackPop(&OperatorStack, tmp);
			continue;
		}
		while(!StackIsEmpty(OperatorStack) &&
		(getPrecendence(token) <= getPrecendence(StackTop(OperatorStack)))){
			char tmp[50];
			StackPop(&OperatorStack, tmp);
			QueuePut(rpn, tmp);
		}
		StackPush(&OperatorStack, token);
	}while(token = strtok(NULL, " "));
	while(!StackIsEmpty(OperatorStack)){
		char tmp[50];
		StackPop(&OperatorStack, tmp);
		QueuePut(rpn, tmp);
	}
}

float CalculateRPN(queue *rpn, double variable[])
{
	StackOfDouble *numbers;
	SODInit(&numbers);
	while(!QueueIsEmpty(*rpn)){
		char token[50];
		QueueGet(rpn, token);
		if(!isOperator(token)){
			if(isVariable(token))
				SODPush(&numbers, variable[token[0] - 'a']);
			else
				SODPush(&numbers, atof(token));
			continue;
		}
		double res = CalcTwoNum(SODPop(&numbers), SODPop(&numbers), token);
		SODPush(&numbers, res);
	}
	return SODPop(&numbers);
}

int main()
{
	queue rpn, pn;
	char equasion[300], inv[300];
	double var[4];

	QueueInit(&rpn);

	printf("Enter an equasion:\n");
	fgets(equasion, 300, stdin);
	equasion[strlen(equasion) - 1] = '\0';

	InvertString(inv, equasion);

	printf("Enter the a, b, c and d: ");
	for(int i = 0; i < 4; i++)
		scanf("%lf", &var[i]);

	ConvertToRPN(&rpn, equasion);
	ConvertToRPN(&pn, inv);

	PrintQueue(rpn);
	PrintReverseQueue(pn.first);
	printf("\n");

	double res = CalculateRPN(&rpn, var);
	printf("%lf\n", res);

	return 0;
}
