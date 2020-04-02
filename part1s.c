//This is the part one of code in which i take user input and declaring variables,array.


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void waiting(int n,int a[10], int b[10], int x[10]);
int main() 
{
    int n;
    printf("\t");
    printf("\n");
    printf("\n\t");
    printf("\n\t");
    printf("\n\t");


    int choice;
    printf("\n\nMain Menu\n\nPress:\n1. Process Scheduling\n2. About\n3. Exit");
    printf("\n>");
    scanf("%d",&choice);
    switch(choice){
    case 1:{
    process_again:
    printf("\n\nEnter the number of Processes:\n");
    printf("");
    scanf("%d",&n);
    if(n<=0){
        printf("\nProcess cannot be 0 or less, Try Again...\n");
        goto process_again;
    } 
    int a[n],b[n],x[n],i,j,k=0,p_no[n];

    for(i=0;i<n;i++){
        printf("\nProcess : %d",i+1);
        p_no[i]=i+1;
        a_again:
        printf("\nEnter Arrival Time: ");
        scanf("%d",&a[i]);
        if(a[i]<0){
            printf("\nArrival Time cannot be less then 0, Try again...\n");
            goto a_again;
        }
        b_again:
      
        printf("Enter Burst Time: ");
        scanf("%d",&b[i]);
        if(b[i]<=0){
     
            printf("\nBurst Time cannot be 0 or less, Try again...\n");
            goto b_again;
        }
        x[i]=b[i];
    }
    waiting(n,a,b,x);
    break;
