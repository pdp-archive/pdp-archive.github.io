---
layout: solution
codename: loutraki
---

## Επεξήγηση εκφώνησης


Μας δίνεται ένας πίνακας με $$N$$ σημεία και μας ζητείται να υπολογίσουμε **πόσα από τα σημεία δεν κρύβονται ούτε από την αριστερή τους πλευρά αλλά ούτε και από την κάτω τους πλευρά**. Για την καλύτερη κατανόηση λόγο της ύπαρξης τόσο θετικών όσο και αρνητικών τιμών στις συντεταγμένες δείτε το παρακάτω σχεδιάγραμμα  

![Παράδειγμα](/assets/24-pdp-c-loutraki-example2.png){:width="640px"}

Στο παραπάνω παράδειγμα, μόνο τα πράσινα ξενοδοχεία θεωρούνται προνομιούχα. Πιο αναλυτικά:  
&nbsp;&nbsp;Το ξενοδοχείο 1 δεν κρύβεται από κανένα άλλο.  
&nbsp;&nbsp;Το ξενοδοχείο 2 κρύβεται από τα 3,6,8.  
&nbsp;&nbsp;Το ξενοδοχείο 3 κρύβεται από τα 1,6,8.  
&nbsp;&nbsp;Το ξενοδοχείο 4 κρύβεται από τα 3,1,7.  
&nbsp;&nbsp;Το ξενοδοχείο 5 δεν κρύβεται από κανένα άλλο.  
&nbsp;&nbsp;Το ξενοδοχείο 6 κρύβεται από τα 5 και 8.  
&nbsp;&nbsp;Το ξενοδοχείο 7 κρύβεται από τα 5 και 6.  
&nbsp;&nbsp;Το ξενοδοχείο 8 δεν κρύβεται από κανένα άλλο.  
  
  	
  	
## Αργή λύση $$O(N^2)$$

Γνώσεις που θα χρειαστούμε: Καμμία.

Δοκιμάζουμε για κάθε ένα από τα $$N$$ ξενοδοχεία όλους τους $$N-1$$ συνδυασμούς για να βρούμε αν κρύβεται από κάποιο άλλο. Συνολική πολυπλοκότητα $$O(N^2)$$ .

Παρακάτω δίνεται μία ενδεικτική υλοποίηση αυτής της λύσης.

```c++
#include <bits/stdc++.h>

using namespace std;

#define MAXN	int(1e6)

int N, ans;
pair<int,int> hotel[MAXN+1];
#define	xx	first
#define	yy	second

int main() {
#ifdef CONTEST
	freopen("loutraki.in","r",stdin);
	freopen("loutraki.out","w",stdout);
#endif
	scanf("%d", &N);
	for(int i=1; i<=N; ++i)
		scanf("%d%d",&hotel[i].xx,&hotel[i].yy);
	for(int i=1;i<=N;++i){
		bool hidden = false;
		for(int j=1;j<=N && !hidden;j++){
			if(i==j)continue;
			if(hotel[j].xx == hotel[i].xx && hotel[j].yy < hotel[i].yy)
				hidden = true;
			if(hotel[j].yy == hotel[i].yy && hotel[j].xx < hotel[i].xx)
				hidden = true;
		}
		if(!hidden)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}
```

## Mέτρια λύση - $$O(N \cdot log(N))$$ - line sweep

Γνώσεις που θα χρειαστούμε: lambda functions (c++11 και νεότερες)

Ταξινομούμε τα ξενοδοχεία πρώτα ως προς $$x$$ και μετά ως προς $$y$$ στον πίνακα $$C[]$$.
Σαρώνουμε από τις μικρότερες προς τις μεγαλύτερες ώστε να ενημερώσουμε τον πίνακα των ξενοδοχείων για το αν έχουν ορατότητα από αυτή την πλευρά.
Αξοποιούμε το πρώτο στοιχείο που συναντούμε και πετάμε τα υπόλοιπα με την ίδια τιμή στη συντεταγμένη.
Το ίδιο θα κάνουμε και για το $$y$$.  

Η ταξινόμιση γίνεται με χρήση δικών μας συναρτήσεων σύγκρισης. Προτιμήθηκε η λύση της lambda (inline σύντομες συναρτήσεις) για να δειχθεί αυτή η λειτουργία της c++
```c++
	sort(C+1,C+N+1,[](const auto& a,const auto& b){return (a.x==b.x)?(a.y<b.y):(a.x<b.x);});
```
Στην παραπάνω εντολή ταξινομούμε τον πίνακα $$C[]$$ πρώτα με το $$x$$ και σε περίπτωση ισότητας με το $$y$$.
Η συνάρτηση:
```c++
[](const auto& a,const auto& b){return (a.x==b.x)?(a.y<b.y):(a.x<b.x);}
```
λέγεται lambda συνάρτηση και είναι η συνάρτηση σύγκρισης που θα χρησιμοποιήσει η sort. Μέσα στα άγγιστρα αυτό που κάνει είναι απλά να συγκρίνει τις συντεταγμένες δυο αντικειμένων του πίνακα, των $$a$$ και $$b$$. Μέσα στις $$[]$$ πρέπει να δηλώσουμε αν και πως η lambda μας θα έχει πρόσβαση σε άλλες μεταβλητές του προγράμματος εκτός από αυτές που παίρνει ως παραμέτρους. Η συγκεκριμένη lambda δεν χρειάζεται τίποτα άλλο από τα δυο στοιχεία του πίνακα οπότε παραμένει κενό το τμήμα αυτό.  

Η λύση αυτή περνά τα 12 από τα 15 test cases.

```c++
#include <bits/stdc++.h>

using namespace std;

#define MAXN	int(1e6)
#define OFFSET	int(1e5)

struct hotel {
	int x,y,visibility;
	hotel(int x,int y): x(x), y(y) { visibility = 0; }
	hotel(){ x = y = visibility = 0; }
} hotel[MAXN+1];

struct coord {
	int x,y,hotel_id;
	coord(int x,int y,int hotel_id):x(x),y(y),hotel_id(hotel_id){}
	coord(){ x = y = hotel_id = 0; }
} C[2*OFFSET+1];

int N, ans;

int main() {
#ifdef CONTEST
	freopen("loutraki.in","r",stdin);
	freopen("loutraki.out","w",stdout);
#endif
	scanf("%d", &N);
	for(int i=1; i<=N; ++i){
		scanf("%d%d",&hotel[i].x,&hotel[i].y);
		hotel[i].x += OFFSET;
		hotel[i].y += OFFSET;
		C[i] = coord( hotel[i].x, hotel[i].y, i );
	}

	sort(C+1,C+N+1,[](const auto& a,const auto& b){return (a.x==b.x)?(a.y<b.y):(a.x<b.x);});
	for(int i=1;i<=N;){
		int co = C[i].x;
		hotel[C[i].hotel_id].visibility++;
		while(C[i].x == co)
			i++;
	}

	sort(C+1,C+N+1,[](const auto& a,const auto& b){return (a.y==b.y)?(a.x<b.x):(a.y<b.y);});
	for(int i=1;i<=N;){
		int co = C[i].y;
		hotel[C[i].hotel_id].visibility++;
		while(C[i].y == co)
			i++;
	}

	for(int i=1;i<=N;i++)
		if(hotel[i].visibility==2)
			ans++;
		
	printf("%d\n", ans);
	return 0;
}
```
  
  
## Μέτρια λύση - $$O(N \cdot log(N))$$

Γνώσεις που θα χρειαστούμε: std::vector, std::sort (C++ stl)

Η λύση που θα δούμε εισάγει ιδέες που θα χρειαστούν για την βέλτιστη λύση.

Αποθηκεύουμε για κάθε διακριτή συντεταγμένη όλες τις αντίστοιχες συντεταγμένες του άλλου άξονα. Θα ελέγξουμε το κάθε ένα από τα $$N$$ ξενοδοχεία, αν επικαλύπτεται από κάποιο άλλο σε πολυπλοκότητα $$O(logN)$$

Η λύση αυτή περνά τα 12 από τα 15 test cases.

Μία ενδεικτική υλοποίηση παρουσιάζεται παρακάτω:

```c++
#include <bits/stdc++.h>

using namespace std;

#define MAXN	int(1e6)
#define OFFSET	int(1e5)

vector<int> X[2*OFFSET+1],Y[2*OFFSET+1];

int N, ans;
pair<int,int> hotel[MAXN+1];
#define	xx	first
#define	yy	second

int main() {
#ifdef CONTEST
	freopen("loutraki.in","r",stdin);
	freopen("loutraki.out","w",stdout);
#endif
	scanf("%d", &N);
	for(int i=1; i<=N; ++i){
		scanf("%d%d",&hotel[i].xx,&hotel[i].yy);
		hotel[i].xx+=OFFSET;
		hotel[i].yy+=OFFSET;
		X[hotel[i].xx].push_back(hotel[i].yy);
		Y[hotel[i].yy].push_back(hotel[i].xx);
	}
	
	for(int x=0;x<2*OFFSET;x++)sort(X[x].begin(),X[x].end());
	for(int y=0;y<2*OFFSET;y++)sort(Y[y].begin(),Y[y].end());
	//μετά την ταξινόμιση το πρώτο στοιχείο κάθε vector έχει τον αριθμό 
	//του ξενοδοχείου που κρύβει τα υπόλοιπα στην ευθεία
	
	for(int i=1;i<=N;++i){
		if(X[hotel[i].xx][0] == hotel[i].yy && Y[hotel[i].yy][0] == hotel[i].xx)
			ans++;
		//αν η μικρότερη τιμή είναι η δικιά μας και στις δύο συντεταγμένες, 
		//τότε είμαστε προνομοιούχοι
	}
	printf("%d\n", ans);
	return 0;
}
```

## Παρατήρηση  
Σε κάθε διακριτή τιμή τετμημένης($$x$$) ή τεταγμένης($$y$$) μας ενδιαφέρει μόνο **το ξενοδοχείο με την μικρότερη τεταγμένη ή τετμημένη** αντίστοιχα γι' αυτό και στην προηγούμενη λύση χρησιμοποιούσαμε μόνο το πρώτο στοιχείο του __vector__. Δηλαδή από όλα τα ξενοδοχεία με ίδιο $$x$$ μας ενδιαφέρει μόνο το ξενοδοχείο με το μικρότερο $$y$$.
Οπότε είμαστε έτοιμοι για την λύση με γραμμική πολυπλοκότητα που ακολουθεί.



## Βέλτιστη λύση - $$O(N)$$

Γνώσεις που θα χρειαστούμε: καμμία. 

Επεξεργαζόμαστε κάθε ξενοδοχείό με τη σειρά που το διαβάζουμε από το αρχείο. Το υπο εξέταση ξενοδοχείο θα το ελέγξουμε ξεχωριστά για την κάθε συντεταγμένη. 

Κρατάμε στη θέση $$X[x]$$ του πίνακα $$X[]$$ τον αριθμό του ξενοδοχείου $$(x,y)$$ με τη μικρότερη τεταγμένη $$y$$.
Αντίστοιχα κρατάμε και στη θέση $$Y[y]$$ του πίνακα $$Y[]$$ τον αριθμό του ξενοδοχείου $$(x,y)$$ με τη μικρότερη τετμημένη $$x$$.

Αν δεν υπάρχει κανένα ξενοδοχείο με το ίδιο $$x$$ τότε δεν το κρύβει κανένα άλλο από το να "βλέπει" προς τα κάτω οπότε αυτό αποκτά ορατότητα από την πλευρά αυτή.
Αν υπάρχει ξενοδοχείο με το ίδιο $$x$$ τότε υπάρχουν δυο περιπτώσεις, ή το υπο εξέταση ξενοδοχείο κρύβεται από το ξενοδοχείο $$X[x]$$ ή θα κρύψει το παλιότερο ξενοδοχείο $$X[x]$$. 

Στην περίπτωση που κρυφτεί το παλιό ξενοδοχείο πρέπει να δώσουμε προσοχή στο αν πρέπει να διορθώσουμε την μεταβλητή $$\mathit{ans}$$. Αν το παλιό ξενοδοχείο είχε επηρεάσει την μεταβλητή $$\mathit{ans}$$ τότε πρέπει να την μειώσουμε, πράγμα που κάνει το παρακάτω απόσπασμα κώδικα:  

```c++
void hide_hotel(int i){//κρύψε το προηγούμενο ξενοδοχείο.
	if(!hidden[i]){	
		//το προηγούμενο ξενοδοχείο ΔΕΝ ήταν κρυμένο μέχρι τώρα, 
		//άρα είχε υπολογιστεί στη μεταβλητή ans
		ans--;//διόρθωσε την ans
		hidden[i] = true;
	}
}
```

**Μια σημείωση**: θα μπορούσαμε να μην κάνουμε διορθώσεις στη μεταβλητή $$\mathit{ans}$$ καθώς επεξεργαζόμαστε τα ξενοδοχεία και απλά στο τέλος του προγράμματος να κάνουμε ένα βρόγχο επανάλληψης και να καταμετρήσουμε πόσα flags είναι σβηστά στον πίνακα $$\mathit{hidden[]}$$ και να τυπώσουμε αυτόν τον αριθμό.

Αφού κάνουμε τον ίδιο έλεγχο και για την τεταγμένη $$y$$ έχουμε μετρήσει από πόσες πλευρές έχει ορατότητα το ξενοδοχείο μας. Αν είναι $$visibility == 2$$ τότε το ξενοδοχείο μας είναι προνομιούχο τουλάχιστο μέχρι αυτή τη στιγμή.

**Πολυπλοκότητα:**  Η εξέταση κάθε ξενοδοχείου γίνεται μόνο μια φορά και ο υπολογισμός αν κρύβεται ή κρύβει γίνεται σε $$O(1)$$ άρα η συνολική μας πολυπλοκότητα είναι $$O(N)$$.

Μία ενδεικτική υλοποίηση παρουσιάζεται παρακάτω:


```c++
#include <bits/stdc++.h>

using namespace std;

#define MAXN	int(1e6)
#define OFFSET	int(1e5)

int N, ans;
bool hidden[MAXN+1];		//αληθές αν το ξενοδοχείο κρύβεται
int X[2*OFFSET+1],Y[2*OFFSET+1];//αριθμός του πρώτου ξενοδοχείου στην x ή y συντεταγμένη
pair<int,int> hotel[MAXN+1];
#define	xx	first
#define	yy	second

void hide_hotel(int i){//κρύψε ένα ξενοδοχείο που έχει υπολογιστεί παλιότερα.
	if(!hidden[i]){
		ans--;//δεν είναι πιά μέρος της απάντησης εφόσον κρύφτηκε από άλλο
		hidden[i] = true;
	}
}

int main() {
#ifdef CONTEST
	freopen("loutraki.in","r",stdin);
	freopen("loutraki.out","w",stdout);
#endif
	scanf("%d", &N);
	for(int x,y,i=1; i<=N; ++i){
		scanf("%d%d",&x,&y);
		x+=OFFSET; y+=OFFSET; //μετέτρεψε σε θετικούς
		hotel[i] = {x,y};
		int visibility = 0;
		
		//θα κρύψουμε κάποιο προηγούμενο ξενοδοχείο με το ίδιο x?
		if(X[x]){//υπάρχει ξενοδοχείο με το ίδιο x
			if(y < hotel[X[x]].yy){	//ναι, θα κρύψουμε το X[x]
				hide_hotel(X[x]);
				X[x] = i;
				visibility++;
			}
		} else {//είμαστε το πρώτο ξενοδοχείο με αυτό το x
			X[x] = i;
			visibility++;
		}
		
		if(Y[y]){
			if(x < hotel[Y[y]].xx){
				hide_hotel(Y[y]);
				Y[y] = i;
				visibility++;
			}
		} else {
			Y[y] = i;
			visibility++;
		}
		
		if(visibility<2)//δεν έχουμε ορατότητα και από τις δύο πλευρές
			hidden[i] = true;
		else		//ναι έχουμε ορατότητα. Αύξησε την απάντηση μας
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}
```
  
  
## Γενική Παρατήρηση στις διαστάσεις των πινάκων

Στον πίνακα $$\mathit{hotel[ ]}$$ χρησιμοποιούμε τα στοιχεία $$1$$ έως και $$N$$ άρα πρέπει να έχει μέγεθος $$10^6+1$$  
Στους πίνακες $$X[ ]$$ και $$Y[ ]$$ θέλουμε να αποθηκεύουμε τιμές από $$-10^5$$ έως και $$+10^5$$ οι οποίες είναι $$10^5$$ από κάθε κατεύθυνση του άξονα συντεταγμένων και μια ακόμα τιμή που είναι το $$0$$ οπότε $$2\cdot 10^5 + 1$$ τιμές συνολικά.  
Λόγω του ότι είναι εύκολο να γίνει λάθος που θα παράγει σφάλμα κατάτμησης (segmentation fault) είναι προτιμότερο στους διαγωνισμούς να δεσμεύονται μερικά στοιχεία περισσότερο στους πίνακες (π.χ. 5 στοιχεία παραπάνω από ότι υπολογίζουμε ότι χρειάζεται) και ας μην χρησιμοποιηθούν παρά να χαθούν test cases από τέτοιες λεπτομέρειες.   


```c++
#define MAXN	int(1e6)
#define OFFSET	int(1e5)

bool hidden[MAXN+5];
int X[2*OFFSET+5],Y[2*OFFSET+5];
pair<int,int> hotel[MAXN+5];
```


## Κώδικας διαγωνιζομένων   
Ο παρακάτω κώδικας ανοίκει στον Παναγιώτου Σωτήριο του 59ο ΓΕΛ Αθηνών και πέρασε όλα τα test case  

```c++
/*
USER:pdp24u226
TASK:loutraki
LANG:C++
*/
#include<bitset>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<algorithm>
#include<stack>
using namespace std;
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"assert.h"
FILE *fin,*fout;
int minx[200001],miny[200001];
int minx_bel[200001],miny_bel[200001];
bool bouno[1000001],paralia[1000001];
int N;
int main(){
	int i,j,k;
	fin=fopen("loutraki.in","r");
	assert(fin);
	fscanf(fin,"%d",&N);
	for(i=1;i<=N;i++){
		fscanf(fin,"%d %d",&j,&k);
		//printf("check (%d,%d)->(%d,	%d)\n",j,k,j+100000,k+100000);

		j+=100000;
		k+=100000;
		//min x for row
		if(minx_bel[k]==0||minx[k]>j){
			minx_bel[k]=i;
			minx[k]=j;
		}
		//min y for row
		if(miny_bel[j]==0||miny[j]>k){
			miny_bel[j]=i;
			miny[j]=k;
		}
	}
	fclose(fin);
	for(i=0;i<=200000;i++){
		if(minx_bel[i]!=0){
			//printf("minx for row %d is %d, belongs to %d\n",i-100000,minx[i]-100000,minx_bel[i]);
			bouno[minx_bel[i]]=true;
		}
	}
	for(i=0;i<=200000;i++){
		if(miny_bel[i]!=0){
			//printf("miny for col %d is %d, belongs to %d\n",i-100000,miny[i]-100000,miny_bel[i]);
			paralia[miny_bel[i]]=true;
		}
	}

	j=0;
	for(i=1;i<=N;i++){
		if(bouno[i]&&paralia[i]){
			//printf("%d wins\n",i);
			j++;
		}
	}
	fout=fopen("loutraki.out","w");
	fprintf(fout,"%d\n",j);
	fclose(fout);
	return 0;
}
```
