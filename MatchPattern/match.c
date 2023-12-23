#include <stdio.h>

int Match(char str[], char pat[])
{
	if (*pat == '\0')
		return *str == '\0';

	if (*pat == '*'){
		int i = 0;
		do{
			if (Match(str + i, pat + 1))
				return 1;
			i++;
		}while(str[i - 1] != '\0');
		return 0;
	}

	if ((*str == '\0') || (*str != *pat && *pat != '?'))
		return 0;

	Match(str + 1, pat + 1);
}

int main(int argc, char *argv[])
{
	if(Match(argv[1], argv[2])){
		printf("They match\n");
		return 0;
	}
	printf("They don't match\n");
	return 0;
}
