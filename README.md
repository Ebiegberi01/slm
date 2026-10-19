SMALL LANGUAGE MODEL by Samson Ebiegberi Stanley
This project implements a small language model using k-grams.

Files in this project are: main.cpp; LanguageModel.cpp; LanguageModel.h; FileReader.h; FileReader.cpp; a_modest_proposal.txt; moby_dick.txt; Gutenberg_license.txt; Makefile.txt; slm.exe

Compiled with the Makefile.txt

Tested with: ./slm.exe 3 Gutenberg_license.txt 30;  ./slm.exe 3 moby_dick.txt 50

Design: FileReader - reads text from files; LanguageModel - builds k-gram statics and generates text.

Exception Handling: The program throws exception when: too few argumenst are thrown(argc < 4); file cant be accessed; k is larger than text length

The project made me leaarn a lot about random  number generation and also updated my knowledge exceptions.