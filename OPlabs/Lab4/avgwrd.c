#include <stdio.h>

int main(){
	char str[256];
	int WordLength = 0, WordNumber = 0, isWord = 0; 
	float AverageLength = 0;

	printf("Enter a sentence: ");
	scanf("%[^\n]s", str);


	for(int i = 0; str[i]; ++i){
		if ((str[i] >= 'a' && str[i] <= 'z') ||
			(str[i] >= 'A' && str[i] <= 'Z') ||
			(str[i] >= '0' && str[i] <= '9') ||
			str[i] == '\''){
			if (str[i] != '\'')
				WordLength++;
			isWord = 1;
		}else{
			AverageLength += WordLength;
			WordLength = 0;
			if (isWord){
				WordNumber++;
				isWord = 0;
			}
		}
	}

	AverageLength += WordLength;
	WordLength = 0;
	if (isWord)
		WordNumber++;

	AverageLength /= WordNumber;

	printf("Average length of word in the sentence: %f \n", AverageLength);
	return 0;
}
