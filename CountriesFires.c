#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

 #define Max_Countries 8
 #define Max_YearsOfFires 2

 typedef struct 
 {
    int year;
    int total;
 } Fire;
 
 typedef struct 
 {
    int id;
    Fire fires[2];
 } Country;

int years[2] = {
      2023,
      2024
};

Country countries[8];
int totalCountries = 1;

//Insertion Sort 
void insertionSortCountriesBy2023(Country *countries, int totalCountries){

    for (int i = 1; i < totalCountries; i++)
    {
        Country key = countries[i];
 
       int j = i - 1;
 
       while (j >= 0 && countries[j].fires[0].total > key.fires[0].total)
       {
          countries[j + 1] = countries[j];
          j--;
       }
       
       countries[j + 1] = key;
     }
} 


int main(){
   int counter = 0;
   int input = 0;
   Country country;
   
   
   int yearsLength = sizeof(years)/ sizeof(years[0]);
   
   while (totalCountries <= Max_Countries)
   { 
      country.id = totalCountries;
      
      for (int i = 0; i < yearsLength; i++)
      {
         country.fires[i].year = years[i]; 
         do
         {
            printf("Χώρα %d: Δώσε αριθμό πυρκαγιών για το %d (100 έως 5000): ", country.id, country.fires[i].year);
            scanf("%d", &input);
            
            if (input < 100 || input > 50000)
            {
               printf("Μη έγκυρη τιμή. Ξαναπροσπάθησε.\n");
            }
         } while (input < 100 || input > 50000);

         country.fires[i].total = input;
      }
      countries[totalCountries++] = country;
   }

   insertionSortCountriesBy2023(countries, totalCountries); 
   
   int totalCountriesWithIncrease = 0;
    int currentIncrease = 0;
    int maxIncrease = 0;

    Country *countriesWithIncrease = malloc(totalCountries * sizeof(Country));

    Country countryWithMaxIncrease;

    for(int i = 0; i < totalCountries; i++)
    {
        if (countries[i].fires[0].total < countries[i].fires[1].total)
        {
            currentIncrease = countries[i].fires[1].total - countries[i].fires[0].total;
            if (currentIncrease > maxIncrease)
            {
                maxIncrease = currentIncrease;
                countryWithMaxIncrease = countries[i];
            }
            
            countriesWithIncrease[totalCountriesWithIncrease++] = countries[i];
        }
    }
    
    printf("--- Αποτέλεσματα Στατιστικής ανάλυσης ---\n");
    printf("Μικρότερος αριθμός πυρκαγιών το 2023: %d\n", countries[1].fires[0].total);
    printf("Μεγαλύτερος αριθμός πυρκαγιών το 2023: %d\n", countries[totalCountries - 1].fires[0].total);
    printf("Αριθμός χωρών με αύξηση πυρκαγιών το 2024: %d\n", totalCountriesWithIncrease);
    printf("Η χώρα %d είχε την μεγαλύτερη αύξηση πυρκαγιών: %d\n", countryWithMaxIncrease.id, maxIncrease);
    printf("-----------------------------------------\n");
    
    free(countriesWithIncrease);
}






