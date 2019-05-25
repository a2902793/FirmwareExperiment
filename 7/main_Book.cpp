#define IN "P07IN.txt"
#define OUT "P07OUT.txt"
#include <stdio.h>
#include <string.h>
void redir();
void dir();
#define maxn 105
int less(const char *s, int p, int q);

int main()
{
    redir();
    int T;
    char s[maxn];
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        int ans = 0;
        int n = strlen(s);
        for (int i = 1; i < n; i++)
        {
            if (less(s, i, ans))
                ans = i;
        }
        for (int i = 0; i < n; i++)
            putchar(s[(i + ans) % n]);
        putchar('\n');
    }
    //dir();
    return 0;
}

int less(const char *s, int p, int q)
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        if (s[(p + i) % n] != s[(q + i) % n])
            return s[(p + i) % n] < s[(q + i) % n];
    return 0; // 相等
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