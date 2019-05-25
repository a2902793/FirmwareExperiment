//[反片語/Ananagrams](1/2)
#define IN "P16IN.txt"
#define OUT "P16OUT.txt"
#include <iostream>
using namespace std;
void redir();
void dir();

#include <string>
#include <vector>
#include <algorithm>
#include <map>
string normalize(string &s);

int main()
{
    redir();
    string s, n;
    vector<string> words, ans;
    map<string, int> cnt;
    int i;
    while (cin >> s)
    {
        if (s[0] == '#')
        {
            break;
        }
        words.push_back(s);
        n = normalize(s); //'=' is overloaded
        if (!cnt.count(n))
        {
            cnt[n] = 0;
        }
        cnt[n]++;
    }
    for (i = 0; i < words.size(); i++)
    {
        if (cnt[normalize(words[i])] == 1)
        {
            ans.push_back(words[i]);
        }
    }
    sort(ans.begin(), ans.end());
    for (i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    //dir();
    return 0;
}

//把每個單字標準化(轉換為小寫字母再按進行排序)
string normalize(string &s)
{
    string ans = s; //'=' is overloaded
    int i;
    for (i = 0; i < ans.length(); i++)
    {
        ans[i] = tolower(ans[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

void redir()
{
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
}

void dir()
{
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
}