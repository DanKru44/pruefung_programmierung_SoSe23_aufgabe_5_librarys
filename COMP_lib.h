/* COMP_lib.h */

#ifndef COMP_LIB_H
#define COMP_LIB_H

typedef struct  
{
	int real_ganz ;
	char rechenzeichen_ganz ;
	int imaginaer_ganz ;
} COMP_int ;

typedef struct
{ 
	float real_gleitkomma ;
	char rechenzeichen_gleitkomma ;
	float imaginaer_gleitkomma ;
} COMP_float ;

int COMP_berechnung_2_norm_int ( COMP_int komplex_ganzzahl ) ;

float COMP_berechnung_2_norm_float ( COMP_float komplex_gleitkomma ) ;

void COMP_addition_komplex ( void *komplexe_zahl_1 , void *komplexe_zahl_2 , void *komplex_ergebniss ) ;


#endif

