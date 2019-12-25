CLEANEXTS   = o
EXEFILE = exec.exe

.PHONY: all
all: $(EXEFILE)

$(EXEFILE): Lab5.o
	g++ -o $(EXEFILE) Lab5.o 



.PHONY: clean 
clean:
	for file in $(CLEANEXTS); do rm -f *.$$file; done

# Indicate dependencies of .ccp files on .hpp files
Lab5.o: Lab5.cpp
