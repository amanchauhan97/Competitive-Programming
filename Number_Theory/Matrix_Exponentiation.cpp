#include<bits/stdc++.h>
using namespace std;

void multiply(int A[3][3], int B[3][3])
{
    int M[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            M[i][j] = 0;
            for(int k=0;k<3;k++)
                M[i][j] += A[i][k] * B[k][j];
        }
    }
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            A[i][j] = M[i][j];
}

int matrix_exponentiation(int F[3][3] , int n)
{
    int M[3][3] = {{1,1,1},{1,0,0},{0,1,0}};
    if(n == 1)
        return F[0][0] + F[0][1];
    matrix_exponentiation(F,n/2);
    multiply(F,F);
    if(n&1)
        multiply(F,M);
    return F[0][0] + F[0][1];
}

int Nth_Term(int n)
{
    if(n==0)
        return 0;
    if(n<=2)
        return 1;
    int F[3][3] = {{1,1,1},{1,0,0},{0,1,0}};
    return matrix_exponentiation(F,n-2);
}

int main()
{
    int n;
    cin >> n;

    cout << Nth_Term(n) << endl;
}
