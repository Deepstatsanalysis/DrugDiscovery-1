SRC1=  src1/main.cpp 
SRC2=  src2/main.cpp 

all: $(SRC1) $(SRC2)
	  g++ -o program1.out $(SRC1)
	  g++ -o program2.out $(SRC2)

debug: $(SRC1) $(SRC2)
	  g++ -g -o program1.out $(SRC1)
	  g++ -g -o program2.out $(SRC2)

warnings: $(SRC1) $(SRC2)
	  g++ -g -Wall -Wextra -o program1.out $(SRC1)
	  g++ -g -Wall -Wextra -o program2.out $(SRC2)

clean:
	rm -rf *.out
