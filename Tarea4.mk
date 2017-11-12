Resultados_hw4.pdf : Resultados_hw4.tex *.png
	pdflatex $< 
*.png : *.dat Plots.py
	python Plots.py
*.dat : sale.out
	./sale.out
sale.out : Ondas.c
	gcc -lm Ondas.c
clean :
	rm *.dat *.png *.log *.aux sale.out