#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Employee {
   char Name[ 100 ] ;
   float Salary ;
   int Duration ;
} typedef Em ;

void InputEmpolyee( Em[] , int ) ;
void Average( Em[] , int ) ;
void Most_Salary( Em[] , int ) ; 
    
int main() {   
   int check = 1 ;      
   setlocale( LC_ALL,"" ) ;
   Em A[ 512 ] ;
   int Pos = 0 ;
   int i = 0 ;
   char input ;
   while ( check ) {
      printf( "\nDo you want to Enter Employee information? (y / n) : " ) ;
      scanf( " %c" , &input ) ;
      if ( input == 'y' ) {
         InputEmpolyee( A , i ) ;
            Pos = i + 1 ;
            i++;
      }else if ( input == 'n' ) {
         check = 0 ;
            Average( A , i ) ;
            Most_Salary( A , i ) ;
      }// end if
   }//end while
   return 0 ; 
}// end function

void InputEmpolyee( Em InputEm[] , int i ) {
   char Name[100];
   getchar();
   printf( "Employee Name : " ) ;
   gets( InputEm[i].Name ) ;
   printf( "Salary (Baht/Month) : " ) ;
   scanf( "%f" , &InputEm[ i ].Salary ) ;
   printf( "Duration (Year) : " ) ;
   scanf( "%d" , &InputEm[ i ].Duration ) ;
}// end function

void Average( Em InputEm[] , int Pos ) {
   float sum  = 0 ;
   for ( int i = 0 ; i < Pos ; i++ ){
      sum = sum + InputEm[ i ].Salary ;
   }// end for
   printf( "\nAverage of Salary : %'.2f " , sum / Pos ); 
   printf( "Baht\n" ); 
   printf( "Payment of every month : %'.2f " , sum ); ;
   printf( "Baht\n" );
}// end function

void Most_Salary( Em InputEm[] , int Pos ) {
   int max = 0 ;
   int most = 0 ;
   int max_salary_check = 0 ;
   int salary ;
   for ( int i = 0 ; i < Pos ; i++ ) {
      salary = InputEm[ i ].Salary ;
      max = max_salary_check < salary ;
      if ( max = 1 ) {
         most = i ;
         max_salary_check = salary ;
      }// end if
   }// end for
   printf( "** Most salary in this business **\n" );
   printf( "Name : %s (%d Years)\n" , InputEm[ most ].Name , InputEm[ most ].Duration);
   printf( "Salary : %'.2f Baht\n" , InputEm[ most ].Salary ) ;
}// end function
