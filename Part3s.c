// Third Part 

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
