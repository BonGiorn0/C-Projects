struct node{
  int distance, prev, visited;
  int isSrc, isEnd, isWall;
};

void PrintPseudoMatrix(const struct node v[] , int n, int m);
void PrintMatrix(const int **g, int n, int m);
void CreateGraph(int **g, int n, int m);
void DeleteGraphVertex(int **g, int v, int n, int m);
void AddGraphVertex(int **g, int v, int n, int m);
void VertexInit(struct node *v, const int **g, 
    int n, int src,int end);
int Dijkstra(struct node *v, const int **cost, 
    int n, int *current);

