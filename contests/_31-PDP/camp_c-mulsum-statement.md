---
layout: statement
codename: mulsum
---

Δίνεται μία ακολουθία $$N$$ φυσικών αριθμών και ένας θετικός φυσικός αριθμός $$M$$. Ζητείται το μέγιστο πολλαπλάσιο του $$M$$ που μπορεί να προκύψει ως άθροισμα (οσωνδήποτε) διαδοχικών όρων της ακολουθίας.

## Αρχεία Εισόδου (mulsum.in):

Η πρώτη γραμμή της εισόδου θα περιέχει ακριβώς δύο φυσικούς αριθμούς χωρισμένους μεταξύ τους με ένα κενό διάστημα: το πλήθος $$N$$ των στοιχείων της ακολουθίας και τον αριθμό $$M$$. Η δεύτερη γραμμή της εισόδου θα περιέχει $$N$$ ακέραιους αριθμούς, χωρισμένους ανά δύο με ένα κενό διάστημα. Να θεωρήσετε ως δεδομένο ότι το άθροισμα όλων των όρων της ακολουθίας δε θα υπερβαίνει το $$1.000.000.000$$.

## Αρχεία Εξόδου (mulsum.out):

Η έξοδος πρέπει να αποτελείται από μία γραμμή που να περιέχει ακριβώς έναν ακέραιο αριθμό, το ζητούμενο πολλαπλάσιο.

## Παραδείγματα Αρχείων Εισόδου - Εξόδου:

**1<sup>o</sup>**

| **mulsum.in**      | **mulsum.out** |
| :--- | :--- |
| 8 7<br>1 2 3 4 5 6 7 8 | 35 |


**Εξήγηση 1<sup>ου</sup> παραδείγματος**: Στο πρώτο παράδειγμα, το άθροισμα των όρων $$2+3+4+5+6+7+8 = 35$$ είναι το μεγαλύτερο πολλαπλάσιο του $$7$$ που μπορεί να γραφεί ως άθροισμα συνεχόμενων όρων της ακολουθίας.

**2<sup>o</sup>**

| **mulsum.in**      | **mulsum.out** |
| :--- | :--- |
| 5 17<br>6 4 3 7 1 | 0 |

**Εξήγηση 2<sup>ου</sup> παραδείγματος**: Στο δεύτερο παράδειγμα, κανένα μη μηδενικό άθροισμα συνεχόμενων όρων της ακολουθίας δεν είναι πολλαπλάσιο του $$17$$. Αν όμως επιλέξουμε να αθροίσουμε μηδέν όρους της ακολουθίας, με άθροισμα μηδέν, αυτό είναι πολλαπλάσιο του $$17$$ και είναι το μέγιστο δυνατό.

## Subtasks

 1. Στο 20%, $$1 \leq N \leq 1.000$$, $$1 \leq M \leq 10.000$$.
 2. Στο 20%, $$1 \leq N \leq 10.000$$, $$1 \leq M \leq 100.000$$.
 3. Στο 60%, $$1 \leq N \leq 1.000.000$$, $$1 \leq M \leq 1.000.000$$.
