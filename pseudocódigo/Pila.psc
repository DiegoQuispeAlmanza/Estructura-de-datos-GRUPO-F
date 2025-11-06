Proceso Pila_Pacientes
    Definir opcion, tope Como Entero
    Definir nombre, dni Como Cadena
    Definir edad Como Entero
    
    Dimension pilaNombre[100]
    Dimension pilaDNI[100]
    Dimension pilaEdad[100]
    
    tope <- 0
    
    Repetir
        Limpiar Pantalla
        Escribir "===== SISTEMA DE PACIENTES (PILA) ====="
        Escribir "1. Registrar paciente "
        Escribir "2. Atender paciente "
        Escribir "3. Mostrar pila"
        Escribir "4. Salir"
        Escribir "Seleccione una opción: " Sin Saltar
        Leer opcion
        
        Segun opcion Hacer
            1:
                Si tope = 100 Entonces
                    Escribir "La pila está llena. No se puede agregar más pacientes."
                SiNo
                    Limpiar Pantalla
                    Escribir "Ingrese nombre del paciente: " Sin Saltar
                    Leer nombre
                    Escribir "Ingrese DNI del paciente: " Sin Saltar
                    Leer dni
                    Escribir "Ingrese edad del paciente: " Sin Saltar
                    Leer edad
                    
                    tope <- tope + 1
                    pilaNombre[tope] <- nombre
                    pilaDNI[tope] <- dni
                    pilaEdad[tope] <- edad
                    
                    Escribir "Paciente agregado correctamente a la pila."
                FinSi
                Esperar Tecla
                
            2:
                Si tope = 0 Entonces
                    Escribir "La pila está vacía. No hay pacientes para atender."
                SiNo
                    Escribir "Atendiendo al paciente:"
                    Escribir "Nombre: ", pilaNombre[tope]
                    Escribir "DNI: ", pilaDNI[tope]
                    Escribir "Edad: ", pilaEdad[tope]
                    tope <- tope - 1
                    Escribir "Paciente retirado de la pila."
                FinSi
                Esperar Tecla
                
            3:
                Limpiar Pantalla
                Si tope = 0 Entonces
                    Escribir "La pila está vacía."
                SiNo
                    Escribir "===== PACIENTES EN LA PILA ====="
                    Para i <- tope Hasta 1 Con Paso -1 Hacer
                        Escribir "Nombre: ", pilaNombre[i]
                        Escribir "DNI: ", pilaDNI[i]
                        Escribir "Edad: ", pilaEdad[i]
                        Escribir "---------------------------"
                    FinPara
                FinSi
                Esperar Tecla
                
            4:
                Escribir "Saliendo del sistema..."
                
            De Otro Modo:
                Escribir "Opción inválida."
                Esperar Tecla
        FinSegun
    Hasta Que opcion = 4
FinProceso
