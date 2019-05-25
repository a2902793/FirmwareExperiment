#define OUT "P19OUT.txt"
#include <iostream>
using namespace std;
void redir();
void dir();

#include <queue>
#include <vector>
#include <set>

int main()
{
    redir();
    priority_queue<long long> pq; //愈小的(整數)優先權愈低
    set<long long> s;
    int i;
    long long x, x0;
    int coef[] = {2, 3, 5}; //2x, 3x, 5x
    int j;
    pq.push(-1);
    s.insert(-1);
    for (i = 1;; i++)
    {
        x = pq.top();
        pq.pop();
        if (i == 1500)
        {
            cout << "The 1500'th ugly number is " << -x << "." << endl;
            break;
        }
        for (j = 0; j < sizeof(coef) / sizeof(int); j++)
        {
            x0 = x * coef[j]; //compute 2x, 3x, 5x
            if (!s.count(x0))
            {
                s.insert(x0);
                pq.push(x0);
            }
        }
    }
    //dir();
    return 0;
}

void redir()
{
    freopen(OUT, "w", stdout);
}

void dir()
{
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
}