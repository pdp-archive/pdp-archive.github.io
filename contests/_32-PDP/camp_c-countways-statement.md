---
layout: statement
codename: countways
---

Μας δίνεται μία σκακιέρα με $$N\times M$$ τετραγωνάκια. Σε κάθε τετραγωνάκι είναι γραμμένος ένας αριθμός. Ξεκινάμε από το πάνω-αριστερά τετραγωνάκι και θέλουμε να πάμε στο κάτω-δεξιά τετραγωνάκι. Σε κάθε κίνηση, μπορούμε να μετακινηθούμε μόνο κατά ένα τετράγωνο πάνω, κάτω, αριστερά ή δεξιά, και μόνο υπό την προϋπόθεση ότι το τετράγωνο στο οποίο πηγαίνουμε έχει (αυστηρά) μεγαλύτερο αριθμό από το τετράγωνο όπου βρισκόμαστε. Με πόσους διαφορετικούς τρόπους μπορούμε να φτάσουμε από το πάνω-
αριστερά τετραγωνάκι στο κάτω-δεξιά;

(Θεωρούμε ότι δύο διαδρομές είναι διαφορετικές όταν οι ακολουθίες των συντεταγμένων των τετραγώνων από τα οποία περνάνε είναι διαφορετικές.)

## Αρχεία Εισόδου (countways.in):

Η πρώτη γραμμή της εισόδου θα περιέχει δύο θετικούς ακέραιους αριθμούς $$N$$ και $$M$$, χωρισμένους με ένα κενό διάστημα: τις διαστάσεις της σκακιέρας. Κάθε μία από τις επόμενες $$N$$ γραμμές θα περιέχει $$M$$ θετικούς ακέραιους αριθμούς χωρισμένους ανά δύο με ένα κενό διάστημα: τους αριθμούς που είναι γραμμένοι στα
τετραγωνάκια της σκακιέρας, με την προφανή σειρά.

## Αρχεία Εξόδου (countways.out):

Η έξοδος πρέπει να περιέχει μία γραμμή με ακριβώς έναν ακέραιο αριθμό: το πλήθος των τρόπων που μπορούμε να φτάσουμε από το πάνω-αριστερά τετραγωνάκι στο κάτω-δεξιά. Επειδή ο αριθμός αυτός μπορεί να είναι πολύ μεγάλος, ζητείται να τυπώσετε το υπόλοιπο της ακέραιας διαίρεσής του (modulo) με τον αριθμό $$10^9+7$$.

## Παράδειγμα Αρχείου Εισόδου - Εξόδου:

| **countways.in**      | **countways.out** |
| :--- | :--- |
| 5 5<br>17 23 26 30 31<br>21 10 19 32 32<br>24 24 54 34 33<br>25 32 37 38 35<br>26 27 80 40 42 | 6 |


**Εξήγηση παραδείγματος**: Υπάρχουν έξι τρόποι για να πάμε από το πάνω-αριστερά τετραγωνάκι ($$17$$) στο κάτω-δεξιά ($$42$$), κινούμενοι πάντα σε τετραγωνάκια με προοδευτικά μεγαλύτερους αριθμούς. Ένας τρόπος είναι κατά μήκος της πρώτης γραμμής και μετά της τελευταίας στήλης: $$17 \to 23 \to 26 \to 30 \to 31 \to 32 \to 33 \to 35 \to 42$$. Ένας άλλος τρόπος είναι αυτός: $$17 \to 21 \to 24 \to 25 \to 26 \to 27 \to 32 \to 37 \to 38\to 40 \to 42$$. Υπάρχουν άλλοι τέσσερις τρόποι που θα πρέπει να ψάξετε να τους βρείτε εσείς.

## Περιορισμοί:

 - $$1 \leq N \leq 1.000$$.
 - $$1 \leq M \leq 1.000$$.
 - Οι αριθμοί στα τετράγωνα της σκακιέρας δε θα υπερβαίνουν το $$1.000.000.000$$.
 - Όριο χρόνου εκτέλεσης: $$1$$ sec.
 - Όριο μνήμης: $$128$$ MB.

## Subtasks

 - Σε testcases που θα αντιστοιχούν στο 30% της βαθμολογίας, θα είναι $$N \leq 10$$ και $$M \leq 10$$.
 - Σε testcases που θα αντιστοιχούν στο 50% της βαθμολογίας, θα είναι $$N \leq 100$$ και $$M \leq 100$$.
