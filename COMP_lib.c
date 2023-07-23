#include "COMP_lib.h"
#include <math.h>
#include <stdio.h>

int COMP_berechnung_2_norm_int ( COMP_komplex komplex_ganzzahl ) 
{
	if ( komplex_ganzzahl.typ == COMP_int )
	{
		return sqrt ( komplex_ganzzahl.int_daten.real * komplex_ganzzahl.int_daten.real + komplex_ganzzahl.int_daten.imaginaer * komplex_ganzzahl.int_daten.imaginaer ) ;
	}
	else
	{	
		printf ( "Falscher Typ der komplexen Zahl. In dieser Funktion können nur komplexe Zahlen vom Typ integer verwendet werden.\n" ) ;
	}
}


float COMP_berechnung_2_norm_float ( COMP_komplex komplex_gleitkomma ) 
{
	if ( komplex_gleitkomma.typ == COMP_float )
	{
		return sqrt ( komplex_gleitkomma.float_daten.real * komplex_gleitkomma.float_daten.real + komplex_gleitkomma.float_daten.imaginaer * komplex_gleitkomma.float_daten.imaginaer ) ;
	}
	else
	{	
		printf ( "Falscher Typ der komplexen Zahl. In dieser Funktion können nur komplexe Zahlen vom Typ float verwendet werden.\n" ) ;
	}
}


void COMP_addition_komplex ( COMP_komplex komplexe_zahl_1 , COMP_komplex komplexe_zahl_2 , COMP_komplex *komplex_ergebniss )
{
	if ( komplexe_zahl_1.typ == komplexe_zahl_2.typ )
	{
		komplex_ergebniss -> typ = komplexe_zahl_1.typ ;
	
		if ( komplexe_zahl_1.typ == COMP_int )
		{
			komplex_ergebniss -> int_daten.real = komplexe_zahl_1.int_daten.real + komplexe_zahl_2.int_daten.real ;
			komplex_ergebniss -> int_daten.imaginaer = komplexe_zahl_1.int_daten.imaginaer + komplexe_zahl_2.int_daten.imaginaer ;
		}

		else
		{
			komplex_ergebniss -> float_daten.real = komplexe_zahl_1.float_daten.real + komplexe_zahl_2.float_daten.real ;
			komplex_ergebniss -> float_daten.imaginaer = komplexe_zahl_1.float_daten.imaginaer + komplexe_zahl_2.float_daten.imaginaer ;
		}
	}

	else
	{
		komplex_ergebniss -> typ == COMP_float ;

		if (komplexe_zahl_1.typ == COMP_int )
		{
			komplex_ergebniss -> float_daten.real = komplexe_zahl_1.int_daten.real + komplexe_zahl_2.float_daten.real ;
			komplex_ergebniss -> float_daten.imaginaer = komplexe_zahl_1.int_daten.imaginaer + komplexe_zahl_2.float_daten.imaginaer ;
		}

		else if ( komplexe_zahl_2.typ == COMP_int )
		{
			komplex_ergebniss -> float_daten.real = komplexe_zahl_1.float_daten.real + komplexe_zahl_2.int_daten.real ;
			komplex_ergebniss -> float_daten.imaginaer = komplexe_zahl_1.float_daten.imaginaer + komplexe_zahl_2.int_daten.imaginaer ;
		}
	}
	
}

// r*e^i*phi = r * ( cos(phi) + i * sin(phi) )
void COMP_ausgabe_eulerform ( COMP_komplex komplexe_euler )
{
	if ( komplexe_euler.typ == COMP_int ) 
	{
		int betrag_int = COMP_berechnung_2_norm_int ( komplexe_euler ) ;
		int winkel_int = atan2 ( komplexe_euler.int_daten.imaginaer , komplexe_euler.int_daten.real ) ;
		
		if ( komplexe_euler.int_daten.real > 0 )	
		{	
				printf ( "Die Euler-Form lautet: %i * e^i*(%i) = cos(%i) + i * sin(%i)\n" , betrag_int , winkel_int , winkel_int , winkel_int ) ;
		}

		else
		{
				printf ( "Die Euler-Form lautet: %i * e^i*(%i+%s) = cos(%i+%s) + i * sin(%i+%s)\n" , betrag_int , winkel_int , "\u03C0" , winkel_int , "\u03C0" , winkel_int , "\u03C0" ) ;
		}

	}

	else 
	{
		float betrag_float = COMP_berechnung_2_norm_float ( komplexe_euler ) ;
		float winkel_float = atan2 ( komplexe_euler.float_daten.imaginaer , komplexe_euler.float_daten.real ) ;

		if ( komplexe_euler.float_daten.real > 0 )	
		{	
				printf ( "Die Euler-Form lautet: %f * e^i*(%f) = cos(%f) + i * sin(%f)\n" , betrag_float , winkel_float , winkel_float , winkel_float ) ;
		}

		else
		{
				printf ( "Die Euler-Form lautet: %f * e^i*(%f+%s) = cos(%f+%s) + i * sin(%f+%s)\n" , betrag_float , winkel_float , "\u03C0" , winkel_float , "\u03C0" , winkel_float , "\u03C0" ) ;
		}
	}
}
