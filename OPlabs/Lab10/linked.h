struct SItem *MakeLinkedList(struct SStudent pArr[], int nSize);
void PrintLinkedListTable(FILE *f, const struct SItem *first);
void RemoveFromLinkedList(struct SItem **pp,
	int (*cond)(struct SStudent*));
void InsertIntoLinkedList(struct SItem **pp, struct SStudent *s,
		int (*cond)(struct SStudent*, struct SStudent*));
int LLTrue(struct SStudent *s);
int HasNoFive(struct SStudent *s);
int HasGradeGreaterThan3(struct SStudent *s);
