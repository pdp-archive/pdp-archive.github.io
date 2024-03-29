---
layout: statement
codename: books
---

Πριν την εφεύρεση της τυπογραφίας, η αντιγραφή των βιβλίων ήταν πολύ επίπονη διαδικασία. Όλες οι σελίδες έπρεπε να αντιγραφούν χειρόγραφα από ειδικευμένα άτομα που ονομάζονταν γραφείς. Ο έφορος της βιβλιοθήκης της Αλεξάνδρειας έχει μια στοίβα από $$N$$ κλασσικά έργα τα οποία πρέπει να αντιγραφούν. Για τον σκοπό αυτό έχει στην διάθεση του $$K$$ γραφείς. Κάθε έργο μπορεί να διαφέρει στον αριθμό σελίδων, και κάθε γραφέας μπορεί να πάρει μόνο συνεχόμενα βιβλία από την στοίβα. Ο έφορος γνωρίζει τον αριθμό σελίδων που έχει το κάθε βιβλίο και πρέπει να κατανείμει τα βιβλία στους γραφείς ώστε να ελαχιστοποιηθεί ο μέγιστος αριθμός σελίδων που θα αντιγράψει κάποιος γραφέας. Να γράψετε ένα πρόγραμμα που θα λύνει το πρόβλημα του εφόρου της βιβλιοθήκης.

## Αρχεία Εισόδου (books.in):

Η πρώτη γραμμή της εισόδου θα περιέχει δύο θετικούς ακεραίους αριθμούς, το πλήθος των βιβλίων $$N$$ και το πλήθος των γραφέων $$K$$. Οι επόμενες $$N$$ γραμμές θα περιέχουν $$N$$ θετικούς ακέραιους $$A_i$$, έναν σε κάθε γραμμή, που αντιπροσωπεύουν το πλήθος των σελίδων του βιβλίου $$i$$.

## Αρχεία Εξόδου (books.out):

Η έξοδος πρέπει να αποτελείται από μία γραμμή που να περιέχει ακριβώς έναν ακέραιο αριθμό, τον μέγιστο αριθμό σελίδων που θα αντιγράψει κάποιος γραφέας.

## Παράδειγμα Αρχείου Εισόδου - Εξόδου:

| **books.in**      | **books.out** |
| :--- | :--- |
| 5 2<br>10<br>20<br>40<br>10<br>50 | 70 |

**Εξήγηση παραδείγματος:** H βέλτιστη λύση είναι να ανατεθούν τα πρώτα τρία βιβλία στον πρώτο γραφέα και τα υπόλοιπα δύο βιβλία στον δεύτερο γραφέα. Έτσι ο μέγιστος αριθμός σελίδων που θα αντιγράψει κάποιος γραφέας είναι $$70$$ ($$10+20+40$$).

## Περιορισμοί:

 - $$1 \leq N \leq 100.000$$, $$1 \leq K \leq N$$, $$1 \leq A_i \leq 10.000$$.
 - Όριο χρόνου εκτέλεσης: $$1$$ sec.
 - Όριο μνήμης: $$64$$ MB.
