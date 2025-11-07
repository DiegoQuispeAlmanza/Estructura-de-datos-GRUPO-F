#include <iostream>
#include <string>
#include <locale> 

using namespace std;

// Funci贸n para limpiar el buffer al encontrar el \n para el pr贸xima getline
void limpiarBuffer() {
    cin.ignore(1000, '\n'); 
}

// ESTRUCTURAS DE DATOS

// 1 Paciente - Lista 
struct Paciente {
    string nombre;
    string dni;
    int edad;
    Paciente *siguiente;
};

// 2 Cita - Cola
struct Cita {
    string nombre;
    string especialidad;
    Cita *siguiente;
};

// 3 CasoClinicoActivo - Pila 
struct CasoClinicoActivo {
    string dniPaciente;        
    string diagnosticoPreliminar; 
    CasoClinicoActivo *siguiente;
};

// Funciones de la COLA para atender citas

// Ver siguiente cita
void verProximaCita(Cita* inicio) {
    if (inicio == NULL) {
        cout << "La cola de citas esta vacia. No hay citas en espera." << endl;
        return;
    }
    cout << "\n>>> SIGUIENTE CITA <<<" << endl;
    cout << "Paciente: " << inicio->nombre << endl;
    cout << "Especialidad: " << inicio->especialidad << endl;
}


// Se atiende la primera cita para DESENCOLAR
void atenderCita(Cita* &inicio, Cita* &fin) {
    if (inicio == NULL) {
        cout << "La cola de citas esta vacia. No hay citas para atender." << endl;
        return;
    }

    Cita *p = inicio; 
    cout << "Atendiendo cita de: " << p->nombre << " para " << p->especialidad << " (DESENCOLAR)." << endl;
    inicio = inicio->siguiente;
    if (inicio == NULL) fin = NULL; 

    delete p;
}

// Funci贸n para buscar paciente por DNI en la LISTA ENLAZADA
void buscarPacientePorDNI(Paciente* inicio) {
    if (inicio == NULL) {
        cout << "no hay pacientes registrados" << endl;
        return;
    }

    string dniBuscado;
    cout << "\n========== BUSCAR PACIENTE POR DNI ==========\n";
    cout << "Ingresa el DNI del paciente que deseas buscar: ";
    getline(cin >> ws, dniBuscado);

    Paciente* actual = inicio;
    bool encontrado = false;

    while (actual != NULL) {
        if (actual->dni == dniBuscado) {
            cout << "\n----- PACIENTE ENCONTRADO ---" << endl;
            cout << "Nombre: " << actual->nombre << endl;
            cout << "DNI: " << actual->dni << endl;
            cout << "Edad: " << actual->edad << endl;
            encontrado = true;
            break;
        }
        actual = actual->siguiente;
    }

    if (!encontrado)
        cout << "No se encontro al paciente" << endl;
}

//Funci贸n para registrar en una LISTA y a la vez ENCOLAR 

void registrarPaciente(Paciente* &inicio, Cita* &inicioCola, Cita* &finCola) {
    
    // P1: Registrar paciente en la LISTA 
    Paciente *nuevo = new Paciente();
    cout << "\n--- 1. REGISTRAR NUEVO PACIENTE ---\n";
    cout << "Nombre: "; getline(cin >> ws, nuevo->nombre);
    cout << "DNI: "; getline(cin, nuevo->dni);
    cout << "Edad: "; cin >> nuevo->edad;
    // Se agrega a la lista enlazada
    nuevo->siguiente = inicio;
    inicio = nuevo;
    cout << "Paciente " << nuevo->nombre << " registrado en el sistema." << endl;
    
    // P2: Asignar cita para la COLA
    Cita *nuevaCita = new Cita();
    nuevaCita->nombre = nuevo->nombre; 
    
    // Se solicita la informaci贸n adicional necesaria para la Cita
    limpiarBuffer(); 
    cout << "\n--- 2. ASIGNAR PRIMERA CITA ---\n";
    cout << "驴Especialidad o motivo de la Cita?: "; 
	getline(cin, nuevaCita->especialidad);
    nuevaCita->siguiente = NULL; 

    // Logica de ENCOLAR
    if (inicioCola == NULL) {
        inicioCola = nuevaCita;
        finCola = nuevaCita;
    } else {
        finCola->siguiente = nuevaCita;
        finCola = nuevaCita;
    }
    cout << "Cita automatica para " << nuevaCita->nombre << " registrada en la Cola de espera." << endl;
}

// Funcion de PILA para los casos cl铆nicos

// Se procede a la ASIGNACION de memoria
void iniciarCasoActivo(CasoClinicoActivo* &tope) {
    CasoClinicoActivo *nuevoCaso = new CasoClinicoActivo();
    cout << "\n--- INICIAR CASO CLINICO (ASIGNAR) ---\n";
    cout << "DNI del Paciente: "; getline(cin >> ws, nuevoCaso->dniPaciente);
    cout << "Diagnostico Preliminar: "; getline(cin, nuevoCaso->diagnosticoPreliminar);
    
    nuevoCaso->siguiente = tope;
    tope = nuevoCaso;
    
    cout << "Caso del DNI " << nuevoCaso->dniPaciente 
         << " iniciado y en foco de atencion (Asignacion de 'Memoria')." << endl;
}

// Se procede a la LIBERACION de memoria
void cerrarCasoActivo(CasoClinicoActivo* &tope) {
    if (tope == NULL) {
        cout << "La pila de casos activos esta vacia. No hay casos para cerrar." << endl;
        return;
    }
    
    CasoClinicoActivo *p = tope;
    cout << "Caso del DNI " << p->dniPaciente 
         << " cerrado (Liberacion)." << endl;
    tope = tope->siguiente;
    delete p;
}

// Funci髇 para buscar un caso activo por DNI 
void buscarCasoActivoPorDNI(CasoClinicoActivo* tope) {
    if (tope == NULL) {
        cout << "\nLa pila de casos activos esta vacia. No hay casos en seguimiento." << endl;
        return;
    }

    string dniBuscado;
    cout << "\n--- BUSCAR CASO ACTIVO POR DNI ---\n";
    cout << "Ingresa el DNI del paciente cuyo caso buscas: ";

    getline(cin >> ws, dniBuscado); 

    CasoClinicoActivo* actual = tope;
    bool encontrado = false;
    int posicion = 1; 

    while (actual != NULL) {
        if (actual->dniPaciente == dniBuscado) {
            cout << "\n----- CASO ACTIVO ENCONTRADO -----" << endl;
            cout << "DNI: " << actual->dniPaciente << endl;
            cout << "Diagnostico Preliminar: " << actual->diagnosticoPreliminar << endl;
            cout << "Posicion en la Pila (Profundidad): " << posicion << " (Tope es 1)" << endl;
            encontrado = true;
            break; 
        }
        actual = actual->siguiente; 
        posicion++;
    }

    if (!encontrado) {
        cout << "No se encontro un caso activo para el DNI " << dniBuscado << "." << endl;
    }
}

// FUNCION MAIN

int main() {
    setlocale(LC_ALL, "Spanish"); 
    
    Paciente *inicioLista = NULL; 
    Cita *inicioCola = NULL; 
    Cita *finCola = NULL; 
    CasoClinicoActivo *topePilaCasos = NULL; 
    int opcion;

    do {
        cout << "\n========= Sistema de clinica =========";
        cout << "\n1. Registrar Paciente y Asignar Cita (Lista y Enconlar)";
        cout << "\n2. Atender Proxima Cita (Desencolar)";
        cout << "\n3. Ver Proxima Cita (Mostrar)"; 
        cout << "\n4. Seguimiento de Casos Clinicos (Pila)";
		cout << "\n5. Buscar Paciente por DNI";
        cout << "\n6. Salir";
        cout << "\nSeleccione una opcion: ";
        if (!(cin >> opcion)) { 
             cin.clear(); 
			 limpiarBuffer();
			 opcion = 0;
        }

        switch(opcion) {
            case 1: 
                registrarPaciente(inicioLista, inicioCola, finCola);
                break;
            case 2: 
                atenderCita(inicioCola, finCola); 
                break;
            case 3: 
                verProximaCita(inicioCola);
                break;
            case 4: { 
                int op_casos;
                do {
                    cout << "\n--- MODULO SEGUIMIENTO DE CASOS ---";
                    cout << "\n1. Iniciar Caso Clinico (ASIGNAR)";
                    cout << "\n2. Cerrar Caso Clinico (LIBERAR)";
                    cout << "\n3. Buscar Caso Activo por DNI";
                    cout << "\n4. Volver al menu principal";
                    cout << "\nSeleccione una opcion: ";
                    if (!(cin >> op_casos)) {
                         cin.clear(); 
						 limpiarBuffer(); 
						 op_casos = 0;
                    }
                    limpiarBuffer();
                    
                    switch(op_casos) {
                        case 1: iniciarCasoActivo(topePilaCasos); break;
                        case 2: cerrarCasoActivo(topePilaCasos); break;
                        case 3: buscarCasoActivoPorDNI(topePilaCasos); break; 
						case 4: break; 
						default: cout << "Opcion invalida." << endl;
                    }
                } while (op_casos != 4);
                break;
            }
            case 5:
                buscarPacientePorDNI(inicioLista);
                break;
			case 6:
			cout << "\nSaliendo del fragmento... Adios!\n";
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 6);

    return 0;
}

