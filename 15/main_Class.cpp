#define IN "P15IN.txt"
#define OUT "P15OUT.txt"
#include <iostream>
using namespace std;
void redir();
void dir();
#include <string>
#include <sstream>
#include <set>

int main()
{
    redir();
    string s, buf;
    int i;
    set<string> dict;
    set<string>::iterator it; //反覆運算子
    while (cin >> s)
    {
        for (i = 0; i < s.length(); i++)
        {
            if (isalpha(s[i]))
            {
                s[i] = tolower(s[i]); //轉成小寫字母字元
            }
            else
            {
                s[i] = ' '; //將非字母字元轉成空白字元
            }
        }
        stringstream ss(s); //block scope
        while (ss >> buf)
        {
            dict.insert(buf);
        }
    }
    for (it = dict.begin(); it != dict.end(); ++it)
    { //列出所有的元素
        cout << *it << endl;
    }
    //dir();
    return 0;
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