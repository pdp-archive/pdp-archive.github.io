---
layout: statement
codename: smalltank
---

Μας δίνεται το οδικό δίκτυο της χώρας. Υπάρχουν $$N$$ πόλεις
(αριθμημένες από $$1$$ μέχρι $$N$$) και $$M$$ δρόμοι διπλής κατεύθυνσης που
συνδέουν ζεύγη διαφορετικών πόλεων. Για κάθε δρόμο γνωρίζουμε
την ποσότητα βενζίνης (σε λίτρα) που χρειάζεται ένα αυτοκίνητο για
να ταξιδέψει από το ένα άκρο του στο άλλο. Θεωρήστε δεδομένο ότι
υπάρχει τουλάχιστον μία διαδρομή, αποτελούμενη πιθανώς από
περισσότερους του ενός δρόμους, που συνδέει οποιαδήποτε πόλη με
οποιαδήποτε άλλη.
Έστω ότι το ντεπόζιτο βενζίνης του αυτοκινήτου μας χωράει $$L$$ λίτρα.
Μπορούμε να το γεμίσουμε σε οποιοδήποτε βενζινάδικο, δυστυχώς
όμως όλα τα βενζινάδικα βρίσκονται στις πόλεις — δεν υπάρχουν
βενζινάδικα κατά μήκος των δρόμων! Επομένως, για να κινηθούμε
κατά μήκος ενός δρόμου, πρέπει η ποσότητα βενζίνης που απαιτείται
για το ταξίδι να είναι μικρότερη ή ίση του $$L$$.
Βρείτε την ελάχιστη δυνατή τιμή του $$L$$ που μας επιτρέπει να
κινηθούμε με το αυτοκίνητό μας από οποιαδήποτε πόλη της χώρας σε
οποιαδήποτε άλλη.


## Πρόβλημα

Να αναπτύξετε ένα πρόγραμμα σε μια από τις γλώσσες του IOI
(PASCAL, C, C++, Java) το οποίο θα διαβάζει τα δεδομένα του οδικού
δικτύου θα εκτυπώνει την ελάχιστη δυνατή τιμή του $$L$$ που μας
επιτρέπει να κινηθούμε από οποιαδήποτε πόλη σε οποιαδήποτε άλλη.


## Αρχεία εισόδου:

Τα αρχεία εισόδου με όνομα **smalltank.in** είναι αρχεία κειμένου με
την εξής δομή: Η πρώτη γραμμή της εισόδου θα περιέχει δύο
φυσικούς αριθμούς $$N$$, $$M$$, χωρισμένους με ένα κενό διάστημα: το
πλήθος των πόλεων και το πλήθος των δρόμων.

Κάθε μία από τις επόμενες $$M$$ γραμμές περιγράφει έναν δρόμο διπλής
κατεύθυνσης. Περιέχει τρεις ακέραιους αριθμούς $$U_i$$, $$V_i$$ και $$W_i$$,
χωρισμένους ανά δύο με ένα κενό διάστημα. Μία τέτοια γραμμή
σημαίνει ότι μπορούμε να πάμε από την πόλη $$U_i$$ στην πόλη $$V_i$$ (ή και
αντίστροφα) και για το ταξίδι αυτό χρειαζόμαστε $$W_i$$ λίτρα βενζίνης.


## Αρχεία εξόδου:

Τα αρχεία εξόδου με όνομα **smalltank.out** είναι αρχεία κειμένου με
την εξής δομή. Περιέχουν ακριβώς μία γραμμή που περιέχει έναν
ακέραιο αριθμό: το ελάχιστο μέγεθος ντεπόζιτου που μας επιτρέπει να
κινηθούμε από οποιαδήποτε πόλη σε οποιαδήποτε άλλη.


## Περιορισμοί:


 - $$2 \leq N \leq 10.000$$,
 - $$1 \leq M \leq 100.000$$,
 - $$1 \leq U_i \leq N$$, $$1 \leq V_i \leq N$$,
 - $$1 \leq W_i \leq 100.000$$.
 
Θα υπάρχει το πολύ ένας δρόμος που συνδέει απευθείας δύο πόλεις

## Παράδειγμα αρχείων εισόδου - εξόδου:

| **smalltank.in**      | **smalltank.out** |
| :--- | :--- |
| 6 9<br>2 1 4<br>3 2 7<br>4 5 6<br>1 3 8<br>1 4 10<br>5 2 8<br>5 6 4<br>1 5 5<br>4 2 5 | 7 |

![Παράδειγμα](/assets/34-pdp-blyk1.svg){:width="280px"}

**Εξήγηση:**

To παράδειγμα είναι αυτό του παραπάνω σχήματος. Δεν υπάρχει
τρόπος να πάει κανείς από την πόλη 3 στην πόλη 4 χωρίς να περάσει
από δρόμο που να χρειάζεται τουλάχιστον 7 λίτρα βενζίνη, επομένως
το ελάχιστο $$L$$ δεν μπορεί να είναι μικρότερο από 7. Εξετάζοντας όλα
τα ζεύγη πόλεων αφετηρίας και προορισμού, διαπιστώνουμε ότι το 7
μας αρκεί για να μετακινηθούμε οπουδήποτε.


## Παρατηρήσεις:

**Μορφοποίηση**: Στην είσοδο αλλά και στην έξοδο, κάθε γραμμή τερματίζει με έναν χαρακτήρα newline.

**Μέγιστος χρόνος εκτέλεσης**: $$1$$ sec.

**Μέγιστη διαθέσιμη μνήμη**: $$64$$ MB.
