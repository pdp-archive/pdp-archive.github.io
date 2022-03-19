#undef DEBUG

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) do ; while(0)
#define NDEBUG
#endif

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <map>

using namespace std;

struct trie;
typedef map<char, struct trie*> trie_map;
struct trie { bool ex; trie_map m; };

void trie_add (trie* &t, const char s[])
{
  trie **p = &t;
  for (int i=0; s[i] != '\0'; i++) {
    if (*p == NULL)
      *p = new trie;
    p = &((*p)->m[s[i]]);
  }
  if (*p == NULL)
    *p = new trie;
  (*p)->ex = true;
}

#ifdef DEBUG
void trie_print (int ind, const trie* t)
{
  if (t != NULL) {
    if (t->ex) debug(" *\n"); else debug("\n");
    for (trie_map::const_iterator j = t->m.begin(); j != t->m.end(); j++) {
      for (int i=0; i<ind; i++) debug(" ");
      debug("%c", j->first);
      trie_print(ind+1, j->second);
    }
  }
}
#endif

#define S 1000
#define T 1000000

#define MOD 3141592653589793LLU

typedef unsigned long long int num;

num trie_walk (trie *t, const char *s, num c[], int ii)
{
  debug("trying to concat %s\n", s);
  num result = 0;
  for (int i=0; s[i] != '\0'; i++) {
    assert(t != NULL);
    trie_map::const_iterator j = t->m.find(s[i]);
    if (j == t->m.end()) {
      debug("  not found %c\n", s[i]);
      break;
    }
    debug("  found %c\n", s[i]);
    t = j->second;
    if (t == NULL)
      break;
    if (t->ex) {
#ifdef DEBUG
      debug("  using ");
      for (int j=0; j<i; j++)
        debug("%c", s[j]);
      debug("  : c[%d] = +%llu\n", ii+i+1, c[i+1]);
#endif
      result = (result + c[i+1]) % MOD;
    }
  }
  
  debug("  setting c[%d] = %llu\n", ii, result);
  return result;
}

char buf[S+1];
char t[T+1];
num dp[T+1];

int main ()
{
#ifdef CONTEST
  freopen("concat.in", "rt", stdin);
  freopen("concat.out", "wt", stdout);
#endif

  // input
  int N;
  scanf("%d\n", &N);
  trie *tr = NULL;
  for (int i=0; i<N; i++) {
    int k, c;
    for (k=0; (c = getchar()) != '\n'; k++)
      buf[k] = c;
    buf[k] = '\0';
    trie_add(tr, buf);
#ifdef DEBUG
    debug("adding: '%s'\n", buf);
    debug("trie:");
    trie_print(0, tr);
#endif
  }

  int k, c;
  for (k=0; (c = getchar()) != '\n'; k++)
    t[k] = c;
  t[k] = '\0';
  // solve in O(T*S)
  /* dp[i] == in how many ways it is possible to express the
              suffix of t starting at char i as a concatenation
              of the given strings
     dp[0] is the answer we're looking for
  */
  dp[k] = 1;
  for (int i=k-1; i>=0; i--)
    dp[i] = trie_walk(tr, t+i, dp+i, i);
  // answer
  printf("%llu\n", dp[0]);
  return 0;
}
