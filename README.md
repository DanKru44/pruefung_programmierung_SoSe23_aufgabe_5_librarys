# Librarys
In diesem Repo befindet sich die Bearbeitung der Aufgabe 5 der Modulprüfung Programmierung im Sommersemester 2023. 

Dieses Repo enthält eine library die den Umgang mit komplexen Zahlen geschrieben wurde. Für das Rechnen mit Komplexen Zahlen wurde hierfür Zwei Datentypen angelegt. COMP_int und COMP-float. Für diese beiden Datentypen gibt es jeweils eine Funktion um die 2-Nrom zu bestimmen. In der library befindet sich ebenfalls eine Funktion zum addieren zweier COMP_Elemente und eine Funktion zum ausgeben eines COMP_Elements in Eulerform.

In diesem Repo befindet sich ebenfalls ein C-Programm dass mir zum testen der Funktionen diente. In diesem Programm werden die Funktionen nach einander aufgerufen und die Ergebnisse ins Terminal geprintet.


## Dokumentation der Bibliothek

## Editor 
Die library sowie das C-Programm wurden mit dem Editor vim in der WSL geschrieben.

## Kompilation
Ich hab für beide kompilationsporozesse jeweils den Compiler gcc verwendet.

### Library 
Die library kann einfach mit einem beliebigen Compiler kompiliert werden. ES muss zuerst das Objectfile (.o) aus der C-Datei (.c) erstellt werden. 

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
