#include <bits/stdc++.h>
using namespace std;
vector<int> lps;
void KMPUtilForminLPSArray(string &pattern)
{

    int len = 0;

    lps.push_back(0);
    int M = pattern.length();

    int i = 1;
    while (i < M)
    {

        if (pattern[i] == pattern[len])
        {
            len++;
            lps.push_back(len);
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }

            else
            {
                lps.push_back(0);
                i++;
            }
        }
    }
}
int KMPSearch(string &str, string &pattern)
{
    int M = pattern.size();
    int N = str.size();
    KMPUtilForminLPSArray(pattern);
    int i = 0;
    int j = 0;
    while ((N - i) >= (M - j))
    {
        if (pattern[j] == str[i])
        {
            i++;
            j++;
        }
        if (j == M)
        {
            return (i - j);
        }
        else if (i < N && pattern[j] != str[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    string str = "";
    cin >> str;
    string pattern = "";
    cin >> pattern;
    cout << "Pattern occurs with shift " << KMPSearch(str, pattern) << endl;
    return 0;
}