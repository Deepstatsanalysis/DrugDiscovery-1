COMMONSRC = commonSrc/Graph.cpp
SRC1=  src1/main.cpp 
SRC2=  src2/main.cpp 

all: $(COMMONSRC) $(SRC1) $(SRC2)
	  g++ -o program1.out $(COMMONSRC) $(SRC1)
	  g++ -o program2.out $(COMMONSRC) $(SRC2)

debug: $(COMMONSRC) $(SRC1) $(SRC2)
	  g++ -g -o program1.out $(COMMONSRC) $(SRC1)
	  g++ -g -o program2.out $(COMMONSRC) $(SRC2)

warnings: $(COMMONSRC) $(SRC1) $(SRC2)
	  g++ -g -Wall -Wextra -o program1.out $(COMMONSRC) $(SRC1)
	  g++ -g -Wall -Wextra -o program2.out $(COMMONSRC) $(SRC2)

clean:
	rm -rf *.out
