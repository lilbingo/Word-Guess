com = g++-10
prog = wordGuess.cpp
out = guessing
ver = -std=c++2a

make:
	$(com) $(ver) $(prog) -o $(out) 

run:
	$(com) $(ver) $(prog) -o $(out)
	./$(out)

clean:
	rm -f $(out)
