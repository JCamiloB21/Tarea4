all: Resultados_hw4.pdf sonido.wav
sonido.wav: Plots.py audio.dat
    python Plots.py
audio.dat: Ondas.c
	gcc -lm Ondas.c
Resultados_hw4.pdf : Resultados_hw4.tex graficas.png
	pdflatex $< 
graficas.png : cuerda.tex tambor.tex Plots.py
	python Plots.py
cuerda.tex : Ondas.c
	gcc -lm Ondas.c
tambor.tex : Ondas.c
	gcc -lm Ondas.c

