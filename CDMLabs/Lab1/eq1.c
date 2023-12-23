#include <stdio.h>

void DrawLine(int n){
	for(int i = 0; i < n; i++){
		printf("-");
	}
	printf("\n");
}

int SolveEquasion(int id, int p, int q, int r){
	if (id == 1){
		return !((p <= q) || (q <= r)) && (p || !r);
	}else{
		return (((p && q) <= !p) && ((q && !r) <= r)) <= (p <= r); 
	}

}

int main(){
	static int ArrLength = 8,
				LineLength = 22;
	static int P[] = {1, 1, 1, 1, 0, 0, 0, 0},
				Q[] = {1, 1, 0, 0, 1, 1, 0, 0},
				R[] = {1, 0, 1, 0, 1, 0, 1, 0};
	int res[ArrLength];
	int id;
	printf("    _____________________        _ \n");
	printf("#1: ((P -> Q) v (Q -> R)) ^ (P v R)\n");
	printf("                 _          _                    \n");
	printf("#2: (((P ^ Q) -> P) ^ ((Q ^ R) -> R)) -> (P -> R)\n\n");
	printf("Enter number of equasion: ");
	scanf("%d", &id);
	DrawLine(LineLength);
	printf("| P | Q | R | Result |\n");
	DrawLine(LineLength);
	for (int i = 0; i < ArrLength; i++){
		res[i] = SolveEquasion(id, P[i], Q[i], R[i]);
		printf("| %d | %d | %d |   %d    |\n", P[i], Q[i], R[i], res[i]);
	}
	DrawLine(LineLength);
	return 0;

}
