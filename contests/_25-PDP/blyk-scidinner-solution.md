---
layout: solution
codename: scidinner
---

*Δυστυχώς η παρακάτω λύση είναι πιο περίπλοκη από ότι θα έπρεπε, επειδή θεωρεί ότι μπορεί να υπάρχουν παραπάνω από ένα $$x$$ που δείχνουν στο ίδιο $$y$$. Θα προσπαθήσουμε να την ανανεώσουμε όταν βρούμε χρόνο.*

## Επεξήγηση εκφώνησης
Μας δίνονται $$Μ$$ σχέσεις της μορφής $$x \to y$$, που σημαίνει ότι ο αριθμός του $$x$$ (ας τον ονομάζουμε $$n_x$$), διαιρεί τον αριθμό του $$y$$, δηλαδή $$n_x \shortmid n_y$$. Αυτές οι σχέσεις ορίζουν έναν κατευθυνόμενο γράφο. Παρακάτω θα δείξουμε ότι ο γράφος είναι ακυκλικός και πώς το πλήθος των ομάδων που χρειάζονται είναι ίσο με το μήκος του μεγαλύτερου μονοπατιού σε αυτό τον γράφο. 


## Μαθηματική απόδειξη
Θα αποδείξουμε κάποιες ιδιότητες που έχει αυτός ο γράφος. 

**Θεώρημα:** Αν υπάρχει ένα μονοπάτι από το $$a_1 \to \ldots \to a_k$$, τότε $$a_1 \shortmid a_k$$.

*Απόδειξη* Η ύπαρξη του μονοπατιού μας δίνει ότι $$a_1 \shortmid a_2$$, $$a_2 \shortmid a_3$$, ... , $$a_{k-1} \shortmid a_k$$. Κάθε μία από αυτές τις σχέσεις σημαίνει ότι υπάρχει σταθερά $$c_i$$ ώστε $$a_{i+1} = c_i a_{i}$$. Συνεπώς,

$$a_k = c_{k-1} a_{k-1} = c_{k-1} c_{k-2} a_{k-2} = \ldots = (c_{k-1} c_{k-2} \ldots c_1) a_1$$

Επομένως, το $$a_1 \shortmid a_k$$.

**Θεώρημα:** Ο γράφος δεν έχει κύκλο.

*Απόδειξη* Η εκφώνηση μας λέει ότι δεν υπάρχουν δύο επιστήμονες με τους ίδιους αριθμούς. Αν υπήρχε κύκλος, έστω $$a_1 \to \ldots \to a_k \to a_1$$, τότε από το παραπάνω θεώρημα $$a_1 \shortmid a_k$$ και $$a_1k \shortmid a_1$$. Επομένως, $$a_1 = a_k$$ , άτοπο.

Συνεπώς, αυτό αποδεικνύει ότι έχουμε έναν γράφο που είναι κατευθυνόμενος και ακυκλικός. Τέτοιοι γράφοι έχουν την ιδιότητα ότι υπάρχει μία *τοπολογική διάταξη* των κορυφών. Αυτό σημαίνει ότι μπορούμε να βάλουμε τις κορυφές στη σειρά ώστε όλες οι ακμές να πηγαίνουν από τα αριστερά προς τα δεξιά.


**Θεώρημα:** Αν έχουμε χωρίσει τους επιστήμονες σε ομάδες ώστε σε καμία ομάδα να μην έχει επιστήμονες που να συνδέονται (έμμεσα ή άμεσα), τότε υπάρχουν αριθμοί ώστε οι ομάδες να είναι σωστές.

*Απόδειξη* Πρέπει να βρούμε αριθμούς ώστε να δείξουμε ότι για δύο επιστημόνες της ίδιας ομάδας, δεν γίνεται ο αριθμός του ενός να διαιρεί τον αριθμό του άλλου. Διαλέγουμε $$N$$ διαφορετικούς πρώτους αριθμούς $$p_1, \ldots, p_N$$. Ορίζουμε τον αριθμό $$n_v$$ κάθε επιστήμονα ως το γινόμενο όλων των αριθμών των εισερχόμενων γειτόνων του και ενός μοναδικού πρώτου.

![ValueCalculationExample](/assets/25-pdp-scidinner-value-graph.svg)

Ή πιο μαθηματικά:
$$n_v = p_v \prod_{u \in \mathit{in}(v)} n_u$$
όπου $$p_v$$ είναι ο μοναδικός πρώτος της κορυφής $$v$$.

O μοναδικός τρόπος ώστε $$v_k \shortmid v_n$$, είναι αν $$p_k \shortmid v_n$$. Αφού το $$p_k$$ είναι μοναδικός πρώτος, υπάρχει ένα μονοπάτι από το $$k$$ στο $$n$$, που δεν γίνεται λόγω υπόθεσης.  

Αν ο γράφος, δεν είναι συνεκτικός μπορούμε να ενώσουμε τις ομάδες από μη-συνδεδεμένα υπογραφήματα, αφού οι επιστήμονες αυτών δεν αλληλεπιδρούν.

**Θεώρημα:** Το ελάχιστο πλήθος ομάδων είναι ίσο με το μήκος του μεγαλύτερου μονοπατιού στον γράφο. 

*Απόδειξη* Για κάθε επιστήμονα $$v$$ χωρίς εισερχόμενη ακμή ορίζουμε $$\mathit{max\_path}[v] = 1$$ και για κάθε άλλον επιστήμονα $$u$$, το ορίζουμε ως το μέγιστο από όλες τις εισερχόμενες κορυφές συν 1, ή πιο μαθηματικά

$$\mathit{max\_path}[u] = 1 + \max_{k \in \mathit{in}(u)} \mathit{max\_path}[k]$$

Βάζουμε όλους τους επιστήμονες με το ίδιο $$\mathit{max\_path}$$ στην ίδια ομάδα. Για παράδειγμα, στο πρώτο αρχείο εισόδου οι τιμές $$\mathit{max\_path}$$ φαίνονται με κόκκινο στο παρακάτω σχήμα. Οι ομάδες που δημιουργούνται είναι οι $$\lbrace 1, 4 \rbrace$$, $$\lbrace 3, 5, 6, 12 \rbrace$$, $$\lbrace 7, 10, 11 \rbrace$$, $$\lbrace 8 \rbrace$$ και $$\lbrace 9 \rbrace$$.

![MaxPathExample](/assets/25-pdp-scidinner-depth-graph.svg)

Θα δείξουμε ότι δύο επιστήμονες της ίδιας ομάδας δεν γίνεται να συνδέονται. Από το παραπάνω θεώρημα αυτό σημαίνει ότι οι ομάδες είναι καλές. 

Έστω ότι υπάρχει μονοπάτι που συνδέει $$u \to a_1 \to \ldots \to a_m \to v$$ που ανήκουν στην ίδια ομάδα. Τότε,

$$\mathit{max\_path}[v] \geq \mathit{max\_path}[u] + m + 1 \implies \mathit{max\_path}[v] > \mathit{max\_path}[u]$$

που σημαίνει ότι δεν είναι στην ίδια ομάδα (άτοπο). 

Αυτό είναι το ελάχιστο πλήθος συνόλων, καθώς αν θεωρήσουμε το μακρύτερο μονοπάτι $$a_1 \to \ldots \to a_m$$, τότε κανένας επιστήμονας δεν μπορεί να τοποθετηθεί στο ίδιο σύνολο (γιατί θα υπήρχε μονοπάτι μεταξύ αυτών, που δεν επιτρέπεται από το παραπάνω θεώρημα).


## Υλοποίηση
Υπάρχουν δύο κλασικοί τρόποι υλοποίησης της εύρεσης τοπολογικής διάταξης: αναδρομικά και γραμμικά. Ο γραμμικός τρόπος έχει το πλεονέκτημα ότι χρησιμοποιεί μικρότερη στοίβα κλήσεων (διαφορά ενός testcase στον διαγωνισμό). 

Όταν βρούμε την τοπολογική διάταξη, υπολογίζουμε το $$\mathit{max\_path}[u]$$ για κάθε κορυφή $$u$$ με τον παραπάνω τύπο και με την τοπολογική σειρά, καθώς όταν επεξεργαστούμε μία κορυφή θα έχουμε ήδη επεξεργαστεί όλες τις κορυφές με εισερχόμενες ακμές.

### Αναδρομική υλοποίηση

```c++

#include <stdio.h>
#include <vector>

const size_t MAXN = 1000000;

std::vector<long> v[MAXN+1];

std::vector<long> topo_sort;
bool visited[MAXN + 1];
long max_path[MAXN + 1];

void dfs(long u) {
   for (const auto& neigh : v[u]) {
      if (!visited[neigh]) {
         visited[neigh] = true;
         dfs(neigh);
      }
   }
   topo_sort.push_back(u);
}

int main() {
   long N, M;
   FILE *fi = fopen("scidinner.in", "r");
   fscanf(fi, "%ld%ld", &N, &M);
   for (long i = 0; i < M; ++i) {
      long a, b;
      fscanf(fi, "%ld%ld", &a, &b);
      v[a].push_back(b);
   }
   fclose(fi);
   
   for (long i = 1; i <= N; ++i) {
      if (!visited[i]) {
         visited[i] = true;
         dfs(i);
      }
   }
   
   long max_max_path = 0;
   for (long i = 0; i < topo_sort.size(); ++i) {
      long u = topo_sort[i];
      for (const auto& neigh : v[u]) {
         max_path[u] = std::max(max_path[u], max_path[neigh] + 1);
      }
      max_max_path = std::max(max_max_path, max_path[u]);
   }
   
   FILE *fo = fopen("scidinner.out", "w");
   fprintf(fo, "%ld\n", max_max_path + 1);
   fclose(fo);
   
   return 0;
}

```

### Γραμμική υλοποίηση

```c++
#include <stack>
#include <stdio.h>
#include <vector>

const size_t MAXN = 1000000;

std::vector<long> v[MAXN+1];

std::vector<long> topo_sort;
bool triggered[MAXN + 1];
long max_path[MAXN + 1];

void dfsIterative(long begin) {
   std::stack<std::pair<long, bool>> s;
   s.push(std::make_pair(begin, false));
   while(!s.empty()) {
      long u = s.top().first;
      bool was_trigger_point = s.top().second;
      s.pop();
      if (was_trigger_point) {
         topo_sort.push_back(u);
         continue;
      }
      if (!triggered[u]) {
         triggered[u] = true;
         s.push(std::make_pair(u, true));
         for (const auto& neigh : v[u]) {
            if (!triggered[neigh]) {
               s.push(std::make_pair(neigh, false));
            }
         }
      }
   }
}

int main() {
   long N, M;
   FILE *fi = fopen("scidinner.in", "r");
   fscanf(fi, "%ld%ld", &N, &M);
   for (long i = 0; i < M; ++i) {
      long a, b;
      fscanf(fi, "%ld%ld", &a, &b);
      v[a].push_back(b);
   }
   fclose(fi);
   
   for (long i = 1; i <= N; ++i) {
      if (!triggered[i]) {
         dfsIterative(i);
      }
   }
   
   long max_max_path = 0;
   for (long i = 0; i < topo_sort.size(); ++i) {
      long u = topo_sort[i];
      for (const auto& neigh : v[u]) {
         max_path[u] = std::max(max_path[u], max_path[neigh] + 1);
      }
      max_max_path = std::max(max_max_path, max_path[u]);
   }
   
   FILE *fo = fopen("scidinner.out", "w");
   fprintf(fo, "%ld\n", max_max_path + 1);
   fclose(fo);
   
   return 0;
}
```
