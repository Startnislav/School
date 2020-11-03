BIN:main
SOURCES:main
SOURCES1:Function
CC:gcc
all: $(BIN)
$(BIN): $(SOURCES)$(SOURCES1)
		$(CC) -c $(SOURCES).c
		$(CC) -c $(SOURCES1).c
		$(CC)$(SOURCES).o $(SOURCES1).o -o $(BIN) $(SOURCES)
		./$(BIN)



clean:
		rm-rf $(BIN)
