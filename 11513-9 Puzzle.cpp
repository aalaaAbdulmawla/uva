#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <limits>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <iterator>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
#define LL long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define setzero(a) memset(a,0,sizeof(a))
#define setdp(a) memset(a,-1,sizeof(a))

#define rep(i, a, b) for (int i = int(a); i <int(b); i++)


using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int findZero (string s){
    rep(i, 0, 9)
        if (s[i] == '0')
            return i;
    return 0;
}

string swapChars(string s, int i, int j){
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;

    return s;
}


map <string, pair <string, LL> > m;

void bfs (){

    queue <string> q;
    q.push("123456789");

    m["123456789"] = mp("", 0);

    while (!q.empty()){
        string current = q.front();
        string direction = m[current].first;
        LL counter = m[current].second;
        q.pop();

        for (int i = 0; i < 9; i+=3){
            string temp = swapChars(current, i, i + 2);
            temp = swapChars(temp, i+1, i);
            if (m.find(temp) == m.end() ){
                ostringstream ss;
                ss << (i/3+1);
                q.push(temp);
                m[temp] = mp(direction + "H" + ss.str(), counter+1);
            }
        }

        for (int i = 0; i < 3; i++){
            string temp = swapChars(current, i, i + 6);
            temp = swapChars(temp, i+6, i + 3);
            if (m.find(temp) == m.end() ){
                ostringstream ss;
                ss << (i+1);
                q.push(temp);
                m[temp] = mp(direction + "V" + ss.str(), counter+1);
            }
        }


    }

}

int main()
{

    bfs();
    string s;
    int num;
    while (1){
        s = "";
        rep(i, 0, 3){
            rep(j, 0, 3){
                cin >> num;
                if (num == 0 ) return 0;
                ostringstream ss;
                ss << num;
                s += ss.str();
            }
        }
        if (m.count(s) == 0 ) cout << "Not solvable" << endl;
        else {
            cout << m[s].second << " " ;
            string str = m[s].first;
            for (int i = str.length()-1; i >=0; i -= 2)
                cout << str[i-1] << str[i];
            cout << endl;
        }

    }
    return 0;
}






