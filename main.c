#include <stdio.h>
#include "COMP_lib.h"

int main () 
{

	COMP_komplex zahl_int_1 =  
	{
		.typ = COMP_int ,
		.int_daten.real = -2 ,
		.int_daten.imaginaer = 3 
	} ;
		
	COMP_komplex zahl_int_2 =
	{
		.typ = COMP_int ,
		.int_daten.real = 3 ,
		.int_daten.imaginaer = -6 
	} ;

	int ergebniss_2_norm_int = 0 ;

	COMP_komplex zahl_float_1 = 
	{
		.typ = COMP_float ,
		.float_daten.real = 2.5 ,
		.float_daten.imaginaer = -4.75 
	} ;

	COMP_komplex zahl_float_2 = 
	{
		.typ = COMP_float ,
		.float_daten.real = -3.21 ,
		.float_daten.imaginaer = 9.232345 
	} ;

	COMP_komplex zahl_ergebniss ;

	float ergebniss_2_norm_float ;
	
	ergebniss_2_norm_int = COMP_berechnung_2_norm_int ( zahl_int_1 ) ;
	printf ( "Die 2-Norm der integer Zahl beträgt: %i\n" , ergebniss_2_norm_int ) ;

	ergebniss_2_norm_int = COMP_berechnung_2_norm_int ( zahl_float_1 ) ;

	ergebniss_2_norm_float = COMP_berechnung_2_norm_float ( zahl_float_2 ) ;
	printf ( "Die 2-Norm der float Zahl beträgt: %f\n" , ergebniss_2_norm_float ) ;
	
	ergebniss_2_norm_float = COMP_berechnung_2_norm_float ( zahl_int_2 ) ;

	COMP_addition_komplex ( zahl_int_1 , zahl_int_2 , &zahl_ergebniss ) ;
	printf ( "Die addition der beiden int Zahlen ergibt : %i+%ii\n" , zahl_ergebniss.int_daten.real , zahl_ergebniss.int_daten.imaginaer ) ;
	
	COMP_addition_komplex ( zahl_float_1 , zahl_int_1 , &zahl_ergebniss ) ;
	printf ( "Die addition der int Zahl mit der float Zahl ergibt : %f+%fi\n" , zahl_ergebniss.float_daten.real , zahl_ergebniss.float_daten.imaginaer ) ;

	COMP_addition_komplex ( zahl_float_1 , zahl_float_2 , &zahl_ergebniss ) ;
	printf ( "Die addition der beiden float Zahlen ergibt : %f+%fi\n" , zahl_ergebniss.float_daten.real , zahl_ergebniss.float_daten.imaginaer ) ;

	COMP_ausgabe_eulerform ( zahl_int_1 ) ;

	COMP_ausgabe_eulerform ( zahl_int_2 ) ;

	COMP_ausgabe_eulerform ( zahl_float_1 ) ;

	COMP_ausgabe_eulerform ( zahl_float_2 ) ;

	return 0 ;
}
