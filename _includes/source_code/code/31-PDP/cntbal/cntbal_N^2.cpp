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
		stack<char> st;
		long long balanced_from_i = 0;
		for(int j = i; j <= N; j++){
			if(get(s, j) == '(') st.push('(');
			else{
				if(!st.empty()){
					st.pop();
					if(st.empty()) balanced_from_i++; //Η στοίβα άδειασε και άρα
												//η s[i...j] είναι ισορροπημένη
				} else{
					break; //Παρένθεση κλείνει χωρίς να έχει ανοίξει
						//άρα απο δώ και στο εξής δεν υπάρχουν ισορροπημένες 
						//υποσυμβολοσειρές
				}
			}
		}
		ans += balanced_from_i;
	}

	cout << ans << '\n';

	return 0;
}