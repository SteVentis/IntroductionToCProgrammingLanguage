#include<stdio.h>
#include<math.h>

 int main(){

    int input = 0;

    do
    {
        printf("Δώσε αριθμό μεγαλύτερο ή ίσο του 100 και μικρότερο ή ίσο του 300: ");
        scanf("%d", &input);

        if (input < 100 || input > 300)
        {
          printf("Προσοχή: ο αριθμός N πρέπει να είναι μεγαλύτερος ή ίσος του 100 και μικρότερος ή ίσος του 300\n");
        }
    } while (input <= 100 || input >= 300);

    double sum1 = 0;
    double sum2 = 0;
    double power = 0;

    for (int i = 1; i <= input; i++)
    {
       power = pow(i, 3);
    
       sum1 += power;
       sum2 += i;
    }

    double sum2Power = pow(sum2, 2);
    printf("Το άθροισμα SUM1 μέ βάση τον Τύπο 1 είναι: %.0f\n", sum1);
    printf("Το άθροισμα SUM2 μέ βάση τον Τύπο 2 είναι: %.0f\n", sum2Power);

    if (sum1 == sum2Power)
    {
        printf("Το Θεώρημα ισχύει\n");
    }
    else
    {
        printf("Το Θεώρημα δεν ισχύει\n");
    }
}