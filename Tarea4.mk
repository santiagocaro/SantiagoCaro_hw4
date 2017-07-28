PuntoNemo.pdf:plots_nemo.py salida.txt
	python plots_nemo.py
	
salida.txt:PuntoGeographicPoint.c
	cc PuntoGeographicPoint.c -lm
	./a.out
