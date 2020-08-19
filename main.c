#include <stdio.h>
#include <time.h>
#include "TestaPrimo.h"


int main (int argc, const char * argv[]){	
	int n = 7;
	int i;
	int alg;
	float speedup2,speedup3,speedup4;
	clock_t inicial1,inicial2,inicial3,inicial4;
	
	float soma1 = 0;
	float soma2 = 0;
	float soma3 = 0;
	float soma4 = 0;
	float media1,media2,media3,media4;
	printf("Numero: %d \n", n);

	for (i=0;i<30;i++){	
	
		inicial1 = clock();		
		int primo1 = TestaPrimo1(n);			
		inicial1 = clock() - inicial1;		
		soma1 = soma1 + inicial1;
		
		
					
		inicial2 = clock();
		int primo2 = TestaPrimo2(n);		
		inicial2 = clock() - inicial2;
		soma2 = soma2 + inicial2;
		
		inicial3 = clock();
		int primo3 = TestaPrimo3(n);		
		inicial3 = clock() - inicial3;
		soma3 = soma3 + inicial3;
		
		
		inicial4 = clock();
		int primo4 = TestaPrimo4(n);		
		inicial4 = clock() - inicial4;
		soma4 = soma4 + inicial4;			
	}
	
	media1 = soma1/30;
	printf("Algoritmo 1\n");
	printf("Ciclos: %f\n\n",media1);	
	
	media2 = soma2/30;
	printf("Algoritmo 2\n");
	printf("Ciclos: %f\n",media2);
	speedup2 = media1/media2;
	printf("SpeedUp 2: %f\n\n", speedup2);
	
	media3 = soma3/30;
	printf("Algoritmo 3\n");
	printf("Ciclos: %f\n",media3);
	speedup3 = media1/media3;
	printf("SpeedUp 2: %f\n\n", speedup3);
	
	media4 = soma4/30;
	printf("Algoritmo 4\n");
	printf("Ciclos: %f\n",media4);
	speedup4 = media1/media4;
	printf("SpeedUp 2: %f\n\n", speedup4);
	
	return 0;
}
int TestaPrimo1(int n) {
    int EhPrimo = 1, //em princípio, n é primo
        d=2;
    if (n <= 1)
    EhPrimo = 0;

    while (EhPrimo == 1 && d <= n / 2) {
    if (n % d  == 0)
        EhPrimo = 0;
    d = d + 1;
    }
    return EhPrimo;
}


int TestaPrimo2(int n) {
    
    int EhPrimo = 1, //em princípio, n é primo
        d=2,
        resto;
    if (n <= 1)
        EhPrimo = 0;

     while (EhPrimo == 1 && d <= n / 2) {
      resto = n % d;
          if (resto == 0)
              EhPrimo = 0;
          d = d + 1;
      }
    return EhPrimo;
}

int TestaPrimo3(int n) {
    
    int EhPrimo,
        d=3;
    if (n <= 1 || (n != 2 && n % 2 == 0))
        EhPrimo = 0;    /* nenhum numero inteiro <= 1 ou par > 2 e' primo */
    else
        EhPrimo = 1;        /* o numero e' primo ate que se prove o contrario */

    while (EhPrimo  && d <= n / 2) {
        if (n % d == 0)
            EhPrimo = 0;
        d = d + 2;        /* testar apenas ímpares*/
    }
    return EhPrimo;
}


int TestaPrimo4(int n) {
    int EhPrimo, //em princípio, n é primo
        d=3;
    if (n <= 1 || (n != 2 && n % 6 == 1 && n % 6 == 5))
        EhPrimo = 0;    /* nenhum numero inteiro <= 1 ou ~ adjacente a 6 eh primo */
    else
        EhPrimo = 1;
    while (EhPrimo  && d <= n / 2) {
        if (n % d == 0)
            EhPrimo = 0;
        d = d + 2;
        }
    return EhPrimo;
}
