---
layout: statement
codename: sumx
---

Δίνεται μια ακολουθία $$N$$ θετικών ακεραίων $$A_1, A_2, \ldots , A_N$$. Δίνεται επίσης ένας ακέραιος $$X$$. Γράψτε ένα πρόγραμμα που να βρίσκει το πλήθος των ζευγών $$(A_i, A_j)$$, όπου $$1 \leq i < j \leq N$$ και $$A_i + A_j = X$$.

## Αρχεία Εισόδου (sumx.in):

Η πρώτη γραμμή της εισόδου θα περιέχει τους αριθμούς $$N$$ και $$X$$, χωρισμένους μεταξύ τους με ένα κενό διάστημα. Η δεύτερη γραμμή της εισόδου θα περιέχει τους $$N$$ ακέραιους αριθμούς $$A_i$$ της ακολουθίας, χωρισμένους μεταξύ τους με ένα κενό διάστημα.

## Αρχεία Εξόδου (sumx.out):

Η έξοδος πρέπει να αποτελείται από μία γραμμή που να περιέχει ακριβώς ένα φυσικό αριθμό: το ζητούμενο πλήθος των ζευγών.

## Παραδείγματα Αρχείων Εισόδου - Εξόδου:

**1<sup>o</sup>**

| **sumx.in**      | **sumx.out** |
| :--- | :--- |
| 9 13<br>5 12 7 10 9 1 2 3 11 | 3 |


**Εξήγηση 1<sup>ου</sup> παραδείγματος**: Στο πρώτο παράδειγμα τα δυνατά ζεύγη είναι τρία:

$$
A_2 + A_6 = 12 + 1 = 13 \\
A_4 + A_8 = 10 + 3 = 13 \\
A_7 + A_9 = 2 + 11 = 13
$$

**2<sup>o</sup>**

| **sumx.in**      | **sumx.out** |
| :--- | :--- |
| 5 12<br>1 2 3 4 6 | 0 |

**Εξήγηση 2<sup>ου</sup> παραδείγματος**: Στο δεύτερο παράδειγμα δεν υπάρχει ζεύγος που να δίνει άθροισμα $$12$$.

**3<sup>o</sup>**

| **sumx.in**      | **sumx.out** |
| :--- | :--- |
| 6 10<br>2 4 6 8 4 6 | 5 |

**Εξήγηση 3<sup>ου</sup> παραδείγματος**: Τέλος, στο τρίτο παράδειγμα τα δυνατά ζεύγη είναι πέντε (προσοχή στους όρους που επαναλαμβάνονται):

$$
A_1 + A_4 = 2 + 8 = 10 \\
A_2 + A_3 = 4 + 6 = 10 \\
A_2 + A_6 = 4 + 6 = 10 \\
A_3 + A_5 = 6 + 4 = 10 \\
A_5 + A_6 = 4 + 6 = 10
$$

## Περιορισμοί

 - $$1 \leq N \leq 1.000.000$$.
 - $$1 \leq X \leq 2.000.000$$.
 - $$1 \leq A_i \leq 1.000.000$$.
 - Όριο χρόνου εκτέλεσης: $$1$$ sec.
 - Όριο μνήμης: $$64$$ MB.