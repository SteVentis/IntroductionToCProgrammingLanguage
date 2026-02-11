#include<stdio.h>
#include<stdlib.h>

#define NumberOfJudges 5
#define NumberOfContestants 7


boolean isCodeValid(int code);
boolean isRatingValid(int rating); 
void findMinMax(int ratings[], int arraySize, int* min, int* max);
float calculateAverage(int ratings[], int arraySize);
ContestResults findTheWinner(Contestant contestants[], int arraySize);

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
} ContestResults;


int main(){
    Contestant contestants[NumberOfContestants];
    int counter = 0;  
    
    
    for(int i = 0; i < NumberOfContestants; i++){
        
        printf("Κωδικός %dου Καλλιτέχνη(10-99): ", i + 1);
        scanf("%d", &contestants[i].code);
        for (int j = 0; j < NumberOfJudges; j++)
        {
            printf("Βαθμός Κριτή %d", j + 1);
            scanf("%d", &contestants[i].ratings[j]);
        }

        contestants[i].average = calculateAverage(contestants[i].ratings, NumberOfJudges);
    }

    

    // for (int i = 0; i < NumberOfContestants; i++)
    // {
    //     printf("%d\n",contestants[i].code);
    // }

    return 0;
}

boolean isCodeValid(int code){
    return false;
}

boolean isRatingValid(int rating){
    return false;
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
    

    return results;
}
