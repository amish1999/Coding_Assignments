#include <stdio.h>
#include<stdlib.h>
#include <string.h>
 
struct student 
{
     char name[30];
     float cgpa;
};
 
 void sort_name(struct student arr[], int n)
{
	int i,j;
	char temp[20];
  for (i = 0; i<n-1 ; i++)
    for (j = i+1; j < n; j++)
       if (strcmp(arr[i].name, arr[j].name) > 0) 
        {
          strcpy(temp, arr[i].name);
          strcpy(arr[i].name, arr[j].name);
          strcpy(arr[j].name, temp);
        }
  }
void sort_cgpa(struct student arr[], int n)
{
	int i,j;
	int temp=0;
  for (i = 0; i<n-1 ; i++)
    for (j = i+1; j < n; j++)
       if (arr[i].cgpa > arr[j].cgpa) 
        {
          temp=arr[i].cgpa;
          arr[i].cgpa=arr[j].cgpa;
          arr[j].cgpa=temp;
        }
  }
void print_list(struct student record[], int n)
{
  int i;
   for(i=0;i<n;i++)
     printf(" STUDENT : %d   NAME : %s   CGPA is: %f \n", i+1,record[i].name,record[i].cgpa);
   printf("\n");
}
void print_name(struct student record[], int n)
{
  int i;
   for(i=0;i<n;i++)
     printf(" STUDENT : %d   NAME : %s  \n", i+1,record[i].name);
   printf("\n");
}
void print_cgpa(struct student record[], int n)
{
  int i;
   for(i=0;i<n;i++)
     printf(" STUDENT : %d   CGPA : %.3f  \n", i+1,record[i].cgpa);
   printf("\n");
}

int main() 
{
     int i,n;
     printf("Enter the number of students: ");
     scanf("%d",&n);
     struct student record[n];
    
     for(i=0;i<n;i++)
	 {
     printf("Enter the name and cgpa of  student %d: ",i+1);
     scanf("%s",&record[i].name);
     scanf("%f",&record[i].cgpa);
    }
	
	int ch;
    do{
    
	 printf("-----MENU-------\n");
     printf("1. Sorted by name\n2. Sorted by cgpa\n3. Print Unsorted List\n4.Exit\n");
     scanf("%d",&ch);
    
     switch(ch){
	   case 1:
	    printf("Records in sorted order of name :-----------\n");
        sort_name(record,n);
        print_name(record,n);
        break;
     
	   case 2:
	    printf("Records in sorted order of cgpa :-----------\n");
	    sort_cgpa(record,n);
        print_cgpa(record,n);
		break;
		
		case 3:
			printf("Records in original form:------------\n");
			print_list(record,n);
			break;
      }
   
  }while(ch!=4);
     return 0;
}
