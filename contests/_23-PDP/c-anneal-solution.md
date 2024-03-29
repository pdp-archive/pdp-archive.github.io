---
layout: solution
codename: anneal
---

## Επεξήγηση εκφώνησης

Μας δίνονται $$N$$ θάλαμοι και οι θερμοκρασίες $$a_i$$ για τον κάθε θάλαμο $$i$$. Έστω $$T_i$$ η θερμοκρασία πριν τον θάλαμο $$i$$. Αν $$a_i > T_i$$ τότε πρέπει να πληρώσουμε τη διαφορά $$a_i - T$$. Διαφορετικά είτε μπορούμε να ανανεώσουμε τη θερμοκρασία σε $$a_i$$ (με μηδενικό κόστος) ή να διατηρήσουμε την ίδια με κόστος $$2 \cdot a_i$$. 

Μας ζητείται να βρούμε το ελάχιστο κόστος για να περάσουμε από όλους τους $$N$$ θαλάμους.

## Brute force

Ξεκινάμε με την εξής παρατήρηση:

**Παρατήρηση 1:** Δεν συμφέρει να έχουμε μεγαλύτερη θερμοκρασία από $$\max_{0 \leq i < N} a_i$$ στην αρχή.

*Αιτιολόγηση:* Έστω ότι η βέλτιστη ακολουθία χρησιμοποιεί μία τιμή μεγαλύτερη από $$\max_{0 \leq i < N} a_i$$. Αυτή η ακολουθία πρέπει να αποφεύγει τους πρώτους $$i$$ θαλάμους (για κάποιο $$i$$), και μετά να ακολουθεί την τιμή του $$a_{i+1}$$. Επομένως, το ίδιο κόστος θα έχει και η ακολουθία που ξεκινάει με το $$\max_{0 \leq i < N} a_i$$.

Άρα μπορούμε να δοκιμάσουμε κάθε δυνατή αρχική τιμή και σε κάθε βήμα να πάρουμε όλες τις δυνατές κινήσεις. Από όλες τις δυνατές εκδοχές κρατάμε αυτή με το ελάχιστο κόστος.

{% include code.md solution_name='anneal_brute_force.cc' %}

Υπάρχουν $$\mathcal{O}(2^N)$$ δυνατές ακολουθίες και $$\mathcal{O}(\max_{0 \leq i < N} a_i)$$ δυνατές αρχικές τιμές. Επομένως ο αλγόριθμος τρέχει σε $$\mathcal{O}(2^N \cdot \max_{0 \leq i < N} a_i)$$ χρόνο και χρειάζεται $$\mathcal{O}(N)$$ μνήμη.


## Δυναμικός προγραμματισμός με την θερμοκρασία

Μπορούμε να λύσουμε το πρόβλημα με την χρήση δυναμικού προγραμματισμού. Έστω $$dp[i][v]$$ το ελάχιστο κόστος ώστε μετά από τους πρώτους $$i$$ θαλάμους να έχουμε τη θερμοκρασία $$v$$. Τότε, η τιμή του δίνεται από την παρακάτω σχέση

$$dp[i][v] = \begin{cases} 
   dp[i-1][v] + 2 \cdot a_i & \text{if $a_i > v$,} \\
   \min_{u \geq a_i} dp[i-1][u] & \text{if $a_i = v$}, \\
   dp[i-1][v] + v - a_i & \text{otherwise,} \end{cases}$$

όπου θεωρούμε ότι $$dp[-1][\cdot] = 0$$. Ο παρακάτω κώδικας λύνει αυτήν την σχέση:

{% include code.md solution_name='anneal_dp_with_values.cc' start=22 end=34 %}

Υπάρχουν συνολικά $$N \cdot \max_{0 \leq i < N} a_i$$ δυνατά states και κάθε γραμμή $$dp[i][\cdot]$$ μπορούμε να την υπολογίσουμε σε $$\mathcal{O}(\max_{0 \leq i < N} a_i)$$ χρόνο (γιατί η (1) και (3) περίπτωση θέλουν $$\mathcal{O}(1)$$ χρόνο, ενώ η (2) θέλει $$\mathcal{O}(\max_{0 \leq i < N} a_i)$$, αλλά υπάρχει μόνο μία τέτοια περίπτωση). Συνολικά ο αλγόριθμος χρειάζεται $$\mathcal{O}(N \cdot \max_{0 \leq i < N} a_i)$$ χρόνο και μνήμη, και περνάει περίπου 10 από τα 18 testcases, γιατί το $$\max_{0 \leq i < N} a_i = 10^7$$.

Ολόκληρος ο κώδικας είναι [εδώ]({% include link_to_source.md solution_name='anneal_dp_with_values.cc' %}).

## Δυναμικός προγραμματισμός με τους δείκτες

**Παρατήρηση 2:** Δεν συμφέρει να χρησιμοποιήσουμε θερμοκρασίες που δεν υπάρχουν σε κάποιον θάλαμο (δηλαδή σε μία βέλτιστη λύση, κάθε θερμοκρασία $$v_i = a_{j_i}$$ για κάποιο $$j_i$$).

*Αιτιολόγηση:* Αν σε κάποιο βήμα ακολουθήσουμε τη θερμοκρασία του θαλάμου, τότε από εκείνο το σημείο και μετά έχουμε θερμοκρασία που αντιστοιχεί σε κάποιο $$a_{j_i}$$. Επομένως, μένει να αιτιολογήσουμε ότι δεν συμφέρει να ξεκινήσουμε από μία θερμοκρασία που δεν εμφανίζεται σε κάποιον θάλαμο. Έστω ότι ξεκινούσαμε από $$x$$ και έστω $$a_i$$ η μικρότερη τιμή ώστε $$a_i > x$$ (υπάρχει λόγω της Παρατήρησης 1), τότε στους διπλασιασμούς έχει το ίδιο κόστος αλλά στην μείωση έχει μικρότερο ($$a_j - a_i < a_j - x$$). Επομένως αν ξεκινήσουμε με το $$a_i$$ αντί για το $$x$$ τότε θα έχουμε μικρότερο συνολικό κόστος. 

Αυτό μας επιτρέπει να μικρύνουμε τις διαστάσεις του πίνακα $$dp$$ σε $$N \times N$$, όπου $$dp[i][j]$$ είναι το ελάχιστο κόστος ώστε μετά από τους πρώτους $$i$$ θαλάμους να έχουμε τη θερμοκρασία $$a_j$$. Η αναδρομική σχέση αλλάζει (λίγο) σε:

$$dp[i][j] = \begin{cases} 
   dp[i-1][j] + 2 \cdot a_i & \text{if $a_i > a_j$,} \\
   \min_{k : a_k \geq a_i} dp[i-1][k] & \text{if $a_i = a_j$}, \\
   dp[i-1][j] + a_j - a_i & \text{otherwise,} \end{cases}$$
   
και η υλοποίηση γίνεται η εξής:

{% include code.md solution_name='anneal_n2_with_idx.cc' %}

Ο αλγόριθμος αυτός χρειάζεται $$\mathcal{O}(N^2)$$ χρόνο και μνήμη. Περνάει 14 από τα 18 testcases, λόγω μνήμης.


## Δυναμικός προγραμματισμός με τους δείκτες (και memoisation)

Μπορούμε να παρατηρήσουμε ότι για να συμπληρώσουμε την γραμμή $$dp[i][j]$$ χρησιμοποιούμε μόνο την γραμμή $$dp[i-1][\cdot]$$ (και όχι κάποια από τις προηγούμενες). Επομένως, μπορούμε να κρατήσουμε μόνο αυτή και να αλλάξουμε τον κώδικα ως εξής:

{% include code.md solution_name='anneal_n2_with_idx_and_mem.cc' start=20 end=30 %}

Ολόκληρος ο κώδικας είναι [εδώ]({% include link_to_source.md solution_name='anneal_n2_with_idx_and_mem.cc' %}).

**Σημείωση:** Στο δοσμένα testcases, αν κάνουμε τις τιμές $$a_i$$ μοναδικές (με ταξινόμηση και αφαίρεση των διπλών), τότε περνάει με μεγαλύτερη άνεση τα testcases. Μπορείτε να δείτε ολόκληρο τον κώδικα [εδώ]({% include link_to_source.md solution_name='anneal_n2_with_unique.cc' %}).
