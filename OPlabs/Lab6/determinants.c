#include <stdio.h>
#define N 3

#if 0
    00 01 02
    10 11 12
    20 21 22
#endif

int CalculateDeterminant(float m[N][N])
{
#if 0
    int res = m[0][0] * m[1][1] * m[2][2] +
                m[0][1] * m[2][0] * m[1][2] +
                m[1][0] * m[0][2] * m[2][1] -
                (m[0][2] * m[1][1] * m[2][1] +
                m[1][0] * m[0][2] * m[2][1] +
                m[1][0] * m[0][2] * m[2][1]) 
    //Doesn`t work. Fix the indexes!
#else
    float res = 0;
    for(int i = 0; i < N - 1; i++)
        for(int j = i + 1; j < N; j++){
            if (!m[i][i])
                return 0;
            float coef = m[j][i] / m[i][i];
            //m[j][i] = 0;
            for(int k = i + 1; k < N; k++)
                m[j][k] -= m[i][k] * coef;
        }
    for(int i = 0; i < N; i++)
        res += m[i][i];
    return res;

#endif
}

void PrintMatrix(const float m[N][N])
{
    for(int i = 0; i < N; i++){
        printf("\n");
        for(int j = 0; j < N; j++)
            printf("%.1f ", m[i][j]);
    }
    printf("\n");
}


int ReadMatrix(float m[N][N])
{
    printf("Enter the 3x3 matrix or smt else to stop:\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            if (!scanf("%f", &m[i][j]))
                return 0;
    }
    return 1;
}

void CopyMatrix(float a[N][N], float b[N][N])
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            a[i][j] = b[i][j];
}

int main(){
    int MaxId = 1;
    float m[N][N], MaxM[N][N];
    float det, max;

    ReadMatrix(m);
    CopyMatrix(MaxM, m);
    max = CalculateDeterminant(m);

    int k = MaxId;
    while(ReadMatrix(m)){
        float tmp[N][N];
        CopyMatrix(tmp, m);
        k++;
        det = CalculateDeterminant(m);
        if (det > max){
            max = det;
            MaxId = k;
            CopyMatrix(MaxM, tmp);
        }
    }

    printf("\nThe matrix №%d has the greatest determinant: %.3f\n",
            MaxId, max);
    PrintMatrix(MaxM);
    return 0;
}
