---
layout: statement
codename: marbles
---

Θα παίξουμε το εξής παιχνίδι. Έχουμε $$N$$ χρωματιστούς βώλους,
αριθμημένους από $$1$$ έως $$N$$. Οι βώλοι είναι τοποθετημένοι ο ένας δίπλα
στον άλλον σε μια ξύλινη βάση με $$N$$ θέσεις, που είναι επίσης αριθμημένες
από $$1$$ έως $$N$$. Ο σκοπός του παιχνιδιού είναι να φέρουμε τους βώλους στη
σωστή σειρά: ο βώλος $$1$$ να είναι στη θέση $$1$$, ο βώλος $$2$$ στη θέση $$2$$, κ.ο.κ.

Για να το κάνουμε αυτό, μπορούμε να εφαρμόσουμε μία σειρά κινήσεων.
Υπάρχουν $$M$$ δυνατές κινήσεις και κάθε μία από αυτές περιγράφεται από
δύο αριθμούς $$(a_i, b_i)$$, όπου $$1 \leq i \leq M$$. Η κίνηση $$(a_i, b_i)$$ αντιμεταθέτει τους
βώλους που βρίσκονται στις θέσεις $$a_i$$ και $$b_i$$. Βρείτε την ακολουθία με τις
λιγότερες δυνατές κινήσεις για να κερδίσετε το παιχνίδι!

Για παράδειγμα, έστω ότι $$N=3$$ και ότι οι βώλοι βρίσκονται αρχικά με τη
σειρά $$2, 1, 3$$, όπως φαίνεται στο παρακάτω σχήμα. Έστω επίσης ότι
υπάρχουν $$M=2$$ δυνατές κινήσεις: $$(1, 3)$$ και $$(2, 3)$$.

<center>
<img alt="34pdp-c2-marbles-example" src="/assets/34-pdp-c2-ex1.svg" width="400px">
</center>

Μπορούμε να κερδίσουμε το παιχνίδι με την εξής ακολουθία $$3$$ κινήσεων:
 * αρχικά &ensp;&ensp;&emsp; $$2,1,3$$ 
 * κίνηση 1 &nbsp;&emsp;$$3,1,2$$&emsp;&nbsp;αντιμεταθέτουμε τις θέσεις $$(1,3)$$
 * κίνηση 2 &nbsp;&emsp;$$3,2,1$$&emsp;&nbsp;αντιμεταθέτουμε τις θέσεις $$(2,3)$$
 * κίνηση 1 &nbsp;&emsp;$$1,2,3$$&emsp;&nbsp;αντιμεταθέτουμε τις θέσεις $$(1,3)$$

Δεν υπάρχει τρόπος να κερδίσουμε το παιχνίδι με λιγότερες από $$3$$ κινήσεις.


## Πρόβλημα:

Να αναπτύξετε ένα πρόγραμμα σε μια από τις γλώσσες της IOI (Pascal, C,
C++, Java) το οποίο θα βρίσκει πώς θα κερδίσουμε $$T$$ τέτοια παιχνίδια. Για
κάθε παιχνίδι, θα διαβάζει την αρχική θέση των βώλων και τις επιτρεπτές
κινήσεις και θα εκτυπώνει το ελάχιστο πλήθος και την ακολουθία κινήσεων
που απαιτούνται για να κερδίσουμε.


## Αρχεία Εισόδου:

Το αρχείο εισόδου με όνομα **marbles.in** είναι αρχείο κειμένου με την εξής
δομή. Η πρώτη γραμμή περιέχει δύο ακέραιους αριθμούς, χωρισμένους
μεταξύ τους με ένα κενό διάστημα: το πλήθος των παιχνιδιών $$T$$ και το
πλήθος των βώλων $$N$$ σε κάθε παιχνίδι. Στη συνέχεια ακολουθούν οι
περιγραφές των $$T$$ παιχνιδιών, κάθε μία με την παρακάτω δομή.

Η πρώτη γραμμή περιέχει έναν ακέραιο αριθμό $$M$$: το πλήθος των
επιτρεπτών κινήσεων. Η δεύτερη γραμμή περιέχει $$N$$ ακέραιους αριθμούς,
χωρισμένους ανά δύο με ένα κενό διάστημα: την αρχική τοποθέτηση των
βώλων, κατά σειρά από τη θέση $$1$$ μέχρι τη θέση $$N$$. Κάθε μία από τις
επόμενες $$M$$ γραμμές περιέχει δύο ακέραιους αριθμούς, χωρισμένους
μεταξύ τους με ένα κενό διάστημα: τις θέσεις $$(a_i, b_i)$$ που αντιμεταθέτει
αυτή η κίνηση.

## Αρχεία Εξόδου:

Το αρχείο εξόδου με όνομα **marbles.out** είναι αρχείο κειμένου με την εξής
δομή. Θα πρέπει να περιέχει την απάντηση για καθένα από τα $$T$$ παιχνίδια,
κατά σειρά. Αν για κάποιο παιχνίδι υπάρχει λύση με ελάχιστο πλήθος
κινήσεων $$K \geq 0$$, η πρώτη γραμμή της απάντησης θα πρέπει να περιέχει τη
λέξη "MOVES" και το πλήθος των κινήσεων $$K$$, χωρισμένα μεταξύ τους με
ένα κενό διάστημα, και οι επόμενες $$K$$ γραμμές πρέπει να περιέχουν τους
αριθμούς των $$K$$ κινήσεων που πρέπει να γίνουν για να κερδίσουμε το
παιχνίδι. Αν υπάρχουν περισσότερες λύσεις με την ίδια ελάχιστη τιμή του
$$K$$, το πρόγραμμά σας μπορεί να εκτυπώνει οποιαδήποτε από αυτές. Αν για
κάποιο παιχνίδι δεν υπάρχει λύση, η απάντηση για αυτό το παιχνίδι πρέπει
να περιέχει μία γραμμή με τη λέξη "IMPOSSIBLE".


## Παράδειγμα Αρχείων εισόδου - εξόδου:

| **marbles.in**      | **marbles.out** |
| :--- | :--- |
| 4 3<br>2<br>2 1 3<br>1 3<br>2 3<br>1<br>1 3 2<br>2 3<br>1<br>1 2 3<br>1 2<br>1<br>1 3 2<br>1 3 | MOVES 3<br>1<br>2<br>1<br>MOVES 1<br>1<br>MOVES 0<br>IMPOSSIBLE |
{:.table_with_monospace_font}


**Εξήγηση**: Πρέπει να απαντήσουμε σε $$T=4$$ παιχνίδια, που σε καθένα υπάρχουν
$$N=3$$ βώλοι. Το πρώτο παιχνίδι είναι αυτό του σχήματος της προηγούμενης
σελίδας, με $$M=2$$. Στο δεύτερο παιχνίδι, με $$M=1$$, αρκεί να γίνει μία κίνηση ώστε
να βρεθούν οι δύο τελευταίοι βώλοι στη σωστή σειρά. Στο τρίτο παιχνίδι, επίσης
με $$M=1$$, οι βώλοι βρίσκονται εξ αρχής στη σωστή σειρά, επομένως δε χρειάζεται
καμία κίνηση. Τέλος, στο τέταρτο παιχνίδι, πάλι με $$M=1$$, η μοναδική επιτρεπτή
κίνηση αντιμεταθέτει τους βώλους που βρίσκονται στις θέσεις $$1$$ και $$3$$. Δεν
υπάρχει κανένας τρόπος να μετακινηθεί ο βώλος με αριθμό $$3$$ που βρίσκεται στη
θέση $$2$$, άρα το παιχνίδι αυτό δεν έχει λύση.


## Περιορισμοί:

 * $$1 \leq T \leq 5$$<br>
 * $$1\leq N\leq 12$$<br>
 * $$1 \leq M \leq N\cdot(N−1)/2$$<br>
 * Για κάθε επιτρεπτή κίνηση θα είναι $$1 \leq a_i < b_i \leq N$$.<br>
 * Η λίστα των επιτρεπτών κινήσεων κάθε παιχνιδιού θα περιέχει κάθε
κίνηση το πολύ μία φορά.<br>
 * Για περιπτώσεις ελέγχου συνολικής αξίας 40% θα είναι $$N\leq 5$$.
 * Για περιπτώσεις ελέγχου συνολικής αξίας 80% θα είναι $$N \leq 10$$.
 
## Προσοχή:

Φροντίστε να διαβάζετε την είσοδο και να εκτυπώνετε την έξοδο αποδοτικά, ειδικά αν προγραμματίζετε σε C++ ή Java.

**Μορφοποίηση**: Στην έξοδο, όλες οι γραμμές τερματίζουν με έναν χαρακτήρα newline.<br>
**Μέγιστος χρόνος εκτέλεσης**: $$1$$ sec.<br>
**Μέγιστη διαθέσιμη μνήμη**: $$256$$ MB.<br>
