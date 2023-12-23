#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "tree.h"

#define BRANCH_SKIN_LEFT "._/"
#define BRANCH_SKIN_RIGHT "\\_."

enum{
	RightBranch,
	LeftBranch
};

enum{
	FirstChar,
	SecondChar,
	LastChar
};

struct tree{
	int data;
	int height;
	struct tree *left, *right;
};

int IsInTree(struct tree *p, int val)
{
	if (p == NULL)
		return 0;
	else if (p->data < val)
		IsInTree(p->left, val);
	else if (p->data > val)
		IsInTree(p->right, val);
	return 1;

}

int AddToTree(struct tree **p, int val)
{
	if (!*p){
		*p = malloc(sizeof(struct tree));
		(*p)->data = val;
		(*p)->height = 0;
		(*p)->left = NULL;
		(*p)->right = NULL;
		return 1;
	}
	if (val < (*p)->data)
		AddToTree(&(*p)->left, val);
	if (val > (*p)->data)
		AddToTree(&(*p)->right, val);
	(*p)->height = 1 + max(getHeight((*p)->left),
						getHeight((*p)->right));
	return 0;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int getHeight(struct tree *p)
{
	if (p == NULL)
		return -1;
	return p->height;
}

int getBalance(struct tree *p)
{
	if (p == NULL)
		return 0;
	return getHeight(p->left) - getHeight(p->right);
}

void RightRotate(struct tree **p)
{
	struct tree *x = (*p)->left;
	struct tree *y = x->right;

	x->right = *p;
	(*p)->left = y;

	(*p)->height = 1 + max(getHeight((*p)->right), 
							getHeight((*p)->left));
	*p = x;

	(*p)->height = 1 + max(getHeight((*p)->right), 
							getHeight((*p)->left));
}

void LeftRotate(struct tree **p)
{
	struct tree *x = (*p)->right;
	struct tree *y = x->left;

	x->left = *p;
	(*p)->right = y;

	(*p)->height = 1 + max(getHeight((*p)->right), 
							getHeight((*p)->left));
	x->height = 1 + max(getHeight(x->right), 
							getHeight(x->left));
	*p = x;
}

int AddToAVLTree(struct tree **p, int val)
{
	if (!*p){
		*p = malloc(sizeof(struct tree));
		(*p)->data = val;
		(*p)->height = 0;
		(*p)->left = NULL;
		(*p)->right = NULL;
	}
	else if (val < (*p)->data)
		AddToAVLTree(&(*p)->left, val);
	else if (val > (*p)->data)
		AddToAVLTree(&(*p)->right, val);
	else
		return 0;

	(*p)->height = 1 + max(getHeight((*p)->left),
						getHeight((*p)->right));

	int bal = getBalance(*p);

	if (bal > 1){
		if (val > (*p)->left->data)
			LeftRotate(&(*p)->left);
		RightRotate(p);
	}

	if (bal < -1){
		if (val < (*p)->right->data)
			RightRotate(&(*p)->right);
		LeftRotate(p);
	}
}

void DrawBranch(int x, int y, int len, char *pattern)
{
	move(y, x);
	addch(pattern[FirstChar]);
	for(int i = 0; i < len - 1; i++)
		addch(pattern[SecondChar]);
	addch(pattern[LastChar]);
}

int BranchLength(struct tree *p)
{
	int n = getBalance(p);
	if (n < 0)
		n = -n;
	return 2 << (getHeight(p) /*- n*/ );
}

void DrawTree(struct tree *p, int x, int y, int branch)
{
	if (p == NULL)
		return;
	DrawTree(
		p->left,
		x - BranchLength(p->left), y + 2,
		LeftBranch
	);
	if(branch == LeftBranch)
		DrawBranch(x + 1, y - 1,
					BranchLength(p) - 1, BRANCH_SKIN_LEFT);
	if(branch == RightBranch)
		DrawBranch(x - BranchLength(p) + 1, y - 1,
					BranchLength(p) - 1, BRANCH_SKIN_RIGHT);
	mvprintw(y, x, "%d ", p->data);
	refresh();
	DrawTree(
		p->right, 
		x + BranchLength(p->right) , y + 2,
		RightBranch
	);
}

void PrintPreorder(struct tree *p)
{
	if (p == NULL)
		return;
	printf("%d ", p->data);
	PrintPreorder(p->left);
	PrintPreorder(p->right);
}
void PrintPostorder(struct tree *p)
{
	if (p == NULL)
		return;
	PrintPostorder(p->left);
	PrintPostorder(p->right);
	printf("%d ", p->data);
}
void PrintInorder(struct tree *p)
{
	if (p == NULL)
		return;
	PrintInorder(p->left);
	printf("%d ", p->data);
	PrintInorder(p->right);
}
