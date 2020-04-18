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
    }
    case 2:{
        M_again:
        system("clear");
        printf("\t");
        printf("\n\t");
        printf("\n\t");
        printf("\n\t");
        printf("\n\t");


        printf("\n");
        char buff[565]="Design a scheduler that can schedule the processes arriving system at periodical intervals. Every process is assigned with a fixed time slice t milliseconds. If it is not able to complete its execution within the assigned time quantum, then automated timer generates an interrupt. The scheduler will select the next process in the queue and dispatcher dispatches the process to processor for execution. Compute the total time for which processes were in the queue waiting for the processor. Take the input for CPU burst, arrival time and time quantum from the user.";
        printf("%s",buff);
        printf("\n\nPress M to go back to Main Menu: ");
        char b;
        fflush(stdin);
        scanf("%s",&b);
        if(b=='m' || b=='M'){
            main();
        }
        else{
            goto M_again;
        }
    }
    case 3:{
        printf("\nThank you for using this Program.....\n");
        exit(0);
    }
    default:{
        printf("\nInvalid \n");
        break;
    }
    }
    return 0;
}

//Function to calculate the Waiting Time for the Processes
void waiting(int n,int a[10],int b[10],int x[10]){
int time_quantum,ccount[n],count=0,i;
 tq_again:
 printf("\nEnter Time Quantum: ");
 scanf("%d",&time_quantum);
 if(time_quantum<=0){
      printf("\nTime Quantum cannot be 0 or less, Try again...\n");
      goto tq_again;
 }
 
int loc=0,torun=1,time_slice=0,min=0,p_ctime=0;


int minfind=0;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(a[i]<a[j]){
            minfind=a[i];
        }
    }
}

int zero_check=0;
for(i=0;i<n;i++){
    if(a[i]==0){
        break;
    }
    else{
        zero_check=minfind;
    }
}
time_slice=zero_check; 

int flag_to_check_two_same_burst_time=0,flag_to_check_two_same_arrival_time=0,loc2=0,loc3=0,sjf_run=0;
printf("\n\nRunning...\n");
while(torun){ 
    min=9999;
    sjf_run=0;
    for(int i2=0;i2<n;i2++){
            for(int i3=i2+1;i3<n;i3++){
                if(a[i2]==a[i3] && (i2!=loc || i2==0) && b[i2]!=0){
                    flag_to_check_two_same_arrival_time=1;
                    loc3=i2;
                    break;
                }
            }
            if(flag_to_check_two_same_arrival_time==1){
                break;
            }
        }
    for(int i2=0;i2<n;i2++){
            for(int i3=i2+1;i3<n;i3++){
                if(b[i2]==b[i3] && b[i2]!=0){
                    flag_to_check_two_same_burst_time=1;
                    loc2=i2;
                    break;
                }
            }
            if(flag_to_check_two_same_burst_time==1){
                break;
            }
        }
    if(flag_to_check_two_same_burst_time==1  && flag_to_check_two_same_arrival_time==1){
                min=b[loc3];
                loc=loc3;
                flag_to_check_two_same_burst_time=0;
                flag_to_check_two_same_arrival_time=0;
                sjf_run=1;
    }
    if(flag_to_check_two_same_burst_time==1){
                min=b[loc2];
                loc=loc2;
                flag_to_check_two_same_burst_time=0;
                sjf_run=1;
    }
    if(sjf_run==0){
    for(i=0;i<n;i++)
    { if((a[i]<=time_slice && b[i]<=min && b[i]>0)||min==0){
                min=b[i];
                loc=i;
        }
    }
    }

     b[loc]=b[loc]-time_quantum;
     if(b[loc]==0){
         count++;
         ccount[loc]=time_slice+time_quantum-p_ctime;
     }
     if(b[loc]<0){
         count++;
         ccount[loc]=time_slice+time_quantum+b[loc]-p_ctime;
         p_ctime=(-(b[loc]));
         b[loc]-=b[loc];         
     }
     if(count==n){ //end the process
         torun=0;
     }
     sleep(1);
     printf("\n\n");
     printf("\nProcess\t\tArrival Time\t\tBurst Time\t\tRemaining Time");
     printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t   %d",loc+1,a[loc],x[loc],b[loc]);
     printf("\n");
    time_slice+=time_quantum;  
}


int turn_arround_time[n];
for(i=0;i<n;i++){
    turn_arround_time[i]=ccount[i]-a[i];  //calculating Turn Arround Time
}

int waiting_time[n],total_wt=0;
for(i=0;i<n;i++){
    waiting_time[i]=turn_arround_time[i]-x[i];  //Calculating Waiting Time
    if(waiting_time[i]<0){
        waiting_time[i]=0;
    }
    total_wt+=waiting_time[i];  //Total Waiting Time
}


   printf("\n");
   printf("Overall Result");
   printf("Process\t\tArrival Time\t\tBurst Time\t\tCompletion Time\t\tWaiting Time");
   printf("\n-----------------------------------------------------------------------------------------------------");
   for(i=0;i<n;i++){
   printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d",i+1,a[i],x[i],ccount[i],waiting_time[i]);
   }
  
 printf("\n\nTotal Waiting time = %d\n\n",total_wt);
}
