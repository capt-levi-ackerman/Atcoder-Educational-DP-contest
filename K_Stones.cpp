/*

  *                                             *
  * *                                             *
  *   *                                             *
        *                                             *
          **********************************************
          * THINK TWICE,        * *      Dknite      *
            *   CODE ONCE.     *   *                *
              *****************     ****************    


*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define FOR(i,a,b)     for (int i = a; i < b; i++)

inline int power(int a, int b)
{
  int x = 1;
  while (b)
  {
    if (b & 1) x *= a;
    a *= a;
    b >>= 1;
  }
  return x;
}


// O(logN) -> __gcd(a,b);


// int gcd(int a,int b)
// {
//   if(b==0) return a;
//   return gcd(b,a%b);
// }



// negative mod
inline int Nmode(int x,int m)
{
   x = x%m;
    if (x < 0) x += m;
    return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
  const char* comma = strchr (names + 1, ',');
  cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

// const int N = 200005;

/* void sieve()
{
  is_prime[0]=is_prime[1] = true;
  for(int i=2;i<=N;i++)
  {
    if(is_prime[i]==false && i*i<=N)
    {
      for(int j = i*i;j<=N;j+=i)
      {
        is_prime[j]= true;
      }
    }
  }
}
*/

int n,k;
int arr[101];
int dp[100001];

int rec(int x)
{
	if(x==0)
	{
		return 0;
	}

	// cache and check
	if(dp[x]!=-1)
	{
		return dp[x];
	}

	// transition / compute

	int ans = 0;
	for(int i =1;i<=n;i++)
	{
		if(arr[i]<=x && rec(x-arr[i])==0)
		{
			ans = 1;
			break;
		}
	}

	// save and return
	return dp[x] = ans;
}

void solve() {
	cin >> n >> k;
	for(int i =1;i<=n;i++)
	{
		cin >> arr[i];
	}

	memset(dp,-1,sizeof(dp));

	if(rec(k)==1)
	{
		cout << "First" << endl;
	}
	else
	{
		cout << "Second" << endl;
	}
}

int32_t main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("input.txt",  "r",  stdin);
//   freopen("output.txt", "w", stdout);
// #endif

  clock_t z = clock();

  int t = 1;
  // cin >> t;
  while (t--) solve();

  cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

  return 0;
}
