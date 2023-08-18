Algoritmo Ejercicio10
	Definir n, promedio, nota3 Como Real
	Escribir "Ingrese la cantidad de notas:"
	Leer n
	x=1
	suma=0
	Mientras x<=n Hacer
		Escribir "Ingrese la nota: ",x
		Leer num
		suma=suma+num
		x=x+1
		
	FinMientras
	promedio= suma/n
	Escribir "El promedio de sus notas es de:",promedio
	nota3=(promedio*0.2)
	Escribir "La equivalencia de la tercera nota es de:", nota3
FinAlgoritmo
