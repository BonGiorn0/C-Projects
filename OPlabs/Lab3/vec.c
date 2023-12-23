#include <stdio.h>

int main(){
	int VecLength = 0;
	float vec[100] = {0};

	for(;;){
		int n;
		printf("Enter a real number or something else to stop: ");
		n = scanf("%f", &vec[VecLength]);
		if (!n){
			printf("------------------------------------------------\n");	
			break;
		}
		VecLength ++;
	}

	if (VecLength == 0){
		printf("Vector is empty\n");
		return 0;
	}

	int flag = 1;
	for(int i = 0; i < VecLength - 1; i++)
		if (*(vec + i) <= *(vec + i + 1)){
			flag = 0;
			break;
		}

	if(flag){
		printf("Vector is descending\n");
		return 0;
	}

	int MinId = 0;
	for(int i = 1; i < VecLength; i++)
		if (vec[i] < vec[MinId])
			MinId = i;

	float tmp;
	tmp = vec[VecLength - 1];
	vec[VecLength - 1] = vec[MinId];
	vec[MinId] = tmp;

	for(int i = 0; i < VecLength; i++){
		printf("%0.3f ", *(vec + i));
	}

	printf("\n");
	return 0;
}
