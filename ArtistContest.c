#include<stdio.h>
#include<stdlib.h>

#define NumberOfJudges 5
#define NumberOfContestants 7

typedef enum { 
    true, 
    false
} boolean;

typedef struct
{
    int code;
    int ratings[NumberOfJudges];
    float average;
} Contestant;

typedef struct 
{
    Contestant* winners;
    int winnersCount;
} ContestResults;


boolean isCodeValid(int code);
boolean isRatingValid(int rating); 
void findMinMax(int ratings[], int arraySize, int* min, int* max);
float calculateAverage(int ratings[], int arraySize);
ContestResults findTheWinner(Contestant contestants[], int arraySize);
void printResults(Contestant contestants[], int arraySize, ContestResults results);




int main(){
    Contestant contestants[NumberOfContestants];
    int counter = 0;  
    
    
    for(int i = 0; i < NumberOfContestants; i++){
        
        do
        {
            printf("Κωδικός %dου Καλλιτέχνη(10-99): ", i + 1);
            scanf("%d", &contestants[i].code);

        } while (isCodeValid(contestants[i].code));
        
        
        for (int j = 0; j < NumberOfJudges; j++)
        {
            do
            {
                printf("Βαθμός Κριτή %d: ", j + 1);
                scanf("%d", &contestants[i].ratings[j]);

            } while (isRatingValid(contestants[i].ratings[j]));
            
        }

        contestants[i].average = calculateAverage(contestants[i].ratings, NumberOfJudges);
    }

    ContestResults results = findTheWinner(contestants, NumberOfContestants);

    printResults(contestants, NumberOfContestants, results);
    
    free(results.winners);
}

boolean isCodeValid(int code){
    if (code < 10 || code > 99)
    {
        printf("Λάθος τιμή!\n");
        return false;
    }
    
    return true;
}

boolean isRatingValid(int rating){
    if (rating > 10 || rating < 0)
    {
        printf("Λάθος τιμή!\n");
        return false;
    }
    
    return true;
}

float calculateAverage(int ratings[], int arraySize){
    int min, max, sum = 0;
    
    float average = 0;

    findMinMax(ratings, arraySize, &min, &max);

    for (int i = 0; i < arraySize; i++)
    {
        sum += ratings[i];   
    }

    average = (float)(sum - min - max) / (arraySize - 2);
    return average;
}

void findMinMax(int ratings[], int arraySize, int *min, int *max){
    *min = ratings[0], *max = ratings[0];

    for (int i = 1; i < arraySize; i++)
    {
        if(ratings[i] < *min)
            *min = ratings[i];
        if(ratings[i] > *max)
            *max = ratings[i];
    }
}

ContestResults findTheWinner(Contestant contestants[], int arraySize){
    ContestResults results;
    results.winners = NULL;
    results.winnersCount = 0;

    float maximumScore = contestants[0].average;
    
    Contestant* temp = malloc(sizeof(Contestant) * arraySize);
    int counter = 0;
    
    for (int i = 0; i < arraySize; i++)
    {
        if (contestants[i].average > maximumScore)
        {
            maximumScore = contestants[i].average;
            counter = 0;
            temp[counter++] = contestants[i];
        }
        else if (contestants[i].average == maximumScore)
        {
            temp[counter++] = contestants[i];
        }   
    }
    
    results.winners = malloc(sizeof(Contestant) * counter);
    results.winnersCount = counter;

    for (int i = 0; i < counter; i++)
    {
        results.winners[i] = temp[i];
    }
    
    free(temp);

    return results;
}

void printResults(Contestant contestants[], int arraySize, ContestResults results){
    printf("\n--- ΑΠΟΤΕΛΕΣΜΑΤΑ ΔΙΑΓΩΝΙΣΜΟΥ ΤΡΑΓΟΥΔΙΟΥ ---\n");

    printf("%-4s| %-3s| %-3s| %-3s| %-3s| %-3s| %-6s\n",
           "ΚΚ", "Κ1", "Κ2", "Κ3", "Κ4", "Κ5", "Μ.Ο.");
    printf("----|----|----|----|----|----|--------\n");

    for (int i = 0; i < arraySize; i++)
    {
        printf("%-4d| %-3d| %-3d| %-3d| %-3d| %-3d| %-6.2f\n",
               contestants[i].code,
               contestants[i].ratings[0],
               contestants[i].ratings[1],
               contestants[i].ratings[2],
               contestants[i].ratings[3],
               contestants[i].ratings[4],
               contestants[i].average);
    }

    printf("\n");

    for (int i = 0; i < results.winnersCount; i++)
    {
        printf("ΝΙΚΗΤΗΣ: Καλλιτέχνης με ΚΚ = %d (Μ.Ο. = %.2f)\n",
               results.winners[i].code,
               results.winners[i].average);
    }
}
