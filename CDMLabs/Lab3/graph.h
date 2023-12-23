//all functions work with square binary matricies, except 
//AddMatrix and MultMatrix
//functions put they result matrix in res variable
//not recommended to use same matrix as parameter and result variable
//all the matricies given shoud be same size
//you can pass your matricies as linear array(a[]), 
//pointer(*a), twodimensional array(a[][n]) or pointer to pointer(**a)
//compiler will give you warning, but everything should work fine
void AddMatrix(int res[], int a[], int b[], int size);
void MultMatrix(int res[], int a[], int b[], int size);
void PrintMatrix(int g[], int size);
void CopyMatrix(int res[], int g[], int size);
void ConstructComplementary(int GC[], int G[], int size);
void TranspondMatrix(int res[], int G[], int size);
void ConstructUnion(int res[], int G[], int H[], int size);
void ConstructCrossing(int res[], int G[], int H[], int size);
void ConstructSymetricalCrossing(int res[], int G[], int H[], int size);
int CountEdges(int G[], int size);
