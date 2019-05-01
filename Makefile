laplace.png: intento.dat
	python graficador.py

intento.dat : a.out
	./a.out

a.out: intent.cpp
	g++ intent.cpp
    
clean:
	rm -rf *.out *.dat