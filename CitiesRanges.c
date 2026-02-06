#include<stdio.h>

int main(){

   int n = 5;
   float cities[n][n];

   float range = 0.0;
   int isFirstRange = 1; 

   float minRange = 0.0;
   int citiesWithMinRange[2] = {0};
   
   float maxRange = 0.0;
   int citiesWithMaxRange[2] = {0};
   
   int l = 0;
   for (int i = 0; i < n; i++)
   {
       for (int j = 0; j < n; j++)
       {
           
           if (i == j)
           {
               cities[i][j] = 0.0;
            }
            else if(j > i)
            {
                do {
                    printf("Δώσε απόσταση μεταξύ %dης και %dης πόλης: ", i + 1, j + 1);
                    scanf("%f", &range);

                    if (range <= 0.0) 
                    {
                        printf("Ο αριθμός πρέπει να είναι θετικός.\n");
                    }

                } while (range <= 0.0);
                
                cities[i][j] = range;
                cities[j][i] = range;
                
                if (isFirstRange || range < minRange)
                {
                    minRange = range;
                    citiesWithMinRange[0] = i;
                    citiesWithMinRange[1] = j;
                }
                
                if (isFirstRange || range > maxRange)
                {
                    maxRange = range;
                    citiesWithMaxRange[0] = i;
                    citiesWithMaxRange[1] = j;
                    isFirstRange = 0;
                }
                l++;
            }
        }
    }
    
    printf("Εμφάνιση πίνακα: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%8.2f ", cities[i][j]);
        }
        printf("\n");
    }
    
    printf("Η μεγαλύτερη απόσταση είναι: %.2f μεταξύ της %dης και της %dης πόλης\n",
        maxRange,
        citiesWithMaxRange[0] + 1,
        citiesWithMaxRange[1] + 1);

    printf("Η μικρότερη απόσταση είναι: %.2f μεταξύ της %dης και της %dης πόλης\n",
        minRange,
        citiesWithMinRange[0] + 1,
        citiesWithMinRange[1] + 1);
    
    printf("Υπολογισμός ταξιδίου προς όλες τις πόλεις: \n");
    float totalRange = 0.0;
    int city = 0;
    
    do
    {
        printf("Δώσε την πόλη αφετηρία: \n");
        scanf("%d", &city);
        if (city == 0 || city > n)
        {
            printf("Η τιμή πρέπει να είναι μεταξύ 1 και %d\n", n);
        }
    } while (city == 0 || city > n);
    
    city = city - 1;
    
    for (int j = 0; j < n; j++)
     {
         if (j != city)
         {
             totalRange += 2 * cities[city][j];
         }
     }
    
     printf("Το ταξίδι απο την αφετηρία προς όλες τις αλλες πόλεις είναι: %.2f\n", totalRange);
            
}