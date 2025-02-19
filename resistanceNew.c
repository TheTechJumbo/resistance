#include <stdio.h>
#include <math.h>

void options() {
    printf("\n\nThis is the menu of possible options for data surrounding the resistors: \n1. The mean resistance of all the resistors");
    printf("\n2. The standard deviation of the resistances of all the resistors\n3. The largest resistance out of all of the resistors\n\n");
    printf("Please enter an option from the above menu:\n");

}
int rep = 1;
void repeat() {
    printf("\nPress 1 if you would like to collect another type of data surrounding the resistors and any other number if not:\n");
    scanf("%i", &rep);

}
float mean;
float sd;
float largest;
void choices() {
    int choice;
    do{
        options();
        scanf("%i", &choice);
        switch (choice) {
            case 1:
                printf("\nThe mean resistance of all the resistors is %f ohms.", mean);
                break;
            case 2:
                printf("\nThe standard deviation of the resistance values is %f ohms", sd);
                break;
            case 3:
                printf("\nThe largest resistor value in our set of resistor values is %f ohms", largest);
                break;
            default:
                break;
        }
        repeat();
    }while (rep==1);
}

int main(void) {
    int num;
    //Between 2 and 10 resistors are to be sampled
    printf("How many resistors have been measured?\n");
    scanf("%i", &num);
    while ((num < 2) || (num > 10)) {
        printf("That is an invalid number of resistors to be sampled\nPlease enter a number of resistors between 2 and 10:\n");
        scanf("%i", &num);
    }
    //Prints the number of resistors that have been measured
    printf("\n%i resistors have been measured.\n\n", num);

    //Allows us to enter the resistance values of each resistor
    float resistors[num];
    int acc;
    for (acc = 0; acc < num; acc++) {
        printf("Please enter the value of the resistor %i in ohms:\n", acc + 1);
        scanf("%f", &resistors[acc]);
        while ((resistors[acc] < 1e-3) || (resistors[acc] > 1e6)) {
            printf("This is an resistor value outside of the accepted range.\nPlease enter a resistance value for resistor %i, in the range 0.001 to 1000000 ohms\n",
                   acc + 1);
            scanf("%f", &resistors[acc]);
        }
    }

    //Prints the values of all the resistors
    for (acc = 0; acc < num; acc++) {
        printf("\nThe value of resistor %i is %f ohms", acc + 1, resistors[acc]);
    }

    //calculation for the mean
    float meanTotal=0;
    int i;
    for (i=0; i<num; i++){
        meanTotal+=resistors[i];
    }
    mean=meanTotal/num;
    //printf("\n\nThe mean resistance of the resistor values is %f", mean);
    //end of mean calculation

    //calculation for the standard deviation
    float sdTotal;
    float numToSq;
    int accumulator;
    for (accumulator=0; accumulator<num; accumulator++){
        numToSq=(resistors[accumulator]-mean);
        sdTotal+=pow(numToSq, 2.0);
    }
    float variance=sdTotal/(num-1);
    sd= sqrt(variance);

    //printf("\nStandard deviation for the resistor values %f", sd);
    //end of calculation for standard deviation

    //calculation of the largest resistance
    int r;
    for (r=0; r<num; r++){
        if (resistors[r]>resistors[0]){
            largest=resistors[r];
        }
    }
    //end of calculation of the largest resistance

    choices();

    //Displays the options for data surrounding the resistors and asks which type of data the user would like to retrieve
    /*int choice1;
    options();
    scanf("%i", &choice1);
    while ((choice1 < 1) || (choice1 > 3)) {
        printf("\nYou have entered an invalid selection.");
        options();
        scanf("%i", &choice1);
    }
    int rep;
    repeat();
    int choice2=0;
    int choice3=0;
    if (rep == 1) {
        options();
        scanf("%i", &choice2);
        while ((choice2 < 1) || (choice2 > 3)) {
            printf("\nYou have entered an invalid selection.");
            options();
            scanf("%i", &choice2);
        }

        while (choice2 == choice1) {
            printf("\nYou have already requested this type of data.\n ");
            options();
            scanf("%i", &choice2);
        }

        repeat();
        if (rep == 1) {
            printf("\nYou would like to receive all three types of data.\n");
            int choice3 = 1;
        } else {
            int choice3 = 0;
        }

    }
    else {
        int choice1 = 0;
        int choice2 = 0;
        int choice3 = 0;
    }

    //Calculations section
    //Calculating the mean

     int accumulator;
    float meanTotal;
    for (accumulator = 0; accumulator < num; acc++) {
        meanTotal += resistors[accumulator];
    }
    float mean = 7.3;
    printf("%f", mean);


    switch (choice1) {
        case 0:
            break;
        case 1:
            printf("The mean of all the resistor values is %f.", mean);
            break;
        case 2:
            printf("The standard deviation of all the resistor values is");
            break;
        case 3:
            printf("The largest resistor value is ");
            break;
    }

    switch (choice2) {
        case 0:
            break;
        case 1:
            printf("The mean of all the resistor values is %f.", mean);
            break;
        case 2:
            printf("The standard deviation of all the resistor values is");
            break;
        case 3:
            printf("The largest resistor value is ");
            break;
        default:

    }
    switch (choice3) {
        case 0:
            break;
        case 1:
            printf("The mean of all the resistor values is %f.", mean);
            break;
        case 2:
            printf("The standard deviation of all the resistor values is");
            break;
        case 3:
            printf("The largest resistor value is ");
            break;
        default:
    }
*/
    return 0;
}
