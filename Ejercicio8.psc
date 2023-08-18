Algoritmo Ejercicio8
	Definir temp Como Caracter
	Definir  num_temp Como Real
	Escribir "Ingrese la escala de temperatura(Celsius,Kelvin,Fahrenheit):"
	Leer temp
	Escribir "Ingrese el número de la temperatura:"
	Leer num_temp
	si temp="Celsius" Entonces
		Kelvin=num_temp + 273.15
		Fahrenheit=(num_temp * 9/5) + 32
		Escribir "La temperatura de Celsius a Kelvin y Farenheit es:"
		Escribir Kelvin,"K°"
		Escribir Fahrenheit,"F°"
	SiNo
		si temp="Kelvin" Entonces
			Celsius=num_temp - 273.15
			Fahrenheit= (num_temp - 273.15) * 9/5 + 32
			Escribir "La temperatura de Kelvin a Celsius y Farenheit es:"
			Escribir Celsius,"C°"
			Escribir Fahrenheit, "F°"
		SiNo
			si temp="Fahrenheit" Entonces
				Celsius=(num_temp - 32) * 5/9 
				Kelvin=(num_temp - 32) * 5/9 + 273.1
				Escribir "La temperatura de Fahrenheit a Celsius y Kelvin es:"
				Escribir Kelvin,"K°"
				Escribir Celsius,"C°"
			FinSi
		
		FinSi
	FinSi
FinAlgoritmo
