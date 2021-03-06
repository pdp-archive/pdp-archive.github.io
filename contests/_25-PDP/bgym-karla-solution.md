---
layout: solution
codename: karla
---

## Επεξήγηση εκφώνησης

Μας δίνεται ένας πίνακας $$N\times N$$ με ακέραιες τιμές και πρέπει να υπολογίσουμε πόσα συνδεδεμένα τμήματα θα μείνουν αν αφαιρέσουμε όλες τις τιμές μικρότερες ή ίσες με $$M$$.


Δύο τιμές $$A, B$$ είναι συνδεδεμένες ($$A\leftrightarrow B$$) αν:

 * H μία είναι μία από τις τέσσερις γειτονικές της άλλης.

 * Αν υπάρχει μία ακολουθία από γειτονικές τιμές $$k_1, \ldots, k_n$$ ώστε $$Α \leftrightarrow k_1 \leftrightarrow \ldots \leftrightarrow k_n \leftrightarrow B$$.

 
Αυτή η συνδεσιμότητα ορίζει έναν γράφο (δείτε την εικόνα για τον γράφο του παραδείγματος). 
Επομένως, πρέπει να μετρήσουμε τα συνεκτικά τμήματα του γράφου. 

<center>
<img alt="Γράφος παραδείγματος" src="/assets/25-pdp-b-karla-graph-example.svg" width="400px">
</center>

Στη συνέχεια θα δούμε δύο λύσεις που εντοπίζουν συνεκτικά τμήματα στο γράφο μας, η μία πρώτη λύση βασίζεται στην αναζήτηση κατά βάθος και η επόμενη στη δομή δεδομένων union-find. Και οι δύο περνάνε όλα τα testcases.


## Αναζήτηση κατά βάθος

Ξεκινάμε από μία τιμή ($$> M$$) του πίνακα και βρίσκουμε όλες με τις οποίες συνδέεται. Το κάνουμε αυτό ξεκινώντας μία αναζήτηση-κατά-βάθος (DFS) στην τιμή. Κάθε τιμή που επισκεπτόμαστε την μαρκάρουμε, ώστε να μην την ξανα-επισκεφτούμε. Όταν δεν υπάρχουν άλλες τιμές που μπορούμε να επισκεφτούμε, συνεχίζουμε με την επόμενη τιμή μεγαλύτερη από $$M$$ και αυξάνουμε τον μετρητή τμημάτων.


Αφού στο τέλος θα επισκεφτούμε κάθε τιμή μία φορά, ο αλγόριθμος τρέχει σε $$\mathcal{O}(N^2)$$ και χρειάζεται μνήμη $$\mathcal{O}(N^2)$$.


Υπάρχουν δύο κλασικοί τρόποι υλοποίησης της DFS: αναδρομικά ή γραμμικά. Ο γραμμικός τρόπος έχει το (μικρό) πλεονέκτημα ότι χρησιμοποιεί μικρότερη στοίβα κλήσεων. Παρακάτω δίνεται η αναδρομική υλοποίηση:

{% include code.md solution_name='karla_efficient_recursive.cc' %}

Η γραμμική υλοποίηση χρησιμοποιεί μία στοίβα:

{% include code.md solution_name='karla_efficient_iterative.cc' start=16 end=42 %}

Μπορούμε να απλοποίησουμε τον έλεγχο των γειτονικών κελιών κρατώντας τις τέσσερις πιθανές διευθύνσεις σε έναν πίνακα:

{% include code.md solution_name='karla_efficient_short.cc' start=16 end=27 %}


## Συνένωση τμημάτων σε ομάδες (sets)

Γνώσεις που θα χρειαστούμε: [union-find disjoint-sets](https://kallinikos.github.io/Union-Find-Disjoint-Sets)


Θα εξερευνήσουμε με τη σειρά ένα ένα όλα τα κελιά, από αριστερά προς τα δεξιά και από πάνω προς τα κάτω. Θα εντάξουμε όλα τα μη πλημμυρισμένα κελιά σε μια νέα ή σε μια υπάρχουσα ομάδα.

Εργαζόμαστε ως εξής: αν το κελί που εξετάζουμε δεν είναι πλημμυρισμένο, το ενώνουμε με τα αμέσως γειτονικά του προς τα αριστερά και προς τα επάνω, εφόσον δεν είναι πλημμυρισμένα. Το αριστερό και το επάνω κελί τα έχουμε επεξεργαστεί πριν φτάσουμε στο τρέχον κελί. Επομένως, χρειάζεται να διατρέξουμε μία φορά τον πίνακα, άρα χρειάζονται $$\mathcal{O}(N^2)$$ βήματα.

Στο τέλος μετράμε πόσες διαφορετικές ομάδες έχουν δημιουργηθεί στη union-find. Αυτό το κάνουμε μετρώντας τους διαφορετικούς εκπροσώπους που υπάρχουν. Το τελευταίο αυτό στάδιο θέλει άλλα $$\mathcal{O}(N^2)$$ βήματα για την καταμέτρηση.

{% include code.md solution_name='karla_simple_disjoint.cc' %}

Μπορούμε να εξαλείψουμε την καταμέτρηση στο τέλος της παραπάνω λύσης. Θα χρησιμοποιήσουμε τη μεταβλητή $$\mathit{ans}$$ στην οποία θα διατηρούμε τον αριθμό των ομάδων που έχουμε δημιουργήσει.

Κάθε μη πλημμυρισμένο κελί $$x,y$$ που εξερευνούμε, το εντάσσουμε σε μία νέα ομάδα με εκπρόσωπο τον εαυτό του, αυξάνοντας την $$\mathit{ans}$$. 

Ελέγχουμε τα αμέσως γειτονικά του προς τα αριστερά και προς τα επάνω και αν δεν είναι πλημμυρισμένα και ανήκουν σε διαφορετική ομάδα, τα ενώνουμε με την ομάδα του τρέχοντος κελιού, μειώνοντας την μεταβλητή $$\mathit{ans}$$. 

Παρατηρήστε στον γράφο της ακόλουθης εικόνας πως θα ανακαλύψουμε αρχικά την πράσινη ομάδα, οπότε το $$\mathit{ans}$$ γίνεται $$1$$ και παραμένει $$1$$ μέχρι και το τέλος της δεύτερης γραμμής. Εξερευνώντας την τρίτη γραμμή, συναντάμε κελιά της ροζ ομάδας, άρα το $$\mathit{ans}$$ γίνεται $$2$$, μέχρι που φτάνουμε στο μωβ κελί στο οποίο ανακαλύπτουμε ότι η πράσινη και η ροζ ομάδα ταυτίζονται και τις ενώνουμε (άρα το $$\mathit{ans}$$ μειώνεται σε $$1$$). Όταν εξερευνήσουμε το δεξί άκρο της τέταρτης γραμμής, θα ανακαλύψουμε και την τρίτη ομάδα του γράφου μας.

<center>
<img alt="Γράφος παραδείγματος" src="/assets/25-pdp-b-karla-graph-disjoint1.svg" width="180px">
</center>

Η αναζήτηση εκπροσώπου και η συνένωση ομάδων, γίνεται amortized σχεδόν σε σταθερό χρόνο[^1] και δεν αλλάζει την ασυμπτωτική πολυπλοκότητα της λύσης.

{% include code.md solution_name='karla_efficient_disjoint.cc' %}


[^1]: Οι λειτουργίες union και find της union-find που χρησιμοποιούν συμπύκνωση μονοπατιών, χρειάζονται χρόνο $$\mathcal{O}(\alpha(N^2))$$ ανα κλήση σε ένα δάσος $$N^2$$ κόμβων σαν αυτό της άσκησης. Με $$\alpha(n)$$ συμβολίζουμε την εξαιρετικά μικρής αύξησης ως προς το $$n$$, [αντίστροφη συνάρτηση Ackermann](https://en.wikipedia.org/wiki/Ackermann_function#Inverse). Ενδεικτικά του ρυθμού αύξησης, το $$\alpha(9876 !)=5$$. Στην πράξη, ο χρόνος στις συναρτήσεις union και find είναι σχεδόν γραμμικός λόγω του ότι το $$\alpha(n)\le 3$$ για οποιοδήποτε $$n$$ μπορεί να προκύψει στην πράξη [ανφ.R.Tarjan](http://encyclopediaofmath.org/index.php?title=Ackermann_function&oldid=49989).
