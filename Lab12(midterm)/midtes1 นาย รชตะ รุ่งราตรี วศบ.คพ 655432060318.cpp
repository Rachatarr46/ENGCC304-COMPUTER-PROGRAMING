#include <stdio.h>
#include <string.h>

struct person {
        char name[100] ;
        float salary ;
        int duration ;
};

struct person p[100];

int check_employee ( char check , int a ) {
    char name[100] ;
    switch ( check ) {
        case 'y' :
            getchar() ;
            printf ( "Employee Name : " ) ;
            gets(p[a].name);
            printf ( "Salary (Bath/Month) : " ) ;
            scanf ( "%f" , &p[a].salary ) ;
            printf ( "Duration (Year) : " ) ;
            scanf ( "%d" , &p[a].duration ) ;
            break ;
        case 'n' :
            return 0;
        default :
            getchar();
            printf ( "Employee Name : " ) ;
            gets(p[a].name);
            printf ( "Salary (Bath/Month) : " ) ;
            scanf ( "%f" , &p[a].salary ) ;
            printf ( "Duration (Year) : " ) ;
            scanf ( "%d" , &p[a].duration ) ;
            break ;
    }//END SWITCHCASE
}//END FUCNTION

void avgpayment(int count){
    count = count - 1 ;
    float avg , payment = 0 ;
    int i = 0 ;
    
    while( i <= count ) {
        payment = p[i].salary + payment ;
        i++;
    }//END WHILE
    avg = payment / count ;
    printf ( "Average of Salary : %.2f Bath \n", avg ) ;
    printf ( "Payment of every month : %.2f Bath \n", payment ) ;
    printf ( "** Most duration in this business ** \n" ) ;
}//END FUCNTION

void mostduration(int count){
    count = count - 1 ;
    float per_yaers[count] ;
    int i = 0 ;

    while( i <= count ){
        per_yaers[i] = p[i].salary * (p[i].duration) ;
        i++ ;
    }//END WHILE

    int max = per_yaers[0] ;
    int icount = 0 ;
    int j = 0 ;

    while (j <= count) {
        int check_max = per_yaers[j] > max ;
        switch (check_max) {
        case 1:
			max = per_yaers[j] ;
			icount = j ;
			j++ ;
		    break ;
		case 0 :
			j++ ;
			break ;
        }//END SWITCHCASE
    }//END WHILE
    printf ( "Name : %s (%.d Years)\n", p[icount].name , p[icount].duration ) ;
    printf ( "Salary : %.2f Bath \n", p[icount].salary ) ;
}//END FUCNTION

int main() {
    int count = 0 ;
    int yn = 1 ;
    char check ;
    while ( yn ) {
        printf ( "Do you want to Enter Employee Information? (yes/no) : " ) ;
        scanf ( " %c", &check ) ;
        yn = check_employee( check , count ) ;
        count++ ;
    }//END WHILE
    avgpayment(count) ;
    mostduration(count) ;
}
