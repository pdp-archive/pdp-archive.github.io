#include <stdio.h>
#include <string.h>

typedef struct tr *tree;
typedef struct tr
{
  char* sptr;
  int len, count;
  tree child, brother;
};

int n;
int cval, mmax;

char *names[1000000];
int len[1000000];
tree root;

tree initNewNode(char *sptr, int len, int count, tree child, tree brother) 
{
  tree newNode = new tr;
  newNode->sptr = sptr;
  newNode->len = len;
  newNode->count = count;
  newNode->child = child;
  newNode->brother = brother;
  return newNode;
}

void solve(tree t, const int depth)
{
  tree temp;
  for (temp=t->child; temp!=NULL; temp=temp->brother)
    {
      cval = temp->count*(depth+temp->len);
      if (cval>mmax)
	mmax=cval;
      solve(temp, depth+temp->len);
    }
}

int main(void)
{
  int i, j, l, k;
  char s[20100];
  bool add;
  tree p1, p2;

  tree t, temp;
  FILE *fin, *fout;
  fin = fopen("toponyms.in", "rt");
  fout = fopen("toponyms.out", "wt");
  
  fscanf(fin, "%d ", &n);
  
  root=initNewNode(NULL, 0, 0, NULL, NULL);                     // initializing the tree with a dummy root
  
  for (i=0; i<n; i++) {
    fgets(s, 20100, fin);
    l = strlen(s)-1; s[l]='\0';
    len[i] = l;
    names[i] = new char[l+1];
    strcpy(names[i], s);
    
    for (j=0, t=root; j < l; ) {
      add=true;
      for (temp = t->child; temp != NULL; temp=temp->brother)
	if (temp->sptr[0]==s[j]) {
	  for (k=1; k<temp->len && temp->sptr[k]==s[j+k]; k++); // find how many characters are equal
	  j+=k;
	  if (k==temp->len) {                                   // if all of them, then just traverse
	    t=temp;
	    add=false;
	  }
	  else {                                                // add a new point in the middle of the edge	    
	    p1 = initNewNode(temp->sptr+k, temp->len-k, temp->count, temp->child, NULL);	    
	    temp->len=k; temp->child=p1; 
	    t=temp;
	  }
	  temp->count++;
	  break;
	}
      if (add) {                                                // adding the remaining part
	p1 = initNewNode(names[i]+j, l-j, 1, NULL, t->child);	
	t->child=p1;
	break;
      }
    }
  }
  solve(root, 0);
  fprintf(fout, "%d\n", mmax);
  fclose(fin);
  fclose(fout);
  return 0;
}
