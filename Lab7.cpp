/*Name - YASH DABAS
ROLL NO. - 2021UCA1912
CLASS - CSAI-2

"I have done this assignment on my own. I have not copied any code from another student or
any online source. I understand if my code is found similar to somebody else's code, my case can
be sent to the Disciplinary committee of the institute for appropriate action."
*/

#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int MatrixChainMultiply(int* p, int i, int j)
{

    if (i == j) 
    {
        return 0;
    }
    if (dp[i][j] != -1) 
    {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++) 
    {
        dp[i][j] = min(
            dp[i][j], MatrixChainMultiply(p, i, k)
                     + MatrixChainMultiply(p, k + 1, j)
                       + p[i - 1] * p[k] * p[j]);
    }
    return dp[i][j];
}
int MatrixChainOrder(int* p, int n)
{
    int i = 1, j = n - 1;
    return MatrixChainMultiply(p, i, j);
}
int main()
{
    int arr[] = { 1, 2, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof dp);
    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, n);
}