#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para calcular la secuencia de Fibonacci hasta un número dado
void calcularFibonacci(int numeroMaximo) {
    int a = 0, b = 1, c = 0;

    cout << "Secuencia de Fibonacci hasta el numero " << numeroMaximo << ":" << endl;

    while (c <= numeroMaximo) {
        cout << c << " ";
        a = b;
        b = c;
        c = a + b;
    }

    cout << endl;
}

// Función para el juego de adivinanzas
void juegoAdivinanzas() {
    srand(time(0));
    int numeroAleatorio = rand() % 100 + 1;
    int intentos = 0;
    int numeroUsuario;

    cout << "Bienvenido al juego de adivinanzas. Adivina el numero del 1 al 100." << endl;

    do {
        cout << "Ingresa tu intento: ";
        cin >> numeroUsuario;
        intentos++;

        if (numeroUsuario < numeroAleatorio) {
            cout << "Intenta con un numero mayor." << endl;
        } else if (numeroUsuario > numeroAleatorio) {
            cout << "Intenta con un numero menor." << endl;
        } else {
            cout << "¡Felicitaciones! Adivinaste el numero en " << intentos << " intentos." << endl;
        }
    } while (numeroUsuario != numeroAleatorio);
}

// Estructura de una tarea
struct Tarea {
    string descripcion;
    bool completada;
};

// Función para el gestor de tareas
void gestorTareas() {
    vector<Tarea> tareas;
    int opcion;

    do {
        cout << "====== GESTOR DE TAREAS ======" << endl;
        cout << "1. Agregar tarea" << endl;
        cout << "2. Marcar tarea como completada" << endl;
        cout << "3. Listar tareas pendientes" << endl;
        cout << "4. Listar todas las tareas" << endl;
        cout << "5. Eliminar tarea" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Tarea nuevaTarea;
                cout << "Ingrese la descripcion de la tarea: ";
                cin.ignore();
                getline(cin, nuevaTarea.descripcion);
                nuevaTarea.completada = false;
                tareas.push_back(nuevaTarea);
                cout << "Tarea agregada correctamente." << endl;
                break;
            }
            case 2: {
                int numeroTarea;
                cout << "Ingrese el numero de la tarea a marcar como completada: ";
                cin >> numeroTarea;

                if (numeroTarea >= 1 && numeroTarea <= tareas.size()) {
                    tareas[numeroTarea - 1].completada = true;
                    cout << "Tarea marcada como completada." << endl;
                } else {
                    cout << "Numero de tarea invalido." << endl;
                }
                break;
            }
            case 3: {
                cout << "Tareas pendientes:" << endl;
                for (int i = 0; i < tareas.size(); i++) {
                    if (!tareas[i].completada) {
                        cout << i + 1 << ". " << tareas[i].descripcion << endl;
                    }
                }
                break;
            }
            case 4: {
                cout << "Todas las tareas:" << endl;
                for (int i = 0; i < tareas.size(); i++) {
                    cout << i + 1 << ". ";
                    if (tareas[i].completada) {
                        cout << "[Completada] ";
                    }
                    cout << tareas[i].descripcion << endl;
                }
                break;
            }
            case 5: {
                int numeroTarea;
                cout << "Ingrese el numero de la tarea a eliminar: ";
                cin >> numeroTarea;

                if (numeroTarea >= 1 && numeroTarea <= tareas.size()) {
                    tareas.erase(tareas.begin() + (numeroTarea - 1));
                    cout << "Tarea eliminada correctamente." << endl;
                } else {
                    cout << "Numero de tarea invalido." << endl;
                }
                break;
            }
            case 6:
                cout << "Saliendo del gestor de tareas." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                break;
        }

        cout << endl;
    } while (opcion != 6);
}

// Función para la calculadora básica
void calculadora() {
    double num1, num2;
    char operador;

    cout << "Ingrese el primer numero: ";
    cin >> num1;
    cout << "Ingrese el operador (+, -, *, /): ";
    cin >> operador;
    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    double resultado;

    switch (operador) {
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;
        case '/':
            resultado = num1 / num2;
            break;
        default:
            cout << "Operador invalido." << endl;
            return;
    }

    cout << "El resultado es: " << resultado << endl;
}

// Estructura de un libro
struct Libro {
    string titulo;
    string autor;
    bool disponible;
};

// Función para el sistema de gestión de biblioteca
void gestionBiblioteca() {
    vector<Libro> catalogo;
    int opcion;

    do {
        cout << "====== SISTEMA DE GESTION DE BIBLIOTECA ======" << endl;
        cout << "1. Agregar libro" << endl;
        cout << "2. Eliminar libro" << endl;
        cout << "3. Buscar libro por titulo o autor" << endl;
        cout << "4. Verificar disponibilidad de un libro" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Libro nuevoLibro;
                cout << "Ingrese el titulo del libro: ";
                cin.ignore();
                getline(cin, nuevoLibro.titulo);
                cout << "Ingrese el autor del libro: ";
                getline(cin, nuevoLibro.autor);
                nuevoLibro.disponible = true;
                catalogo.push_back(nuevoLibro);
                cout << "Libro agregado correctamente." << endl;
                break;
            }
            case 2: {
                int numeroLibro;
                cout << "Ingrese el numero del libro a eliminar: ";
                cin >> numeroLibro;

                if (numeroLibro >= 1 && numeroLibro <= catalogo.size()) {
                    catalogo.erase(catalogo.begin() + (numeroLibro - 1));
                    cout << "Libro eliminado correctamente." << endl;
                } else {
                    cout << "Numero de libro invalido." << endl;
                }
                break;
            }
            case 3: {
                string busqueda;
                cout << "Ingrese el titulo o autor a buscar: ";
                cin.ignore();
                getline(cin, busqueda);

                cout << "Resultados de busqueda:" << endl;
                for (int i = 0; i < catalogo.size(); i++) {
                    if (catalogo[i].titulo.find(busqueda) != string::npos || catalogo[i].autor.find(busqueda) != string::npos) {
                        cout << i + 1 << ". " << catalogo[i].titulo << " - " << catalogo[i].autor << endl;
                    }
                }
                break;
            }
            case 4: {
                int numeroLibro;
                cout << "Ingrese el numero del libro a verificar disponibilidad: ";
                cin >> numeroLibro;

                if (numeroLibro >= 1 && numeroLibro <= catalogo.size()) {
                    if (catalogo[numeroLibro - 1].disponible) {
                        cout << "El libro esta disponible." << endl;
                    } else {
                        cout << "El libro no esta disponible." << endl;
                    }
                } else {
                    cout << "Numero de libro invalido." << endl;
                }
                break;
            }
            case 5:
                cout << "Saliendo del sistema de gestion de biblioteca." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                break;
        }

        cout << endl;
    } while (opcion != 5);
}

// Función para el programa de simulación básica
void simulacion() {
    // Aquí puedes agregar la lógica de tu simulación
    cout << "Simulacion en proceso..." << endl;
}

// Función principal que muestra el menú de selección de programas
int main() {
    int opcion;

    do {
        cout << "====== MENU DE PROGRAMAS ======" << endl;
        cout << "1. Programa de calculo de Fibonacci" << endl;
        cout << "2. Juego de adivinanzas" << endl;
        cout << "3. Gestor de tareas" << endl;
        cout << "4. Calculadora" << endl;
        cout << "5. Sistema de gestion de biblioteca" << endl;
        cout << "6. Programa de simulacion" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int numeroMaximo;
                cout << "Ingrese el numero maximo para la secuencia de Fibonacci: ";
                cin >> numeroMaximo;
                calcularFibonacci(numeroMaximo);
                break;
            }
            case 2:
                juegoAdivinanzas();
                break;
            case 3:
                gestorTareas();
                break;
            case 4:
                calculadora();
                break;
            case 5:
                gestionBiblioteca();
                break;
            case 6:
                simulacion();
                break;
            case 7:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                break;
        }

        cout << endl;
    } while (opcion != 7);

    return 0;
}
