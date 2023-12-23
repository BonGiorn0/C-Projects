struct SStudent *ReadList(FILE *f, struct SStudent *pArr, int *nSize);
struct SStudent *ReadRow(FILE *f, struct SStudent *pArr, int *nSize);
void PrintRow(FILE *f, const struct SStudent *s, int n);
void PrintTable(FILE *f, const struct SStudent pArr[], int nSize,
		int (*condition)(const struct SStudent*, float), float n);
float AverageRating(const struct SStudent pArr[], int nSize);
int IsRatingGreaterThan(float avr, const struct SStudent *s);
int True(const struct SStudent *s, float avr);
