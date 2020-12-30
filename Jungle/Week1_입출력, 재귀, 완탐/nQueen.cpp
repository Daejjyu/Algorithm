#include <iostream>
#include <cstring>
using namespace std;

int rowUsed[15];
int queenRowPosAt[15];
int ans = 0;
int N;

bool isCross(int col)
{
    if (col == 0)
        return false;
    else
    {
        for (int i = 0; i < col; i++)
        {
            if (col - i == abs(queenRowPosAt[col] - queenRowPosAt[i]))
                return true;
        }
        return false;
    }
}

void nQueen(int col)
{
    for (int i = 0; i < N; i++)
    {
        if (rowUsed[i] == 0)
        {
            queenRowPosAt[col] = i;

            if (isCross(col))
                continue;

            if (col == N - 1)
                ans++;
            else
            {
                rowUsed[i] = 1;
                nQueen(col + 1);
                rowUsed[i] = 0;
            }
        }
    }
}

int main()
{
    scanf("%d", &N);
    memset(queenRowPosAt, -1, sizeof(queenRowPosAt));

    nQueen(0);
    printf("%d", ans);
}