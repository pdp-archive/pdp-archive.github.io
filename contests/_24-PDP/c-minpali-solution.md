---
layout: solution
codename: minpali
---

## Επεξήγηση εκφώνησης


Μας ζητείται να υπολογίσουμε τον μικρότερο μήκος παλίνδρομου που μπορεί να παραχθεί από τη δοσμένη συμβολοσειρά η οποία πρέπει ταυτόχρονα να αποτελεί prefix του παλίνδρομου.   
Ας υποθέσουμε ότι μας δίνεται η συμβολοσειρά **abcdefed**. Η brute force λύση είναι να δοκιμάσουμε όλους τους συνδυασμούς πιθανών παλίνδρομων άρα από μήκος $$N$$ έως $$2\cdot N-1$$. Λεπτομέρειες στο παρακάτω σχήμα.


![Παράδειγμα](/assets/24-pdp-c-minpali-example2.svg){:width="640px"}

Για τους χαρακτήρες της συμβολοσειράς εισόδου δηλαδή ισχύει ότι $$0 \leq i \leq N-1 < N+i$$ όπου $$i$$ είναι η θέση που ξεκινά το παλίνδρομο, $$N-1$$ ο τελευταίος 
χαρακτήρας της συμβολοσειράς εισόδου και από $$N$$ έως τη $$N+i$$ θέση θα πρέπει να προσθέσουμε $$i$$ χαρακτήρες 
για να πετύχουμε το παλίνδρομο που μας ζητείται (τους $$i$$ πρώτους χαρακτηρες με αντίστροφη σειρά).  
  
  	
  	
## Αργή λύση $$\mathcal{O}(N^2)$$ Brute Force

Παρακάτω δίνεται μία ενδεικτική υλοποίηση αυτής της λύσης. Η λύση αυτή περνά τα 11 από τα 14 test cases.

```c++
#include <cstdio>
#include <algorithm>

using namespace std;

const long MAXN = long(1e7);
long N;
char S[MAXN+1];

bool is_palindrome(long K){
	//check if a string of size Κ with S as prefix is a palindrome
	//ie [S[0],S[j/2-1]] should be equal to [S[j/2],S[S-1]]
	//but remember that not all of those chars exist
	//note:	if the ans is odd, then we have a central pivot char
	//	if the ans is even, we have two exact halfs without a pivot.
	long left = K/2, right = K/2;
	if((K%2)==0)
		left--;
	while(left>=0 && right<N)
		if(S[left--] != S[right++])
			return false;
	return true;
}

int main(){
#ifdef CONTEST
	freopen("minpali.in","r",stdin);
	freopen("minpali.out","w",stdout);
#endif
	scanf("%ld %s",&N,S);
	//worst case: no part of string can be reused to build palindrome.
	//	We will need N-1 more chars (1 pivot at the center)
	//best  case: entire string is a palindrome
	//	so no more chars are required
	long 	bestcase  = N, 
		worstcase = N * 2 - 1, 
		ans;
	for(ans=bestcase;ans<=worstcase && !is_palindrome(ans);++ans)
		;
	printf("%ld\n",ans);
	return 0;
}
```


## Βέλτιστη Λύση - $$\mathcal{O}(N)$$

Γνώσεις που θα χρειαστούμε: **Rabin-Karp Algorithm** και **Rolling hash**   
([camp ΠΔΠ 2017 Rabin-Karp](http://git.softlab.ntua.gr/pub/pdp-camp/blob/master/2017/hashing.cpp))  
([camp ΠΔΠ 2017 Rabin-Karp](http://git.softlab.ntua.gr/pub/pdp-camp/blob/master/2017/String%20Algorithms.pdf))  
([Καλλίνικος Hash-Table](https://kallinikos.github.io/Hash-Table))  
([wikipedia Rabin-Karp](https://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm))  
([wikipedia Rolling hash](https://en.wikipedia.org/wiki/Rolling_hash))  

Το πρόβλημα με την προηγούμενη λύση είναι ότι κάθε φορά που θέλουμε να αρχίσουμε τον έλεγχο από την επόμενη θέση, 
ελέγχουμε από την αρχή τα $$N$$ στοιχεία.  

Στη λύση που ακολουθεί θα χρησιμοποιήσουμε τον αλγόριθμο Rabin-Karp. Ο Αλγόριθμος Rabin-Karp ορίζει μία τιμή hash για κάθε συμβολοσειρά, ως τον υπολογισμό ενός πολυωνύμου modulo ενός "μεγάλου" ακεραίου $$\mathit{MOD}$$ όπου κάθε $$i$$ όρος του αποτελεί γινόμενο της αριθμητικής αναπαράστασης του χαρακτήρα $$S_i$$ και ενός συντελεστή $$C_i$$.
Υπάρχει πιθανότητα δύο διαφορετικές συμβολοσειρές να έχουν ίδια τιμή hash αλλά αυτή η πιθανότητα μικραίνει αρκετά με μια καλή επιλογή $$\mathit{MOD}$$. Γενικά προτιμάμε πρώτους αριθμούς με τιμές όσο το δυνατό μεγαλύτερες, όχι όμως τόσο μεγάλες που να γίνεται overflow στις πράξεις που κάνουμε πριν εφαρμοσθεί το modulo).

Προσοχή: στην εκφώνηση δεν δίνεται το σύνολο χαρακτήρων που περιέχει η συμβολοσειρά οπότε θα πρέπει ή να υποθέλουμε ότι είναι το $$256$$ ή να το υπολογίσουμε.  
Η παρακάτω συνάρτηση κάνει συμπίεση των τιμών των χαρακτήρων και υπολογισμό της μέγιστης τιμής της συμβολοσειράς (μετά την συμπίεση). 

```c++
void readS(){//read and compress S[]
	scanf("%ld %s",&N,S);
	C = 1;
	long V[256];
	memset(V,0,sizeof(V));
	for(long i=0;i<N;++i){//compress values
		long& cv = V[long(S[i])];
		if(cv == 0)
			cv = C++;
		S[i] = cv;
	}
}

```

Η υλοποίηση που θα δούμε παρακάτω ξεκινά από την χειρότερη περίπτωση (όπου για να έχουμε παλίνδρομο θα έπρεπε να αντιγράψουμε όλη τη συμβολοσειρά εκτός του 
τελευταίου χαρακτήρα στο τέλος αντεστραμμένο για να έχουμε παλίνδρομο) και θα κάνουμε επαύξηση των hash values ώστε να καλύπτουν το νέο υπο εξέταση χαρακτήρα.
Στο ένα hash value που ασχολείται με την μια φορά ανάγνωσης της συμβολοσειράς προσθέτουμε τον χαραλτήρα με τον μικρότερο εκθέτη ($$C^0$$) ενώ στο άλλο με τον μεγαλύτερο ($$C^{length}$$).  
Πολυπλοκότητα της λύσης: $$\mathcal{O}(N)$$ κάθε χαρακτήρας χρησιμοποιείται δύο φορές. Η λύση αυτή περνά όλα τα test cases.
Μία ενδεικτική υλοποίηση με τη χρήση **Rabin-Karp Algorithm** παρουσιάζεται παρακάτω:  
```c++
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <map>
#include <cmath>
#include <cstring>
#include <cassert>

using namespace std;

const long 	MAXN = long(1e7);
long 		N,ans,C;	//factor for rabin karp poly. Has to be > number of chars
char 		S[MAXN+1];

typedef unsigned long long hasht;
const hasht	MOD = hasht(1e9)+7;	//It is imperative that MOD*MOD fit hasht typedef

void readS(){//read and compress S[]
	scanf("%ld %s",&N,S);
	//compress input chars. Note: If all 256 chars were introduced, the S[i] values
	//would overflow (because we start counting from 1 instead of 0).
	//However this is not the case as there are symbols and special chars
	//line ESC,EOF,'\a','\n',\r' that cannot be part of the input string
	C = 1;
	long V[256];
	memset(V,0,sizeof(V));
	for(long i=0;i<N;++i){//compress values
		long& cv = V[long(S[i])];
		if(cv == 0)
			cv = C++;
		S[i] = cv;
	}
}

int main(){
#ifdef CONTEST
	freopen("minpali.in", "r",stdin);
	freopen("minpali.out","w",stdout);
#endif
	readS();
	
	hasht left_right = 0, right_left = 0, expC = 1;//expC = exponent for Rabin-Karp
	for(long i=N-1;i>=0;i--){
		left_right = ( left_right + ((S[i]*expC)%MOD) ) % MOD;
		right_left = (((right_left*C)%MOD) + S[i] ) % MOD;
		expC = (expC * C) % MOD;
		if(left_right == right_left){
			//this is a palindrome with lengh = N-i
			//outside palindrome are i characters
			//so a total of i (prefix) + N-i (palindrome) + i(tail need to add)
			ans = N + i;
		}
	}
	printf("%ld\n",ans);
}
```

Αντί για υπόλοιπα διαιρέσεων με πρώτο αριθμό που υπολογιστικά έχουν κάποιο βάρος, μπορούμε να χρησιμοποιήσουμε δυαδική λογική και να χρησιμοποιήσουμε για τα υπόλοιπα των πράξεων μας μια δύναμη του δύο. Ας δώσουμε στη δύναμη αυτή το όνομα $$\mathit{MOD\_VAL}$$. Αξιοποιώντας δυαδικούς τελεστές, δεν θα χρειαστούμε να χρησιμοποιήσουμε τον τελεστή της *C++* για modulo. Το υπόλοιπο με τη $$\mathit{MOD\_VAL}$$ βρίσκεται αν κάνουμε δυαδικό $$AND$$ με τα bits των $$\mathit{MOD\_VAL}-1$$ και του $$\mathit{hash}$$ value που θέλουμε να βρούμε το υπόλοιπό του. 
 Για  $$\mathit{MOD\_VAL} = 2^{32}$$ χρειάζεται να γίνει $$AND$$ με το $$2^{32}-1$$.
 Η μέγιστη τιμή που μπορεί να φτάσουμε στους υπολογισμούς κατά τον υπολογισμό μιας hash value και πριν εφαρμοσθεί το $$AND$$ παράγετε από τo γινόμενο $$S_i\cdot\mathit{expC}$$ και είναι $$C\cdot\mathit{MOD\_VAL}$$.

 Προσοχή: ο $$C$$ και ο $$\mathit{MOD\_VAL}$$ πρέπει να είναι πρώτοι μεταξύ τους άρα ο $$C$$ δεν μπορεί να είναι άρτιος. Αυτό το φροντίζουμε ανάβοντας (αν χρειάζεται) το **LSB** (least significant bit) που αντιπροσωπεύει τις μονάδες  
```c++
	C |= 1;
```

Ακολουθεί η τροποποίηση στην Rabin-Karp λύση για χρήση binary AND

```c++
	const hasht MOD = hasht(0xffffffff);
	hasht left_right = 0, right_left = 0, expC = 1;
	C |= 1;//make C odd (set LSB)
	for(long i=N-1;i>=0;i--){
		left_right = (left_right + ((S[i]*expC)&MOD))&MOD;
		right_left = (((right_left*C)&MOD) + S[i])&MOD;
		expC = (expC*C)&MOD;
		if(left_right == right_left){
			//this is a palindrome with lenght = N-i
			//outside palindrome are i characters
			//so a total of i (prefix) + N-i (palindrome) + i(tail we should add)
			ans = N + i;
		}
	}
```

  
## Βέλτιστη λύση - $$\mathcal{O}(N)$$

Γνώσεις που θα χρειαστούμε: **Knuth–Morris–Pratt algorithm** ή **$$\mathcal{Z}$$ algorithm**   
([Z algorithm](https://drive.google.com/open?id=1ev5dqBCS5KJU7-042QUEe_GVwtVNhuby)   

Ο αλγόριθμος $$\mathcal{Z}$$ έχοντας μια συμβολοσειρά σαν είσοδο, υπολογίζει έναν πίνακα ακεραίων $$Ζ$$ έτσι ώστε στη θέση
$$Z_i$$ περιέχει το μήκος της συμβολοσειράς που ξεκινά από τη θέση $$i$$ και ταυτίζεται με τους $$Z_i$$ χαρακτήρες του προθέματος (συμβολοσειρά που ξεκινά στη θέση $$0$$). Δηλαδή $$S_{i+j} == S_j, \forall j \in [0,Z_i]$$  
Θέλουμε να βρούμε ένα παλίνδρομο από μια θέση $$i$$ έως το τέλος της συμβολοσειράς εισόδου (όπως εξηγήσαμε στο αρχικό σχήμα). 
Φτιάχνουμε έναν πίνακα χαρακτήρων $$S$$ με μήκος $$2Ν$$. Αντιστρέφουμε τη συμβολοσειρά εισόδου στο πρώτο μισό του πίνακα χαρακτήρων $$S$$ και 
στο δεύτερο μισό του πίνακα έχουμε αυτούσια τη συμβολοσειρά εισόδου. Τρέχουμε τον αλγόριθμο $$\mathcal{Z}$$ και κατόπιν ξεκινάμε 
από τη θέση $$N$$ έως την τελική θέση $$2N-1$$ να ελέγχουμε αν το $$Z_i$$ ισούται με το υπολοιπόμενο μήκος της συμβολοσειράς. 
Όταν το τμήμα από τη θέση $$i$$ έως το τέλος του $$S$$ ταυτίζεται, τότε σημαίνει ότι βρήκαμε τμήμα που διαβάζεται ώς παλίνδρομο 
και απλά πρέπει να προσθέσουμε δυο φορές το πρόθεμα (από την θέση $$N$$ έως τη θέση $$i$$) το οποίο δεν έχει ταυτιστεί (μια φορά 
ως πρόθεμα και μια ώς κατάληξη).  

Μία ενδεικτική υλοποίηση με $$\mathcal{Z}$$ algorithm παρουσιάζεται παρακάτω:

```c++
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>

using namespace std;

const long MAXN = long(1e7);
long N, Z[2*MAXN+1];
char S[2*MAXN+1];


void fill_Z(const char *s, long *Z, long n) { 
	int L, R, k; 

	L = R = 0; 
	for(long i = 1; i < n; ++i) { 
		if(i > R){ 
			L = R = i; 
			while (R<n && s[R-L]==s[R]) R++; 
			Z[i] = R-L; 
			R--; 
		} else { 
			k = i - L; 
			if(Z[k]<R-i+1) {
				Z[i] = Z[k]; 
			} else {
				L = i; 
				while (R<n && s[R-L]==s[R]) R++; 
				Z[i] = R-L; 
				R--; 
			} 
		} 
	} 
} 

int main(){
#ifdef CONTEST
	freopen("minpali.in","r",stdin);
	freopen("minpali.out","w",stdout);
#endif
	scanf("%ld",&N);
	scanf(" %s",S+N);//read string from middle of string array
	//add reversed string in the yet unfilled first half
	for(long i=0,rev=2*N-1;i<N;i++,rev--)
		S[i] = S[rev];

	fill_Z(S,Z,2*N);
	
	long ans = 2*N-1;//worst case
	for(long i=N,k=2*N-1; i<k; ++i){
		if(Z[i] >= k-i){
			//(k-i) is a palindrome. N-(k-i) is 
			//the prefix part that is not in the palindrome and
			//if we add it reversed at the end of S[] we would
			//complete the palindrome that its length is asked.
			ans = k-i + 2 * (N - (k-i)) - 1;
			break;
		}
	}
	
	printf("%ld\n",ans);
	return 0;
}
```

## Official λύση
([camp ΠΔΠ 2017 KMP explained](http://git.softlab.ntua.gr/pub/pdp-camp/blob/master/2016/String%20matching.pdf))  
([wikipedia KMP](https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm))   
```c++
/*
USED : pdp24u11
TASK : minpali
LANG : C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define MAXC 10000005
#define mp make_pair
#define INF 0x3f3f3f3f
#define X first
#define Y second
typedef long long llint;
typedef pair<int,int> pii;
int N, F[MAXC];
char str[MAXC], rev[MAXC];

void Read() {
	int i;
	scanf ("%d %s\n", &N, str);
	for ( i=0; i<N; ++i ) {
		rev[i] = str[N-i-1];
	}
}

void Prefix () {
	int i, j;
	F[0] = F[1] = 0;
	for ( i=2; i<=N; ++i ) {
		j = F[i-1];
		while ( 1 ) {
			if ( rev[i-1] == rev[j] ) {
				F[i] = j+1;
				break;
			}
			else if ( j==0 ) {
				F[i] = j;
				break;
			}
			else {
				j = F[j];
			}
		}
	}
}
void KMP () {
	int i=0, j=0;
	while ( 1 ) {
		if ( i==N ) {
			break;
		}
		if ( str[i] == rev[j] ) {
			++i;
			++j;
		}
		else if ( j==0 ) {
			++i;
		}
		else {
			j = F[j];
		}
	}
	printf ("%d\n", 2*N - j );
}

int main ( void ) {
	#ifdef D
		freopen ("input","r",stdin);
	#endif
	freopen ("minpali.in","r",stdin);
	freopen ("minpali.out", "w", stdout );
	Read();
	Prefix();
	KMP();
	return 0;
}
```
