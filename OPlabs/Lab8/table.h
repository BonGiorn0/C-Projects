void ReadList(FILE *f, struct student arr[], int size);
void PrintTable(FILE *f, const struct student arr[], int size,
		int (*condition)(const struct student*, float), float n);
float AverageRating(const struct student arr[], int size);
int isGreaterThanAverageRating(const struct student *s, float avr);
int True(const struct student *s, float avr);
