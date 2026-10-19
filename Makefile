all:
    g++ main.cpp FileReader.cpp LanguageModel.cpp -o slm.exe
clean: 
    rm -f slm.exe

