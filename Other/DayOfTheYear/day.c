#include <stdio.h>

int main(){
	int year, month, day, DaysInYear;
	printf("Enter a year and its day: ");
	scanf("%d %d", &year, &day);

	if (year % 400 == 0) 
		DaysInYear = 366;
	else if (year % 100 == 0) 
		DaysInYear = 365;
	else if (year % 4 == 0) 
		DaysInYear = 366;
	else 
		DaysInYear = 365;

	if (year < 1 || day > DaysInYear || day < 1){
		printf("Wrong input!");
		return 1;
	}

	month = 1;
	while(day > 31){
		if (month <= 7){
			if (month == 2)
				day -= DaysInYear - 337;
			else if (month % 2 == 0)
				day -= 30;
			else
				day -= 31;
		}else{
			if (month % 2 == 0)
				day -= 31;
			else
				day -= 30;
		}
		month++;
	}

	if (month == 2 && day > DaysInYear - 337){
		day -= DaysInYear - 337;
		month++;
	}

	printf("%d ", day);

	switch(month){
		case 1:
			printf("January");
			break;
		case 2:
			printf("February");
			break;
		case 3:
			printf("March");
			break;
		case 4:
			printf("April");
			break;
		case 5:
			printf("May");
			break;
		case 6:
			printf("June");
			break;
		case 7:
			printf("July");
			break;
		case 8:
			printf("August");
			break;
		case 9:
			printf("September");
			break;
		case 10:
			printf("October");
			break;
		case 11:
			printf("November");
			break;
		case 12:
			printf("December");
			break;
	}

	printf("\n");
	return 0;
	
}
