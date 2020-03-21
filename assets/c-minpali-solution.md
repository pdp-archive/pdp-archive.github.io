---
layout: solution
codename: minpali
---

## Επεξήγηση εκφώνησης


Μας δίνεται μια συμβολοσειρά χαρακτήρων μήκους $$Ν$$ (το μήκος συμβολοσειρών χαρακτήρων γενικά συμβολίζεται $$\lvert N\rvert$$) και μας ζητείται να υπολογίσουμε το μικρότερο μήκος παλίνδρομου που μπορεί να παραχθεί από αυτό ενώ πρέπει οπωσδήποτε η δοσμένη συμβολοσειρά να αποτελεί prefix του τελικού παλίνδρομου  
Προσέξτε ότι δεν δίνεται το σύνολο χαρακτήρων στο οποίο ανήκουν οι χαρακτήρες. 
Ας υποθέσουμε ότι μας δίνεται η συμβολοσειρά **abcdefed**. Η brute force λύση είναι να δοκιμάσουμε όλους τους συνδυασμούς πιθανών παλίνδρομων άρα από μήκος $$N$$ έως $$2\cdot N-1$$. Λεπτομέρειες στο παρακάτω σχήμα.


![Παράδειγμα](/assets/24-pdp-c-minpali-example2.png){:width="640px"}

  
  	
  	
## Αργή λύση $$\mathcal{O}(N^2)$$ Brute Force

Γνώσεις που θα χρειαστούμε: Καμία.

Παρακάτω δίνεται μία ενδεικτική υλοποίηση αυτής της λύσης.

```c++
#include <cstdio>
#include <algorithm>

using namespace std;

const long MAXN = long(1e7);
long N;
char S[MAXN+1];

bool accepted(long K){
	//check if a string of size Κ with S as prefix can a palindrome
	//[S[0],S[j/2-1]] should be equal to [S[j/2],S[S-1]]
	//but remember that not all of those chars exists
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
	for(ans=bestcase;ans<=worstcase && !accepted(ans);++ans)
		;
	printf("%ld\n",ans);
	return 0;
}
```


## Ικανοποιητική Λύση - $$\mathcal{O}(N\cdot log{N})$$

Γνώσεις που θα χρειαστούμε: **Rabin-Karp Algorithm** και **Rolling hash**   
([camp ΠΔΠ 2017 Rabin-Karp](http://git.softlab.ntua.gr/pub/pdp-camp/blob/master/2017/hashing.cpp))  
([camp ΠΔΠ 2017 Rabin-Karp](http://git.softlab.ntua.gr/pub/pdp-camp/blob/master/2017/String%20Algorithms.pdf))  
([Καλλίνικος Hash-Table](https://kallinikos.github.io/Hash-Table))  
([wikipedia Rabin-Karp](https://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm))  
([wikipedia Rolling hash](https://en.wikipedia.org/wiki/Rolling_hash))  

Το πρόβλημα με την προηγούμενη λύση είναι ότι ενώ θέλουμε να δοκιμάσουμε έναν χαρακτήρα κάθε φορά ολισθαίνοντας τα δυo τμήματα του υποψήφιου παλίνδρομου, ελέγχουμε από την αρχή τα $$\frac{N}{2}$$ στοιχεία. Η μέθοδος που θα χρησιμοποιήσουμε θα κάνει κυλιόμενη σύγκριση στην αριστερή και δεξιά συμβολοσειρά ώστε να έχουμε γραμμική πολυπλοκότητα.  

Στον αλγόριθμο Rabin Karp κατασκευάζουμε ένα πολυώνυμο το οποίο αποτελείται από αθροίσματα μονώνυμων. Κάθε μονώνυμο είναι γινόμενο ενός χαρακτήρα του αλφαριθμητικού και κάποιας δύναμης ενός σταθερού αριθμού $$C$$. Λόγω των μεγάλων εκθετών που χρησιμοποιεί το πολυώνυμο για αλφαρηθμιτικά μεγέθους $$\mathit{MAXN}$$ δηλαδή $$10^7$$ μονώνυμα, θα ξεπεράσει το όριο των τύπων ακεραίων μέχρι 64bit που χρησιμοποιούν οι περισσότερες γλώσσες προγραμματισμού, ενώ με χρήση **BigInteger** θα είχαμε πολύ χαμένο χρόνο σε υπολογισμούς.  
Μια εύκολη λύση είναι να χρησιμοποιήσουμε τα υπόλοιπα της διαίρεσης με κάποιον μεγάλο αριθμό ώστε να κρατήσουμε τα αποτέλεσμα σε διαχειρίσιμα για το πρόγραμμα μας όρια. Ορίζοντας έναν τέτοιο αριθμό $$\mathit{MOD}$$ πρέπει να προσέξουμε να είναι πρώτος σε σχέση με τον αριθμό $$C$$ που χρησιμοποιούν τα μονώνυμα στο πολυώνυμο μας ώστε να μειώσουμε τις πιθανότητες ένα μονώνυμο να επηρεάσει το ίδιο σημείο με κάποιο άλλο αλλά και να είναι μικρότερος από $$2^{32}$$ ώστε να επιτρέπει πολλαπλασιασμό δυο hash values μεταξύ τους χωρίς υπερχείλιση. Ο αριθμός $$C$$ πρέπει επιπλέον να είναι μεγαλύτερος από τον αριθμό των διαφορετικών χαρακτήρων που έχουμε στη συμβολοσειρά εισόδου. Δηλαδή αν η μέγιστη τιμή ενός χαρακτήρα είναι ο ASCII χαρακτήρας $$'z'$$ τότε θα πρέπει το C να είναι μεγαλύτερο από την τιμή αυτή.  

Προσέχοντας την εκφώνηση θα δούμε ότι δεν καθορίζει το σύνολο χαρακτήρων στην είσοδο μας. Δεν μπορούμε να υποθέσουμε ότι υπάρχουν μόνο πεζά γράμματα. Θα πρέπει ή να προβλέψουμε τη χρήση όλων των εκτυπώσιμων χαρακτήρων (σύμβολα, γράμματα, αριθμούς) ή να κάνουμε compress και να αντιστοιχίσουμε κάθε διακριτό χαρακτήρα σε ένα δικό μας αριθμό μεγαλύτερο του μηδενός.  
  
Ο αλγόριθμος Rabin Karp έχει δυνατότητα να "σπρώχνει" (ολισθαίνει) ένα string προς πιο μεγάλες δυνάμεις στο πολυώνυμο, αφήνοντας κενή την θέση που έχει εκθέτη $$C^0$$. Επειδή σε εμάς χρειάζεται ολίσθηση στο ένα τμήμα της συμβολοσειρά προς τη μια κατεύθυνση και στο άλλο τμήμα προς την ανάποδη, σημαίνει ότι το ένα hash πρέπει να το ολισθαίνουμε ώστε να βγάζουμε τα μεγάλα μονώνυμα ενώ το άλλο να βγάζουμε τα μικρά μονώνυμα. Αν δοκιμάσουμε να κάνουμε ολίσθηση ώστε να βγάλουμε τα μικρά μονώνυμα, θα χρειαστεί να διαιρέσουμε με τον αριθμό $$C$$ με καταστροφικά αποτελέσματα για τον υπολογισμό των τιμών **hash** που χρησιμοποιούμε. Η λύση σε αυτό είναι να προϋπολογίσουμε τα hash values από τη μια κατεύθυνση και κατόπιν να σαρώσουμε με ένα βρόγχο τη συμβολοσειρά μας από την άλλη κατεύθυνση για να δούμε αν θα ταυτιστούν το αριστερό με το δεξιό hash value. Τα hash values που έχουμε να αποθηκεύσουμε είναι $$\frac{N}{2}$$ οπότε θα καταλάβουν μνήμη εντός ορίων αν χρησιμοποιήσουμε για hash values **long long** ή καλύτερα **__int64** ώστε να έχουμε $$8$$ bytes ανά τιμή.  
  
Δεν τελειώσαμε όμως με τη μνήμη, χρειαζόμαστε και έναν πίνακα με τις δυνάμεις του $$C$$ ώστε να μπορούμε καθώς μειώνεται συνεχώς το μήκος του υπό εξέταση πολυωνύμου να έχουμε τον μέγιστο εκθέτη του ώστε να αφαιρέσουμε τον μέγιστο όρο όταν χρειάζεται. Η λύση που θα δώσουμε είναι τύπου **binary lifting** δηλαδή θα έχουμε έναν πίνακα $$\mathit{pow}$$ με $$log_2(\frac{N}{2})$$ στοιχεία όπου κάθε θέση του $$i$$ θα έχει το $$C^{2^i}$$ αποθηκευμένο, οπότε θα χρειαζόμαστε $$log_2{k}$$ βήματα για να βρούμε τον όρο $$C^k$$ του πολυωνύμου.  
```c++
hasht powC(long n){	
	//O(log2N) calc power of C (not enough mem to store all values in array)
	//binary lifting to calc value of pow(C,n) in log2(n)
	static hasht _pow[32];
	static long sz = 0;
	if(sz == 0){//precompute powers of C array
		sz = ceil(log2(N/2));
		_pow[0] = C;
		for(long i=1; i<=sz; ++i)
			_pow[i] = (_pow[i-1] * _pow[i-1]) % MOD;
	}
	hasht z = 1;
	for(long i = sz; i>=0; --i)
		if(n & (1l<<i))
			z = (z * _pow[i]) % MOD;
	return z;
}
```
Η παραπάνω συνάρτηση επιστρέφει το $$C^n, \forall n \in [0,\frac{N}{2}]$$ αξιοποιώντας τους εκθέτες του $$2$$ καθώς κάθε ακέραιος γράφεται σαν άθροισμα δυνάμεων του $$2$$ και αυτό ακριβώς είναι αποθηκευμένο στα bit του αριθμού $$n$$.

Το hashing είναι μια βολική τεχνική να αντιμετωπίζουμε ένα ολόκληρο αντικείμενο (σας το κάθε τμήμα της συμβολοσειράς) σε ένα μικρό και εύκολα συγκρίσιμο κωδικό (το hash). Όπως βέβαια δεν είναι δυνατό να χωρέσουμε 10 πορτοκάλια σε 9 καλάθια χωρίς να βάλουμε 2 πορτοκάλια σε ένα καλάθι έτσι και με το hashing μπορεί να έχουνε collition (δηλαδή δύο συμβολοσειρές να έχουν ίδια τιμή hash) και ο αλγόριθμος να βγάλει εσφαλμένα συμπέρασμα ότι οι δυο συμβολοσειρές είναι ίδιες.
Μια λύση (που δεν ακολουθούμε γενικά σε διαγωνισμούς λόγω περιορισμένων χρονικών απαιτήσεων εκτέλεσης) είναι να ελέγξουμε με brute force ότι πράγματι η ταυτοποίηση των δυο hash values επιβεβαιώνει πράγματι την ισότητα των δυο αλφαριθμητικών. Η συνάρτηση αυτή θα κληθεί ακριβώς $$\frac{N}{2}$$ φορές άρα $$\mathcal{O}(N)\cdot log_2N$$ πολυπλοκότητα.
Η παρακάτω συνάρτηση δέχεται σαν παραμέτρους το τέλος της πρώτης συμβολοσειράς και το μήκος της (η δεύτερη έχει τέλος στο $$N-1$$ και ίδιο μήκος).
```c++
bool doublecheck(long leftend,long length){
	//check if collition in hashing occured. We have to check up to length chars.
	long left = leftend - length + 1;//where lest string starts(forward parsing)
	long right= N-1;//where right string starts (backward parsing)
	dprintf("dc: %ld[%d] with %ld[%d]\n",left,S[left],right,S[right]);
	while(left<right)
		if(S[left++]!=S[right--])
			return false;
	return true;
}

```

Η παρακάτω συνάρτηση κάνει συμπίεση των τιμών των χαρακτήρων. Αν π.χ. η συμβολοσειρά εισόδου έχει συνδυασμό μόνο από τους χαρακτήρες $$\{'a', 'b', 'g', 'k', 'p' \}$$ θα αντικαταστήσει όλες τις εμφανίσεις του $$'a'$$ με το $$1$$, του $$'b'$$ με το $$2$$ κ.ο.κ. επιτρέποντας να μειωθεί η τιμή του $$C$$ στο ελάχιστο δυνατό μειώνοντας τις πιθανότητες collition. Τρέχει σε $$\mathcal{O}(N)$$ πολυπλοκότητα  
```c++
void readS(){//read and compress S[]
	scanf("%ld %s",&N,S);
	//compress input chars
	C = 1;
	int V[256];
	memset(V,0,sizeof(V));
	for(long i=0;i<N;++i){//compress values
		int& cv = V[S[i]];
		if(cv == 0)
			cv = C++;
		S[i] = cv;
	}
}
```

Συνολική πολυπλοκότητα $$\mathcal{O}N\cdot log_2N$$ λόγω της **powC**. Η λύση αυτή περνά όλα τα test cases.
Μία ενδεικτική υλοποίηση με τη χρήση **Rabin-Karp Algorithm** παρουσιάζεται παρακάτω:
```c++
//https://pdp-archive.github.io/24-PDP/c-minpali-statement
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <map>
#include <cmath>
#include <cstring>

#ifndef CONTEST
	#define dprintf	printf	//allow debug printf
#else
	#define dprintf (void)//don't prode code for dprintf
	#define NDEBUG	//remove assert()
#endif
#include <cassert>

using namespace std;

const long 	MAXN = long(1e7);
long 		N;
char 		S[MAXN+1];
long 		C;	//factor for rabin karp poly. Has to be > number of chars

typedef unsigned long long hasht;
const hasht	MOD = hasht(1e9)+7;	//It is imperative that MOD*MOD fit hasht typedef
hasht right[MAXN/2+2];//right[i] = hash of substr that ends at [N-i] with length i	
	//typical memory usage for sizeof(hasht)==8 is less than 40Mbytes
	//so we are withing allowed limit provided that the only other array
	//is of 10Mbytes the S[] array

hasht powC(long n){	
	//O(log2N) calc power of C (not enough mem to store all values in array)
	//binary lifting to calc value of pow(C,n) in log2(n)
	static hasht _pow[32];
	static long sz = 0;
	if(sz == 0){//precompute powers of C array
		sz = ceil(log2(N/2));
		_pow[0] = C;
		for(long i=1; i<=sz; ++i)
			_pow[i] = (_pow[i-1] * _pow[i-1]) % MOD;
	}
	hasht z = 1;
	for(long i = sz; i>=0; --i)
		if(n & (1l<<i))
			z = (z * _pow[i]) % MOD;
	return z;
}

bool doublecheck(long leftend,long length){
	//check if collition in hashing occured. We have to check up to length chars.
	long left = leftend - length + 1;//where lest string starts(forward parsing)
	long right= N-1;//where right string starts (backward parsing)
	dprintf("dc: %ld[%d] with %ld[%d]\n",left,S[left],right,S[right]);
	while(left<right)
		if(S[left++]!=S[right--])
			return false;
	return true;
}

void readS(){//read and compress S[]
	scanf("%ld %s",&N,S);
	//compress input chars
	C = 1;
	int V[256];
	memset(V,0,sizeof(V));
	for(long i=0;i<N;++i){//compress values
		int& cv = V[S[i]];
		if(cv == 0)
			cv = C++;
		S[i] = cv;
	}
}

void calc_reverse_hashes(){
	//calc reverse hashes for every i in [1,N/2] for
	//substr starting from N-i and length i
	//This is the rightmost substr of palindrome.
	//The max powered element is the rightmost (Rabin Karp polynomial expr)
	//The min powered element is the leftmost (Rabin Karp polynomial expr)
	hasht val = 0;
	for(long i=1;i<=N/2;++i){
		val = (val * C) % MOD;//shift prev substr (create space)
		val = (val + S[N-i]) % MOD;//add newbie to space created
		right[i] = val;
	}
}
	
int main(){
#ifdef CONTEST
	freopen("minpali.in", "r",stdin);
	freopen("minpali.out","w",stdout);
#endif
	readS();
	
	//worst case: no part of string can be reused to build palindrome.
	//	We will need N-1 more chars.
	//best  case: entire string is a palindrome
	//	so no more chars are required
	//note:	if the ans is odd, then we have a central pivot char
	//	if the ans is even, we have two exact halfs without a pivot.
	//worstcase is 2*(N-1)+1 (with last char being pivot)
	
	long 	worstcase 	= (N-1)*2+1,
		bestcase 	= N,
		ans 		= worstcase;

	calc_reverse_hashes();

	long 	leftend  = N/2-1, length = N/2;
	hasht 	left 	 = 0, expC = powC(length-1);
	bool 	haspivot = (N&1);

	//calc the first subst of palindrome
	for(long i = 0; i<=leftend; ++i)
		left = ((left * C) % MOD + S[i]) % MOD;

	for(ans=bestcase; ans<=worstcase; ++ans){
		dprintf("ans=%ld, left=%lld, right[%ld]=%lld, length=%ld leftend=%ld haspivot=%d\n",
			ans,left,length,right[length],length,leftend,haspivot);
		
		if(left == right[length] /*&& doublecheck(leftend,length)*/)
			break;
			
		//left substr in [leftend - length + 1, leftend]
		//right substr starts in [leftend + 1 + haspivot] and has length chars
		
		if(haspivot){
			//roll left substr 1 to the right. length not changed
			//first step: remove maximum powered character
			left = (left - (expC * S[leftend-length+1])%MOD + MOD) % MOD;
			//shift remaining value and add newbie character
			left = ((left * C) % MOD + S[++leftend]) % MOD;
		} else {
			//shrink left edge of left substr by one
			left = (left - (expC * S[leftend-length+1])%MOD + MOD) % MOD;
			--length;
			expC = powC(length - 1);//length changed, recalc exponent of max element
		}
		haspivot = !haspivot;
	}
	
	printf("%ld\n",ans);
	return 0;
}

```

Αντί για υπόλοιπα διαιρέσεων που υπολογιστικά έχουν κάποιο βάρος, μπορούμε να χρησιμοποιήσουμε δυαδική λογική και να χρησιμοποιήσουμε για τα υπόλοιπα των πράξεων μας μια δύναμη του δύο που ας της δώσουμε το όνομα $$\mathit{MOD\_VAL}$$ οπότε δεν θα χρειαστούμε να χρησιμοποιήσουμε τον τελεστή **%**. Το υπόλοιπο με τη $$\mathit{MOD\_VAL}$$ βρίσκεται αν κάνουμε δυαδικό $$AND$$ με τα bits των $$\mathit{MOD\_VAL}-1$$ και του $$\mathit{hash}$$ value που θέλουμε να βρούμε το υπόλοιπό του. Στο παρακάτω πρόγραμμα εμφανίζεται η λύση με $$\mathit{MOD} = \mathit{MOD\_VAL}-1$$ όπου $$\mathit{MOD\_VAL}$$ είναι το $$2^{32}$$. Προσοχή ο $$C$$ και ο $$\mathit{MOD\_VAL}$$ πρέπει να είναι πρώτοι μεταξύ τους άρα ο $$C$$ δεν μπορεί να είναι άρτιος. Αυτό το φροντίζουμε ανάβοντας (αν χρειάζεται) το **LSB** (least significant bit) που αντιπροσωπεύει τις μονάδες  
```c++
	C |= 1;
```

Συνολική πολυπλοκότητα $$\mathcal{O}N\cdot log_2N$$ λόγω της **powC**. Η λύση αυτή περνά όλα τα test cases.
Μία ενδεικτική υλοποίηση παρουσιάζεται παρακάτω. Τα περισσότερα σχόλια αφαιρέθηκαν καθώς ο κώδικας αυτός είναι όμοιος με τον παραπάνω:

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
long 		N;
char 		S[MAXN+1];
long 		C;

typedef unsigned long long hasht;
const hasht	MOD_VAL = hasht(1)<<32;
const hasht	MOD = hasht(0xffffffff);//equivalent to MOD_VAL-1
hasht right[MAXN/2+2];

hasht powC(long n){	
	static hasht _pow[32];
	static long sz = 0;
	if(sz == 0){
		sz = ceil(log2(N/2));
		_pow[0] = C;
		for(long i=1; i<=sz; ++i)
			_pow[i] = (_pow[i-1] * _pow[i-1]) & MOD;
	}
	hasht z = 1;
	for(long i = sz; i>=0; --i)
		if(n & (1l<<i))
			z = (z * _pow[i]) & MOD;
	return z;
}

bool doublecheck(long leftend,long length){
	long left = leftend - length + 1;
	long right= N-1;
	while(left<right)
		if(S[left++]!=S[right--])
			return false;
	return true;
}

void readS(){//read and compress S[]
	scanf("%ld %s",&N,S);
	C = 1;
	int V[256];
	memset(V,0,sizeof(V));
	for(long i=0;i<N;++i){//compress values
		int& cv = V[S[i]];
		if(cv == 0)
			cv = C++;
		S[i] = cv;
	}
	C |= 1; //the binary OR with 1 makes sure that C is odd
}

void calc_reverse_hashes(){
	hasht val = 0;
	for(long i=1;i<=N/2;++i){
		val = (val * C) & MOD;
		val = (val + S[N-i]) & MOD;
		right[i] = val;
	}
}
	
int main(){
#ifdef CONTEST
	freopen("minpali.in", "r",stdin);
	freopen("minpali.out","w",stdout);
#endif
	readS();
	
	long 	worstcase 	= (N-1)*2+1,
		bestcase 	= N,
		ans 		= worstcase;

	calc_reverse_hashes();

	long 	leftend  = N/2-1, length = N/2;
	hasht 	left 	 = 0, expC = powC(length-1);
	bool 	haspivot = (N&1);

	for(long i = 0; i<=leftend; ++i)
		left = (((left * C) & MOD) + S[i]) & MOD;

	for(ans=bestcase; ans<=worstcase; ++ans){
		if(left == right[length] /*&& doublecheck(leftend,length)*/)
			break;
		
		if(haspivot){
			left = (left - ((expC * S[leftend-length+1])&MOD) + MOD_VAL) & MOD;
			left = (((left * C) & MOD) + S[++leftend]) & MOD;
		} else {
			left = (left - ((expC * S[leftend-length+1])&MOD) + MOD_VAL) & MOD;
			--length;
			expC = powC(length-1);//length changed, recalc exponent of max element
		}
		haspivot = !haspivot;
	}
	
	printf("%ld\n",ans);
	return 0;
}

```

  
## Βέλτιστη λύση - $$\mathcal{O}(N)$$

Γνώσεις που θα χρειαστούμε: **Knuth–Morris–Pratt algorithm** ή **$$\mathcal{Z}$$ algorithm**   
([camp ΠΔΠ 2017 KMP code](http://git.softlab.ntua.gr/pub/pdp-camp/blob/master/2017/kmp.cpp))  
([camp ΠΔΠ 2017 KMP explained](http://git.softlab.ntua.gr/pub/pdp-camp/blob/master/2016/String%20matching.pdf))  
([wikipedia KMP](https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm))   

Ο αλγόριθμος $$\mathcal{Z}$$ έχοντας μια συμβολοσειρά σαν είσοδο, υπολογίζει έναν πίνακα ακεραίων $$Ζ$$ έτσι ώστε στη θέση
$$Z_i$$ περιέχει το μήκος του αλφαριθμητικού που ξεκινά από τη θέση $$i$$ και ταυτίζεται με τους $$Z_i$$ χαρακτήρες του προθέματος (αλφαριθμητικό που ξεκινά στη θέση $$0$$). Δηλαδή $$S_{i+j} == S_j, \forall j \in [0,Z_i]$$  
Θέλουμε να βρούμε ένα παλίνδρομο από μια θέση $$i$$ έως το τέλος της συμβολοσειράς εισόδου (όπως εξηγήσαμε στο αρχικό σχήμα). Φτιάχνουμε έναν πίνακα χαρακτήρων $$S$$ με μήκος $$2Ν$$. Αντιστρέφουμε τη συμβολοσειρά εισόδου στο πρώτο μισό του πίνακα χαρακτήρων $$S$$ και στο δεύτερο μισό του πίνακα έχουμε αυτούσια τη συμβολοσειρά εισόδου. Τρέχουμε τον αλγόριθμο $$\mathcal{Z}$$ και κατόπιν ξεκινάμε από τη θέση $$Ν$$ έως την τελική θέση $$2N-1$$ να ελέγχουμε αν το $$Z_i$$ ισούται με το υπολοιπόμενο μήκος της συμβολοσειράς. Όταν το τμήμα από τη θέση $$i$$ έως το τέλος του $$S$$ ταυτίζεται, τότε σημαίνει ότι βρήκαμε τμήμα που διαβάζεται ώς παλίνδρομο και απλά πρέπει να προσθέσουμε δυο φορές το πρόθεμα (από την θέση $$N$$ έως τη θέση $$i$$) το οποίο δεν έχει ταυτιστεί (μια φορά ως πρόθεμα και μια ώς κατάληξη).  
Μία ενδεικτική υλοποίηση με $$\mathcal{Z}$$ algorithm παρουσιάζεται παρακάτω:

```c++
//https://pdp-archive.github.io/24-PDP/c-minpali-statement
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


## Κώδικας διαγωνιζομένων   
Ο παρακάτω κώδικας ανήκει στον Κηπουρίδη Ευάγγελο του 11ου ΓΕΛ Θεσσαλονίκης και πέρασε όλα τα test case:

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
 
