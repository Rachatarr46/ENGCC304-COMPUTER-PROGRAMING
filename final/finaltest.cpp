#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Employee {
	char name [100] ; //name of person
	int y ; //years
	int m ; //month
	int b ; // Birthday date 
}typedef dt ;

int  importdata (dt [] ) ; //find data in structure
void showdata (dt [], int ) ; //show output

int main(){
	dt y_m_b[100] ;
	int people  = importdata(y_m_b) ;
	showdata (y_m_b,people) ;

}

int importdata (dt y_m_b[]){
	FILE *FP ; // filedata
	
	int people = 0 ;
	int un ; //data unnecessary
	char uns [100] ;
	FP = fopen( "a.txt" , "r") ;
	if(FP == NULL){
		printf("can't find your file.") ;
		exit (0) ;
	}
	fscanf(FP, "%s\t%s\t\t%s\n",uns,uns,uns) ;
	for (int i = 0; i < 100 ; i++){
		if (fscanf(FP, "%d\t%s\t\t%d-%d-%d\n",&un,y_m_b[i].name, &y_m_b[i].y,&y_m_b[i].m,&y_m_b[i].b) != EOF ){
			people++ ;	
		}
		else {
			break ;
		}
	}
	fclose (FP) ;
	return people ; //return back count people
}

void showdata (dt y_m_b[], int people ) {
	int all2day [100] ;
	int Max = 0 ;
	char *oldest ;
	int Min = 999999;
	char *youngest ;
	for(int i = 0 ; i < people ;i++){
		all2day [i] = (2018-y_m_b[i].y) * 365 + (6-y_m_b[i].m) * 30 + (21-y_m_b[i].b) ;
		printf("%s %d Years, %d Months\n",y_m_b[i].name,all2day[i]/365,(all2day[i]%365)/30) ;
			
	}
	for(int d = 0 ; d < people ; d++) {
		if(all2day[d] > Max){
			Max = all2day [d] ;
			oldest = y_m_b[d].name ;	
		}
		if(all2day[d] < Min){
			Min = all2day [d] ;
			youngest = y_m_b[d].name ;	
		}
	}
	printf("\nMax : %s[%d Years, %d Months]\n" ,oldest,Max/365,(Max%365)/30) ;//out put max 
	printf("Min : %s[%d Years, %d Months]\n",youngest,Min/365,(Min%365)/30) ;//out put Min
	
}
	

	
	
