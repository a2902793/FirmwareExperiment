//[團體佇列/Queue](1/3)
#define IN "P18IN.txt"
#define OUT "P18OUT.txt"
#include <iostream>
using namespace std;
void redir(void);
void dir(void);

#include <map>
#include <queue>
#include <string>

int main()
{
    redir();
    int t, n, x;
    int i;
    int t0;
    int kase = 0;
    while (scanf("%d", &t) == 1 && t)
    {                       //t: the number of teams, 0 for quit
        map<int, int> team; //block scope
        for (i = 0; i < t; i++)
        {
            scanf("%d", &n); //n: the number of elements of team i
            while (n--)
            {
                scanf("%d", &x); //x: element
                team[x] = i;
            }
        }
        queue<int> teamQueue;
        queue<int> elementQueue[1000]; //elemnetQueue[i]: queue of elements of team i
        printf("Scenario #%d\n", ++kase);
        while (1)
        {
            string cmd; //block scope
            cin >> cmd;
            if (cmd[0] == 'S')
            { //STOP
                break;
            }
            else if (cmd[0] == 'D')
            { //DEQUEUE
                t0 = teamQueue.front();
                cout << elementQueue[t0].front() << endl;
                elementQueue[t0].pop();
                if (elementQueue[t0].empty())
                {
                    teamQueue.pop();
                }
            }
            else if (cmd[0] == 'E')
            { //ENQUEUE
                scanf("%d", &x);
                t0 = team[x];
                if (elementQueue[t0].empty())
                {
                    teamQueue.push(t0);
                }
                elementQueue[t0].push(x);
            }
        }
        printf("\n");
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