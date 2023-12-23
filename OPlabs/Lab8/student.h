struct ExamGrade{
	int OP;
	int CDM;
	int Calculus;
	int LAAG;
	int History;
};

struct student{
	char surname[100];
	char name[100];
	char birthdate[100];
	struct ExamGrade ExamGrade;
};

struct item{
	struct student student;
	struct item *next;
};
