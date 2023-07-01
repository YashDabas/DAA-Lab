#include<iostream>
using namespace std;
# define NO_OF_CHARS 256;
void booyermoore(string s, string t)
    {
        int badchar [NO_OF_CHARS];
        badChar(t, t.length(), badchar);
        int i = 0;
        int x=s.length() - t.length();
        while (i <= x)
        {
            int j = t.length() - 1;
            while (j >= 0 && t[j] == s[i + j])
                j--;
            if (j < 0)
            {
                if(i+ t.length() < s.length()){
                    i+=t.length()- badchar[s[i+ t.length()]];
                }
                else{
                    i++;
                }
            }

            else
            {
                i += max(1, j - badchar[s[i + j]]);
            }
        }
    }
int main(){
    string str = "";
    cin >> str;
    string pattern = "";
    cin >> pattern;
    cout << "Pattern occurs with shift " << booyermoore(str, pattern) << endl;
    return 0;
   
    return 0;
}