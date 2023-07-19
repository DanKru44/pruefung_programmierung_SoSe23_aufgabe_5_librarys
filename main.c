#include <stdio.h>
#include "COMP_lib.h"

int main () 
{
	COMP_int zahl_int_1 =  
	{
		.real_ganz = 2 ,
		.rechenzeichen_ganz = '+' ,
		.imaginaer_ganz = 3 
	} ;
		
	COMP_int zahl_int_2 =
	{
		.real_ganz = 3 ,
		.rechenzeichen_ganz = '-' ,
		.imaginaer_ganz = 6 
	} ;

	COMP_int zahl_int_3 = 
	{
		.real_ganz = 0 ,
		.imaginaer_ganz = 0 
	} ;

	int ergebniss_2_norm_int = 0 ;

	COMP_float zahl_float_1 = 
	{
		.real_gleitkomma = 2.5 ,
		.rechenzeichen_gleitkomma = '-' ,
		.imaginaer_gleitkomma = 4.75 
	} ;

	COMP_float zahl_float_2 = 
	{
		.real_gleitkomma = 3.21 ,
		.rechenzeichen_gleitkomma = '+' ,
		.imaginaer_gleitkomma = 9.232345 
	} ;

	COMP_float zahl_float_3 =
	{
		.real_gleitkomma = 0 ,
		.imaginaer_gleitkomma = 0 
	} ;

	float ergebniss_2_norm_float ;

	
	ergebniss_2_norm_int = COMP_berechnung_2_norm_int ( zahl_int_2 ) ;
	printf ( "Die 2-Norm der integer Zahl beträgt: %i\n" , ergebniss_2_norm_int ) ;

	ergebniss_2_norm_float = COMP_berechnung_2_norm_float ( zahl_float_2 ) ;
	printf ( "Die 2-Norm der float Zahl beträgt: %f\n" , ergebniss_2_norm_float ) ;

	return 0 ;
}
