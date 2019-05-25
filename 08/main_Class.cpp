//[古老的密碼/Ancient Cipher](1/2)
#define IN "P08IN.txt"
#define OUT "P08OUT.txt"
#include <iostream>
using namespace std;
void redir(void);

#include <algorithm>
#include <cstring>

int main(void)
{
    redir();
    char stringA[101], stringB[101];
    int countA[26], countB[26];
    int len;
    int i;
    bool ans;
    while (cin >> stringA)
    {
        cin >> stringB;
        memset(countA, 0, sizeof(countA));
        memset(countB, 0, sizeof(countB));
        len = strlen(stringA);
        for (i = 0; i < len; i++)
        {
            countA[stringA[i] - 'A']++;
            countB[stringB[i] - 'A']++;
        }
        sort(countA, countA + 26); //sort A[0], A[1], ..., A[25]
        sort(countB, countB + 26); //sort B[0], B[1], ..., B[25]
        ans = true;
        for (i = 0; i < 26; i++)
        {
            if (countA[i] != countB[i])
            {
                ans = false;
                break;
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    return 0; //the end...
}
//[古老的密碼/Ancient Cipher](2/2)
void redir(void)
{
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
}