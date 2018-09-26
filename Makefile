GRAPH = Graph/Graph.cpp
SRC1=  src1/main.cpp 
SRC2=  src2/main.cpp 

all: $(GRAPH) $(SRC1) $(SRC2)
	  g++ -o program1.out $(GRAPH) $(SRC1)
	  g++ -o program2.out $(GRAPH) $(SRC2)

debug: $(GRAPH) $(SRC1) $(SRC2)
	  g++ -g -o program1.out $(GRAPH) $(SRC1)
	  g++ -g -o program2.out $(GRAPH) $(SRC2)

warnings: $(GRAPH) $(SRC1) $(SRC2)
	  g++ -g -Wall -Wextra -o program1.out $(GRAPH) $(SRC1)
	  g++ -g -Wall -Wextra -o program2.out $(GRAPH) $(SRC2)

clean:
	rm -rf *.out *.satinput
