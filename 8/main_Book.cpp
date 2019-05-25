#define IN "P08IN.txt"
#define OUT "P08OUT.txt"
#include <stdio.h>
#include <string.h> // strlen
#include <stdlib.h> // qsort
void redir();
void dir();
int cmp(const void *a, const void *b);

int main()
{
    redir();
    char s1[200], s2[200];
    while (scanf("%s%s", s1, s2) == 2)
    {
        int n = strlen(s1);
        int cnt1[26] = {0}, cnt2[26] = {0};
        for (int i = 0; i < n; i++)
            cnt1[s1[i] - 'A']++;
        for (int i = 0; i < n; i++)
            cnt2[s2[i] - 'A']++;
        qsort(cnt1, 26, sizeof(int), cmp);
        qsort(cnt2, 26, sizeof(int), cmp);
        int ok = 1;
        for (int i = 0; i < 26; i++)
            if (cnt1[i] != cnt2[i])
                ok = 0;
        if (ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
    //dir();
    return 0;
}

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
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