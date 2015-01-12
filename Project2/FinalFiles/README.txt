Compile by executing 

gmakemake > Makefile
make
and then ./weather

This program prompts the user for the time of the observation, as well as the temperature. The program accepts time 
in the format HH:MM, and reject any time less than 00:00, and greater than 23:59. 
In the case of an invalid time entry, "Time is out of range" is printed to STDERR and program execution will 
continue.

The program would not accept more than 24 observations. If over 24 observations are entered, the program will return 
"Maximum number of observations recorded" to STDERR and immediately show the results (average, highs and lows).

To exit data entry prior to 24 entries, use CTRL-D