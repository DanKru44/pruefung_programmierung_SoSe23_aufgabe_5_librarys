# Librarys
In diesem Repo befindet sich die Bearbeitung der Aufgabe 5 der Modulprüfung Programmierung im Sommersemester 2023. 

Dieses Repo enthält eine library die den Umgang mit komplexen Zahlen geschrieben wurde. Für das Rechnen mit Komplexen Zahlen wurde hierfür Zwei Datentypen angelegt. COMP_int und COMP-float. Für diese beiden Datentypen gibt es jeweils eine Funktion um die 2-Nrom zu bestimmen. In der library befindet sich ebenfalls eine Funktion zum addieren zweier COMP_Elemente und eine Funktion zum ausgeben eines COMP_Elements in Eulerform.

In diesem Repo befindet sich ebenfalls ein C-Programm dass mir zum testen der Funktionen diente. In diesem Programm werden die Funktionen nach einander aufgerufen und die Ergebnisse ins Terminal geprintet.


## Dokumentation der Bibliothek
In diesem Abschnitt befindet sich die Dokumentation der library. Es wird erklärt welche Datenstrukturen verwendet werden können und welche Funktionen enthalten sind, sowie diese genutzt werden können. 

Die Library ist dafür gedacht den Umgang mit komplexen Zahlen zu vereinfachen. Dazu wird eine Datenstruktur für die komplexen Zahlen eingeführt. Ebenfalls enthalten sind Funktionen für mathematische Operationen um diese für die komplexen Zahlen zu nutzen. Diese umfassen die Berechnung der 2-Norm für Integer und flaot Daten, die Addition von zwei komlexen Zahlen und die Darstellung in Euler-Form.

Beispiele zur Nutzung der Funktionen und zum anlegen der Datenstrukturen finden sich in dem C-Programm main.c in diesem Repo.

### Datenstrukur für die Funktionen 
Für die Verwendung der Funktionen wird in der library eine eigene Datenstruktur für die komlexen Zahlen eingeführt. Diese heißt ***COMP_komplex***. Dies ist eine Union um die Verwendung einfacher zu machen. Der Name dieser Union ist COMP_komplex.

Bei der Anlegung der Struktur kann dieser ein beliebiger Name zugewiesen werden. 

Mit dieser Struktur können sowohl integer als auch float daten gespeichert werden. Die Unterschied wird in der Information .typ der union gespeichert. 

**typ**:
 - COMP_int: Zur Verwendung von Ganzzahligen Werten
 - COMP_float: ZUr Verwendung von Gleitkomma Werten

Die Addressierung der Information erweitert sich nach dem festlegen des typ für COMP_int und COMP_float. Es muss zusätzlich nach COMP_komplex noch der Zusatz **.int_daten** für COMP_int und **.float_daten** mit angegeben werden.

Die weiteren Informationen die die Struktur benötigt sind der real- und der imaginaer-Teil der komplexen Zahl. Der real-Teil wird in der Information **.real** gespeichert und der imaginaer-Teil in der Information **.imaginaer**.

Die Strukturt sieht damit folgerndermaßen aus:
 - COMP_int:
	COMP_komplex "Structname" = 
	{
		.typ = COMP_int ,
		.int_daten.real = "Integer Wert" ,
		.int_daten.imaginaer = "Integer Wert"
	} ; 

- COMP_float:
	COMP_komplex "Structname" =
	{ 
		.typ = COMP_float ,
		.float_daten.real = "float Wert" ,
		.float_daten.imaginaer = "float Wert"
	} ;

Beispiel zur Anlegung der Datenstruktur COMP_int:
```
COMP_komplex zahl_int = 
{
	.typ = COMP_int ,
	.int_daten.real = 4 ,
	.int_daten.imaginaer = 75
} ;
```

Beispiel zur Anlegung der Datenstruktur COMP_float:
```
COMP_komplex zahl_float = 
{
	.typ = COMP_float
	.float_daten.real = 4.67 ,
	.float_daten.imaginaer = 23.12
} ;
```

Zur Nutzung der Funktionen reicht es den Namen des angelegten structs zu übergeben. Dies gilt nicht bei der Übergabe des structs das für das Ergebniss der Funktion COMP_addition_komplex. Zur Nutzung dieser Funktion muss ein struct mit Namen erstellt, aber weder typ noch realteil oder imaginaer teil festgelegt, werden. Dies übernimmt die Funktion in Abhängigkeit der übergebenen Daten. Die Übergabe erfolgt mit dem Adressierungsoperator & vor dem struct. Ein Beispiel dazu findet sich in der Beschreibung der Funktion COMP_addition_komplex und in dem C-Programm main.c in diesem Repo.

Beispiel zum Anlegen des structs für das Ergebniss aus COMP_addition_komplex:
```
COMP_komplex zahl_ergebniss ;
```

### Berechnung der 2-Norm 
Die Funktionen zur Berechnung der 2-Norm von komplexen Zahlen lauten **COMP_berechnung_2_norm_int** und **COMP_berechnung_2_norm_float**. Der Unterschied lässt sich am Ende des Funtkionsnamen erkennen und beschreibt den Datentyp für den diese Funktion genutzt werden kann. Einmal integer-Werte und einmal float-Werte. Bei dem Funktionsaufruf muss nur die entsprechende Datenstruktur COMP_komplex mit übergeben werden. Die Ergeniss erfolgen entsprechend des Datentyps der Funktion als integer oder float. Somit können die Ergebnisse in diesen einfachen Datentypen gespeichert werden.

Nutzung der Funktion:

COMP_berechnung_2_norm_int ( "Structname" ) ;

COMP_berechnung_2_norm_float ("Structname" ) ;

Beispiel zur Nutzung der Funktion COMP_berechnung_norm_int:
```
int ergebniss = COMP_berechnung_2_norm_int ( zahl_int ) ;
```

Beispiel zur Nutzung der Funktion COMP_berechnung_2_norm_float:
```
float ergebniss = COMP_berechnung_2_norm_float ( zahl_float ) ;
```

### Addition von komplexen Zahlen
Die enthaltene Funktion zu addition von komplexen Zahlen lautet **COMP_addition:komplex**. Mit dieser Funktion können zwei komplexe Zahlen die mit der Datenstruktur COMP_komplex angelegt wurden addiert werden. Dabei ist es unabhängig ob diese vom typ COMP_int oder COMP_float sind. Die Funktion erkennt dies automatisch. Bei der Verwendung anderen Datenstrukturen gibt diese eine Fehlermeldung zurück. 
Bei der Nutzung der Funktion müssen drei Parameter übergeben werden. Die beiden zu addierenden Zahlen und eine weitere Datenstruktur vom Typ COMP_komplex in der das Ergebniss gespeichert werden soll. Die beiden Zahlen die addiert werden sollen können einfach übergeben werden. Das Ergebniss muss allerdings mit Operator & zur Addressierung des Speicherbereiches übergeben werden. Ein Beispiel zum anlegen des Ergebnisses findet sich in Beschreibung der Datenstruktur und im Programm main.c ind diesem Repo.

Nutzung der Funktion:

COMP_addition_komplex ( "Structname" , "Structname" , &"Structname" ) ;

Beispiel zur Nutzung der Funktion COMP_addition_komplex:
```
COMP_addition_komplex ( zahl_int , zahl_float , &zahl_ergebniss ) ;
```

### Ausgaben von komplexen Zahlen in Euler-form

## Editor 
Die library sowie das C-Programm wurden mit dem Editor vim in der WSL geschrieben.

## Kompilation
Ich hab für beide kompilationsporozesse jeweils den Compiler gcc verwendet.

### Library 
Die library kann einfach mit einem beliebigen Compiler kompiliert werden. Es muss zuerst das Objectfile (.o) aus der C-Datei (.c) erstellt werden. 

Beispiel: 
```
gcc -c COMP_lib.c -o COMP_lib.o
```
Anschließend muss das Archiv (.a) aus dem Objectfile erstellt werden.

Beispiel:
```
ar rcs libCOMP_lib.a COMP_lib.o
```

### Programm
Das Programm kann ebenfalls mit einem beliebigen Compiler einfach kompiliert werden. Dazu muss einmal die library COMP_lib, mit dem library search path, gelinkt werden sowie mathematische Bibiliothek eingebunden werden.

Beispiel:
```
gcc main.c -o main.elf -L. -lCOMP_lib -lm
```
