---
layout: statement
codename: incint
---

Δίνεται μια ακολουθία αποτελούμενη από $$N$$ φυσικούς αριθμούς: $$A_1, A_2, \ldots, A_N$$. Ζητείται το πλήθος των
διαστημάτων διαδοχικών όρων της ακολουθίας που είναι σε (όχι απαραίτητα γνησίως) αύξουσα σειρά.
Με άλλα λόγια, με πόσους διαφορετικούς τρόπους μπορούμε να επιλέξουμε δύο θέσεις $$i$$ και $$j$$ στον πίνακα,
όπου $$1 \leq i < j \leq N$$, τέτοιες ώστε $$A_i \leq A_{i+1} \leq \ldots \leq A_{j−1} \leq A_j$$.

## Δεδομένα εισόδου (incint.in)

Η πρώτη γραμμή της εισόδου θα περιέχει έναν ακέραιο αριθμό $$N$$, το πλήθος των όρων της ακολουθίας. Η
δεύτερη γραμμή της εισόδου θα περιέχει τους $$N$$ όρους της ακολουθίας, χωρισμένους ανά δύο με ένα κενό
διάστημα.

## Δεδομένα εξόδου (incint.out)

Η έξοδος πρέπει να αποτελείται από ακριβώς μία γραμμή που θα περιέχει ακριβώς έναν ακέραιο αριθμό: το
ζητούμενο πλήθος των διαστημάτων διαδοχικών όρων της ακολουθίας που είναι σε αύξουσα σειρά.

## Παραδείγματα αρχείων εισόδου-εξόδου:

**1<sup>o</sup>**

| **incint.in**      | **incint.out** |
| :--- | :--- |
| 7<br>10 13 15 12 19 17 17 | 12 |

*Εξήγηση:* Τα $$12$$ διαστήματα που μπορούμε να επιλέξουμε είναι:
 - $$7$$ διαστήματα με ένα μόνο όρο (δηλαδή με $$i = j$$): $$10, 13, 15, 12, 19, 17, 17$$.
 - $$4$$ διαστήματα με δύο όρους: $$10 \leq 13$$, $$13 \leq 15$$, $$12 \leq 19$$ και $$17 \leq 17$$.
 - $$1$$ διάστημα με τρεις όρους: $$10 \leq 13 \leq 15$$.

**2<sup>o</sup>**

| **incint.in**      | **incint.out** |
| :--- | :--- |
| 5<br>5 4 3 2 1 | 5 |

*Εξήγηση:* Οι όροι της ακολουθίας είναι σε γνησίως φθίνουσα σειρά, επομένως δεν υπάρχει άλλο διάστημα
που να μπορούμε να επιλέξουμε, εκτός από τα $$5$$ διαστήματα με ένα μόνο όρο (δηλαδή με $$i = j$$): $$5, 4, 3, 2, 1$$.

## Περιορισμοί:
- $$1 \leq N \leq 1.000.000$$,
- $$0 \leq A_i \leq 1.000.000.000$$ για κάθε $$1 \leq i \leq N$$.

Προσέξτε ότι για μεγάλες τιμές του $$N$$ μπορεί να υπάρχουν περισσότερα από $$2^{32}$$ τέτοια διαστήματα.

## Subtasks
- Για περιπτώσεις ελέγχου συνολικής αξίας 30%, θα είναι $$N \leq 1.000$$.
- Για περιπτώσεις ελέγχου συνολικής αξίας 50%, θα είναι $$N \leq 20.000$$.


**Μέγιστος χρόνος εκτέλεσης**: $$1$$ sec.<br>
**Μέγιστη διαθέσιμη μνήμη**: $$64$$ MB.
