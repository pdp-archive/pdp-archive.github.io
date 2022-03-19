---
layout: solution
codename: getout
---

*Η λυση αυτή απαιτεί γνώσεις BFS και βασικές γνώσεις bitwise τελεστών.*

## Επεξήγηση εκφώνησης

Μας δίνεται ένας $$N \times N$$ πίνακας με κάποια $$2 \times 1$$ "αυτοκίνητα" που μπορούν να μετακινηθούν οριζοντίως και κάποια $$1 \times 2$$ αυτοκίνητα που μπορούν να μετακινηθούν καθέτως, όσο δεν υπάρχει κάποιο άλλο αυτοκίνητο στον δρόμο τους.

Μας ζητείται να βρούμε τον αριθμό των ελάχιστων κινήσεων ώστε η γραμμή $$R$$ να μείνει ελεύθερη.

## Λύση με αναζήτηση κατά βάθος

Θεωρούμε τον γράφο όπου οι κόμβοι είναι τα δυνατά states του πίνακα, δηλαδή οι πιθανές διατάξεις των αυτοκινήτων. Η ακμή $$S_1 \to S_2$$ υπάρχει αν και μόνο αν στο $$S_1$$ αν κουνήσουμε ένα από τα αυτοκίνητα πηγαίνουμε στο $$S_2$$. Σε αυτόν τον γράφο ξεκινάμε από την αρχική διάταξη $$\textit{init}$$ και στόχος μας είναι να βρούμε τον ελάχιστο αριθμό βημάτων που χρειάζεται για να πάμε σε κάποιο state όπου η γραμμή $$R$$ είναι κενή.

<center>
<img alt="Το αρχικό μέρος του γράφου για τον πίνακα του παραδείγματος" src="/assets/22-c-getout-graph-example.svg" width="700px">
</center>

Αφου οι ακμές δεν έχουν βάρος μπορούμε να χρησιμοποιήσουμε μία αναζήτηση κατά βάθος (BFS) ώστε να βρούμε αυτό το κοντινότερο state. Κάθε BFS λύση χρειάζεται μία αναπαράσταση για τα states, και έναν τρόπο για την εύρεση των γειτονικών κόμβων. Θα ξεκινήσουμε με μία απλή αναπαράσταση και σχετικά εκτενή κώδικα και θα προσπαθήσουμε να τον μικρύνουμε. Στο τέλος θα δείξουμε και μία εναλλακτική αναπαράσταση που χρειάζεται λιγότερη μνήμη.

### Αρχική λύση

Θα ξεκινήσουμε με την αναπαράσταση όπου κρατάμε τη συντεταγμένη του δεξιότερου και υψηλότερου σημείου για κάθε αυτοκίνητο ξεχωριστά για τα οριζόντια και κάθετα αυτοκίνητα. Αυτό μας επιτρέπει να ελέχουμε αν δύο states είναι ίδια σε χρόνο γραμμικό των αυτοκινήτων στον πίνακα (τον `operator<` θα τον χρειαστούμε για την αποθήκευση state σε `std::set`).

{% include code.md solution_name='bfs_initial.cc' start=11 end=25 %}

Για να βρούμε τις πιθανές κινήσεις από ένα state, δοκιμάζουμε να μετακινήσουμε κάθε οριζόντιο ή κάθετο αυτοκίνητο σε μία από τις δύο πιθανές κατευθύνσεις. Για να ελέγχουμε γρήγορα αν μία θέση είναι άδεια, κρατάμε τον πίνακα στον $$64$$-bit ακέραιο `not_free`. Όπως θα παρατηρήσετε, οι παρακάτω τέσσερις περίπτωσεις έχουν πολύ παρόμοιο κώδικα.

{% include code.md solution_name='bfs_initial.cc' start=27 end=101 %}

Ο έλεγχος για το αν ένα state έχει κενή τη $$R$$-οστή γραμμή είναι απλός:

{% include code.md solution_name='bfs_initial.cc' start=103 end=112 %}

Έχοντας υλοποιήσει την `getNext` και την `isTerminal`, η BFS δίνεται ως εξής:

{% include code.md solution_name='bfs_initial.cc' start=103 end=112 %}

Παρατηρήστε ότι κρατάμε τα states σε ένα `std::set`, ώστε να μην επισκεπτόμαστε κάποιο πάνω από μία φορά.

### Συντομότερος κώδικας για `getNext()`

Για τα οριζόντια αυτοκίνητα, μπορούμε να συγχωνεύσουμε τον κώδικα για τις κινήσεις προς τα αριστερά και προς τα δεξιά. Αντίστοιχα, για τα κάθετα αυτοκίνητα, μπορούμε να συγχωνεύσουμε τις κινήσεις προς τα πάνω και κάτω.

{% include code.md solution_name='bfs_shorter.cc' start=41 end=79 %}

Ολόκληρος ο κώδικας είναι [εδώ]({% include link_to_source.md solution_name='bfs_shorter.cc' %}).

### Ακόμη συντομότερος κώδικας για `getNext()`

Επίσης, μπορούμε να κρατήσουμε όλα τα αυτοκίνητα στο ίδιο vector, μαζί με έναν bool που μας λέει αν είναι οριζόντιο ή κάθετο. Με αυτόν τον τρόπο, ορίζοντας κάποιες βοηθητικές συναρτήσεις, μπορούμε να συγχωνεύσουμε τις τέσσερις κινήσεις:

{% include code.md solution_name='bfs_even_shorter.cc' start=39 end=69 %}

Ολόκληρος ο κώδικας είναι [εδώ]({% include link_to_source.md solution_name='bfs_even_shorter.cc' %}).

### Αναπαράσταση με λιγότερη μνήμη

Αντί για το vector από συντεταγμένες, μπορούμε να κρατήσουμε έναν binary πίνακα με τις θέσεις που ξεκινάνε οριζόντια αυτοκίνητα και έναν πίνακα με τις θέσεις που ξεκινάνε κάθετα αυτοκίνητα. Αφού το μέγεθος του κάθε πίνακα είναι το πολύ $$8\times 8$$, μπορούμε να τον αποθηκεύσουμε σε έναν $$64$$-bit ακέραιο. Με αυτόν τον τρόπο χρειαζόμαστε λιγότερη μνήμη στην χειρότερη περίπτωση και ο έλεγχος για ισότητα μεταξύ states γίνεται πιο γρήγορος (απλή σύγκριση ακεραίων). 

{% include code.md solution_name='bfs_efficient_representation.cc' start=12 end=21 %}

Από την άλλη η εύρεση των γειτονικών states είναι πιο αργή αφού πρέπει να διατρέξουμε όλες τις θέσεις του πίνακα για να βρούμε ποιες θέσεις είναι κατειλημμένες.

{% include code.md solution_name='bfs_efficient_representation.cc' start=48 end=79 %}

Ολόκληρος ο κώδικας είναι [εδώ]({% include link_to_source.md solution_name='bfs_efficient_representation.cc' %}).