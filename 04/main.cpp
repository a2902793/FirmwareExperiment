#define IN "P04IN.txt"
#define OUT "P04OUT.txt"
#include <stdio.h>
#include <cstring>
#include <cctype>

void redir();
void dir();
char mirrored(char ch);

const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* msg[] = {"not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome"};
int main() {
    redir();
    char s[21];
    while (scanf("%s", s) == 1) {
        int len = strlen(s);
        int p = 1, m = 1;
        for (int i = 0; i < (len + 1) / 2; i++) {
            if (s[i] != s[len - 1 - i])
                p = 0;
            if (mirrored(s[i]) != s[len - 1 - i])
                m = 0;
        }
        printf("%s -- is %s.\n\n", s, msg[m * 2 + p]);
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

char mirrored(char ch) {
    if (isalpha(ch))
        return rev[ch - 'A'];
    return rev[ch - '0' + 25];
}