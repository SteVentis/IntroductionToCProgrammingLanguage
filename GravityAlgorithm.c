#include<stdio.h>

int main(){
    int n = 10;
    int maxValue = 100;

    int A[10];
    
    int counts[maxValue];

    for (int i = 0; i < n; i++) {
        int value;
        do {
            printf("Eισάγεται το στοιχείο %d (επιτρεπόμενες τιμές απο 0 έως και %d): ", i + 1, maxValue);
            scanf("%d", &value);

            if (value < 0 || value > maxValue) {
                printf("Η τίμη που εισάγεται πρέπει να είναι μεταξύ 0 εως και %d. Επαναλάβετε την είσοδο.\n", maxValue);
            }
        } while (value < 0 || value > maxValue);

        A[i] = value;
    }


    for (int i = 0; i < maxValue; i++)
    {
        counts[i] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < A[i]; j++)
        {
            counts[j]++;
        }
    }
    
    int B[n];

    for (int k = 0; k <= n; k++)
    {
        int treshold = n - k + 1;
        int counter = 0;

        for (int j = 0; j < maxValue; j++)
        {
            if (counts[j] >= treshold)
            {
                counter++;
            }
        }
        B[k - 1] = counter;
    }
    

    for (int i = 0; i < n; i++)
    {
        printf("Το στοιχείο %d είναι ίσο με %d\n", i, B[i]);

    }
}