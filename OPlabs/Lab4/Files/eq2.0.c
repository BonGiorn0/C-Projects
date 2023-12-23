#include <stdio.h>
#include <time.h>
#include <string.h>
#define DATE_LENGTH 25
#define PATH_LENGTH 100


int main(){
	time_t CurrentTime;
	char *date;
	char InputFile[PATH_LENGTH], OutputFile[PATH_LENGTH];
	FILE *io, *log;
	float Ti, x;

	log = fopen("log.txt", "w");
	CurrentTime = time(0);
	date = ctime(&CurrentTime);
	date[DATE_LENGTH - 1] = '\0';
	fprintf(log, "[ %s %lf ] ", date, (double)clock() / CLOCKS_PER_SEC);
	fprintf(log, "Program started \n");

	printf("Enter the name of input file: ");
	fgets(InputFile, PATH_LENGTH, stdin);
	InputFile[strlen(InputFile) - 1] = '\0';

	CurrentTime = time(0);
	date = ctime(&CurrentTime);
	date[DATE_LENGTH - 1] = '\0';
	fprintf(log, "[ %s %lf ] ", date, (double)clock() / CLOCKS_PER_SEC);
	fprintf(log, "Name of input file was entered \n");

	io = fopen(InputFile, "r");
	if (!io){
		CurrentTime = time(0);
		date = ctime(&CurrentTime);
		date[DATE_LENGTH - 1] = '\0';
		fprintf(log, "[ %s %lf ] ", date, (double)clock() / CLOCKS_PER_SEC);
		fprintf(log, "Can\'t open \"%s\"\n", InputFile);
		return 1;
	}

	CurrentTime = time(0);
	date = ctime(&CurrentTime);
	date[DATE_LENGTH - 1] = '\0';
	fprintf(log, "[ %s %lf ] ", date, (double)clock() / CLOCKS_PER_SEC);
	fprintf(log, "\"%s\" was opened \n", InputFile);

	fscanf(io , "%f", &x);

	CurrentTime = time(0);
	date = ctime(&CurrentTime);
	date[DATE_LENGTH - 1] = '\0';
	fprintf(log, "[ %s %lf ] ", date, (double)clock() / CLOCKS_PER_SEC);
	fprintf(log, "X is now = %f \n", x);

	fclose(io);

	CurrentTime = time(0);
	date = ctime(&CurrentTime);
	date[DATE_LENGTH - 1] = '\0';
	fprintf(log, "[ %s %lf ] ", date, (double)clock() / CLOCKS_PER_SEC);
	fprintf(log, "\"%s\" was closed \n", InputFile);

	printf("Enter the of a output file: ");
	fgets(OutputFile, PATH_LENGTH, stdin);
	OutputFile[strlen(OutputFile) - 1] = '\0';

	CurrentTime = time(0);
	date = ctime(&CurrentTime);
	date[DATE_LENGTH - 1] = '\0';
	fprintf(log, "[ %s %lf ] ", date, (double)clock() / CLOCKS_PER_SEC);
	fprintf(log, "Name of output file was entered \n");

	io = fopen(OutputFile, "w");

	CurrentTime = time(0);
	date = ctime(&CurrentTime);
	date[DATE_LENGTH - 1] = '\0';
	fprintf(log, "[ %s %lf ] ", date, (double)clock() / CLOCKS_PER_SEC);
	fprintf(log, "\"%s\" was opened \n", OutputFile);

	Ti = x / (1 - x*x /(3 - x*x / (5 - x*x / 7)));

	CurrentTime = time(0);
	date = ctime(&CurrentTime);
	date[DATE_LENGTH - 1] = '\0';
	fprintf(log, "[ %s %lf ] ", date, (double)clock() / CLOCKS_PER_SEC);
	fprintf(log, "Ti is now = %f \n", Ti);

	fprintf(io, "Result is %f \n", Ti);

	CurrentTime = time(0);
	date = ctime(&CurrentTime);
	date[DATE_LENGTH - 1] = '\0';
	fprintf(log, "[ %s %lf ] ", date, (double)clock() / CLOCKS_PER_SEC);
	fprintf(log, "\"%s\" was written \n", OutputFile);

	fclose(io);

	CurrentTime = time(0);
	date = ctime(&CurrentTime);
	date[DATE_LENGTH - 1] = '\0';
	fprintf(log, "[ %s %lf ] ", date, (double)clock() / CLOCKS_PER_SEC);
	fprintf(log, "\"%s\" was closed \n", OutputFile);

	fclose(log);

	return 0;
}
