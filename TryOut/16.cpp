#define IN "P16IN.txt"
#define OUT "P16OUT.txt"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
void redir();
void dir();
using namespace std;
string normalize(string &s);

int main()
{
    redir();
    string str, str_norm;
    vector<string> words, ans;
    map<string, int>cnt;

    while(cin >> str)   //讀取一個一個單字 (cin遇到空格會停止)
    {
        if(str[0] == '#')   //遇到 # 停止
            break;
        words.push_back(str);   //推進單詞vector裡
        str_norm = normalize(str);  //將單詞標準化
        if(!cnt.count(str_norm))    //尋找有沒有在map裡
            cnt[str_norm] = 0;      //
                                    //這兩段用意是為了不重複計數
        cnt[str_norm]++;            //
    }
    for(int i = 0; i < words.size(); i++)
    {
        if(cnt[normalize(words[i])] == 1)   //如果在map裡有對應的單詞
            ans.push_back(words[i]);        //就推進答案vector裡
    }
    sort(ans.begin(), ans.end());           //再將答案vector從小排到大
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    //dir();
    return 0;
}

string normalize(string &s)
{
    string ans = s;
    for (int i = 0; i < ans.length(); i++)
    {
        ans[i] = tolower(ans[i]);   //將字串轉成小寫
    }
    sort(ans.begin(), ans.end());   //將字串從小排到大
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