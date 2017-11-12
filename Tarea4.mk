Resultados_hw4.pdf : Resultados_hw4.tex graficas.png
	pdflatex $< 
graficas.png : cuerda.tex tambor.tex Plots.py
	python Plots.py
cuerda.tex : Ondas.c
	gcc -lm Ondas.c
tambor.tex : Ondas.c
	gcc -lm Ondas.c
clean :
	rm cuerda.tex graficas.png tambor.tex 