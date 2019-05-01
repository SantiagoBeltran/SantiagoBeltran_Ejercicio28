calor.png: intento.dat
	python graficador.py

intento.dat : a.out
	./a.out

a.out: SantiagoBeltran_Ejercicio28.cpp
	g++ SantiagoBeltran_Ejercicio28.cpp
    
clean:
	rm -rf *.out *.dat
