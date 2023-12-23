#include <string.h>
#include <stdlib.h>

#include "student.h"
#include "sort.h"

void swap(struct SStudent *a, struct SStudent *b)
{
	struct SStudent tmp = *a;
	*a = *b;
	*b = tmp;
}

//==============================================================================

void SortArray(struct SStudent pArr[], int nSize,
		int (*condition)(struct SStudent*, struct SStudent*))
{
	for(int i = 0; i < nSize - 1; i++)
		for(int j = 0; j < nSize - i - 1; j++)
			if(condition(&pArr[j], &pArr[j + 1]))
				swap(&pArr[j], &pArr[j + 1]);
}

//==============================================================================

int MagicNumber(struct SStudent *s)       //converts nBirthdate to a number
{                                         //12.10.2005 -> 20051012
    int res = 0, coef = 1;
    for(int i = 0; i < nDateElements; i++){
        res += s->nBirthdate[i] * coef;
        coef *= 100;
    }
    return res;
}

//==============================================================================

int AgeUp(struct SStudent *a, struct SStudent *b)  //returns TRUE if student a
{                                                  //is younger student b
    if(MagicNumber(a) < MagicNumber(b))
        return 1;
    return 0;
}             
