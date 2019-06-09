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
    bool ans;
    while(cin >> stringA)
    {
        memset(countA, 0, sizeof(countA));  //這若不在裡面會影響後面判斷，每一次都要初始化成都是 0
        memset(countB, 0, sizeof(countB));  //
        cin >> stringB;
        len = strlen(stringA);
        for(int i = 0; i < len; i++)
        {
            countA[stringA[i] - 'A']++;
            countB[stringB[i] - 'A']++;
        }
        sort(countA, countA + 26);
        sort(countB, countB + 26);
        ans = true;
        for(int i = 0; i < 26; i++)
        {
            if(countA[i] != countB[i])
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