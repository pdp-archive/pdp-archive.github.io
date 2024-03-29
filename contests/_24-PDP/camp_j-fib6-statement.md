---
layout: statement
codename: fib6
---

Η ακολουθία αριθμών Fibonacci ορίζεται με τον εξής αναδρομικό τύπο:

$$
F_0 = 0, F_1 = 1, F_{n+2} = F_{n+1} + F_n
$$

Οι πρώτοι όροι της ακολουθίας είναι: $$0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, \ldots$$. 

Δίνεται ένας θετικός φυσικός αριθμός $$X$$. Ζητείται να βρεθεί αν o $$X$$ μπορεί να γραφεί ως άθροισμα το πολύ έξι αριθμών Fibonacci, όχι απαραίτητα διαφορετικών. Αν υπάρχουν πολλοί διαφορετικοί τρόποι που αυτό μπορεί να γίνει, ζητείται μία λύση με το μικρότερο δυνατό πλήθος προσθετέων.

## Αρχεία Εισόδου (fib6.in):

Η είσοδος θα αποτελείται από μία μόνο γραμμή που θα περιέχει έναν μόνο ακέραιο αριθμό, το $$X$$.

## Αρχεία Εξόδου (fib6.out):

Η έξοδος πρέπει να αποτελείται από μία γραμμή που να περιέχει:
 - είτε τη λέξη "impossible", χωρίς τα εισαγωγικά, αν ο $$X$$ δεν μπορεί να γραφεί με κανέναν τρόπο ως άθροισμα το πολύ έξι αριθμών Fibonacci,
 - είτε έναν αριθμό $$N$$ μεταξύ $$1$$ και $$6$$, συμπεριλαμβανομένων, ακολουθούμενο από $$N$$ αριθμούς Fibonacci, τέτοιους ώστε το άθροισμά τους να είναι ίσο με $$X$$ και το πλήθος τους να είναι το ελάχιστο δυνατό. Αν υπάρχουν περισσότερες σωστές λύσεις με το ελάχιστο πλήθος προσθετέων, μπορείτε να τυπώσετε οποιαδήποτε από αυτές. Όλοι οι αριθμοί της γραμμής πρέπει να χωρίζονται ανά δύο με ένα κενό διάστημα.

## Παραδείγματα Αρχείων Εισόδου - Εξόδου:

**1<sup>o</sup>**

| **fib6.in**      | **fib6.out** |
| :--- | :--- |
| 42 | 2 8 34 |

**2<sup>o</sup>**

| **fib6.in**      | **fib6.out** |
| :--- | :--- |
| 166418946 | 3 6765 832040 165580141 |

**3<sup>o</sup>**

| **fib6.in**      | **fib6.out** |
| :--- | :--- |
| 649814661 | impossible |

## Περιορισμοί:

 - $$1 \leq X \leq 1.000.000.000$$.
 - Όριο χρόνου εκτέλεσης: $$1$$ sec.
 - Όριο μνήμης: $$16$$ MB.
