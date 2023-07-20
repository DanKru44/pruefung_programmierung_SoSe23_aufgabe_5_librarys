/* COMP_lib.h */

#ifndef COMP_LIB_H
#define COMP_LIB_H

typedef enum
{
	COMP_int ,
	COMP_float 
} COMP_TYP ;

typedef struct
{
	COMP_TYP typ ;
   	union
   	{	   
		struct
		{
			int real ;
			int imaginaer ;
		} int_daten ;

		struct
		{	
			float real ;
			float imaginaer ;
		} float_daten ;
	} ;
} COMP_komplex ;

int COMP_berechnung_2_norm_int ( COMP_komplex komplex_ganzzahl ) ;

float COMP_berechnung_2_norm_float ( COMP_komplex komplex_gleitkomma ) ;

void COMP_addition_komplex ( COMP_komplex komplexe_zahl_1 , COMP_komplex komplexe_zahl_2 , COMP_komplex *komplex_ergebniss ) ;


#endif

