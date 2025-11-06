Algoritmo Lista_Enlazada_Pacientes
	Definir opcion, i, total Como Entero
	Definir pacienteNombre, pacienteDNI Como Cadena
	Definir pacienteEdad Como Entero
	// lista enlazada con arreglos paralelos
	Dimensionar nombres(100)
	Dimensionar dnis(100)
	Dimensionar edades(100)
	Dimensionar siguiente(100)
	total <- 0
	primero <- 0
	ultimo <- 0
	Repetir
		Limpiar Pantalla
		Escribir '===== SISTEMA DE PACIENTES (LISTA ENLAZADA) ====='
		Escribir '1. Agregar paciente'
		Escribir '2. Mostrar lista'
		Escribir '3. Salir'
		Escribir 'Seleccione una opción: 'Sin Saltar
		Leer opcion
		Según opcion Hacer
			1:
				Limpiar Pantalla
				Escribir 'Ingrese nombre del paciente: 'Sin Saltar
				Leer pacienteNombre
				Escribir 'Ingrese DNI del paciente: 'Sin Saltar
				Leer pacienteDNI
				Escribir 'Ingrese edad del paciente: 'Sin Saltar
				Leer pacienteEdad
				total <- total+1
				nombres[total] <- pacienteNombre
				dnis[total] <- pacienteDNI
				edades[total] <- pacienteEdad
				siguiente[total] <- 0
				Si primero=0 Entonces
					primero <- total
				SiNo
					siguiente[ultimo] <- total
				FinSi
				ultimo <- total
				Escribir 'Paciente agregado correctamente.'
				Esperar Tecla
			2:
				Limpiar Pantalla
				Escribir '===== LISTA DE PACIENTES ====='
				Si primero=0 Entonces
					Escribir 'No hay pacientes registrados.'
				SiNo
					i <- primero
					Mientras i<>0 Hacer
						Escribir 'Nombre: ', nombres[i]
						Escribir 'DNI: ', dnis[i]
						Escribir 'Edad: ', edades[i]
						Escribir '---------------------------'
						i <- siguiente[i]
					FinMientras
				FinSi
				Esperar Tecla
			3:
				Escribir 'Saliendo del sistema...'
			De Otro Modo:
				Escribir 'Opción inválida.'
				Esperar Tecla
		FinSegún
	Hasta Que opcion=3
FinAlgoritmo
