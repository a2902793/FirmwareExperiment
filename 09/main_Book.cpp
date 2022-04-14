#define IN "P09IN.txt"
#define OUT "P09OUT.txt"
#include <stdio.h>
#include <string.h>
void redir();
void dir();

#define maxn 100
int left, chance;
char s[maxn], s2[maxn];
int win, lose;

void guess(char ch) {
    int bad = 1;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ch) {
            left--;
            s[i] = ' ';
            bad = 0;
        }
    }
    if (bad)
        --chance;
    if (!chance)
        lose = 1;
    if (!left)
        win = 1;
}

int main() {
    redir();
    int rnd;
    while (scanf("%d%s%s", &rnd, s, s2) == 3 && rnd != -1) {
        printf("Round %d\n", rnd);
        win = lose = 0;
        left = strlen(s);
        chance = 7;
        for (int i = 0; i < strlen(s2); i++) {
            guess(s2[i]);
            if (win || lose)
                break;
        }
        if (win)
            printf("You win.\n");
        else if (lose)
            printf("You lose.\n");
        else
            printf("You chickened out.\n");
    }
    dir();
    return 0;
}

void redir() {
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
}

void dir() {
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
}