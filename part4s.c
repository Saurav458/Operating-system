// 4th Partof code 

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
