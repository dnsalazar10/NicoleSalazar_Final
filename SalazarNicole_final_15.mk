SalazarNicole_final_15.pdf:   qplots.py       qdatos.dat
					python qplots.py
datos1.dat:a.out
					./a.out>>qdatos.dat
a.out: primero.cpp
					g++ primero.cpp
