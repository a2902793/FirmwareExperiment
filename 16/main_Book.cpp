#define IN "P16IN.txt"
#define OUT "P16OUT.txt"
void redir();
void dir();

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> cnt;
vector<string> words;
string repr(string s);

int main()
{
    redir();
    int n = 0;
    string s;
    while (cin >> s)
    {
        if (s[0] == '#')
            break;
        words.push_back(s);
        string r = repr(s);
        if (!cnt.count(r))
            cnt[r] = 0;
        cnt[r]++;
    }
    vector<string> ans;
    for (int i = 0; i < words.size(); i++)
        if (cnt[repr(words[i])] == 1)
            ans.push_back(words[i]);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";
    //dir();
    return 0;
}

// 将单词s进行“标准化”
string repr(string s)
{
    string ans = s;
    for (int i = 0; i < ans.length(); i++)
        ans[i] = tolower(ans[i]);
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