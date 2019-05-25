#define IN "P07IN.txt"
#define OUT "P07OUT.txt"
#include <iostream>
#include <string>
using namespace std;
void redir();
void dir();

int main()
{
    redir();
    int N;
    cin >> N;
    while (N--)
    {
        string str;
        cin >> str;
        string mini = str;
        for (int i = 0; i < str.size(); i++)
        {
            string tmp = str.substr(i + 1) + str.substr(0, i + 1);
            if (tmp < mini)
                mini = tmp;
        }
        cout << mini << endl;
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