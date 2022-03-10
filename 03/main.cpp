#define IN "P03IN.txt"
#define OUT "P03OUT.txt"
#include <iostream>
void redir();
void dir();

int main()
{
    redir();
    char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    int i, c;
    while((c = getchar()) != EOF)
    {
        for(i = 1; s[i] && s[i] != c; i++);
        if(s[i]) putchar(s[i-1]);
        else putchar(s[i]);
    }
    dir();
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