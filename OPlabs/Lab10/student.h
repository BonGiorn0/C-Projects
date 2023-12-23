enum{
	nSurnameMaxLength = 50,
	nNameMaxLength = 50,
	nExamGradesAmount = 5,
	nDateElements = 3
};

struct SStudent{
	char szSurname[nSurnameMaxLength];
	char szName[nNameMaxLength];
	int nBirthdate[nDateElements];
	int nExamGrade[nExamGradesAmount];
};

struct SItem{
	struct SStudent SStudent;
	struct SItem *pNext;
};

