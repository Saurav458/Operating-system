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
