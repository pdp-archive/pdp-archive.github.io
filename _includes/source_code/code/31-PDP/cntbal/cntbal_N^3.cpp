#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

char get(string &str, int ind){
	return str[ind - 1];
}

int main(){
	ios_base::sync_with_stdio(false); //Τα χρησιμοποιούμε πάντα οταν θέλουμε να 
	cin.tie(NULL), cout.tie(NULL);    //χρησιμοποιήσουμε cin/cout

	#ifdef CONTEST
	freopen("cntbal.in", "r", stdin);
	freopen("cntbal.out", "w", stdout);
	#endif
	

	int N; string s;
	cin >> N >> s;

	long long ans = 0;
	for(int i = 1; i <= N; i++){
		for(int j = i + 1; j <= N; j++){
			//Θα ελέγξουμε αν η s[i...j] είναι ισορροπημένη
			stack<char> st;
			bool isBalanced = true;
			for(int k = i; k <= j; k++){
				if(get(s, k) == '(') st.push('(');
				else{
					if(st.empty()){
						isBalanced = false;
						break;
					} else{
						st.pop();
					}
				}
			}
			if(isBalanced && st.empty()) ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}