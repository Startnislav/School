BIN	 :=CALCULATOR
LIB :=libSimpleFunction.so
LIB_SOURCES := deduction.c multiplication.c segmentation.c addition.c
SOURCES := main.c 
HEADERS :=deduction.h multiplication.h segmentation.h addition.h

$(LIB): $(BIN) clean
		gcc -fPIC -c deduction.c
		gcc -fPIC -c multiplication.c
		gcc -fPIC -c segmentation.c
		gcc -fPIC -c addition.c
		gcc -shared -o Plagins/$(LIB) *.o
$(BIN) : $(SOURCES)
		gcc $(SOURCES) -c
		gcc main.o -o $(BIN) -ldl -Wl,-rpath,./Plagins/
$(BIN):$(HEADERS)


clean:
		rm  -rf *.o
	       	rm -rf Plagins/*.so	
