/*
Author : lifecodemohit
*/

#ifdef __APPLE__

    #include <cassert>
    #include <iostream>
    #include <iomanip>
    #include <ctime>
    #include <cstdio>
    #include <vector>
    #include <algorithm>
    #include <utility>
    #include <queue>
    #include <stack>
    #include <string>
    #include <cstring>
    #include <sstream>
    #include <map>
    #include <set>
    #include <unordered_map>
    #include <unordered_set>

#else

    #include <bits/stdc++.h>

#endif  

using namespace std;

long long DP[100010][3][2];
long long MOD = 1e9 + 7;
string str;

long long dp(int idx, int mod_val, int flag, int len) {
	if (DP[idx][mod_val][flag] != -1)
		return DP[idx][mod_val][flag];
	if (idx == len) {
		if (!flag && (mod_val == 0))
			DP[idx][mod_val][flag] = 1;
		else
			DP[idx][mod_val][flag] = 0;
		return DP[idx][mod_val][flag];
	}
	if (flag) {
		long long ans = 0;
		for (int i = 0; i <= str[idx]-'0'; i++) {
			ans = (ans + dp(idx+1, (mod_val + i*i)%3, i == (str[idx]-'0'), len)) % MOD; 
		}
		DP[idx][mod_val][flag] = ans;
	}
	else {
		long long ans = 0;
		for (int i = 0; i < 10; i++)
			ans = (ans + dp(idx+1, (mod_val + i*i)%3, 0, len)) % MOD; 
		DP[idx][mod_val][flag] = ans;
	}
	return DP[idx][mod_val][flag];
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		memset(DP, -1, sizeof(DP));
		cin >> str;
		int sz = str.length();
		cout << dp(0, 0, 1, sz) << endl;	// left - to - right
	}
	return 0;
}