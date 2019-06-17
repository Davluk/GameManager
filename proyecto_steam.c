// algo como steam pero mas sencillo ...
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int sesion=0;
int c[9]={0}, turno, jugador;
char denuevo=' ';
struct user
{
int numero_usuario;
char Nombre[50];
char contrasena[16];
int puntaje_snake,puntaje_gato,puntaje_pong,puntaje_total_snake,puntaje_total_pong,puntaje_total_gato;
double timegame_snake,tiempo_total_gato,tiempo_total_snake,tiempo_total_pong,timegame_pong,timegame_gato;
}A={0,'\0','\0',0,0,0,0,0,0,0,0,0,0,0,0},B={0,'\0','\0',0,0,0,0,0,0,0,0,0,0,0,0},C={0,'\0','\0',0,0,0,0,0,0,0,0,0,0,0,0};

int limpiar_pantalla()//limpia la pantalla en cualquier sistema operativo
{
if(getenv("OS")==NULL)
{
system("clear");
}
else
{
system("cls");
}
return 0;
}

int crearfichero()//crea el archivo base de datos e inicia algunos valores en el 
{

FILE *pfichero;
int j=0,i=0,h=0;
pfichero=fopen("base_datos.txt","r+");
if(pfichero==NULL)
{
i=1;
h=1;
pfichero=fopen("base_datos.txt","w+");
}
fclose(pfichero);
if(h==1)
{
pfichero=fopen("base_datos.txt","ab+");
for(j=0;j<40;j++)
{
	fwrite(&A,sizeof(struct user),1,pfichero);
}
fclose(pfichero);
}
return i;
}

int actualizar_datos()//manda los datos modificados de la estructura de usuario A a archivo
{
	int i,b;
	b=A.numero_usuario;
	FILE *pfichero;
	pfichero=fopen("base_datos.txt","rb+");
	fseek(pfichero,(b-1)*sizeof(struct user),SEEK_SET);
	fwrite(&A,sizeof(struct user),1,pfichero);
	fclose(pfichero);
	return 0;
}

int  ayuda()//recuadro simple de ayuda fuera de los juegos
{
char c;
printf("\n\n\t\t\t\t    Ayuda!\n\n\n");
printf("\n\n\t\t\tBienvenido a nuestro programa!");
printf("\n\n\n\n\n\t\t\teste ha sido desarrollado por :");
printf("\n\n\t\t\tAguilar Moreira David Uriel");
printf("\n\n\t\t\tJuarez Salazar Ricardo Edmundo");
printf("\n\n\n\t\tprotegido por derechos de autor...(si como no)");
printf("\n\n\n\t\t\t\t\t\t\t\t\t");
printf("\n\n\t\t\t\t    Presiona Enter para continuar...");
fflush(stdin);
c=getchar();
c=getchar();
limpiar_pantalla();
printf("\n\n\n\n\n\n\tAqui podras jugar algunos juegos simples y comparar lo bueno que");
printf("\n\n\teres con los resultados de otros usuarios.");
printf("\n\n\n\n\n\n\tLos juegos disponibles son: gato, ahorcado, y buscaminas\n\n");
printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
printf("\n\n\n\n\n\t\t\t\t    Presiona Enter para continuar...");
fflush(stdin);
c=getchar();
limpiar_pantalla();
printf("\n\n\n\n\n\t\t\t\t    Gato:");
printf("\n\t        intenta ganarle a la computadora en este juego! ");
printf("\n\t      se ingresa el numero de casilla para colocar tu ficha");
printf("\n\n\n\t\t\t\t    Ahorcado:");
printf("\n\t      adivina las letras de la palabra magica");
printf("\n\t  ingresa caracteres  e intenta no equivocarte");
printf("\n\n\n\t\t\t\t    Buscaminas:");
printf("\n\t\t      intenta adivinar la ubicacion de las minas!");
printf("\n        ingresa las coordenadas de el punto en el que quieres ver si hay mina");
printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
printf("\n\n\t\t\t\t    Presiona Enter para Salir al menu...");
fflush(stdin);
c=getchar();
limpiar_pantalla();
return 0;

}

int imprimir_banner_ahorcado()//imprime el baner del ahorcado en la pantalla
{
limpiar_pantalla();
char m;

FILE *f;
char c;
f=fopen("PAPUSHIAHORCADO.txt","r");
c=fgetc(f);
while(c!=EOF)
{
printf("%c",c);
c=fgetc(f);
}
fclose(f);

m=getchar();
m=getchar();
limpiar_pantalla();
return 0;
}
int imprimir_palabra(int longitud,char palabra_impresa[30])//imprimie la palabra de ahorcado en la pantalla
{
	int contador=0;
	for(contador=0;contador<longitud;contador++)
	{
		printf("%c ",palabra_impresa[contador]);
	}
	printf("\n\t\t");
	for(contador=0;contador<longitud;contador++)
	{
		printf("_ ");
	}
	return 0;
	}

int imprimirBanner_buscaminas()//la funcion extrae el contenido de un archivo y lo muestra en pantalla antes de iniciar el juego de gato
{
limpiar_pantalla();
char m;
{
FILE *f;
char c;
f=fopen("PAPUSHIBUSCAMINAS.txt","r");
c=fgetc(f);
while(c!=EOF)
{
printf("%c",c);
c=fgetc(f);
}
fclose(f);
}
m=getchar();
m=getchar();
return 0;
}	
	
int Buscaminas() 
{
	limpiar_pantalla();
int DimMat, i, I, Juego[10][10], Numeros, Minas, Cont,puntaje=0;
	char Tablero[10][10];
	printf("\n\n\t\tDa la dimension deseada para el juego <maximo 10>:\n\n\t\t\t\t       ");
	scanf("%d", &DimMat);
	printf("\n\t\t\t\t    ");
    for(i = 0; i < DimMat; i++)

        {
            for(I = 0; I < DimMat; I++)

                {   Tablero[i][I]='o';
                    printf(" %c",Tablero[i][I]);
                }

                printf("\n\t\t\t\t    ");
        }


	printf("\n\t\tDa el numero de minas deseadas: ");
	scanf("%d", &Minas);

	limpiar_pantalla();

	if(DimMat > 0 && DimMat <= 10 && Minas > 0)
    {
		Cont = 0;

		srand((unsigned)time(NULL));

		/*Llenado de la matriz */
		for(i = 0; i < DimMat; i++)

        {
			for(I = 0; I < DimMat; I++)
			{
				if(Cont <= Minas - 1)       //cont aumenta, y si hace es menor, en esa casilla se hara 0 o 1 aleatoriamente
				{
					Numeros = rand() % 10;
					if(Numeros<7)
					{
						Numeros=1;
					}
					else
					{
						Numeros=0;
					}
					  //coloca aleatoriamente 0 o 1 para que las minas queden aleatorias en el tablero
				}

                else

				{
					Numeros = 1;            //esto se ejecuta si ya no quedan minas que poner, hace a la casilla 1
				}

				if(Numeros == 0)

                    {
                        Cont++;
                    }

				Juego[i][I] = Numeros;  //llena cada casilla del juego con un 1 o con un 0 segun sea el caso
			}
		}

		limpiar_pantalla();






	}

	else
	{
		//esto se ejecuta cuando DimMat no es correcta.
		printf("\nLa dimension debe ser menor a 20 y mayor a 0.\n");
		printf("\nAdemas de que las minas deben ser mayor a 0.\n");

	}

	int X, Y, Intento;
do{
        getchar();
        limpiar_pantalla();
        printf("\n\n\n\t\t      Minas: %d\t Dimension: %d\n", Minas, DimMat);
		printf("\n\t\t\t\t  ");

		for(i = 0; i < DimMat; i++)
        {
			printf(" %d", i); //imprime los numeros de las columnas
		}
        printf("\n");

		for(i = 0; i < DimMat; i++)
        {
			if(i >= 10)
			{
				printf(" %d", i );

				for(I = 0; I < DimMat; I++)

                {
                  printf(" %c",Tablero[i][I]);
				}
			}
			else

            {
				printf("\t\t\t\t %d", i ); //imprime el numero de renglon

				for(I = 0; I < DimMat; I++)

                {
                    printf(" %c",Tablero[i][I]);
				}
			}

			printf("\n");
		}


		Intento += 1;
		printf("\n\t  Introduce la ubicacion que deseas (Separadas por espacio):_ ");
		scanf("%d", &X);
		scanf("%d", &Y);
		printf("\n\t\t    Escogiste(%d,%d)\n\n",X,Y);
		Tablero[X][Y]='x';

if(Juego[X][Y] == 0)
        {
            getchar();

			printf("\n\t\tHaz perdido, ahi habia una mina.\n\t\t\t\t\t");

			getchar();

			break;
		}

		else
		{
			puntaje++;
			A.puntaje_snake=10*puntaje;
	        A.tiempo_total_snake+=10*puntaje;
		    if(X>DimMat||Y>DimMat) //Si las coordenadas seleccionadas no estan en el tablero, no sirven
                {
                    printf("\t\tSeleccion no valida\n");
                }
		    else
                {
		        printf("\t\tNo hay mina. \n\n\t\t\t\t\t");
		        getchar();

                }
			continue;
	}
}while(Intento != DimMat*DimMat - Minas);
	
	limpiar_pantalla();
	if(Intento==(DimMat*DimMat - Minas))
    {
	printf("\n\n\n\t\tFelicidades, haz ganado!!!");
	getchar();
	getchar();
	} //Se imprime solo si ganas


	printf("\n\n\n\n\n\n\t\t\t      El mapa era: \n\n");


	/*Impresion de la matriz */
printf("\t\t\t\t");
	for(i = 0; i < DimMat; i++)
    {
		for(I = 0; I < DimMat; I++)
		{
			printf(" %d", Juego[i][I]);
		}

		printf("\n\t\t\t\t");
	}


    printf("\n\t\t\t\t0 = Mina \n");
    A.puntaje_snake=puntaje;
	A.puntaje_total_snake+=puntaje; 
	getchar();
	getchar();
	return 0;
}

int menu_buscaminas()
{
	imprimirBanner_buscaminas();
	time_t comienzo,final;
	int h=0,i=0;
	while(h<1)
	{
		limpiar_pantalla();
		printf("\n\n\n\n\n\n\n\t\t\t\tPAPUSHI_BUSCAMINAS\n\n\t\t\t\t      1.-jugar\n\n\t\t\t\t      2.-salir\n\n\n\t\t\t\t\t");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				comienzo=time(NULL);
				Buscaminas();
				final=time(NULL);
				A.timegame_snake=difftime(final, comienzo);
				A.tiempo_total_snake+=difftime(final, comienzo);
				break;
			case 2:
				h++;
				break;
			default:
			printf("\n\t\t\tseleccion invalida");
			
		}
	}
	return 0;
}
	
int buscar_caracter(char palabra[30],char palabra_impresa[30],char m,int longitud)//busca el caracter ingresado en palabra y hace que se imprima en pantalla
{
	int contador=0,verificador=0;
	for(contador=0;contador<longitud;contador++)
	{
		if(m==palabra[contador])
		{
			palabra_impresa[contador]=palabra[contador];
			verificador=1;
		}
	}
	return verificador;
	
}
int comprobar(char palabra[30],char palabra_impresa[30],int letras)//comprueva que se hayan ingresado bien todos los caracteres
{
	int contador=0, verificador=0;
	for(contador=0;contador<letras;contador++)
	{
		if(palabra_impresa[contador]==palabra[contador])
		{
		verificador++;
		}
	}
	return verificador;
}
int jugar_ahorcado()//funcion de juego de ahorcado
{
	int contador=0,intentos=6,i=0,j=0,a=0,b=0,d=0,e=0,ganador=0;
	char c,palabra[30],palabra_impresa[30]={0},registro[30]={"\0"},caracter_ingresado='\0';
	FILE *pfichero;
	pfichero=fopen("listado_palabras.txt","r");
	while(!feof(pfichero))
	{
	fscanf(pfichero,"%s",palabra);
	contador++;
	}
	fclose(pfichero);
	contador--;
	i=rand() % contador;
	if(i==0)
	{
		i++;
	}
	pfichero=fopen("listado_palabras.txt","r");
	for(j=0;j<i;j++)
	{
		fscanf(pfichero,"%s",palabra);
	}
	fclose(pfichero);
	j=strlen(palabra);
	c=getchar();
	while(a<1)
	{
	limpiar_pantalla();
	printf("\n\n\n\n\n\n\n\t\t\t\tJUGUEMOS AHORCADO!!!\n\t\t\t\ttienes %d intentos\n\n\n\t\t",intentos);
	imprimir_palabra(j,palabra_impresa);
	printf("\n\n\t\tla parabra tiene %d letras\n\t\t\t\t\t",j);
	scanf("%c",&caracter_ingresado);
	getchar();
	fflush(stdin);
	if(strchr(registro,caracter_ingresado)!=NULL)
	{
	printf("\n\t\t\t esa letra ya ha sido ingresada\n\t\t\t\t\t");
	c=getchar();
	c=getchar();
	}
	else
	{
	registro[d]=caracter_ingresado;
	d++;
	b=buscar_caracter(palabra,palabra_impresa,caracter_ingresado,j);	
	if(b==0)
	{
		printf("\n\t\tesa letra no se encuentra en la palabra");
		c=getchar();
		c=getchar();
		intentos--;
	}
	}
	if(intentos==0)
	{
	limpiar_pantalla();
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tGAME_OVER!!!!");
	c=getchar();
	a++;
	}
	if(comprobar(palabra,palabra_impresa,j)==j)
	{
	printf("\n\n\t\t\t\tHAS GANADO!!!");
	c=getchar();
	a++;
	ganador=1;
	A.puntaje_pong=2*(10-intentos);
	A.puntaje_total_pong+=2*(10-intentos);
	}
	}
	return 0;
}
int ahorcado()//funcion principal del ahorcado
{
	char c;
	imprimir_banner_ahorcado();
	srand(time(NULL));
	time_t comienzo,final;
	int ciclo_externo=0,valor_menu;
	
	
	while(ciclo_externo<1)
	{
	limpiar_pantalla();
	printf("\n\n\n\n\n\n\n\t\t\t\tPAPUSHI-AHORCADO" );
	printf("\n\n\t\t\t\t    1.-jugar");
	printf("\n\n\t\t\t\t    2.-salir");
	printf("\n\n\n\n\n\t\t\t\t       ");
	scanf("%d",&valor_menu);
	fflush(stdin);
	
	switch(valor_menu)
	{
		case 1:
			comienzo=time(NULL);
			jugar_ahorcado();
			final=time(NULL);
			A.timegame_pong=difftime(final, comienzo);
			A.tiempo_total_pong+=difftime(final, comienzo);
			break;
		case 2:
			limpiar_pantalla();
			ciclo_externo++;
			break;
		default:
			printf("\n\t\t\t\tseleccion invalida\n\t\t\t\t\t");
			c=getchar();
			c=getchar();
			
	}
	
	}
	
	
	return 0;
}

char tirada(int i)//funcion necesaria para mostrar en pantalla las tiradas en el gato
{
     switch (i)
     {
            case (-1):
                return 'X';
                break;

            case (1):
                return 'O';
                break;

            default:
                return ' ';
     }
}
int imprimirBanner()//la funcion extrae el contenido de un archivo y lo muestra en pantalla antes de iniciar el juego de gato
{
limpiar_pantalla();
char m;
{
FILE *f;
char c;
f=fopen("PAPUSHIGATO.txt","r");
c=fgetc(f);
while(c!=EOF)
{
printf("%c",c);
c=fgetc(f);
}
fclose(f);
}
m=getchar();
m=getchar();
limpiar_pantalla();
return 0;
}

void print_gato() /*esta funcion acomoda los valores en el dibujo del tablero*/
{
     printf("\n\t\t\t\t %c | %c | %c\n\t\t\t\t---+---+---\n\t\t\t\t %c | %c | %c\n\t\t\t\t---+---+---\n\t\t\t\t %c | %c | %c\n", tirada(c[0]), tirada(c[1]), tirada(c[2]), tirada(c[3]), tirada(c[4]), tirada(c[5]), tirada(c[6]), tirada(c[7]), tirada(c[8]));
}


int ganador() /*esta funcion compara el arreglo con los patrones de posible ganador*/
{
    if ((c[0]+c[1]+c[2]==3)|| (c[3]+c[4]+c[5]==3)|| (c[6]+c[7]+c[8]==3)|| (c[6]+c[3]+c[0]==3)|| (c[7]+c[4]+c[1]==3)|| (c[8]+c[5]+c[2]==3)|| (c[6]+c[4]+c[2]==3)|| (c[8]+c[4]+c[0]==3)) return 1;
    else if ((c[0]+c[1]+c[2]==-3)|| (c[3]+c[4]+c[5]==-3)|| (c[6]+c[7]+c[8]==-3)|| (c[6]+c[3]+c[0]==-3)|| (c[7]+c[4]+c[1]==-3)|| (c[8]+c[5]+c[2]==-3)|| (c[6]+c[4]+c[2]==-3)|| (c[8]+c[4]+c[0]==-3)) return -1;
    else return 0;
}

void turno_jugador() /*coloca el caracter en la casilla seleccionada y verifica que no este ocupada*/
{
     int quieres;
     printf("\n\n\t\tTe toca, En que casilla quieres tirar? [1-9]:_ ");
     scanf("%d",&quieres);
     if ((quieres>9)|| (quieres<1)|| (c[quieres-1]!=0))
     {
                       do
                       {
                                     printf("\n\t    Esa casilla esta ocupada, intenta en otra: [1-9]:_ ");
                                     fflush(stdin);

                                     scanf("%d",&quieres);
                       }
                       while ((quieres>9)|| (quieres<1)|| (c[quieres-1]!=0));
     }

     c[quieres-1]=1;
     jugador = 0;
}

void turno_computadora() /* coloca el valor de la computadora a tirar, en una posicion aleatoria*/
{
     int quiero;
     time_t t;
     printf("\n\t\tMe toca, tiro en la casilla: ");
     do
     {
                  srand(time(&t));
                  quiero=rand()%9;
     }
     while (c[quiero]!=0);
     printf(" %d\n", quiero + 1);

     c[quiero]=-1;
     jugador = 1;
}

int gato()//juego de gato
{
char z;
int x=0;
double q=0,g=0;
time_t comienzo,final;
imprimirBanner();
do
{
limpiar_pantalla();
int h, menu=0;
char t;
printf("\n\n\n\n\n\t\t\t      ==PAPUSHI-GATO== \n\n\n\t\t\tMenu: \n\n\t\t\t 1) Jugar \n\t\t\t 2) Leer instrucciones \n\t\t\t 3) Salir \n\n\t\t\t");
scanf("%d", &menu);

switch(menu)
{
						case 1:
						comienzo=time(NULL);
						jugador = 1;
                        turno = 0;
                        limpiar_pantalla();
                        printf("\n\t\t\t  EMPIEZA EL JUEGO!!!!!");
						printf("\n\n\t\t\t\t 1 | 2 | 3 \n\t\t\t\t---+---+---\n\t\t\t\t 4 | 5 | 6 \n\t\t\t\t---+---+---\n\t\t\t\t 7 | 8 | 9 \n");
                        do
                        {
                        	
                              turno++;
                              if(jugador)
                              {
                              turno_jugador();
                              x++;
                          		}
                              else
                              {
							
                              turno_computadora();
                              print_gato();
                          }

                         }
                         while ((!ganador())&&(turno<=8));
                         limpiar_pantalla();
                         switch (ganador())
                         {
                                case 0:
                                	printf("\n\n\n\t");
                                	print_gato();
                                    printf("\n\n\t\tEmpatamos\n");
                                    g++;
                                    break;

                                case 1:
                                	printf("\n\n\n\t");
                                	print_gato();
                                    printf("\n\n\t\tTu ganas!!!\n\n");
                                    g++;
                                    break;

                                case -1:
                                	printf("\n\n\n\n");
                                	print_gato();
                                    printf("\n\n\t\to.O yo te gano :P \n");
                                    break;
                         }
                         if(g==1)
                         {
                         q=50/x;
                         A.puntaje_gato=(int)(ceil(q));
                         A.puntaje_total_gato+=(int)(ceil(q));
                         final=time(NULL);
                         A.timegame_gato=difftime(final, comienzo);
                         A.tiempo_total_gato+=difftime(final, comienzo);
						 }

				printf("\n\n\t    tu puntaje en esta partida: %d en un  tiempo de %.lf segundos",A.puntaje_gato,A.timegame_gato);
                 break;

         case 2:
              limpiar_pantalla();
              printf("\n\n\n\t\t\t      Vamos a jugar GATO!\n\n\t\t      Las casillas estan enumeradas asi:\n\n\n\t\t\t\t 1 | 2 | 3 \n\t\t\t\t---+---+---\n\t\t\t\t 4 | 5 | 6\n\t\t\t\t---+---+---\n\t\t\t\t 7 | 8 | 9\n\n\n\t\t\t\t");
              printf("\n\t        intenta ganarle a la computadora en este juego! ");
			  printf("\n\t      se ingresa el numero de casilla para colocar tu ficha\n\n\t\t\t");
              t=getchar();
			  t=getchar();
			  limpiar_pantalla();
              break;


          case 3:
              limpiar_pantalla();
               printf("\n\n\t\t\tFue un placer jugar contigo");
               denuevo='n';
               limpiar_pantalla();
              break;
         }
         if(menu!=3)
         {
         printf("\n\t\tVolver al menu? (s o n) ");
         scanf("%s", &denuevo);
         if (denuevo>=97)denuevo-=32;
         if ((denuevo!='s')&&(denuevo!='n'))
         {
         	for(h=0;h<=8;h++)
         	{
         		c[h]=0;
			 }
		 }
		 }
}
while (denuevo=='S');  
z=getchar();
z=getchar();
}

int inicio_sesion()//aqui se junta todo el inicio de sesion
{
	
limpiar_pantalla();
FILE *pfichero;
char c,contrasena_aux[16]={'\0'};
int a,b=0,d=0,e=0,f=0,g=0,x=0,z=0;
a=crearfichero();
if(a==1)
{
printf("\n\n\n\n\n\t se el primero en iniciar sesion!! ");
printf("\n\n\t ingresa un nombre de usuario(sin espacios, max 50 caracteres):_\n\n\t\t ");
scanf("%s",&A.Nombre);
fflush(stdin);
printf("\n\n\t ingresa una contrase�a (sin espacios, max 16 caracteres):_ \n\n\t\t ");
scanf("%s",&A.contrasena);
fflush(stdin);

A.numero_usuario=1;
printf("\n\t tu numero de usuario es importante, con el iniciaras sesion y\n\t podras acceder a tu informacion\n");
printf("\n\t\t\t numero de usuario:_ %d",A.numero_usuario);
printf("\n\n\n\n\t\t\t\t\t\t");
actualizar_datos();
fflush(stdin);
c=getchar();
c=getchar();

sesion=1;
}
else
{
while(z<1)
{
b=d=e=f=g=0;
printf("\n\n\n\t\t\t Seleccione que accion quiere hacer:_ \n\n\n\n\t\t\t 1.- inicio de sesion\n\n\n\t\t\t 2.- crear cuenta\n\n\n\t\t\t 3.- regresar\n\n\n\t\t\t    ");
scanf("%d",&x);
switch(x)
{
	case 1:
limpiar_pantalla();
printf("\n\n\n\n\t antes que nada, recuerda tu numero de usuario (si no lo recuerdas\n\t estas en lios...)\n\n\t ");
printf("\n\n\t\t NUMERO DE USUARIO :_ ");
scanf("%d",&d);
if(d<=30)
{
pfichero=fopen("base_datos.txt","rb+");
fseek(pfichero,(d-1)*sizeof(struct user),SEEK_SET);
fread(&A,sizeof(struct user),1,pfichero);
fclose(pfichero);
if(A.numero_usuario==0)
{
printf("\n\t\t el usuario no existe");
fflush(stdin);
c=getchar();
c=getchar();
}
else
{
while(f<3)
{
limpiar_pantalla();
int h=0;
printf("\n\n\n\n\t usuario:_ %s",A.Nombre);
printf("\n\n\t ingresa la contrase�a:_ ");
scanf("%s",contrasena_aux);
fflush(stdin);
e=strcmp(contrasena_aux,A.contrasena);
if(e==0)
{
sesion=1;
f=3;
z++;
}
else
{
printf("\n\t contrase�a incorrecta !!" );
printf("\n\t quiere intentarlo de nuevo? solo tiene 3 intentos (1=si | 0=no)\n\n\t");
printf("\n\t intento %d\n\t ",f+1);
while(h<1)
{
scanf("%d",&g);
fflush(stdin);
switch(g)
{
case 0:
h++;
f=3;
break;
case 1:
f++;
h++;
break;
default:
printf("\n\t seleccion invalida!! ");
}
}
}
}
}
}
else
{
printf("\n\t lo sentimos al parecer el numero de usuario es invalido");
fflush(stdin);
c=getchar();
c=getchar();
}
break;
case 2:
limpiar_pantalla();
printf("\n\n\t ingresa un nombre de usuario(sin espacios, max 50 caracteres):_\n\n\n\t\t ");
scanf("%s",&A.Nombre);
fflush(stdin);
printf("\n\n\t ingresa una contrase�a (sin espacios, max 16 caracteres):_ \n\n\t\t");
scanf("%s",&A.contrasena);
fflush(stdin);
pfichero=fopen("base_datos.txt","rb+");
while(!feof(pfichero))
{
f++;
fread(&C,sizeof(struct user),1,pfichero);
if(C.numero_usuario==0)
{
break;	
}
}
fclose(pfichero);
A.numero_usuario=f;
printf("\n\t tu numero de usuario es importante, con el iniciaras sesion y\n\t podras acceder a tu informacion\n");
printf("\n\t\t\t numero de usuario:_ %d",A.numero_usuario);
printf("\n\n\n\n\t\t\t\t\t\t");
actualizar_datos();
fflush(stdin);
c=getchar();
c=getchar();
z++;
sesion=1;
	break;
	case 3:
		z++;
	break;
	default:
		printf("\n\t\t\t seleccion invalida");
}
}
}
return 0;
}




int editar_informacion()// te da la oportunidad de editar tu informacion como usuario y la actualiza 
{
limpiar_pantalla();
int i=0,o=0,u=0;
char c,a[16]={'\0'};
printf("\n\n\n\tSe necesita autorizacion previa para poder modificar\n\tlos datos de usuario");
printf("\n\n\tCONTRASENA:_ ");
scanf("%s",a);
i=strcmp(a,A.contrasena);
if(i==0)
{
while(o<1)
{
limpiar_pantalla();
printf("\n\n\n\n\n\n\t informacion a modificar \n\t 1.- Nombre de Usuario\n\t 2.- Contrasena\n\t 3.-regresar\n\n\t ");
scanf("%d",&u);
switch(u)
{
case 1:
printf("\n\tingrese un nuevo nombre de usuario( sin espacios, max 50 caracteres )\n\t ");
scanf("%s",A.Nombre);
actualizar_datos();
break;
case 2:
printf("\n\tingrese una nueva contrase�a( sin espacios, max 16 caracteres )\n\t ");
scanf("%s",A.contrasena);
actualizar_datos();
break;
case 3:
printf("\n\tlos datos de usuario en este momento son:\n\tNOMBRE DE USUARIO:_ %s\n\tCONTRASENA:_ %s\n\n\t",A.Nombre,A.contrasena);
c=getchar();
c=getchar();
o++;
break;
default:
	printf("\n\tseleccion invalida! ");
}
}
}
else
{
printf("\n\t ACCESO DENEGADO! ");
c=getchar();
c=getchar();
}
return 0;
}

int Estadisticas(int Estadistica,int Nusuarios,int X[30])//determina el orden en que deben de ser imporesos los usuarios en pantalla acorde con su puntaje
{
	FILE *pfichero;
	int a=0,b=0,c=0;
	switch(Estadistica)
	{
		case 1://gato
for(a=0;a<Nusuarios;a++)
{
	int d=0,e=0,f=0,g=0;
	pfichero=fopen("base_datos.txt","rb+");
	if(a==0)
	{
		fread(&B,sizeof(struct user),1,pfichero);
		for(b=1;b<Nusuarios;b++)
		{
			fread(&C,sizeof(struct user),1,pfichero);
			d=(int)ceil(sqrt(pow(B.puntaje_total_gato,2)+pow((B.puntaje_total_gato/B.tiempo_total_gato),2)));
			e=(int)ceil(sqrt(pow(C.puntaje_total_gato,2)+pow((C.puntaje_total_gato/C.tiempo_total_gato),2)));
			if(d>e)
			{
				X[a]=B.numero_usuario;
			}
			if(d<e)
			{
				X[a]=C.numero_usuario;
				fseek(pfichero,(C.numero_usuario-1)*sizeof(struct user),SEEK_SET);
				fread(&B,sizeof(struct user),1,pfichero);
				fseek(pfichero,C.numero_usuario*sizeof(struct user),SEEK_SET);
				
			}
			if(d==e)
			{
				if(B.numero_usuario>C.numero_usuario)
				{
					X[a]=B.numero_usuario;
				}
				else
				{
				X[a]=C.numero_usuario;
				fseek(pfichero,(C.numero_usuario-1)*sizeof(struct user),SEEK_SET);
				fread(&B,sizeof(struct user),1,pfichero);
				fseek(pfichero,C.numero_usuario*sizeof(struct user),SEEK_SET);
				}
			}
		}
	}else
	{
		fread(&B,sizeof(struct user),1,pfichero);
		b=0;
		while(b<a)
		{
			if(B.numero_usuario==X[b])
			{
			fread(&B,sizeof(struct user),1,pfichero);
			b=0;
			}
			else
			{
			b++;
			}
		}
		for(b=0;b<Nusuarios;b++)
		{
			fread(&C,sizeof(struct user),1,pfichero);
			c=0;
			while(c<a)
			{
				if(C.numero_usuario==B.numero_usuario||C.numero_usuario==X[c])
				{
					fread(&C,sizeof(struct user),1,pfichero);
					c=0;
				}
				else
				{
					c++;
				}
			}
			d=(int)ceil(sqrt(pow(B.puntaje_total_gato,2)+pow((B.puntaje_total_gato/B.tiempo_total_gato),2)));
			e=(int)ceil(sqrt(pow(C.puntaje_total_gato,2)+pow((C.puntaje_total_gato/C.tiempo_total_gato),2)));
			if(d>e) 
			{
				X[a]=B.numero_usuario;
			}
			if(d<e)
			{
				X[a]=C.numero_usuario;
				fseek(pfichero,(C.numero_usuario-1)*sizeof(struct user),SEEK_SET);
				fread(&B,sizeof(struct user),1,pfichero);
				fseek(pfichero,C.numero_usuario*sizeof(struct user),SEEK_SET);
				
			}
			if(d==e)
			{
				if(B.numero_usuario>C.numero_usuario)
				{
					X[a]=B.numero_usuario;
				}
				else
				{
				X[a]=C.numero_usuario;
				fseek(pfichero,(C.numero_usuario-1)*sizeof(struct user),SEEK_SET);
				fread(&B,sizeof(struct user),1,pfichero);
				fseek(pfichero,C.numero_usuario*sizeof(struct user),SEEK_SET);
				}
			}
			
			
		}
	}
	fclose(pfichero);
}
			break;
		case 2:
		for(a=0;a<Nusuarios;a++)
{
	int d=0,e=0,f=0,g=0;
	pfichero=fopen("base_datos.txt","rb+");
	if(a==0)
	{
		fread(&B,sizeof(struct user),1,pfichero);
		for(b=1;b<Nusuarios;b++)
		{
			fread(&C,sizeof(struct user),1,pfichero);
			d=(int)ceil(sqrt(pow(B.puntaje_total_snake,2)+pow((B.puntaje_total_snake/B.tiempo_total_snake),2)));
			e=(int)ceil(sqrt(pow(C.puntaje_total_snake,2)+pow((C.puntaje_total_snake/C.tiempo_total_snake),2)));
			if(d>e)
			{
				X[a]=B.numero_usuario;
			}
			if(d<e)
			{
				X[a]=C.numero_usuario;
				fseek(pfichero,(C.numero_usuario-1)*sizeof(struct user),SEEK_SET);
				fread(&B,sizeof(struct user),1,pfichero);
				fseek(pfichero,C.numero_usuario*sizeof(struct user),SEEK_SET);
				
			}
			if(d==e)
			{
				if(B.numero_usuario>C.numero_usuario)
				{
					X[a]=B.numero_usuario;
				}
				else
				{
				X[a]=C.numero_usuario;
				fseek(pfichero,(C.numero_usuario-1)*sizeof(struct user),SEEK_SET);
				fread(&B,sizeof(struct user),1,pfichero);
				fseek(pfichero,C.numero_usuario*sizeof(struct user),SEEK_SET);
				}
			}
		}
	}else
	{
		fread(&B,sizeof(struct user),1,pfichero);
		b=0;
		while(b<a)
		{
			if(B.numero_usuario==X[b])
			{
			fread(&B,sizeof(struct user),1,pfichero);
			b=0;
			}
			else
			{
			b++;
			}
		}
		for(b=0;b<Nusuarios;b++)
		{
			fread(&C,sizeof(struct user),1,pfichero);
			c=0;
			while(c<a)
			{
				if(C.numero_usuario==B.numero_usuario||C.numero_usuario==X[c])
				{
					fread(&C,sizeof(struct user),1,pfichero);
					c=0;
				}
				else
				{
					c++;
				}
			}
			d=(int)ceil(sqrt(pow(B.puntaje_total_snake,2)+pow((B.puntaje_total_snake/B.tiempo_total_snake),2)));
			e=(int)ceil(sqrt(pow(C.puntaje_total_snake,2)+pow((C.puntaje_total_snake/C.tiempo_total_snake),2)));
			if(d>e) 
			{
				X[a]=B.numero_usuario;
			}
			if(d<e)
			{
				X[a]=C.numero_usuario;
				fseek(pfichero,(C.numero_usuario-1)*sizeof(struct user),SEEK_SET);
				fread(&B,sizeof(struct user),1,pfichero);
				fseek(pfichero,C.numero_usuario*sizeof(struct user),SEEK_SET);
				
			}
			if(d==e)
			{
				if(B.numero_usuario>C.numero_usuario)
				{
					X[a]=B.numero_usuario;
				}
				else
				{
				X[a]=C.numero_usuario;
				fseek(pfichero,(C.numero_usuario-1)*sizeof(struct user),SEEK_SET);
				fread(&B,sizeof(struct user),1,pfichero);
				fseek(pfichero,C.numero_usuario*sizeof(struct user),SEEK_SET);
				}
			}
			
			
		}
	}
	fclose(pfichero);
}
		//snake
		
			break;
		case 3://pong
		
		for(a=0;a<Nusuarios;a++)
{
	int d=0,e=0,f=0,g=0;
	pfichero=fopen("base_datos.txt","rb+");
	if(a==0)
	{
		fread(&B,sizeof(struct user),1,pfichero);
		for(b=1;b<Nusuarios;b++)
		{
			fread(&C,sizeof(struct user),1,pfichero);
			d=(int)ceil(sqrt(pow(B.puntaje_total_pong,2)+pow((B.puntaje_total_pong/B.tiempo_total_pong),2)));
			e=(int)ceil(sqrt(pow(C.puntaje_total_pong,2)+pow((C.puntaje_total_pong/C.tiempo_total_pong),2)));
			if(d>e)
			{
				X[a]=B.numero_usuario;
			}
			if(d<e)
			{
				X[a]=C.numero_usuario;
				fseek(pfichero,(C.numero_usuario-1)*sizeof(struct user),SEEK_SET);
				fread(&B,sizeof(struct user),1,pfichero);
				fseek(pfichero,C.numero_usuario*sizeof(struct user),SEEK_SET);
				
			}
			if(d==e)
			{
				if(B.numero_usuario>C.numero_usuario)
				{
					X[a]=B.numero_usuario;
				}
				else
				{
				X[a]=C.numero_usuario;
				fseek(pfichero,(C.numero_usuario-1)*sizeof(struct user),SEEK_SET);
				fread(&B,sizeof(struct user),1,pfichero);
				fseek(pfichero,C.numero_usuario*sizeof(struct user),SEEK_SET);
				}
			}
		}
	}else
	{
		fread(&B,sizeof(struct user),1,pfichero);
		b=0;
		while(b<a)
		{
			if(B.numero_usuario==X[b])
			{
			fread(&B,sizeof(struct user),1,pfichero);
			b=0;
			}
			else
			{
			b++;
			}
		}
		for(b=0;b<Nusuarios;b++)
		{
			fread(&C,sizeof(struct user),1,pfichero);
			c=0;
			while(c<a)
			{
				if(C.numero_usuario==B.numero_usuario||C.numero_usuario==X[c])
				{
					fread(&C,sizeof(struct user),1,pfichero);
					c=0;
				}
				else
				{
					c++;
				}
			}
			d=(int)ceil(sqrt(pow(B.puntaje_total_pong,2)+pow((B.puntaje_total_pong/B.tiempo_total_pong),2)));
			e=(int)ceil(sqrt(pow(C.puntaje_total_pong,2)+pow((C.puntaje_total_pong/C.tiempo_total_pong),2)));
			if(d>e) 
			{
				X[a]=B.numero_usuario;
			}
			if(d<e)
			{
				X[a]=C.numero_usuario;
				fseek(pfichero,(C.numero_usuario-1)*sizeof(struct user),SEEK_SET);
				fread(&B,sizeof(struct user),1,pfichero);
				fseek(pfichero,C.numero_usuario*sizeof(struct user),SEEK_SET);
				
			}
			if(d==e)
			{
				if(B.numero_usuario>C.numero_usuario)
				{
					X[a]=B.numero_usuario;
				}
				else
				{
				X[a]=C.numero_usuario;
				fseek(pfichero,(C.numero_usuario-1)*sizeof(struct user),SEEK_SET);
				fread(&B,sizeof(struct user),1,pfichero);
				fseek(pfichero,C.numero_usuario*sizeof(struct user),SEEK_SET);
				}
			}
			
			
		}
	}
	fclose(pfichero);
}
		
			break;
		default:
			printf("\n\n\t\t seleccion invalida");
		//seleccion invalida
		
	}
	return 0;
}

int menu()//menu general de el programa
{
char m;
int a=0,b=0,c=0,d=0,e=0,f=0,g=0,Z[30]={0},h=0;
FILE *pfichero;
if(sesion==0)
{
while(c<1)
{
 limpiar_pantalla();
printf("\n\n\n\n\n\t\t\t      ==PAPUSHI-STEAM==");
printf("\n\t\t\t\t version 1.0");
printf("\n\n\n\n\n\t\t\t       1-inicio de sesion");
printf("\n\n\n\t\t\t             2-ayuda");
printf("\n\n\n\t\t\t             3-salir");
printf("\n\n\n\n\n\t\t\t\t        ");
scanf("%d",&a);
fflush(stdin);
switch(a)
{
case 1:
inicio_sesion();
if(sesion==1)
{c++; }
break;
case 2:
ayuda();			
break;
case 3:
limpiar_pantalla();
printf("\n\n\n\n\n\t\t\t\thasta la proxima!\n\n\n\n");
fflush(stdin);
m=getchar();
m=getchar();
limpiar_pantalla();
c++; 			
break;
		
default:
printf("\t\t\t\t seleccion invalida");
printf("\n\t\t\t\t       ");
fflush(stdin);
m=getchar();
m=getchar();
break;
}
}
}
if(sesion==1)
{

int z=0,y=0;
while(z<1)
{
m='\0';
a=b=c=d=e=f=g=0;
for(h=0;h<30;h++)
{
	Z[h]=0;
}
h=0;
limpiar_pantalla();
printf("\n USER:_ %s",A.Nombre);
printf("\n\n\n\n\t\t\t      ==PAPUSHI-STEAM==");
printf("\n\t\t\t\t version 1.0");
printf("\n\n\n\n\t\t\t1.- juegos");
printf("\n\n\t\t\t2.- editar informacion");
printf("\n\n\t\t\t3.- estadisticas");
printf("\n\n\t\t\t4.- ayuda");
printf("\n\n\t\t\t5.- salir");
printf("\n\n\n\t\t\t\t       ");
scanf("%d",&y);
fflush(stdin);
switch(y)
{
case 1:
	while(d<1){
	limpiar_pantalla();
printf("\n\n\n\n\n\n\n\t\t1.- gato\n\n\t\t2.- ahorcado\n\n\t\t3.- buscaminas\n\n\t\t4.- regresar\n\n\t\t");
scanf("%d",&e);
switch(e)
{
	case 1:
		
		gato();//gato
		actualizar_datos();
		
		break;
	case 2:
		ahorcado();
		actualizar_datos();
		//ahorcado primero se penso en el pong pero se necesitaban muchas funciones que solo windows reconoce
		break;
	case 3:
		menu_buscaminas();
		actualizar_datos();
		//buscamimas primero se penso en el pong pero se necesitaban muchas funciones que solo windows reconoce
		break;
	case 4:
		d++;
		break;
		
	default:
		printf("\n\n\t\t seleccion invalida");
		c=getchar();
}

}

break;
case 2:
//edita informacion
editar_informacion();
break;
case 3:
limpiar_pantalla();
pfichero=fopen("base_datos.txt","rb+");
while(!feof(pfichero))
{
f++;
fread(&C,sizeof(struct user),1,pfichero);
if(C.numero_usuario==0)
{
break;	
}
}
f--;
fclose(pfichero);
printf("\n\n\n\n\n\t\tseleccione que estadisticas desea ver:_\n\n\t\t1.- gato\n\n\t\t2.- buscaminas\n\n\t\t3.- ahorcado\n\n\t\t4.- regresar\n\n\t\t");
scanf("%d",&g);
if(g!=4)
{
limpiar_pantalla();
Estadisticas(g,f,Z);
printf("\n\t #usuario\t       NOMBRE\t\tSCORE\t      TIEMPO TOTAL");
for(h=0;h<f;h++)
{
pfichero=fopen("base_datos.txt","rb+");
fseek(pfichero,(Z[h]-1)*sizeof(struct user),SEEK_SET);
fread(&B,sizeof(struct user),1,pfichero);
fclose(pfichero);
if(g==1)
{
printf("\n\t %d\t %20s\t\t %d\t\t %.1lf",B.numero_usuario,B.Nombre,B.puntaje_total_gato,B.tiempo_total_gato);	
}
if(g==2)
{
printf("\n\t %d\t %20s\t\t %d\t\t %.1lf",B.numero_usuario,B.Nombre,B.puntaje_total_snake,B.tiempo_total_snake);	
}
if(g==3)
{
printf("\n\t %d\t %20s\t\t %d\t\t %.1lf",B.numero_usuario,B.Nombre,B.puntaje_total_pong,B.tiempo_total_pong);
}
}
if(g==1)
{
printf("\n\n\n\t puntale del usuario:_ \n\t puntaje total gato= %d papushipoints \n\t total de tiempo jugado= %.lf segundos\n\n",A.puntaje_total_gato,A.tiempo_total_gato);
}
if(g==2)
{
printf("\n\n\n\t puntale del usuario:_ \n\t puntaje total snake= %d papushipoints \n\t total de tiempo jugado= %.lf segundos\n\n",A.puntaje_total_snake,A.tiempo_total_snake);	
}
if(g==3)
{
	printf("\n\n\n\t puntale del usuario:_ \n\t puntaje total pong= %d papushipoints \n\t total de tiempo jugado= %.lf segundos\n\n",A.puntaje_total_pong,A.tiempo_total_pong);
}

printf("\n\n\t total de usuarios registrados :_ %d\n\n\n\t\t\t", f);
}
else
{
break;
}
for(h=0;h<30;h++)
{
	Z[h]=0;
}
m=getchar();
m=getchar();
//estadisticas
break;
case 4:
ayuda();
break;
case 5:
limpiar_pantalla();
printf("\n\n\n\n\n\t\t\t\thasta la proxima!\n\n\n\n");
fflush(stdin);
m=getchar();
m=getchar();
limpiar_pantalla();
z++;
break;
default:
printf("\n\n\t\t\t seleccion invalida!!");
printf("\n\t\t\t\t       ");
m=getchar();
m=getchar();
fflush(stdin);
}
}
}

return 0;
}




int Papushisteam()//imprime logo de el equipo en pantalla contenido en un archivo de texto
{
{
FILE *f;
char c;
f=fopen("PAPUSHISTEAM.txt","r");
c=fgetc(f);
while(c!=EOF){
printf("%c",c);
c=fgetc(f);
}
fclose(f);
}
char c;
c=getchar();
fflush(stdin);
return 0;
}

int main()//funcion principal del programa
{
	
limpiar_pantalla();
if(getenv("OS")!=NULL)
{
system("color 37");
}
Papushisteam();
menu();

return 0;
}

