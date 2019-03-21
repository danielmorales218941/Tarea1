/* TAREA 1                                               *
*  CURSO: LENGUAJES DE PROGRAMACIÓN - LPW72 GRUPO 1      *
*  DOCENTE: JUAN CAMILO CORREA CHICA                     *
*  INSTITUTO TECNOLÓGICO METROPOLITANO                   *
*  FECHA MÁXIMA DE ENTREGA: MARZO 20/2019 - 11:59PM      */

#include<iostream>
#include<string>
#include<math.h>
using namespace std;

#define True 1
#define False 0

bool ok_chscrb = False;

// 1. La función NumCharToInt es una función que debe convertir un número escrito en letras (cadena de caracteres) 
// en un número de tipo entero, usted debe agregar las líneas de código necesarias para implementar dicha funcionalidad.
// Se debe garantizar que se convierten números enteros positivos y negativos.
// Se debe garantizar que la función no intente convertir un número que sobrepasa la capacidad del tipo de dato int.
// Utilice el tipo de dato "string" en caso de necesitar alguna variable para almacenar cadenas de caracteres.
// Utilice al final una sentencia cout<< <<endl; para imprimir en pantalla el número transformado a entero
// Dato1: La representación en caracter (ASCII) de un número natural (0 al 9) es igual al número + 48 (o bien 0x30 en hexa)
//        Ejemplo: '9' = 9 + 48 = 0x09 + 0x30
// Dato2: Para verificar la longitud de la cadena de caracteres que representa un número puede usar el operador size()
//        Ejemplo: string numero = "123456" -> numero.size() da como resultado 6
// Dato3: Solo puede utilizar declaración de variables, operadores de C++ y estructuras de control para codificar la solución.
// Dato4: Recuerde que las cadenas de caracteres (strings) se comportan como arrays de tipo char, se puede utilizar el operador
//        corchetes [] para acceder individualmente a las letras -> Ejemplo: string hh = "Hola"; hh[1] es la letra o

void NumStringToInt(string numero)
{
	string num = numero; /* NO borre esta linea de codigo */
	int t=num.size();
	int c=0,x,y, total=0;
	
	if(t>11){
		cout<<"el numero ingresado es demasiado grande1";
	}
	else{
	    t=t-1;
		x=num[0];
		y=num[1];
		if(((t==11) && (x==45) && (y<50)) || ((t<=10) && (x==45) && (y<50)) ||((t==10) && (x>=48) && (x<50)) || ((t<10) && (x>=48) && (x<=57))){
			while (t >= 0){
			    x=num[t];
			    y=x-48;
			    if(t > 0){
			        total=total+(y*pow(10,c));
			    }
			    else{
			        if(x==45){
			            total=total*(-1);
			        }
			        else{
			        	total=total+(y*pow(10,c));
					}
			    }     
			t-=1;
			c+=1;
			}
			cout<<"El numero ingresado es: "<<total<<endl;
		}
		else{
			cout<<"el numero ingresado es demasiado grande2";
		}
	}
	
}

// 2. La función CheckScrabble es una función que debe permitir descubrir si dos palabras están escritas con las mismas letras pero
// en distinto orden, ejemplos: "#Colombia" y "Boci#loam", "Z4PotlaN3jo" y "Pozjotlan43". Usted debe codificar esta funcionalidad usando
// operadores y estructuras de control de C++.
// En caso de que las palabras cumplan con la caracteristica de estar escritas con las mismas letras (¡la misma cantidad de letras obviamente!)
// se debe asignar el valor True a la variable ok_chscrb.
// Las palabras pueden estar formadas indistintamente por letras, números y caracteres raros, tal como vio en los ejemplos.
// Dato1: Lo primero que se debe verificar es si las palabras tienen el mismo número de letras, recuerde el operador size() del ejercicio anterior
// Dato2: Preguntele al buen Google por la representación en ASCII de las letras del abecedario (mayusculas y minusculas)
// Dato3: Puede utilizar directamente las variables palabra1 y palabra2 para implementar su codigo
// Pista esencial: NO es necesario que compare letra por letra individualmente.
//                 Reduzca el problema a un dominio común.

void CheckScrabble (string &palabra1, string &palabra2)
{
	string pal1 = palabra1;
	string pal2 = palabra2;
	bool ok_chscrb = true;
	int aux=0;
	bool bandera=false;
	int tam_pal1=pal1.size(),tam_pal2=pal2.size();
	//Analizamos si las dos palabras son del mismo tamaño como primera condicion
	if(tam_pal1==tam_pal2){
		
		//El tamaño de las palabras se lo asigno a 2 vectores
		int vector1[tam_pal1];
		int vector2[tam_pal2];
		
		/*Agrego cada letra a un vector, obteniendo 2 vectores de tipo entero
		donde cada una de las posiciones tiene una letra representada en su codigo ASCII*/
		for(int i=0; i<(tam_pal1);i++){
		    vector1[i]=pal1[i];
			vector2[i]=pal2[i];
		    if (vector1[i]>=65 && vector1[i]<=90){
		        vector1[i]= vector1[i]+32;
		    }
		    if (vector2[i]>=65 && vector2[i]<=90){
		        vector2[i]= vector2[i]+32;
		    }
		}
		//Ordeno el vector1
		do{
			bandera=false;
			for(int i=0; i<(tam_pal1-1);i++){
				if(vector1[i]>vector1[i+1]){
					bandera=true;
					aux=vector1[i];
					vector1[i]=vector1[i+1];
					vector1[i+1]=aux;
				}
			}
		}while(bandera);
		
		//ordeno vector2
		do{
			bandera=false;
			for(int i=0; i<(tam_pal1-1);i++){
				if(vector2[i]>vector2[i+1]){
					bandera=true;
					aux=vector2[i];
					vector2[i]=vector2[i+1];
					vector2[i+1]=aux;
				}
			}
		}while(bandera);
		
		//comparo los dos vectores ordenados
		for(int i=0; i<(tam_pal1);i++){
			if(vector1[i]!=vector2[i]){
				ok_chscrb=false;
			}
		}		
	}
	else{
		ok_chscrb=false;
	}
	if(ok_chscrb)
		cout<<"Tienen las mismas letras"<<endl;
	else
		cout<<"No tienen las mismas letras"<<endl;	
}


// 3. En la funcion printStruct utilice un puntero a la estructura local_struct, aritmetica de punteros y conversión explícita (type casting) 
// para imprimir el valor de los miembros de la estructura local declarada en la función.
// Dato1: NO debe utilizarse el operador punto (.) ni el operador flecha (->) Solo el puntero a local_struct y aritmetica de punteros.
// Dato2: Para imprimir los valores utilice la función "cout". Ejemplo: cout<<var_x<<endl;
// Enlaces útiles: http://ecomputernotes.com/what-is-c/function-a-pointer/type-casting-of-pointers 
//                 https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C/Punteros
//                 https://dgvergel.blogspot.com/2015/02/gestion-de-memoria-iii.html
//                 https://www.taringa.net/+apuntes_y_monografias/c-alineamiento-de-memoria-en-structs-clases_waqeq


/*Por favor NO borre las lineas de codigo siguientes que definen la estructura */
struct Clase
	{
		char mem1 = 'D';
		double mem2 = 12345678987654321.88888888888889;
		unsigned short mem3 = 4554;
		float mem4 = 3.14159;
		long long int mem5 = 5444333222;
		char mem6 = 'X';
		int mem7 = 434776;
		double mem8 = 2.35656778457911;		
	};

void printStruct(void)
{
	struct Clase local_struct; /*NO borre esta linea con la declaracion de la estructura local_struct */
	struct Clase *ptr= &local_struct;
	
	cout<<*((char*)ptr)<<endl;
	cout<<*((double*)ptr+1)<<endl;
	cout<<*((unsigned short*)ptr+8)<<endl;
	cout<<*((float*)ptr+5)<<endl;
	cout<<*((long long int*)ptr+3)<<endl;
	cout<<*((char*)ptr+32)<<endl;
	cout<<*((int*)ptr+9)<<endl;
	cout<<*((double*)ptr+5)<<endl;
	
	//De aqui en adelante se debe implementar la lógica en código de C++
	
	
}


/* NO es necesario que modifique nada de la función main */

int main()
{
	//1.
	string number = "45678945";
	string numerato = "777000555666999";
	NumStringToInt(number);
	NumStringToInt(numerato);
	cout<<endl;
	
	//2. 
	string pal1 = "Mex1C4l1";
	string pal2 = "411clEmX";
	string pw1 = "Lenguajes";
	string pw2 = "Languages";
	CheckScrabble (pal1, pal2);
	CheckScrabble (pw1, pw2);
	cout<<endl;
	
	//3.
	printStruct();
}
