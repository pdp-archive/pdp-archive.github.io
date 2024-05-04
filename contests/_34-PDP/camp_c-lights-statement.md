---
layout: statement
codename: lights
---

Έστω $$N$$ λαμπτήρες, τοποθετημένοι στη σειρά ο ένας δίπλα στον άλλο και αριθμημένοι από το $$1$$ μέχρι το $$N$$. Κάποιοι από αυτούς τους λαμπτήρες είναι αρχικά αναμμένοι και οι υπόλοιποι σβηστοί. Ο σκοπός μας είναι να σβήσουμε όλους τους λαμπτήρες (ξέρετε πόσο έχει ακριβύνει το ρεύμα τελευταία), αυτό όμως θα φανεί κάπως δύσκολο γιατί δεν ξέρουμε ποιοι ακριβώς είναι αναμμένοι.

Το πρόβλημα αυτό είναι διαφορετικό και μπορείτε να το φανταστείτε σαν ένα παιχνίδι πολλών ανεξάρτητων γύρων, σε καθέναν από τους οποίους πρέπει να βρείτε τον τρόπο να σβήσετε όλους τους λαμπτήρες κάνοντας μία κατάλληλη σειρά κινήσεων το πλήθος των οποίων δεν πρέπει να υπερβαίνει κάποιο δοθέντα αριθμό $$Q$$. Ο κώδικας που θα γράψετε πρέπει να καλεί τις συναρτήσεις με τις παρακάτω επικεφαλίδες, που θα βρίσκονται στο ``#include "lightslib.h"``:

```c++
pair<int, int> getNQ();
int move(int left, int right);
bool finish();
```

Συγκεκριμένα:
 - Η συνάρτηση $$\texttt{getNQ()}$$ επιστρέφει ένα ζεύγος θετικών ακεραίων: το συνολικό πλήθος $$N$$ των λαμπτήρων και το μέγιστο πλήθος $$Q$$ των επιτρεπόμενων <!-- Διόρθωση του: επιτρεπόμενο --> κινήσεων. Πρέπει να <!-- Διόρθωση: δεν υπήρχε το να --> καλείται ακριβώς μία φορά στην αρχή κάθε γύρου.
 - Η συνάρτηση $$\texttt{move(left, right)}$$ εναλλάσσει την κατάσταση των λαμπτήρων που βρίσκονται μεταξύ των θέσεων $$\texttt{left}$$ και $$\texttt{right}$$, συμπεριλαμβανομένων. Δηλαδή, για κάθε λαμπτήρα $$i$$ τέτοιον ώστε $$\texttt{left} \leq i \leq \texttt{right}$$, ο λαμπτήρας $$i$$ σβήνει αν προηγουμένως ήταν αναμμένος, ή ανάβει αν προηγουμένως ήταν σβηστός. Η συνάρτηση επιστρέφει το συνολικό πλήθος των λαμπτήρων που είναι αναμμένοι μετά την ολοκλήρωση αυτής της κίνησης. Οι τιμές των παραμέτρων πρέπει να ικανοποιούν τη σχέση $$1 \leq \texttt{left} \leq \texttt{right} \leq N$$. 
 - Η συνάρτηση $$\texttt{finish()}$$ πρέπει να καλείται τουλάχιστον μία φορά στον τέλος κάθε γύρου, όταν όλοι οι λαμπτήρες είναι σβηστοί. Προκαλεί το τέλος του γύρου. Επιστρέφει $$\texttt{false}$$ αν το παιχνίδι δεν έχει ακόμα τελειώσει (δηλαδή το πρόγραμμά σας πρέπει να συνεχίσει σε επόμενο γύρο), ή $$\texttt{true}$$ αν το πρόγραμμά σας πρέπει να σταματήσει την εκτέλεσή του.

Για το πρόβλημα αυτό δεν υπάρχουν δεδομένα εισόδου και δεδομένα εξόδου. Η επικοινωνία του προγράμματος σας με τον grader γίνεται μόνο μέσω των παραπάνω τριών συναρτήσεων.

| Το πρόγραμμά σας καλεί | Η συνάρτηση επιστρέφει | Περιγραφή |
| :--- | :--- | :--- |
| $$\texttt{getNQ}()$$ | $$\texttt{(5, 15)}$$ | Αρχίζει ο 1ος γύρος με $$N = 5$$ λαμπτήρες και επιτρέπονται το πολύ $$Q = 15$$ κινήσεις. Ας υποθέσουμε ότι η αρχική κατάσταση είναι:<br><center><img width="35px" src="/assets/34-camp-lights-lightbulb-off.svg"/><img width="35px" src="/assets/34-camp-lights-lightbulb-on.svg"/><img width="35px" src="/assets/34-camp-lights-lightbulb-on.svg"/><img width="35px" src="/assets/34-camp-lights-lightbulb-on.svg"/><img width="35px" src="/assets/34-camp-lights-lightbulb-off.svg"/><center> |
| $$\texttt{move(1, 3)}$$ | $$\texttt{2}$$ | Οι τρεις πρώτοι λαμπτήρες έχουν αλλάξει κατάσταση και είναι αναμμένοι $$2$$ λαμπτήρες.<br><center><img width="35px" src="/assets/34-camp-lights-lightbulb-on.svg"/><img width="35px" src="/assets/34-camp-lights-lightbulb-off.svg"/><img width="35px" src="/assets/34-camp-lights-lightbulb-off.svg"/><img width="35px" src="/assets/34-camp-lights-lightbulb-on.svg"/><img width="35px" src="/assets/34-camp-lights-lightbulb-off.svg"/><center> |
| $$\texttt{move}(2,4)$$ | $$\texttt{3}$$ | <center><img width="35px" src="/assets/34-camp-lights-lightbulb-on.svg"/><img width="35px" src="/assets/34-camp-lights-lightbulb-on.svg"/><img width="35px" src="/assets/34-camp-lights-lightbulb-on.svg"/><img width="35px" src="/assets/34-camp-lights-lightbulb-off.svg"/><img width="35px" src="/assets/34-camp-lights-lightbulb-off.svg"/><center> |
| $$\texttt{move}(1,3)$$ | $$\texttt{0}$$ | <center><img width="35px" src="/assets/34-camp-lights-lightbulb-off.svg"/><img width="35px" src="/assets/34-camp-lights-lightbulb-off.svg"/><img width="35px" src="/assets/34-camp-lights-lightbulb-off.svg"/><img width="35px" src="/assets/34-camp-lights-lightbulb-off.svg"/><img width="35px" src="/assets/34-camp-lights-lightbulb-off.svg"/><center> |
| $$\texttt{finish}()$$ | $$\texttt{false}$$ | Ο 1ος γύρος τελείωσε επιτυχώς και θα υπάρξει και επόμενος. |
