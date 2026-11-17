/* Κυριάκος Ίσπογλου (2ο ΓΕΛ Κοζάνης) */

#include <stdio.h>
#include <string.h>

int L, C, i, c;
char *PV, *VP, *bkp, key;

int main( void )
{
  FILE *in = fopen("Alexander.in", "r" );
  FILE *out = fopen("Alexander.out", "w" );

  fscanf( in, "%d %d %c", &L, &C, &key );
  fclose( in );

  PV = new char[ 2*12000 + 3 ];
  VP = new char[ 2*12000 + 3 ];

  memset( PV, 'P', C );
  for( i=1; i<C; i+=2 ) PV[ i ] = 'V';
  PV[ C ] = '\n';
  PV[ C + 1 ] = '\0';

  memset( VP, 'V', C );
  for( i=1; i<C; i+=2 ) VP[ i ] = 'P';
  VP[ C ] = '\n';
  VP[ C + 1 ] = '\0';
 
  if( key == 'V' )
  {
    bkp = PV; PV = VP; VP = bkp;
  }

  strcat( PV, VP );

  for( c=2*C+2, i=0; i<L-1; i+=2 )
  {
    fwrite( PV, c, 1, out );
  }

  if( L % 2 )
  {
    fwrite( PV, C, 1, out );
  }

  delete [] VP;
  delete [] PV;

  fclose( out );
  return 0;
}

