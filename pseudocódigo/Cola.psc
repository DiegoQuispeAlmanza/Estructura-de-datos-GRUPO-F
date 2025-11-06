Algoritmo Cola_Pacientes
	Definir opcion, frente, ultimo Como Entero
	Definir nombre, dni Como Cadena
	Definir edad Como Entero
	Dimensionar colaNombre(100)
	Dimensionar colaDNI(100)
	Dimensionar colaEdad(100)
	frente <- 1
	ultimo <- 0
	Repetir
		Limpiar Pantalla
		Escribir '===== SISTEMA DE GESTIÓN DE CITAS (COLA DE PACIENTES) ====='
		Escribir '1. Registrar cita (Encolar)'
		Escribir '2. Atender paciente (Desencolar)'
		Escribir '3. Mostrar pacientes en espera'
		Escribir '4. Salir'
		Escribir 'Seleccione una opción: 'Sin Saltar
		Leer opcion
		Según opcion Hacer
			1:
				Si ultimo=100 Entonces
					Escribir 'La cola está llena. No se pueden registrar más pacientes.'
				SiNo
					Escribir 'Ingrese nombre del paciente: 'Sin Saltar
					Leer nombre
					Escribir 'Ingrese DNI del paciente: 'Sin Saltar
					Leer dni
					Escribir 'Ingrese edad del paciente: 'Sin Saltar
					Leer edad
					ultimo <- ultimo+1
					colaNombre[ultimo] <- nombre
					colaDNI[ultimo] <- dni
					colaEdad[ultimo] <- edad
					Escribir '? Paciente registrado correctamente.'
				FinSi
				Esperar Tecla
			2:
				Si frente>ultimo Entonces
					Escribir 'No hay pacientes en espera.'
				SiNo
					Escribir 'Atendiendo al paciente:'
					Para i<-frente Hasta ultimo Con Paso 1 Hacer
						Escribir 'Nombre: ', colaNombre[i]
						Escribir 'DNI: ', colaDNI[i]
						Escribir 'Edad: ', colaEdad[i]
						Escribir '-----------------------------'
					FinPara
					Escribir 'Nombre: ', colaNombre[frente]
					Escribir 'DNI: ', colaDNI[frente]
					Escribir 'Edad: ', colaEdad[frente]
					frente <- frente+1
					Escribir 'Paciente atendido correctamente.'
				FinSi
				Esperar Tecla
			3:
				Si frente>ultimo Entonces
					Escribir 'No hay pacientes en la cola.'
				SiNo
					Escribir '===== PACIENTES EN ESPERA ====='
				FinSi
				Esperar Tecla
			4:
				Escribir 'Saliendo del sistema...'
			De Otro Modo:
				Escribir 'Opción inválida.'
				Esperar Tecla
		FinSegún
	Hasta Que opcion=4
FinAlgoritmo
