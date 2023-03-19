---
layout: solution
codename: filiki
---

## Επεξήγηση εκφώνησης 

Μας δίνεται ένα δέντρο (ριζωμένο στον κόμβο $$1$$) και ένας ακέραιος αριθμός $$K$$. Μας ζητείται να μαρκάρουμε $$K$$ κόμβους του δέντρου, έτσι ώστε η μέγιστη απόσταση ενός κόμβου προς τον κοντινότερο μαρκαρισμένο πρόγονό του να ελαχιστοποιείται.

## Λύση $$\mathcal{O}(\binom{N}{K} N)$$
Η λύση αυτή είναι μία πολύ αργή brute force. Μαντεύει κάθε πιθανό τρόπο να μαρκάρει $$K$$ κόμβους, και υπολογίζει κάθε φορά σε $$O(N)$$ χρόνο το κόστος.

Στα μαθηματικά, με $$\binom{N}{K}$$ συμβολίζουμε το πλήθος διαφορετικών τρόπων να μαρκάρουμε $$K$$ κόμβους. Διαβάζεται "$$N$$ ανά $$K$$", ή "$$N$$ choose $$K$$" στα αγγλικά. Από εκεί προκύπτει και η πολυπλοκότητα του αλγορίθμου μας.

Αν συμβολίσουμε με $$N!$$ το γινόμενο $$1\cdot 2\cdot 3 \cdot \ldots \cdot (N-1) \cdot N$$ (διαβάζεται N παραγοντικό), τότε ισχύει

$$\binom{N}{K} = \frac{N!}{K! \cdot (N-K)!}$$

Αυτή η λύση τρέχει για $$N\le 25$$ ($$10\%$$ των αρχείων ελέγχου), αφού το χειρότερο πιθανό $$K$$ είναι το $$12$$ και το $$13$$ (γενικότερα μεγιστοποιείται πάντα όταν το $$K$$ είναι το μισό του $$N$$), και έτσι έχουμε $$\binom{N}{K} N = \binom{25}{12} 25 = 5.200.300 \cdot 25 = 130.007.500$$, που είναι διαχειρίσιμο για έναν υπολογιστή μέσα σε ένα δευτερόλεπτο.

Ένας πιθανός κώδικας για να υλοποιήσετε αυτή τη λύση είναι ο εξής:

{% include code.md solution_name='filiki_brute.cc' %}

## Λύση $$\mathcal{O}(N^2K^2)$$ για δυαδικά δέντρα

Αυτή η λύση στηρίζεται στον δυναμικό προγραμματισμό (δείτε [εδώ](https://kallinikos.github.io/Dynamic-Programming)). Παρουσιάζουμε μία πρώτη σκέψη που μπορεί να κάνει κανείς, η οποία όμως έχει ένα πρόβλημα. Φανταστείτε ότι μας δίνεται ένας κόμβος $$u$$ και ένας αριθμός $$k\le K$$, και μας ζητείται να λύσουμε το εξής υποπρόβλημα: Αντί για το αρχικό δέντρο, έχουμε μόνο το υπόδεντρο του $$u$$, κι αντί για δυνατότητα $$K$$ μαρκαρισμάτων, μπορούμε να μαρκάρουμε μόνο $$k$$ κόμβους. Για παράδειγμα αν το αρχικό δέντρο είναι αυτό στα αριστερά, τότε το υποπρόβλημα που ορίζεται από τα $$u=3, k=2$$ θα ήταν αυτό στα δεξιά:

![](/assets/filikiDP_wrong.svg)

Αυτή είναι μια κλασική προσέγγιση δυναμικού προγραμματισμού σε δέντρα. Δυστυχώς εν προκειμένω δεν φαίνεται να λειτουργεί αποδοτικά. Η μόνη αναδρομή που μπορούμε να σκεφτούμε θα λειτουργούσε κάπως έτσι: πρώτα θα μάντευε όλους τους απογόνους του $$u$$ η οποίοι στην βέλτιστη λύση είναι μαρκαρισμένοι και για τους οποίους ο κοντινότερος μαρκαρισμένος τους πρόγονος είναι ο ίδιος ο $$u$$ (δηλαδή τίποτα ανάμεσά τους δεν είναι μαρκαρισμένο). Κατόπιν θα μάντευε πόσοι κόμβοι θα μαρκαριστούν στο υπόδεντρο του καθενός από αυτούς τους κόμβους, και μετά θα έκανε αναδρομή στο υπόδεντρό τους. Όμως οι μαντεψιές αυτές είναι πολύ ακριβές, και δεν εκμεταλλεύονται καθόλου τη δυαδική φύση του δέντρου. Έτσι, μια τέτοια προσέγγιση θα ήταν πολύ αργή.

Ιδανικά θα θέλαμε η αναδρομή μας να εξαρτάται μόνο από τα $$2$$ παιδιά του κόμβου $$u$$, έτσι ώστε να χρειάζονται πολύ λιγότερες μαντεψιές. Το πρόβλημα είναι ότι αν μαρκάρω τον $$u$$ και μετά κάνω αναδρομή σε ένα παιδί του $$v$$, πιθανώς να μη θέλω να μαρκάρω τον $$v$$. Αν όμως μετά (πάλι λόγω αναδρομής) πάω σε ένα παιδί $$w$$ (εγγόνι του $$u$$), τότε ο $$w$$ δεν θα ξέρει πώς να χρεωθεί, γιατί χρειάζεται να μάθει πρώτα τον κοντινότερο μαρκαρισμένο πρόγονό του. Στο παράδειγμα που αναφέρουμε θα έπρεπε να γνωρίζει ότι ο πρόγονος αυτός είναι ο $$u$$. Για τον λόγο αυτό, τροποποιούμε τον δυναμικό προγραμματισμό μας ώστε να γνωρίζουμε και τον κοντινότερο πρόγονο του $$u$$ ο οποίος είναι μαρκαρισμένος.

Ανακεφαλαιώνοντας, ο δυναμικός μας προγραμματισμός θα λειτουργεί ως εξής. Δεδομένου ενός κόμβου $$u$$, ενός προγόνου $$y$$ του $$u$$ και ενός αριθμού $$k\le K$$, πρέπει να λύσουμε το πρόβλημα στο υπόδεντρο του $$u$$, μαρκάροντας το πολύ $$k$$ κόμβους, και με δεδομένο ότι ο κοντινότερος πρόγονος του $$u$$ που είναι μαρκαρισμένος είναι ο $$y$$. Για παράδειγμα, αν το αρχικό δέντρο είναι αυτό στα αριστερά, τότε το υποπρόβλημα που ορίζεται από τα $$u=3, y=1, k=2$$ είναι το εξής:

![](/assets/filikiDP.svg)

Για συντομία θα περιγράφουμε ένα υποπρόβλημα ως $$[u,y,k]$$. Θέλουμε την λύση του $$[1,1,K]$$, την οποία θα υπολογίσουμε αναδρομικά. Θα γράφουμε επίσης $$L(u), R(u)$$ για να αναφερθούμε στο αριστερό και το δεξί παιδί του $$u$$.

Πώς λύνουμε λοιπόν το $$[u,y,k]$$; Απλά πρέπει να σκεφτούμε πολλές περιπτώσεις:
* Αν μαρκάρω τον $$u$$, τότε πληρώνω όσο η απόσταση του $$u$$ απ' τον $$y$$, και λύνω αναδρομικά τα $$2$$ υπόδεντρα. Επειδή δεν ξέρω όμως πόσους κόμβους να μαρκάρω σε κάθε υπόδεντρο, πρέπει να το μαντέψω. Δοκιμάζω λοιπόν να δώσω $$k'$$ κόμβους στο αριστερό υπόδεντρο, και τους υπόλοιπους $$k-k'-1$$ στο δεξί υπόδεντρο. Δοκιμάζω προφανώς όλες τις τιμές $$k'\le k-1$$. Αρκεί λοιπόν για όλες αυτές τις δοκιμές να λύσω τα $$[L(u), u, k']$$ και $$[R(u), u, k-k'-1]$$.
* Αν δεν μαρκάρω τον $$u$$ τότε πρέπει να κάνω τις ίδιες μαντεψιές για τα $$2$$ υπόδεντρα, αλλά αυτή τη φορά $$k'\le k$$ και το δεξί υπόδεντρο θα πάρει $$k-k'$$ πιθανά μαρκαρίσματα (επειδή ο $$u$$ έμεινε αμαρκάριστος). Επιπλέον, ο κοντινότερος πρόγονος που είναι μαρκαρισμένος παραμένει ο $$y$$, όχι ο $$u$$. Άρα καλούμαστε να λύσουμε τα $$[L(u), y, k']$$ και $$[R(u), y, k-k']$$.

Ο τρόπος με τον οποίο συνδυάζουμε τις λύσεις είναι αρκετά προφανής για όποιον έχει μια μικρή εξοικείωση με δυναμικό προγραμματισμό, και θεωρούμε ότι φαίνεται καλύτερα στον παρακάτω κώδικα. Η πολυπλοκότητα είναι $$\mathcal{O}(N^2K^2)$$, επειδή έχουμε $$\mathcal{O}(N^2K)$$ διαφορετικά υποπροβλήματα, και για το καθένα χρειαζόμαστε χρόνο $$\mathcal{O}(K)$$ για να δοκιμάσουμε όλα τα $$k'$$. 

{% include code.md solution_name='filiki_dp_binary.cc' %}

## Λύση $$\mathcal{O}(N^2K^2)$$ για γενικά δέντρα

Η λύση αυτή είναι πολύ ενδιαφέρουσα. Αντί να σκεφτούμε βαθύτερα το πρόβλημα, δείχνουμε απλώς έναν μετασχηματισμό του (γενικού) δέντρου μας σε δυαδικό δέντρο. Αυτή είναι μια γενική τεχνική που εφαρμόζουμε στον δυναμικό προγραμματισμό, καθώς τα δυαδικά δέντρα είναι πολύ πιο εύκολα.

Τι ακριβώς κάναμε στην παραπάνω εικόνα; Πολύ απλά, όποτε ο $$u$$ έχει παραπάνω από δύο παιδία, κρατάει μόνο ένα από αυτά ως το αριστερό του παιδί, και δημιουργεί ένα ψεύτικο νέο παιδί ως το δεξί του παιδί. Ο ψευδοκόμβος αυτός είναι υπεύθυνος για τα υπόλοιπα παιδιά του $$u$$, τα οποία τα δημιουργούμε ακριβώς με τον ίδιο τρόπο. Μια αναπαράσταση αυτή της διαδικασίας φαίνεται εδώ:

![](/assets/filiki_convertToBinary.svg)

Έτσι ο κώδικάς μας παραμένει ίδιος, με την διαφορά ότι μετασχηματίζουμε το δέντρο σε δυαδικό, όπως φαίνεται εδώ:

{% include code.md start=15 end=33 solution_name='filiki_dp.cc' %}

Επιπλέον προσθέτουμε τις εξής γραμμές μέσα στην main συνάρτηση:

{% include code.md start=68 end=69 solution_name='filiki_dp.cc' %}

και θυμόμαστε να διπλασιάσουμε το μέγεθος των πινάκων, επειδή το πλήθος κόμβων μπορεί να διπλασιαστεί.

Ο μετασχηματισμός γίνεται σε γραμμικό χρόνο, και το πλήθος κόμβων το πολύ να διπλασιαστεί. Επομένως η πολυπλοκότητα παραμένει $$\mathcal{O}(N^2K^2)$$.

## Λύση $$\mathcal{O}(N\log{(ΜΑX\_COST)})$$ για γενικά δέντρα

Η λύση αυτή ακολουθεί μια πολύ διαφορετική προσέγγιση. Είναι πολύ γενική και αξίζει να την έχετε πάντα στο μυαλό σας. Εν προκειμένω μας δίνεται το μέγιστο πλήθος μαρκαρισμάτων $$K$$, και προσπαθούμε να βελτιστοποιήσουμε το κόστος. Αξίζει πάντα να σκεφτόμαστε και το αντίστροφο πρόβλημα: τι θα κάναμε αν μας δίνανε ένα αποδεκτό κόστος $$C$$, και μας ζητούσανε να το πετύχουμε μαρκάροντας το ελάχιστο πλήθος κόμβων;

Γιατί αξίζει να σκεφτώ αυτό το αντίστροφο πρόβλημα; Επειδή μπορώ να λύσω το αρχικό μου πρόβλημα ως εξής: Υποθέτω ότι το βέλτιστο κόστος είναι $$0$$, και λύνω το αντίστροφο πρόβλημα. Αν το πλήθος κόμβων που χρειάζεται να μαρκάρω για να πετύχω κόστος $$0$$ είναι το πολύ $$K$$, τότε πράγματι το βέλτιστο κόστος είναι $$0$$. Αλλιώς, δοκιμάζω ξανά, αλλά αυτή τη φορά υποθέτω ότι το βέλτιστο κόστος είναι $$1$$. Συνεχίζω με αυτό τον τρόπο μέχρι να βρω τη σωστή απάντηση. Προσέξτε ότι αυτό μοιάζει με σειριακή αναζήτηση του βέλτιστου κόστους.

Παρατηρούμε όμως ότι οι δύο αυτές ποσότητες σχετίζονται άμεσα. Όσο περισσότερα μαρκαρίσματα έχω, τόσο μικρότερο κόστος μπορώ να πετύχω. Κι απ' την ανάποδη, όσο μεγαλύτερο είναι το αποδεκτό κόστος που μπορώ να πληρώσω, τόσο λιγότερους κόμβους χρειάζεται να μαρκάρω. Επομένως αντί για σειριακή αναζήτηση, μπορώ να κάνω [δυαδική αναζήτηση](https://www.topcoder.com/thrive/articles/Binary%20Search). Και πάλι φαντάζομαι το βέλτιστο κόστος, και κοιτάω αν έχω αρκετά μαρκαρίσματα ώστε να το πετύχω. Οι δοκιμές που κάνω όμως τώρα υπαγορεύονται από μία δυαδική αναζήτηση, αντί για μία σειριακή. Ο παρακάτω κώδικας κάνει ακριβώς αυτή τη δυαδική αναζήτηση, υποθέτωντας ότι ήδη ξέρουμε να λύνουμε το αντίστροφο πρόβλημα.

{% include code.md start=40 end=46 solution_name='filiki_bsearch.cc' %}

Βλέπουμε λοιπόν ότι αρκεί να λύσουμε το εξής πρόβλημα: Αν μας δίνεται ένα αποδεκτό κόστος $$C$$, ποιο είναι το ελάχιστο πλήθος κόμβων που χρειάζεται να μαρκάρω; Το καλό είναι ότι αυτό το πρόβλημα μπορεί να λυθεί άπληστα, σε γραμμικό χρόνο. Απλώς μαρκάρω τον πρώτο κόμβο, και μετά κατεβαίνω όσο πιο βαθιά μπορώ στο δέντρο, αρκεί να μην ξεπεράσω το αποδεκτό κόστος $$C$$. Όταν δεν μπορώ να προχωρήσω άλλο, απλώς μαρκάρω τον κόμβο στον οποίο έχω φτάσει, και συνεχίζω. Ο παρακάτω κώδικας υλοποιεί αυτή την άπληστη λογική:

{% include code.md start=9 end=20 solution_name='filiki_bsearch.cc' %}

Η τελική πολυπλοκότητα είναι $$\mathcal{O}(N\log{(ΜΑX\_COST)})$$ αφού έχουμε μία δυαδική αναζήτηση που κάνει $$\mathcal{O}(\log{(MAX\_COST)})$$ βήματα, και σε κάθε βήμα της κάνει $$O(N)$$ χρόνο για να υπολογίσει τη λύση στο αντίστροφο πρόβλημα. Παρακάτω δίνεται ολόκληρος ο κώδικας.

{% include code.md solution_name='filiki_bsearch.cc' %}