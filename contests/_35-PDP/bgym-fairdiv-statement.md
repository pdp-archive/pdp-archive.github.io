---
layout: statement
codename: fairdiv
---

Τρεις φίλοι, ο Ανδρέας, ο Βασίλης και ο Γιώργος, πρόκειται να τρέξουν σε έναν αγώνα σκυταλοδρομίας μεγάλης απόστασης. Ο αγώνας γίνεται κατά μήκος ενός δρόμου που περνάει από πολλά χωριά και οι τρεις φίλοι γνωρίζουν ότι η διαδρομή αποτελείται από $$N$$ τμήματα (από την αφετηρία μέχρι το πρώτο χωριό, από το πρώτο μέχρι το δεύτερο, κ.ο.κ., μέχρι τον τερματισμό που βρίσκεται στο $$N$$-οστό χωριό). Επίσης γνωρίζουν το μήκος κάθε τμήματος σε μέτρα. Σύμφωνα με τους κανόνες του αγώνα, οι αλλαγές σκυτάλης πρέπει να γίνονται σε κάποιο χωριό της διαδρομής και οι τρεις φίλοι πρέπει εκ των προτέρων να αποφασίσουν πού ακριβώς θα τις κάνουν.

Οι φίλοι έχουν συμφωνήσει στα ακόλουθα:
 1. Η σειρά που θα τρέξουν είναι: Ανδρέας, Βασίλης, Γιώργος.
 2. Η συνολική απόσταση που θα τρέξει ο Ανδρέας (που έχει την μεγαλύτερη αντοχή στην παρέα) πρέπει να είναι μεγαλύτερη ή ίση της συνολικής απόσταση που θα τρέξει ο Βασίλης. Αντίστοιχα, ο Βασίλης (που έχει τη δεύτερη μεγαλύτερη αντοχή στην παρέα) πρέπει να τρέξει συνολική απόσταση μεγαλύτερη ή ίση αυτής που θα τρέξει ο Γιώργος.
 3. Οι τρεις φίλοι θέλουν να μοιράσουν τη συνολική διαδρομή **δίκαια**, τηρουμένων των παραπάνω. Δηλαδή, ο Γιώργος (που θα τρέξει τελευταίος και λιγότερο) πρέπει να διανύσει όσο μεγαλύτερη απόσταση είναι δυνατόν. Αφού εξασφαλιστεί αυτό, ο Βασίλης πρέπει επίσης να διανύσει όσο μεγαλύτερη απόσταση είναι δυνατόν.
 4. Αν τα παραπάνω δεν μπορούν να τηρηθούν, ο Γιώργος ή και ο Βασίλης ενδέχεται να μην τρέξουν καθόλου. Με αυτούς τους περιορισμούς, βοηθήστε τους τρεις φίλους να βρουν την απόσταση που θα διανύσει καθένας.

Με αυτούς τους περιορισμούς, βοηθήστε τους τρεις φίλους να βρουν την απόσταση που θα διανύσει καθένας.

## Πρόβλημα

Να αναπτύξετε ένα πρόγραμμα σε μια από τις γλώσσες του IOI (PASCAL, C, C++, Java) το οποίο θα διαβάζει το πλήθος των τμημάτων της διαδρομής και το μήκος καθενός, και θα εκτυπώνει την απόσταση που θα διανύσει καθένας από τους τρεις φίλους.

## Αρχεία Εισόδου:

Τα αρχεία εισόδου με όνομα **fairdiv.in** είναι αρχεία κειμένου με την εξής δομή: Στην πρώτη γραμμή υπάρχει ένας ακέραιος αριθμός: το πλήθος $$N$$ των τμημάτων της διαδρομής. Στη δεύτερη γραμμή υπάρχουν $$N$$ ακέραιοι αριθμοί, χωρισμένοι ανά δύο με ένα κενό διάστημα: τα μήκη $$A_1, A_2, \ldots, A_N$$ των τμημάτων της διαδρομής.

## Αρχεία Εξόδου:

Τα αρχεία εξόδου με όνομα **fairdiv.out** είναι αρχεία κειμένου με την εξής δομή. Περιέχουν ακριβώς μία γραμμή η οποία περιέχει τρεις ακέραιους αριθμούς χωρισμένους ανά δύο με ένα κενό διάστημα. Ο πρώτος αριθμός είναι η συνολική απόσταση που θα διανύσει ο Ανδρέας, ο δεύτερος είναι η συνολική απόσταση που θα διανύσει ο Βασίλης και ο τρίτος είναι η συνολική απόσταση που θα διανύσει ο Γιώργος.

## Περιορισμοί:

 - $$1 \leq N \leq 1.000.000$$,
 - $$0 \leq A_i \leq 1.000$$.

## Παραδείγματα αρχείων εισόδου-εξόδου:

**1<sup>o</sup>**

| **fairdiv.in**      | **fairdiv.out** |
| :--- | :--- |
| 10<br>78 43 72 17 66 63 20 58 1 56 | 193 146 135 |

**Εξήγηση:** 
Οι φίλοι θα τρέξουν ως εξής:

![Παράδειγμα](/assets/35-pdp-bgym.PNG){:width="650px"}

 - Ανδρέας: $$78 + 43 + 72 = 193$$
 - Βασίλης: $$17 + 66 + 63 = 146$$
 - Γιώργος: $$20 + 58 + 1 + 56 = 135$$

Προσέξτε ότι η συνολική απόσταση που θα διανύσει ο Γιώργος δεν υπερβαίνει αυτήν που θα διανύσει ο Βασίλης, η οποία δεν υπερβαίνει αυτήν
που θα διανύσει ο Ανδρέας. Δηλαδή $$193 \geq 146 \geq 135$$. Προσέξτε επίσης ότι ο Γιώργος δεν μπορεί να διανύσει μεγαλύτερη απόσταση: αν τρέξει επιπλέον το τμήμα με μήκος $$63$$, δηλαδή συνολική απόσταση $$63 + 20 + 58 + 1 + 56 = 198$$, τότε δεν υπάρχει τρόπος οι άλλοι δύο φίλοι να μοιραστούν την υπόλοιπη διαδρομή έτσι ώστε να τηρούνται τα συμφωνημένα μεταξύ τους.

**2<sup>o</sup>**

| **fairdiv.in**      | **fairdiv.out** |
| :--- | :--- |
| 5<br>17 42 3 42 17 | 59 45 17 |

**Εξήγηση:** Οι φίλοι μοιράζονται τη συνολική απόσταση ως εξής: $$17 + 42 \geq 3 + 42 \geq 17$$. Προσέξτε ότι το τμήμα μήκους $$3$$ θα το τρέξει ο Βασίλης, εφόσον αυτό είναι δυνατόν.

**3<sup>o</sup>**

| **fairdiv.in**      | **fairdiv.out** |
| :--- | :--- |
| 5<br>10 20 30 40 100 | 100 100 0 |

**Εξήγηση:** Το τελευταίο τμήμα της διαδρομής είναι πολύ μεγάλο. Αν το τρέξει ο Γιώργος, τότε δεν υπάρχει τρόπος οι άλλοι δύο φίλοι να μοιραστούν σωστά την υπόλοιπη διαδρομή. Η μόνη λύση λοιπόν είναι ο Γιώργος να μην τρέξει καθόλου.

**4<sup>o</sup>**

| **fairdiv.in**      | **fairdiv.out** |
| :--- | :--- |
| 4<br>10 10 10 40 | 70 0 0 |

**Εξήγηση:** Τα μήκη των τμημάτων είναι τέτοια ώστε ο Ανδρέας θα πρέπει να τρέξει μόνος του όλη τη διαδρομή.

## Παρατηρήσεις:

**Μορφοποίηση**: Στην είσοδο αλλά και στην έξοδο, κάθε γραμμή τερματίζει με έναν χαρακτήρα newline.

**Μέγιστος χρόνος εκτέλεσης**: $$1$$ sec.

**Μέγιστη διαθέσιμη μνήμη**: $$64$$ MB.