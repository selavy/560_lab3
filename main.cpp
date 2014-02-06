#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "Timer.hpp"

using namespace std;

//#define _PRINT_LIST_
//#define _PART_1_
#define _PART_2_
#define NUM_TESTS 10

#ifdef _PART_1_
#define N 200000
#define _RAND_SEED_
#endif

#ifdef _PART_2_
#define N2 400000
#endif

double remove_dups( int * arr, int n );

int main( int argc, char ** argv )
{
#ifdef _PART_1_
  // BEGIN PART 1

  int arr[N];
  double times[NUM_TESTS];

#ifdef _RAND_SEED_
  srand( time( NULL ) );
#else
  srand( 5 );
#endif
 
  for( int i = 0; i < NUM_TESTS; ++i )
    {
      for( int j = 0; j < N; ++j )
	{
	  arr[j] = (rand() % 80001) - 40000; // number between -40,000 and 40,000
	}
      
      times[i] = remove_dups( arr, N );
      cout << "Run #" << i + 1 << ": ";
      printf( "%5.3f seconds\n", times[i] );
    }

  // END PART 1
#endif

  // BEGIN PART 2
#ifdef _PART_2_
  int arr2[N2];
  double times2[NUM_TESTS];
  srand( 10 ); // seed with 10 per specifications
  
  for( int i = 0; i < NUM_TESTS; ++i )
    {
      for( int j = 0; j < N2; ++j )
	{
	  arr2[j] = (rand() % 160001) - 80000; // number between -80,000 and 80,000
	}

      times2[i] = remove_dups( arr2, N2 );
      cout << "Run #" << i + 1 << ": ";
      printf("%5.3f seconds\n", times2[i] );
    }

#endif
  return 0;
}

double remove_dups( int * arr, int n ) {
  Timer aTimer;
  aTimer.start();

  int last = n;
  for( int i = 0; i < last; ++i )
    {
      for( int j = (i + 1); j < last; ++j )
	{
	  if( arr[i] == arr[j] )
	    {
	      last--;
	      for( int k = j; k < last; ++k )
		{
		  arr[k] = arr[k+1];
		}
	      j--;
	    }
	}
    }
  
  aTimer.stop();

#ifdef _PRINT_LIST_
  for( int i = 0; i < last; ++i )
    {
      cout << arr[i] << " ";
    }
  cout << endl;
#endif

  return aTimer.getDuration();
}
