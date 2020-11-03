BIN	 :=CALCULATOR
LIB :=libCalc.a 
LIB_SOURCES := deduction.c multiplication.c segmentation.c addition.c
SOURCES := main.c 
HEADERS :=deduction.h multiplication.h segmentation.h addition.h


all: $(LIB) $(BIN) 
		gcc $(LIB_SOURCES) -c
		ar rc  $(LIB) *.o

$(BIN) : $(SOURCES)
		gcc $(SOURCES) -c
		gcc  $(SOURCES) -L. -lCalc -o $(BIN)

$(BIN):$(HEADERS)



clean:
		rm -f *.o *.so

