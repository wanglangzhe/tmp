#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 111111

//for my angel
//she can't hear what i say?
int n, a[MAXN];

int main(){
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) scanf("%d", &a[i]);
	sort(a+1, a+1+n);
	for (int i=1; i<=n; ++i) printf("%d\n", a[i]);
	return 0;
}