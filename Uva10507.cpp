#include <iostream>
#include <vector>
#include <cstdio>

#define vi vector<int>

using namespace std;

class UnionFind { // OOP style
private: vi p, rank; // remember: vi is vector<int>
public:
UnionFind(int N) { rank.assign(N, 0);
p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) {
if (!isSameSet(i, j)) { // if from different set
int x = findSet(i), y = findSet(j);
if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
else { p[x] = y;
if (rank[x] == rank[y]) rank[y]++; }
} } };

int letterToNumber(char c)
{
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i =0; i < 26; i++)
    {
        if(c == alphabet[i])
            return i;
    }
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        UnionFind uf(26);
        int connections; scanf("%d",&connections);
        string wakeUp; cin >> wakeUp;

        bool connectionsGraph[26][26];
        for(int i = 0; i < 26; i++)
        {
            for(int z = 0; z < 26; z++)
            {
                connectionsGraph[i][z] = false;
            }
        }

        for(int i = 0; i < connections; i++)
        {
            string con; cin >> con;
            int first = letterToNumber(con[0]);
            int second = letterToNumber(con[1]);

            connectionsGraph[first][second] = true;
            connectionsGraph[second][first] = true;
        }

        int awakeGroup = letterToNumber(wakeUp[0]);

        uf.unionSet(awakeGroup,letterToNumber(wakeUp[1]));
        uf.unionSet(awakeGroup,letterToNumber(wakeUp[2]));
        int year = 0, awake = 3;
        while(awake < n)
        {
            year++;
            vi toWake;
            bool stop = true;
            for(int i = 0 ; i < 26; i++)
            {
                int amount = 0;
                for(int a = 0; a < 26; a++)
                {
                    if(connectionsGraph[i][a])
                    {
                        if(uf.isSameSet(awakeGroup,a))
                        {
                            amount++;
                        }
                    }
                }
                if(amount >= 3)
                {
                    toWake.push_back(i);
                }

            }
            for(int i = 0; i < toWake.size();i++)
            {
                if(!uf.isSameSet(toWake[i],awakeGroup))
                {
                    uf.unionSet(toWake[i],awakeGroup);
                    awake++;
                    stop = false;
                }
            }
            if(stop)
            {
                break;
            }
        }
        if(awake >= n)
        {
            cout << "WAKE UP IN, " << year << ", YEARS\n";
        }
        else{
            cout << "THIS BRAIN NEVER WAKES UP\n";
        }
    }
    return 0;
}
/*
6
11
HAB
AB
AC
AH
BD
BC
BF
CD
CF
CH
DF
FH

5
0
ABZ

5
6
ABC
AD
AE
BD
BE
CD
CE

3
0
ABZ

4
0
ATJ

11
12
ABC
AB
BC
CD
BE
AE
AF
AG
AH
AI
AJ
AK
KJ

8
0
TYJ

10
20
ABC
AB
BC
CD
DE
EF
FG
IJ
FI
IC
DA
BJ
FJ
AC
DF
HI
HB
GA
GF
BG
CH

6
14
ABC
AB
AC
BC
AD
BD
CD
AE
BE
CE
DE
FB
FC
FD
FE

8
16
XYZ
ZA
AX
BY
BZ
CX
CY
DZ
YD
XE
ZE
XY
YZ
ZX
EF
CA
BD

7
12
JOM
PO
PJ
LM
PM
NO
NP
QP
QN
NM
QJ
LJ
LP

3
0
IUH

6
9
ABC
AD
BD
EC
ED
EA
FE
FA
FB
DC

6
9
ABC
AD
BD
CD
EC
ED
EA
FD
FC
FA

*/
