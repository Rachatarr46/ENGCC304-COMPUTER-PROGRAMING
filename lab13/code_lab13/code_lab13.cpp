#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Employee {
   char name [ 100 ] ;
   float salary ;
}typedef Em ;

int main() {
   Em User [ 100 ] ;
   char *name ;
   float *money ; 
   char chack [ 10 ] = "-1" ;
   int No = 1 ;
   int stop = 1 ;
   int i = 0 ;
   float sum  = 0 ;
   float max = -99999 ;

   while( stop != 0 ) {
      printf( "Employee %d's Name : " , No ) ;
      scanf( "%s" , &User[ No ].name ) ;
      name = User[ No ].name ;
      stop = strcmp( name , chack ) ;
      if( stop == 0 ) {
         break;
      }
      printf( "Salary (Baht/Month) : " ) ;
      scanf( "%f" , &User[ No ].salary ) ;
      No++;
   }
   
   for( i = 0 ; i < No  ; i++ ) {
		sum = sum + User[ i ].salary ;
		if ( User[ i ].salary > max ) {
			max = User[ i ].salary ;
			name = User[ i ].name ;
			money = &( User[ i ].salary ) ;
      }
   }

   printf( "------------------------------------------\n") ;
	printf( "All salary per month : %.2f Bath\n", sum) ;
	printf( "All salary per year : %.2f Bath\n", sum*12) ;
	printf( "Tax (7%% per year) : %.2f Bath\n", sum*12*7/100) ;
	printf( "Most tax in company : %s( %.2f Bath per year)", name, *money*12*7/100 ) ;
}// end function
