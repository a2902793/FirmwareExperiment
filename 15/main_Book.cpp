#define IN "P15IN.txt"
#define OUT "P15OUT.txt"
#include <iostream>
using namespace std;
void redir();
void dir();

#include <string>
#include <sstream>
#include <set>

set<string> dict;
string s, buf;

int main()
{
    redir();
      while(cin >> s) {
    for(int i = 0; i < s.length(); i++)
      if(isalpha(s[i])) s[i] = tolower(s[i]); else s[i] = ' ';
    stringstream ss(s);
    while(ss >> buf) dict.insert(buf);
  }
  for(set<string>::iterator it = dict.begin(); it != dict.end(); ++it)
    cout << *it << "\n";
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