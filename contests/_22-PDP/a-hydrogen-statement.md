---
layout: statement
codename: hydrogen
---

Αποτελεί πλέον κοινή παραδοχή ότι το υφιστάμενο μοντέλο ανάπτυξης, πέραν όλων των άλλων στρεβλώσεων προκαλεί μια τρομακτική υποβάθμιση στο περιβάλλον του πλανήτη μας. Η μείωση της καύσης υδρογονανθράκων και ο περιορισμός της ποσότητας του εκπεμπόμενου διοξειδίου του άνθρακα (CO<sub>2</sub>), αποτελούν πρώτιστη προτεραιότητα για την ανθρωπότητα. Η χρήση υδρογόνου (H<sub>2</sub>), που μπορεί να παραχθεί φθηνά από το θαλασσινό νερό με ηλεκτρόλυση, τα ηλεκτρικά φορτία της οποίας μπορούν να μας τα παρέχουν φωτοβολταϊκά στοιχεία, είναι μια ελπιδοφόρα λύση. Η ένωση του υδρογόνου (H<sub>2</sub>) με το Οξυγόνο (Ο<sub>2</sub>) γίνεται με ισχυρή εξώθερμη αντίδραση και μόνο κατάλοιπο το νερό! (2H<sub>2</sub> + O<sub>2</sub> --> 2H<sub>2</sub>O). Η ελεγχόμενη αντίδραση σε «κυψέλες υδρογόνου» παράγει ηλεκτρικό ρεύμα.

Σύμπραξη Ελληνικών Πανεπιστημίων, e-TEE και ΕΠΥ κατασκεύασαν μερικά δοκιμαστικά αυτοκίνητα υδρογόνου με εξελιγμένα συστήματα μετατροπής ισχύος, μηχανολογικά αλλά και ηλεκτρονικά, για βέλτιστη συμπεριφορά. Προκειμένου να δοκιμαστεί η συμπεριφορά τους σε πραγματικές συνθήκες οδήγησης, με τη βοήθεια του δικτύου των Ελληνικών Πανεπιστημίων και ΤΕΙ, καταγράφεται σε κεντρικό πληροφοριακό σύστημα κάθε βλάβη που εντοπίζεται σε κάθε ένα από $$10000$$ ξεχωριστά τμήματα του αυτοκινήτου. Οι βλάβες που δεν οφείλονται στον οδηγό, ελέγχονται και καταχωρίζονται, ενώ οι άλλες “οφειλόμενες στον οδηγό” δεν καταχωρίζονται.

## Πρόβλημα

Να αναπτύξετε ένα πρόβλημα σε μια από τις γλώσσες του ΙΟΙ το οποίο, αφού διαβάσει τις αναφορές βλαβών για κάθε τμήμα, θα παραγάγει ένα αρχείο με τον αριθμό των τμημάτων που παρουσίασαν βλάβη (μη οφειλόμενη στον οδηγό) και τα αντίστοιχα τμήματα του αυτοκινήτου, ταξινομημένα κατά φθίνουσα σειρά αναφοράς βλαβών.

## Αρχεία εισόδου

Τα αρχεία εισόδου με όνομα **hydrogen.in** είναι αρχεία κειμένου με την εξής δομή: Η πρώτη γραμμή έχει έναν ακέραιο αριθμό, τον αριθμό των τμημάτων για τα οποία υπήρξαν αναφορές βλάβης $$10 \leq C \leq 10000$$. Οι επόμενες $$C$$ γραμμές περιέχουν η κάθε μία δύο ακέραιους αριθμούς χωριζόμενους από ένα κενό. Τον αριθμό του τμήματος και τις συνολικές βλάβες που διαπιστώθηκαν.

## Αρχεία εξόδου

Τα αρχεία εξόδου με όνομα **hydrogen.out** είναι αρχεία κειμένου με την εξής δομή: Η πρώτη γραμμή έχει έναν ακέραιο αριθμό, τον αριθμό των τμημάτων τα οποία παρουσίασαν βλάβη ευθύνης του κατασκευαστή $$0 \leq L \leq 10000$$. Οι επόμενες $$L$$ γραμμές περιέχουν από έναν αριθμό, τον αριθμό του τμήματος που παρουσίασε βλάβη με φθίνουσα όμως σειρά. (Με βάση τη συχνότητα εμφάνισης βλάβης)

## Παραδείγματα αρχείων εισόδου - εξόδου

**1<sup>o</sup>**

| **hydrogen.in**                         | **hydrogen.out** |
| ------------------------------------ | ------------- |
| 10 <br> 1 34 <br> 2 11 <br> 17 2 <br> 18 1 <br> 19 5 <br> 20 6 <br> 9001 0 <br> 1111 0 <br> 701 0 <br> 111 11 | 7 <br> 1 <br> 2 <br> 111 <br> 20 <br> 19 <br> 17 <br> 18 |

**2<sup>o</sup>**

| **hydrogen.in**                         | **hydrogen.out** |
| ------------------------------------ | ------------- |
| 20 <br> 11 1 <br> 22 0 <br> 33 2 <br> 44 0 <br> 55 3 <br> 66 0 <br> 77 4 <br> 88 0 <br> 99 5 <br> 111 0 <br> 222 6 <br> 333 0 <br> 444 7 <br> 555 0 <br> 666 8 <br> 777 0 <br> 888 9 <br> 999 0 <br> 1111 10 <br> 2222 11 | 11 <br> 2222 <br> 1111 <br> 888 <br> 666 <br> 444 <br> 222 <br> 99 <br> 77 <br> 55 <br> 33 <br> 11 |

## Παρατηρήσεις

1. Οι κωδικοί των διαφόρων τμημάτων του αυτοκινήτου εμφανίζονται μόνο μια φορά στο αρχείο εισόδου.
2. Αν δύο κωδικοί έχουν την ίδια συχνότητα εμφάνισης βλάβης, στο αρχείο εξόδου θα εμφανιστούν με αύξουσα σειρά.