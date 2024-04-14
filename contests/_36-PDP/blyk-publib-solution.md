---
layout: statement
codename: publib
---

## Επεξήγηση εκφώνησης

Μας δίνεται ένας μη-κατευθυνόμενος γράφος και μας ζητείται να βρούμε την [ακτίνα](https://el.wikipedia.org/wiki/%CE%91%CE%BA%CF%84%CE%AF%CE%BD%CE%B1_(%CE%B8%CE%B5%CF%89%CF%81%CE%AF%CE%B1_%CE%B3%CF%81%CE%AC%CF%86%CF%89%CE%BD)) του γράφου.

<img style="float: right" src="/assets/36-bgym-publib.png"/>

Στο παράδειγμα της εκφώνησης, ο κόμβος $$1$$ απέχει $$2$$ από τον κόμβο $$2$$, απέχει $$2$$ από τον κόμβο $$3$$, απέχει $$3$$ από τον κόμβο $$4$$, κ.ο.κ. Συνοψίζοντας μπορούμε να τα βάλουμε στην παρακάτω γραμμή:

<center>
<table style="width: auto; cellpadding: 1px">
<tr style="background:#e0e0e0"> <td style="padding: 3px">1</td> <td style="padding: 3px">2</td> <td style="padding: 3px">3</td> <td style="padding: 3px">4</td> <td style="padding: 3px">5</td> <td style="padding: 3px">6</td> <td style="padding: 3px">7</td> <td style="padding: 3px">8</td> </tr>
<tr><td style="padding: 3px">0</td> <td style="padding: 3px">2</td> <td style="padding: 3px">2</td> <td style="padding: 3px">3</td> <td style="padding: 3px">1</td> <td style="padding: 3px">2</td> <td style="padding: 3px">1</td> <td style="padding: 3px">1</td> </tr>
</table>
</center>

και η μέγιστη απόσταση από τον κόμβο $$1$$ είναι $$3$$ προς τον κόμβο $$4$$. Επαναλαμβάνοντας για τους υπόλοιπους κόμβους, έχουμε

<center>
<table style="width: auto; cellpadding: 1px">
<tr style="background:#e0e0e0"> <td style="padding: 3px"></td> <td style="padding: 3px">1</td> <td style="padding: 3px">2</td> <td style="padding: 3px">3</td> <td style="padding: 3px">4</td> <td style="padding: 3px">5</td> <td style="padding: 3px">6</td> <td style="padding: 3px">7</td> <td style="padding: 3px">8</td> </tr>
<tr><td style="background:#e0e0e0">1</td> <td style="padding: 3px">0</td> <td style="padding: 3px">2</td> <td style="padding: 3px">2</td> <td style="padding: 3px"><b style="color:red">3</b></td> <td style="padding: 3px">1</td> <td style="padding: 3px">2</td> <td style="padding: 3px">1</td> <td style="padding: 3px">1</td> </tr>
<tr><td style="background:#e0e0e0">2</td> <td style="padding: 3px">2</td> <td style="padding: 3px">0</td> <td style="padding: 3px"><b>4</b></td> <td style="padding: 3px">1</td> <td style="padding: 3px">1</td> <td style="padding: 3px">2</td> <td style="padding: 3px">3</td> <td style="padding: 3px">1</td> </tr>
<tr><td style="background:#e0e0e0">3</td> <td style="padding: 3px">2</td> <td style="padding: 3px">4</td> <td style="padding: 3px">0</td> <td style="padding: 3px"><b>5</b></td> <td style="padding: 3px">3</td> <td style="padding: 3px">4</td> <td style="padding: 3px">1</td> <td style="padding: 3px">3</td> </tr>
<tr><td style="background:#e0e0e0">4</td> <td style="padding: 3px">3</td> <td style="padding: 3px">1</td> <td style="padding: 3px"><b>5</b></td> <td style="padding: 3px">0</td> <td style="padding: 3px">2</td> <td style="padding: 3px">1</td> <td style="padding: 3px">4</td> <td style="padding: 3px">2</td> </tr>
<tr><td style="background:#e0e0e0">5</td> <td style="padding: 3px">1</td> <td style="padding: 3px">1</td> <td style="padding: 3px"><b style="color:red">3</b></td> <td style="padding: 3px">2</td> <td style="padding: 3px">0</td> <td style="padding: 3px"><b style="color:red">3</b></td> <td style="padding: 3px">2</td> <td style="padding: 3px">2</td> </tr>
<tr><td style="background:#e0e0e0">6</td> <td style="padding: 3px">2</td> <td style="padding: 3px">2</td> <td style="padding: 3px"><b>4</b></td> <td style="padding: 3px">1</td> <td style="padding: 3px">3</td> <td style="padding: 3px">0</td> <td style="padding: 3px">3</td> <td style="padding: 3px">1</td> </tr>
<tr><td style="background:#e0e0e0">7</td> <td style="padding: 3px">1</td> <td style="padding: 3px">3</td> <td style="padding: 3px">1</td> <td style="padding: 3px"><b>4</b></td> <td style="padding: 3px">2</td> <td style="padding: 3px">3</td> <td style="padding: 3px">0</td> <td style="padding: 3px">2</td> </tr>
<tr><td style="background:#e0e0e0">8</td> <td style="padding: 3px">1</td> <td style="padding: 3px">1</td> <td style="padding: 3px"><b style="color:red">3</b></td> <td style="padding: 3px">2</td> <td style="padding: 3px">2</td> <td style="padding: 3px">1</td> <td style="padding: 3px">2</td> <td style="padding: 3px">0</td> </tr>
</table>
</center>

όπου με **έντονα γράμματα** βάζουμε την μέγιστη απόσταση για κάθε κόμβο. Η μικρότερη από αυτές είναι η απάντηση και δίνεται με κόκκινο.

## Βέλτιστη λύση

Σε έναν μη-κατευθυνόμενο γράφο όπου οι ακμές δεν έχουν βάρη μπορούμε να βρούμε την συντομότερη απόσταση από έναν κόμβο $$u$$ προς όλους τους άλλους χρησιμοποιώντας την *αναζήτηση κατά βάθος* (ή αλλιώς BFS). Ο τρόπος που δουλεύει ο αλγόριθμος είναι ο εξής: 
 - Ξεκινάμε με μία ουρά (queue) που αρχικά έχει τον κόμβο $$u$$ (με απόσταση $$0$$)
 - Μετά προσθέτουμε στην ουρά τους γείτονές του με απόσταση $$1$$.
 - Έπειτα για κάθε κόμβο με απόσταση $$d$$ προσθέτουμε τους γείτονές του που δεν έχουμε ήδη συναντήσει, με απόσταση $$d+1$$.

Η τελευταία απόσταση που προσθέτουμε είναι η μέγιστη απόσταση για τον κόμβο $$u$$. Επομένως, επαναλαμβάνουμε την αναζήτηση κατά βάθος μία φορά για κάθε κόμβο για να βρούμε την ακτίνα. Ο παρακάτω κώδικας υλοποιεί ακριβώς αυτό. 

{% include code.md solution_name='publib_bfs_with_queue.cc' start=22 end=45 %}

Παρακάτω δίνεται ένα παράδειγμα εκτέλεσης της αναζήτησης κατά βάθος, όπου η ουρά $$q$$ κρατάσει ζεύγη κόμβου και απόστασης:
<center>
<img width=600px src="/assets/36-blyk-publib-bfs_example.svg"/>
</center>

Κάθε αναζήτηση κατά βάθος θέλει $$\mathcal{O}(N + M)$$ χρόνο, επομένως συνολικά ο αλγόριθμος χρειάζεται $$O(N \cdot M)$$ χρόνο. Μπορείτε να βρείτε ολόκληρο τον κώδικα [εδώ]({% include link_to_source.md solution_name='publib_bfs_with_queue.cc' %}).

**Διαφορετικές υλοποιήσεις:** Η ουρά μπορεί να υλοποιηθεί με την χρήση ενός πίνακα, που έχει την ίδια πολυπλοκότητα, αλλά στην πράξη είναι λίγο πιο γρήγορη γιατί αποφεύγει τις πολλές δεσμεύσεις μνήμης (δείτε [εδώ]({% include link_to_source.md solution_name='publib_bfs_with_array_queue.cc' %}) τον κώδικα). Επίσης, η αναζήτηση κατά βάθος, μπορεί να υλοποιηθεί με δύο πίνακες ακεραίων αντί για μία ουρά με ζεύγη (δείτε [εδώ]({% include link_to_source.md solution_name='publib_bfs.cc' %}) τον κώδικα). 
 
