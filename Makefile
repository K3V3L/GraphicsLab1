all: clean compile run
compile: source.cpp
	g++ -lglut -lGL -lGLU -lGLEW source.cpp -o main 
run: main
	./main
clean: 
	rm -rf main
