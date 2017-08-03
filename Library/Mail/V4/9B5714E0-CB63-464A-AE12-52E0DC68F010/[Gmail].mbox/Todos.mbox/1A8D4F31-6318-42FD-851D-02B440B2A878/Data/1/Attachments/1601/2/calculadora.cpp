/*+------------------------------+------------------------------------+
|       Intel Code             |      AT&T Code                     |
+------------------------------+------------------------------------+
| mov     eax,1                |  movl    $1,%eax                   |
| mov     ebx,0ffh             |  movl    $0xff,%ebx                |
| int     80h                  |  int     $0x80                     |
| mov     ebx, eax             |  movl    %eax, %ebx                |
| mov     eax,[ecx]            |  movl    (%ecx),%eax               |
| mov     eax,[ebx+3]          |  movl    3(%ebx),%eax              |
| mov     eax,[ebx+20h]        |  movl    0x20(%ebx),%eax           |
| add     eax,[ebx+ecx*2h]     |  addl    (%ebx,%ecx,0x2),%eax      |
| lea     eax,[ebx+ecx]        |  leal    (%ebx,%ecx),%eax          |
| sub     eax,[ebx+ecx*4h-20h] |  subl    -0x20(%ebx,%ecx,0x4),%eax |
+------------------------------+------------------------------------+*/
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void menu();
void suma();
void resta();
void multiplicacion();
void division();
void potenciacion();
void seno();
void coseno();
void raiz_cuadrada();
void tangente();
void operacionSuma();
void operacionResta();
void operacionMultiplicacion();
void operacionDivision();
void operacionPotenciacion();
float operacionSeno(float);
float operacionCoseno(float);
float operacionRaiz(float);
float operacionTangente(float);
void separador(char str[], char s2[],char *ptr, char chartmp[]);
void resultado();
void capturaDatos(int opc);


int numA = 0, numB = 0, decr = 1;;
float $theta;


int main() {
	menu();
	return 0;
}

void menu()
{
 	char opc;
 	system("CLS");
 	printf("\n\t\t\t Calculadora ASM\n\n");

 	printf("\n 1) Sumar.");
 	printf("\n 2) Restar. ");
 	printf("\n 3) Multiplicar.");
 	printf("\n 4) Dividir.");
 	printf("\n 5) Potenciacion.");
 	printf("\n 6) Seno.");
 	printf("\n 7) Coseno.");
 	printf("\n 8) Raiz Cuadrada.");
 	printf("\n 9) Tangente.");
 	printf("\n S) Salir.");

 	printf("\n\n Escoja una opcion: ");
 	opc = getche();
 	switch(opc)
 	{
	 		   case 49:
			   		suma();
			   		break;
		   	   case 50:
			   		resta();
					break;
 			   case 51:
			   		multiplicacion();
			 	  	break;
	 	  	   case 52:
			   		division();
				  	break;
			   case 53:
			   		potenciacion();
				   	break;
               case 54:
			   		seno();
				   	break;
			   case 55:
			   		coseno();
				   	break;
               case 56:
			   		raiz_cuadrada();
				   	break;
			   case 57:
			   		tangente();
				   	break;
               case 83:
				    exit(0);
    		   default:
					system("CLS");
					printf("\n\t\t\t  Opcion invalida.\n\n\n Favor ingrese un numero establecido.\n\n Presione una tecla para ir al menu: ");
					getch();
	}
	menu();
}

void suma()
{
 	fflush(stdin);
    fflush(stdout);
 	system("CLS");
 	printf("\n Operacion de suma.\n\n");
 	printf(" Ingrese la operacion(a+b): ");
 	capturaDatos(1);
}

void resta()
{
 	fflush(stdin);
    fflush(stdout);
 	system("CLS");
 	printf("\n Operacion de resta.\n\n");
 	printf(" Ingrese la operacion(a-b): ");
 	capturaDatos(2);
}
void multiplicacion()
{
 	fflush(stdin);
    fflush(stdout);
 	system("CLS");
 	printf("\n Operacion de multiplicacion.\n\n");
 	printf(" Ingrese la operacion(a*b): ");
 	capturaDatos(3);
}
void division()
{
 	fflush(stdin);
    fflush(stdout);
 	system("CLS");
 	printf("\n Operacion de division.\n\n");
 	printf(" Ingrese la operacion(a/b): ");
 	capturaDatos(4);
}
void potenciacion()
{
 	fflush(stdin);
    fflush(stdout);
 	system("CLS");
 	printf("\n Operacion de potenciacion.\n\n");
 	printf(" Ingrese la operacion(a^b): ");
 	capturaDatos(5);
}

void seno()
{
 	fflush(stdin);
    fflush(stdout);
 	system("CLS");
 	printf("\n Funcion Trigonometrica de Seno.\n\n");
 	printf(" Ingrese el angulo: ");
 	scanf("%f", & $theta);
 	printf("\n\nResultado: %f", operacionSeno($theta));
    printf("\n\n Presione una tecla para ir al menu: ");
    getch();
}


void coseno()
{
 	fflush(stdin);
    fflush(stdout);
 	system("CLS");
 	printf("\n Funcion Trigonometrica de Coseno.\n\n");
 	printf(" Ingrese el angulo: ");
 	scanf("%f", & $theta);
 	printf("\n\nResultado: %f", operacionCoseno($theta));
    printf("\n\n Presione una tecla para ir al menu: ");
    getch();
}

void raiz_cuadrada()
{
 	fflush(stdin);
    fflush(stdout);
 	system("CLS");
 	printf("\n Operacion de raiz cuadrada.\n\n");
 	printf(" Ingrese el numero: ");
 	scanf("%f", & $theta);
 	printf("\n\nResultado: %f", operacionRaiz($theta));
    printf("\n\n Presione una tecla para ir al menu: ");
    getch();
}

void tangente()
{
 	fflush(stdin);
    fflush(stdout);
 	system("CLS");
 	printf("\n Funcion Trigonometrica de Tangente.\n\n");
 	printf(" Ingrese el angulo: ");
 	scanf("%f", & $theta);
 	printf("\n\nResultado: %f", operacionTangente($theta));
    printf("\n\n Presione una tecla para ir al menu: ");
    getch();
}


void operacionSuma() {
	 //Uso notación AT&T
  __asm("movl _numA, %ebx ") ;  // Muevo lo que hay en la variable global al acumulador b
  __asm("movl _numB, %eax") ;   // Se lee de derecha a izquierda
  __asm("addl %ebx,%eax");      // Adiciono lo que hay en el registro ebx en eax
  __asm("movl %eax, _numA") ;   // Muevo el contenido de lo que hay en el registro a la variable global
}

void operacionResta()
{
	__asm("movl _numA, %eax");
	__asm("movl _numB, %ebx");
	__asm("sub %ebx, %eax");
	__asm("movl %eax, _numA");
}
void operacionMultiplicacion()
{
	__asm("movl _numA, %eax");
	__asm("movl _numB, %ebx");
	__asm("imull %ebx"); // Multiplica ebx con eax y queda en memoria el resultado almacenado en eax
	__asm("movl %eax, _numA");
}
void operacionDivision()
{
	__asm("movl _numA, %eax");
	__asm("movl _numB, %ebx");
	__asm("cltd"); //  Se usa para el signo por lo que se guarda en el registro Data, para GAS en 32 bits es necesario esto
	__asm("idivl %ebx");
	__asm("movl %eax, _numA");
}
void operacionPotenciacion()
{

	decr = numB - 1; // Inicializo la condición del loop en un decremento
	__asm("movl _numA, %eax");// Muevo al registro lo que hay en numA
	__asm("movl _numA, %ebx");// Hago lo mismo para no alterar el resultado
	__asm("movl _decr, %ecx");// Asigno la condición que se evalúa hasta que sea cero
	__asm("CICLO_PARA_ELEVAR:"); // Hago el label del loop
	__asm("imull %ebx, %eax"); // Multiplico el registro ebx con eax
	__asm("loop CICLO_PARA_ELEVAR"); // Itero hasta que el registro ecx sea cero
	__asm("movl %eax, _numA"); // Muevo el resultado a la variable para imprimirlo
}

float operacionSeno(float $theta)
 {
 float $resultado;
 float $two_right_angles = 180.0f;

 __asm__ __volatile__
(
 "fld %1;"
 "fld %2;"
 "fldpi;"
 "fmulp;"
 "fdivp;"
 "fsin;"
 "fstp %0;" : "=m" ( $resultado ):"m"( $two_right_angles ), "m" ( $theta )
 );
 return $resultado ;
 }

float operacionCoseno( float $grados )
 {
 float $resultado;
 float $two_right_angles = 180.0f;
 float $radianes;

 __asm__ __volatile__
 (
 "fld %1;"
 "fld %2;"
 "fldpi;"
 "fmulp;"
 "fdivp;"
 "fstp %0;" : "=m" ($radianes):"m"($two_right_angles), "m" ($grados)
 );

 __asm__ __volatile__
(
"fld %1;"
"fcos;"
 "fstp %0;" : "=m" ($resultado) : "m" ($radianes)
 ) ;
 return $resultado;
 }

float operacionTangente(float $theta)
 {
 float $resultado;
 float $two_right_angles = 180.0f;

 __asm__ __volatile__
(
 "fld %1;"
 "fld %2;"
 "fptan;"
 "fdivrp;"
 "fstp %0;" : "=m" ( $resultado ):"m"( $two_right_angles ), "m" ( $theta )
 );
 return $resultado ;
 }


 float operacionRaiz( float $valor )
{
 float $resultado ;

 __asm__ __volatile__
 (
"fld %1;"
"fsqrt;"
"fstp %0;" : "=m" ($resultado) : "m" ($valor)
 );
  return $resultado ;
 }

void capturaDatos(int opc)
{

 	char str[MAX_PATH], chartmp[MAX_PATH];

 	char *ptr;

 	 fgets(str,MAX_PATH+1,stdin);
 	 fflush(stdin);
     fflush(stdout);
     if(strlen(str)>3)
     {
		if(opc==1)
		{
			char s2[4] = "+\n\t";
			separador(str, s2, ptr, chartmp);
		}
		else if(opc==2)
		{
			char s2[4] = "-\n\t";
		 	separador(str, s2, ptr, chartmp);
		}
		else if(opc==3)
		{
			char s2[4] = "*\n\t";
			separador(str, s2, ptr, chartmp);
		}
		else if(opc==4)
		{
			char s2[4] = "/\n\t";
			separador(str, s2, ptr, chartmp);
		}
		else if(opc==5)
		{
			char s2[4] = "^\n\t";
			separador(str, s2, ptr, chartmp);
		}

	    switch(opc)
	    {
		   case 1:
			 	operacionSuma();
			 	break;
			case 2:
				 operacionResta();
				 break;
	 		case 3:
			 	 operacionMultiplicacion();
			 	 break;
	  		case 4:
			  	 operacionDivision();
			  	 break;
	   		case 5:
			   	 operacionPotenciacion();
			   	 break;
            case 6:
			   	 //printf("Resultado: %f=%f", &theta, operacionSeno(&theta));
			   	 break;
			case 7:
			   	 //operacionCoseno();
			   	 break;
            case 8:
			   	 //operacionRaiz();
			   	 break;

            case 9:
			   	 //operacionTangente();
			   	 break;

			default:
				 system("CLS");
				 printf("\n Ocurrio un evento inesperado, se va a cerrar este programa, presione una tecla y vuelva a abrir: ");
				 getch();
				 exit(0);
   		}
		resultado();
	 }
	 else
	 {

		switch(opc)
	    {
		   case 1:
			 	suma();
			 	break;
			case 2:
				 resta();
				 break;
	 		case 3:
			 	 multiplicacion();
			 	 break;
	  		case 4:
			  	 division();
			  	 break;
	   		case 5:
			   	 potenciacion();
			   	 break;
			case 6:
			   	 seno();
			   	 break;
            case 7:
			   	 coseno();
			   	 break;
            case 8:
			   	 raiz_cuadrada();
			   	 break;
            case 9:
			   	 tangente();
			   	 break;
			case 'S':
			   	 exit(0);
			   	 break;

			default:
				 system("CLS");
				 printf("\n Ocurrio un evento inesperado, se va a cerrar este programa, presione una tecla y vuelva a abrir: ");
				 getch();
				 exit(0);
   		}
	 }
}
void separador(char str[], char s2[],char *ptr, char chartmp[])
{
	ptr = strtok( str, s2 );
	strcpy(chartmp,ptr);
 	if(isdigit(chartmp[0]))
 	{
	 	numA = atoi(chartmp);
	}

 	while( (ptr = strtok( NULL, s2 )) != NULL )    // Posteriores llamadas
 	{
	     strcpy(chartmp,ptr);
	 	 if(isdigit(chartmp[0]))
	 	 {
		 	numB = atoi(chartmp);
		 }
	     break;
    }
}
void resultado()
{
 	 printf("\n El resultado es: %d", numA);
	 printf("\n\n Presione una tecla para ir al menu: ");
	 getch();
}
