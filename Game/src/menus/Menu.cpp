#include "Menu.h"

using namespace std;

Menu::Menu() : nombreJuego("UNO") {}

Menu::~Menu()
{
    // Liberar recursos si es necesario
}

void Menu::limpiarPantalla()
{
    system("cls"); // En Windows
    // Linux: system("clear");
}

void Menu::mostrarLinea(int ancho)
{
    for (int i = 0; i < ancho; i++)
    {
        cout << "=";
    }
    cout << endl;
}

void Menu::mostrarMenuPrincipal()
{
    limpiarPantalla();
    mostrarLinea(40);
    cout << "   BIENVENIDO A " << nombreJuego << endl;
    mostrarLinea(40);
    cout << "1. Iniciar Juego" << endl;
    cout << "2. Reglas" << endl;
    cout << "3. Salir" << endl;
    mostrarLinea(40);
}

void Menu::limpiarBuffer()
{
    if (cin.fail())
    {
        cin.clear();
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int Menu::obtenerOpcion(int minimo, int maximo)
{
    int opcion;
    bool valida = false;
    int intentos = 0;
    const int MAX_INTENTOS = 5;

    while (!valida)
    {
        try
        {
            cout << "Ingresa tu opcion (" << minimo << "-" << maximo << "): ";

            // Verificar si cin está en buen estado antes de leer
            if (cin.eof())
            {
                throw InputBufferException();
            }

            string entrada;
            getline(cin, entrada);

            // Verificar si la entrada está vacía
            if (entrada.empty())
            {
                throw InvalidInputException("No se ingresó ningún valor");
            }

            // Verificar que solo contenga dígitos (y opcionalmente un signo negativo)
            bool esNumero = true;
            size_t inicio = 0;
            if (entrada[0] == '-' || entrada[0] == '+')
            {
                inicio = 1;
            }

            for (size_t i = inicio; i < entrada.length(); i++)
            {
                if (!isdigit(entrada[i]))
                {
                    esNumero = false;
                    break;
                }
            }

            if (!esNumero || entrada.length() == inicio)
            {
                throw InvalidInputException("Debe ingresar un número válido");
            }

            // Convertir la entrada a entero
            try
            {
                opcion = stoi(entrada);
            }
            catch (const out_of_range &)
            {
                throw InvalidInputException("Número demasiado grande");
            }
            catch (const invalid_argument &)
            {
                throw InvalidInputException("No es un número válido");
            }

            // Verificar si está en el rango
            if (opcion < minimo || opcion > maximo)
            {
                throw OutOfRangeInputException(opcion, minimo, maximo);
            }

            valida = true;
        }
        catch (const InputException &e)
        {
            intentos++;
            if (intentos >= MAX_INTENTOS)
            {
                cout << "Demasiados intentos fallidos. Usando opción por defecto: " << minimo << endl;
                return minimo;
            }
            cout << "Por favor, intenta de nuevo." << endl;
        }
    }

    return opcion;
}

void Menu::mostrarReglas()
{
    limpiarPantalla();
    cout << "REGLAS:" << endl;
    cout << "1. El objetivo es quedarse sin cartas." << endl;
    cout << "2. Cada jugador comienza con 7 cartas." << endl;
    cout << "3. En tu turno, debes jugar una carta que coincida en color o número con la carta superior del mazo." << endl;
    cout << "4. Si no puedes jugar, debes robar una carta del mazo." << endl;
    cout << "5. Cartas especiales: +2, +4, reversa, salto, comodín." << endl;
    cout << "6. Cuando te quede una sola carta, debes decir 'UNO'." << endl;
    cout << "7. El primer jugador en quedarse sin cartas gana." << endl;
    cout << "\nPresiona Enter para volver al menú principal..." << endl;

    try
    {
        limpiarBuffer();
        cin.get();
    }
    catch (...)
    {
        // Si hay problemas con la entrada, simplemente continuar
        cout << "Continuando..." << endl;
    }
}

void Menu::pedirConfiguracion()
{
    limpiarPantalla();
    mostrarLinea(40);
    cout << "ELIGE UNA OPCION " << endl;
    mostrarLinea(40);
    cout << "[1]. Configuracion predeterminada" << endl;
    cout << "[2]. Configuracion personalizada" << endl;
    mostrarLinea(40);
}

void Menu::pedirCantidadJugadores()
{
    limpiarPantalla();
    mostrarLinea(40);
    cout << "CANTIDAD DE JUGADORES" << endl;
    mostrarLinea(40);
    cout << "Ingresa un valor entre minimo 2" << endl;
    mostrarLinea(40);
}

void Menu::mostrarConfiguracion()
{
    limpiarPantalla();
    mostrarLinea(40);
    cout << "CONFIGURACION PERSONALIZADA" << endl;
    mostrarLinea(40);
    cout << "[1] Acumulacion" << endl;
    cout << "[2] Reto del +4" << endl;
    cout << "[3] Modo de robo" << endl;
    cout << "[4] Grito UNO!" << endl;
    cout << "[5] Continuar >>>>>" << endl;
    cout << "[6] Regresar <<<<<" << endl;
    mostrarLinea(40);
}

void Menu::mostrarConfiguracion(Setting &configuration)
{
    mostrarConfiguracion();
}

void Menu::mostrarMenuStacking(Setting &configuration)
{
    limpiarPantalla();
    mostrarLinea(40);
    cout << "Acumulacion +2: " << "\033[33m" << (configuration.getPlusTwoStacking() ? "Activada" : "Desactivada") << "\x1b[0m" << endl;
    cout << "[1] Cambiar acumulacion +2" << endl;
    cout << endl;
    cout << "Acumulacion +4: " << "\033[33m" << (configuration.getPlusFourStacking() ? "Activada" : "Desactivada") << "\x1b[0m" << endl;
    cout << "[2] Cambiar acumulacion +4" << endl;
    cout << endl;
    cout << "[3] informacion" << endl;
    cout << "[4] Regresar <<<<<" << endl;
    mostrarLinea(40);
}

void Menu::mostrarMenuDare(Setting &configuration)
{
    limpiarPantalla();
    mostrarLinea(40);
    cout << "Reto del +4: " << "\033[33m" << (configuration.getPlusFourDare() ? "Activado" : "Desactivado") << "\x1b[0m" << endl;
    cout << "[1] Cambiar reto del +4" << endl;
    cout << endl;
    cout << "[2] informacion" << endl;
    cout << "[3] Regresar <<<<<" << endl;
    mostrarLinea(40);
}

void Menu::mostrarMenuStealMode(Setting &configuration)
{
    limpiarPantalla();
    mostrarLinea(40);
    cout << "Modo de robo: " << "\033[33m" << (configuration.getOptionStealMode() == 0 ? "Robar una carta" : "Robar hasta que puedas jugar") << "\x1b[0m" << endl;
    cout << "[1] Cambiar modo de robo" << endl;
    cout << endl;
    cout << "[2] informacion" << endl;
    cout << "[3] Regresar <<<<<" << endl;
    mostrarLinea(40);
}

void Menu::mostrarMenuSoutUno(Setting &configuration)
{
    limpiarPantalla();
    mostrarLinea(40);
    cout << "Grito UNO!: " << "\033[33m" << (configuration.getSoutUno() ? "Obligatorio" : "Opcional") << "\x1b[0m" << endl;
    cout << "[1] Cambiar grito UNO!" << endl;
    cout << endl;
    cout << "[2] informacion" << endl;
    cout << "[3] Regresar <<<<<" << endl;
    mostrarLinea(40);
}

void Menu::pausarPantalla()
{
    limpiarBuffer();
    cin.get();
}

