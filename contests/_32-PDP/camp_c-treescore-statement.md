---
layout: statement
codename: treescore
---

Σε μία εταιρεία εργάζονται $$N$$ άνθρωποι. Κάθε εργαζόμενος έχει έναν προϊστάμενο, εκτός από τον διευθυντή της εταιρείας που δεν έχει κανέναν πάνω από το κεφάλι του. Το οργανόγραμμα της εταιρείας, δηλαδή ένα σχήμα που δείχνει ποιος είναι προΐστάμενος ποιου, έχει δομή δέντρου, με τον διευθυντή της εταιρείας στη ρίζα του. Για κάθε εργαζόμενο $$A$$ ορίζουμε την «ομάδα που εποπτεύει» ως εξής:
 - ο ίδιος ο εργαζόμενος $$A$$ ανήκει στην ομάδα που εποπτεύει, και
 - για κάθε υφιστάμενο $$B$$ του εργαζόμενου $$A$$, όλοι όσοι ανήκουν στην ομάδα που εποπτεύει ο $$B$$ ανήκουν και στην ομάδα που εποπτεύει ο $$A$$.
 
Φέτος η εταιρεία αποφάσισε να αξιολογήσει τους εργαζόμενους και τους έβαλε να κάνουν ένα τεστ ικανότητας. Σε αυτό το τεστ, κάθε εργαζόμενος βαθμολογήθηκε με ένα σκορ από $$1$$ μέχρι και $$T$$.

Θέλουμε να μπορούμε οποιαδήποτε στιγμή να απαντάμε ερωτήσεις της μορφής: «πόσοι εργαζόμενοι στην ομάδα που εποπτεύει ο $$A$$ πήραν σκορ μεταξύ $$L$$ και $$U$$ (συμπεριλαμβανομένων);».

Για να γίνουν όμως τα πράγματα χειρότερα, κάποιοι εργαζόμενοι αποφάσισαν να ξανακάνουν το τεστ και έτσι αλλάζει το σκορ τους...

## Αρχεία Εισόδου (treescore.in):

Η πρώτη γραμμή της εισόδου θα περιέχει τρεις φυσικούς αριθμούς $$N$$, $$T$$ και $$Q$$: το πλήθος των εργαζομένων, τη μέγιστη τιμή του σκορ και το πλήθος των ενεργειών που θα πρέπει το πρόγραμμά σας να κάνει.

Οι επόμενες $$N$$ γραμμές περιγράφουν τους εργαζόμενους που θεωρούμε ότι είναι αριθμημένοι από $$1$$ έως $$N$$. Πιο συγκεκριμένα, η $$i$$-οστή από αυτές περιέχει δύο φυσικούς αριθμούς $$P_i$$ και $$S_i$$, χωρισμένους με ένα κενό διάστημα. Αυτό σημαίνει ότι ο υπάλληλος με αριθμό $$i$$ έχει προϊστάμενο τον $$P_i$$ και έχει πάρει σκορ $$S_i$$ στο τεστ. Για τον διευθυντή της εταιρείας που δεν έχει προϊστάμενο, θα είναι $$P_i = 0$$. Θεωρήστε ότι το οργανόγραμμα της εταιρείας που ορίζεται σε αυτές τις γραμμές είναι πάντοτε έγκυρο.

Οι επόμενες $$Q$$ γραμμές περιγράφουν μία ενέργεια που θα πρέπει το πρόγραμμά σας να κάνει. Οι ενέργειες είναι δύο τύπων. Αρχίζουν είτε με το γράμμα "u" είτε με το γράμμα "q" και ακολουθούν δύο ή τρεις ακέραιοι αριθμοί αντίστοιχα. Το γράμμα και οι αριθμοί είναι χωρισμένοι ανά δύο με ένα κενό διάστημα. Η σημασία των ενεργειών είναι η εξής:
 - **u** $$A_j$$ $$S_j$$ (update) Ο εργαζόμενος $$A_j$$ ξανάκανε το τεστ και πήρε σκορ $$S_j$$.
 - **q** $$A_j$$ $$L_j$$ $$U_j$$ (query) Απαντήστε στην ερώτηση: πόσοι εργαζόμενοι στην ομάδα που εποπτεύει ο εργαζόμενος $$A_j$$ έχουν πάρει σκορ $$S$$ τέτοιο ώστε $$L_j \leq S \leq U_j$$.

## Αρχεία Εξόδου (treescore.out):

Η έξοδος πρέπει να περιέχει μία γραμμή για κάθε ενέργεια τύπου "q" (query). Κάθε μία από αυτές τις γραμμές πρέπει να περιέχει, με τη σειρά, έναν ακέραιο αριθμό: την απάντηση στην αντίστοιχη ερώτηση.

## Παράδειγμα Αρχείου Εισόδου - Εξόδου:

| **treescore.in**      | **treescore.out** |
| :--- | :--- |
| 4 4 3<br>0 1<br>1 2<br>1 4<br>2 3<br>q 1 2 3<br>u 4 1<br>q 2 2 3 | 2<br>1 |


**Εξήγηση παραδείγματος**: Η πρώτη ερώτηση έχει απάντηση $$2$$ γιατί στην ομάδα που εποπτεύει ο $$1$$ υπάρχουν δύο εργαζόμενοι με σκορ μεταξύ $$2$$ και $$3$$ (ο $$2$$ έχει σκορ $$2$$ και ο $$4$$ έχει σκορ $$3$$). Μετά, το σκορ του $$4$$ αλλάζει και γίνεται $$1$$. Η δεύτερη ερώτηση έχει τώρα απάντηση $$1$$ γιατί στην ομάδα που εποπτεύει ο $$2$$ υπάρχει τώρα μόνο ένας εργαζόμενος με σκορ μεταξύ $$2$$ και $$3$$ (ο ίδιος ο $$2$$, που έχει σκορ $$2$$).

## Περιορισμοί:

 - $$1 \leq N \leq 40.000$$.
 - $$1 \leq T \leq 40.000$$.
 - $$1 \leq Q \leq 40.000$$.
 - Όριο χρόνου εκτέλεσης: $$1$$ sec.
 - Όριο μνήμης: $$256$$ MB.

## Subtasks

 - Σε testcases που θα αντιστοιχούν στο 30% της βαθμολογίας, θα είναι $$N \leq 1.000$$, $$Q \leq 1.000$$.
 - Σε testcases που θα αντιστοιχούν στο 20% της βαθμολογίας, θα είναι $$T = 1$$, δηλαδή όλοι οι εργαζόμενοι θα έχουν πάρει το ίδιο σκορ και το μόνο που θα χρειάζεται είναι να τους μετράτε.
 - Σε testcases που θα αντιστοιχούν στο 20% της βαθμολογίας, θα είναι $$T = 10$$.