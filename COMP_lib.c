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

	else if	( ( komplexe_zahl_1.typ ==  COMP_float && komplexe_zahl_2.typ == COMP_int ) || ( komplexe_zahl_1.typ == COMP_int && komplexe_zahl_2.typ == COMP_float ) )
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
		else
		{
			printf ( "Ungültige Typen einer oder beider komplexen Zahlen\n" ) ;
		}
	}
}

