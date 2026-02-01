//
// Created by mrazeko on 16.01.2026.
//
#include <stdio.h>
#include <math.h>

double my_fabs(double x){
    return (x < 0) ? -x : x;
}

int main(void){
   double a, b, c, d, x1, x2;
   int intX1, intX2;

   printf("Napis cislo a: ");
   scanf("%lf", &a);
   printf("Napis cislo b: ");
   scanf("%lf", &b);
   printf("Napis cislo c: ");
   scanf("%lf", &c);

   d = my_round(b) - 4 * a * c;
   
   double epsilon = 1e-9; // 0.0000000009

   if (my_fabs(d) < epsilon) { 
       /* 
        * absolutni hodnota cisla (prevedeme ho na kladne)
        * A pokud je to kladne mensi jako epsilon (0.0000000009xxx)
        * tak to beru jako nulu
        */
       printf("Kvadraticka rovnice ma jen jedno reseni: \n");
       x1 = (-b) / (2 * a);

       intX1 = (int)x1;
       if (intX1 < x1) {
           printf("x = %.10lf\n", x1);
       } else {
           printf("x = %.0lf\n", x1);
       }

   } else if (d < -epsilon ) { // nebo to muzeme napsat sloziteji my_fabs(d) > epsilon && d < 0 
       printf("Kvadraticka rovnice nema reseni\n");
   } else {
       printf("Kvadraticka rovnice ma dve reseni: \n");
       x1 = ((-b) + sqrt(d)) / (2 * a);
       x2 = ((-b) - sqrt(d)) / (2 * a);
       intX1 = (int)x1;
       intX2 = (int)x2;

       if (intX1 < x1) {
           printf("x1 = %.10lf\n", x1);
       } else {
           printf("x1 = %.0lf\n", x1);
       }

       if (intX2 < x2) {
           printf("x2 = %.10lf\n", x2);
       } else {
           printf("x2 = %.0lf\n", x2);
       }

   }

  return 0;
}
