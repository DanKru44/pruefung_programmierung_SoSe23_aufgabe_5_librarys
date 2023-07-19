#include "COMP_lib.h"
#include <math.h>


int COMP_berechnung_2_norm_int ( COMP_int komplex_ganzzahl ) 
{
	return sqrt ( komplex_ganzzahl.real_ganz * komplex_ganzzahl.real_ganz + komplex_ganzzahl.imaginaer_ganz * komplex_ganzzahl.imaginaer_ganz ) ;
}


float COMP_berechnung_2_norm_float ( COMP_float komplex_gleitkomma ) 
{
	return sqrt ( komplex_gleitkomma.real_gleitkomma * komplex_gleitkomma.real_gleitkomma + komplex_gleitkomma.imaginaer_gleitkomma * komplex_gleitkomma.imaginaer_gleitkomma ) ;
}


void COMP_addition_komplex ( void *komplexe_zahl_1 , void *komplexe_zahl_2 , void *komplex_ergebniss )
{
	unsigned int groesse_int = sizeof ( COMP_int ) , groesse_float = sizeof ( COMP_float ) , groesse_zahl_1 = sizeof ( *komplexe_zahl_1 ) ;
   	unsigned int groesse_zahl_2 = sizeof ( *komplexe_zahl_2 ) ;

	if ( groesse_zahl_1 == groesse_int && groesse_zahl_2 == groesse_int )
	{
		COMP_int *zahl_1_pointer = komplexe_zahl_1 ;
		COMP_int *zahl_2_pointer = komplexe_zahl_2 ; 
		COMP_int *ergebniss_pointer = komplex_ergebniss ;
		ergebniss_pointer -> real_ganz = ( zahl_1_pointer -> real_ganz ) + ( zahl_2_pointer -> real_ganz ) ;
		ergebniss_pointer -> imaginaer_ganz = ( zahl_1_pointer -> imaginaer_ganz ) + ( zahl_2_pointer -> imaginaer_ganz ) ;
	}

	else if ( ( groesse_zahl_1  == groesse_float )  || ( groesse_zahl_2 == groesse_float ) )
	{
		COMP_float *zahl_1_pointer = komplexe_zahl_1 ;
		COMP_float *zahl_2_pointer = komplexe_zahl_2 ;
		COMP_float *ergebniss_pointer = komplex_ergebniss ;
		
		if ( groesse_zahl_1 == groesse_int )
		{
			COMP_int *zahl_1_int_pointer = komplexe_zahl_1 ;
			zahl_1_pointer -> real_gleitkomma = (float) zahl_1_int_pointer -> real_ganz ;
			zahl_1_pointer -> imaginaer_gleitkomma = (float) zahl_1_int_pointer -> imaginaer_ganz ;
		}

		else 
		{
			COMP_int *zahl_2_int_pointer = komplexe_zahl_2 ;
			zahl_2_pointer -> real_gleitkomma = (float) zahl_2_int_pointer -> real_ganz ;
			zahl_2_pointer -> imaginaer_gleitkomma = (float) zahl_2_int_pointer -> imaginaer_ganz ;
		}

		ergebniss_pointer -> real_gleitkomma = ( zahl_1_pointer -> real_gleitkomma ) + ( zahl_2_pointer -> real_gleitkomma ) ;
		ergebniss_pointer -> imaginaer_gleitkomma = ( zahl_1_pointer -> imaginaer_gleitkomma ) + ( zahl_2_pointer -> imaginaer_gleitkomma ) ;
	}

}

