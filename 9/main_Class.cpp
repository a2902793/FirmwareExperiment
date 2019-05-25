#define IN "P09IN.txt"
#define OUT "P09OUT.txt"
#include <iostream>
#include <string>
using namespace std;
void redir(void);
int main(void)
{
    redir();
    int rnd;
    string s1, s2;
    int win, lose;
    int left;
    int chance;
    int i, j;
    int bad;

    while (scanf("%d", &rnd) == 1 && rnd != -1)
    {
        cin >> s1 >> s2;
        win = lose = 0;
        left = s1.length();
        chance = 7;
        for (i = 0; i < s2.length(); i++)
        {
            bad = 1;
            for (j = 0; j < s1.length(); j++)
            {
                if (s1[j] == s2[i])
                {
                    left--;
                    s1[j] = ' ';
                    bad = 0;
                }
            }
            if (bad)
                chance--;
            if (!chance)
                lose = 1;
            if (!left)
                win = 1;
            if (win || lose)
                break;
        }
        printf("Round %d\n", rnd);
        if (win)
        {
            cout << "You win.\n";
        }
        else if (lose)
        {
            cout << "You lose.\n";
        }
        else
        {
            cout << "You chickened out.\n";
        }
    }
    freopen("CON", "r", stdin); //取消重新導向
    freopen("CON", "w", stdout);
    return 0; //the end...
}
void redir(void)
{
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
}