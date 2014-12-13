DEBUG= 
EXECS= cuShell logger

all:	$(EXECS)

logger:	logger.c
	gcc $(DEBUG) -o logger logger.c

cuShell:	cuShell.c
	gcc $(DEBUG) -o cuShell cuShell.c

clean:
	rm -f $(EXECS)

cleanlogs:
	rm -f *.log
