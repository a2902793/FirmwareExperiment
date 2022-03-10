#define IN "P02IN.txt"
#define OUT "P02OUT.txt"
#include <stdio.h>
void redir();
void dir();

int main()
{
    redir();
    char c;
    bool q;
    while((c = getchar()) != EOF) {
        if(c == '"') {
            printf("%s", q ? "``" : "''");
            q = !q;
        }
        else
            printf("%c",c);
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