#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>

using namespace std;

#define PB push_back

ifstream os;

map <string, bool > mp;
map <string, int > dist;
map <string, string > pre;
string str;

void init() {
    ios::sync_with_stdio(false);
    os.open("dictionary-yawl.txt");
    mp.clear();
    while (os >> str) {
        mp[str] = true;
    }
    cout << "reading finish" << endl;
    os.close();
}

void bfs(const string &st, const string &ed) {
    dist.clear();
    queue <string > q;
    q.push(st); dist[st] = 0;
    
    while (q.size()) {
        string u = q.front(), now = u; q.pop();
        for (int i = 0; i < u.size(); ++i) {
            for (char ch = 'A'; ch <= 'Z'; ++ch) {
                swap(u[i], ch);
                if (dist.count(u) == 0 || dist[u] > dist[now] + 1) {
                    if (mp.count(u) && dist.count(u) == 0) {
                        q.push(u);    
                    }
                    dist[u] = dist[now] + 1;
                    pre[u] = now;
                }
                swap(u[i], ch);
            }
        }
    }
    vector <string  > ans;
    string u = ed; ans.PB(ed);
    while (u != st) {
        u = pre[u];
        ans.PB(u);
    }
    reverse(ans.begin(), ans.end());
    
    cout << "Word ladder from data to code: " << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] <<' '; 
    } cout << endl;
}

void solve() {
    string a, b;
    while (cin >> a) {
        cin >> b;
        if (a.size() != b.size()) {
            cout << "The length is not the same" << endl;
            continue;
        } else if (!mp.count(a) || !mp.count(b)) {
            cout << "The word not exist" << endl;
            continue;
        }
        bfs(a, b);        
        cout << "length: " << dist[b] << endl;
    }
}

int main() {
    string cont;
    do {
        init();
        solve();
    } while (cont == "Y");
    return 0;
    
}
