#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
long long cnt[MAXN];

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
	
	cnt[0] = 0; //Βοηθητική θέση σε περίπτωση που η s[1...i] είναι απλή
				//συμβολοσειρά. Τότε cnt[i] = 1 + cnt[0] = 1
	stack<int> st;

	for(int i = 1; i <= N; i++){
		if(get(s, i) == '(') st.push(i);
		else{
			if(!st.empty()){
				int j = st.top();
				cnt[i] = 1 + cnt[j - 1]; //Η συμβολοσειρά s[j...i] είναι απλή
				st.pop();
			}
		}
	}

	long long ans = 0;
	for(int i = 1; i <= N; i++){
		ans += cnt[i]; 
	}
	cout << ans << '\n';

	return 0;
}