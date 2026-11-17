/* Dimitris Fotakis
   Nikolaos S. Papaspyrou */

/*
(Για τη λύση του συγκεκριμένου προβλήματος – κύκλος Hamilton - υπάρχουν περισσότερες από μία ορθές λύσεις. Ο χρόνος που απαιτείται για την εξαγωγή των αποτελεσμάτων, εξαρτάται από τα test cases. Επειδή για τα συγκεκριμένα test cases κανένας μαθητής δεν έδωσε λύση που να λύνει τουλάχιστον το 50% αυτών εντός χρόνου, δίνεται στη δημοσιότητα μια από τις δυνατές λύσεις που για τα συγκεκριμένα tests, απαιτεί χρόνο πολύ μικρότερο από 20 sec για πάνω από το 50% των tests)
*/

#define DEBUG
#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) do ; while(0)
#define NDEBUG
#endif
 
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>
#define NILL (-1)
#define INF ((long) (LONG_MAX))
#define NONE (-1)
#define VISITED 0
#define UNVISITED 1
#define EXPLORED 2

  
void randomize ()
{
  time_t t1;
  (void) time(&t1);
  srand((long) t1); /* use time in seconds to set the seed */
}

/* Implements a FIFO queue for use with BFS */
typedef struct _elem {
  int id;
  struct _elem *next;
} elem;
elem *head = NULL, *tail = NULL;


void addToQueue (int v)
{
  elem *last;
  if ((last = (elem *)malloc(sizeof(elem))) == NULL) {
    fprintf(stderr, "Out of memory!\n");
    exit(1);
  }
  last->id = v;
  last->next = NULL;
  if (tail != NULL) tail->next = last;
  tail = last;
  if (head == NULL) head = last;
}


int extractFromQueue ()
{
  elem *first;
  int res;
  if (head == NULL) return(NILL);
  first = head;
  res = first->id;
  head = first->next;
  if (head == NULL) tail = NULL;
  free(first);
  return res;
}

/* Data type definitions for adjacency list */
typedef struct _edge {
  int id;
  struct _edge *next;
} Edge;

typedef struct _node {
  Edge *head;
  Edge *tail;
  int prevInCycle;
  int nextInCycle;
  int inCycle;
  int degree;
} Node;

typedef Node * List;

/* Creates an edge */

Edge *initEdge (int id)
{
  Edge *e;
  if ((e =(Edge *)malloc(sizeof(Edge))) == NULL) {
    fprintf(stderr, "Out of memory!\n");
    exit(1);
  }
  e->next = NULL;
  e->id = id;
  return e;
}

/* Reads a graph from filename and creates its adjacency list */
/* Initializes N (#vertices) and M (#edges) and returns the list */

List readGraph(FILE *fp, int *N, int *M)
{
  Edge *lastV1, *lastV2;
  int i, n = 0, v1, v2;
  List G;
  fscanf(fp, "%d\n", M);
  if ((G = (List) malloc((*M)*sizeof(Node))) == NULL) {
    fprintf(stderr, "Out of memory!\n");
    exit(1);
  }
  for (i = 0; i < *M; i++) {
    G[i].head = G[i].tail = NULL;
    G[i].nextInCycle = G[i].prevInCycle = NONE;
    G[i].degree = G[i].inCycle = 0;
  }
  for (i = 0; i < *M; i++) {
    fscanf(fp, "%d %d\n", &v1, &v2);
    if (n < v1) n = v1;
    if (n < v2) n = v2;
    v1--; v2--;
    lastV1 = initEdge(v2); G[v1].degree++;
    lastV2 = initEdge(v1); G[v2].degree++;
    if (G[v1].head == NULL)
      G[v1].head = G[v1].tail = lastV1;
    else
      G[v1].tail = G[v1].tail->next = lastV1;
    if (G[v2].head == NULL)
      G[v2].head = G[v2].tail = lastV2;
    else
      G[v2].tail = G[v2].tail->next = lastV2;
  }
  *N = n;
  if ((G = (List) realloc(G, n*sizeof(Node))) == NULL) {
    fprintf(stderr, "Error in realloc!\n");
    exit(1);
  }
  return G;
}


bool degree_lt_2 (List G, int N)
{
  int i;
  for (i = 0; i < N; i++)
    if (G[i].degree < 2)
      return true;
  return false;
}


bool not_connected (List G, int N)
{
  int s, cc = 0, v;
  Edge *e;
  int *m;
  if ((m = (int *) malloc(N*sizeof(int))) == NULL) {
    fprintf(stderr, "Out of memory!\n");
    exit(1);
  }
  for (s = 0; s < N; s++)
    m[s] = UNVISITED;
  for (s = 0; s < N; s++) {
    if (m[s] == EXPLORED) continue;
    addToQueue(s);
    m[s] = VISITED; cc++;
    while ((v = extractFromQueue()) != NILL) {
      m[v] = EXPLORED;
      for (e = G[v].head; e != NULL; e = e->next)
        if (m[e->id] == UNVISITED) {
          addToQueue(e->id);
          m[e->id] = VISITED;
        }
    }
  }
  return cc > 1;
}


int extension_rotation (List G, int N)
{
  long iter, maxIter = (long) (((double) N)*(pow(log((double)N), 4)));
  int inVert = 1, cur, last, rotv, i, k, ofs, tmp, first;
  Edge *p;
  cur = rand() % N;
  G[cur].inCycle = 1;
  first = cur;
  for (iter=0; inVert <= N && iter < maxIter; iter++) {
    /* complete a Hamiltonian path to a cycle */
    if (inVert == N)
      for (p = G[cur].head; p != NULL; p = p->next)
        if (G[p->id].prevInCycle == NONE) {
          G[p->id].prevInCycle = cur;
          return(inVert+1);
        }
    /* extension phase */
    for (p = G[cur].head, k = 0; !k && p != NULL; p = p->next)
      if (G[p->id].inCycle == 0) {
        G[p->id].inCycle = 1;
        G[p->id].prevInCycle = cur;
        G[cur].nextInCycle = p->id;
        cur = p->id;
        inVert++;
        k = 1;
      }
    /* rotation phase */
    if (!k) {
      do {
        ofs = (rand() % G[cur].degree);
        for (p = G[cur].head; ofs > 0; ofs--)
          p = p->next;
        rotv = p->id;
      } while (rotv == G[cur].prevInCycle);
      if (rotv == first) {
        first = G[rotv].nextInCycle;
        G[rotv].nextInCycle = NONE;
        G[rotv].prevInCycle = cur;
        G[cur].nextInCycle = rotv;
        G[first].prevInCycle = NONE;
        cur = rotv;
      }
      else {
        last = G[rotv].nextInCycle;
        G[rotv].nextInCycle = cur;
        G[cur].nextInCycle = rotv;
        i = G[last].nextInCycle;
        G[last].nextInCycle = NONE;
        G[last].prevInCycle = i;
        do {
          tmp = G[i].nextInCycle;
          G[i].nextInCycle = G[i].prevInCycle;
          G[i].prevInCycle = tmp;
          i = tmp;
        } while (i != rotv);
        cur = last;
      }
    }
  }
  return inVert;
}


int main ()
{
  FILE * fin = fopen("code.in", "rt");
  FILE * fout = fopen("code.out", "wt");
  int N, M, res, i;
  int iter = 0, maxIter = 40;
  List G;
  assert(fin != NULL);
  assert(fout != NULL);
  G = readGraph(fin, &N, &M);
  if (degree_lt_2(G, N) || not_connected(G, N))
    fprintf(fout, "0\n");
  else {
    randomize();
    do {
      if ((res = extension_rotation(G, N)) == N+1) break;
      iter++;
      for (i = 0; i < N; i++) {
        G[i].nextInCycle = G[i].prevInCycle = NONE;
        G[i].inCycle = 0;
      }
    } while (iter < maxIter);
    if (res == N+1) {
      fprintf(fout, "1\n");
      for (i = G[0].nextInCycle; i != 0; i = G[i].nextInCycle)
        fprintf(fout, "%d\n", i+1);
    }
    else
      fprintf(fout, "0\n");
  }
  fclose(fin);
  fclose(fout);
  return 0;
}

