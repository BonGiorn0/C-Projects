struct tree;

int IsInTree(struct tree *p, int val);
int AddToTree(struct tree **p, int val);
int AddToAVLTree(struct tree **p, int val);
void PrintPreorder(struct tree *p);
void PrintPostorder(struct tree *p);
void PrintInorder(struct tree *p);
int TreeHeight(struct tree *p, int n);
int getHeight(struct tree *p);
void DrawBranch(int x, int y, int len, char *pattern);
void DrawTree(struct tree *p, int x, int y, int branch);

