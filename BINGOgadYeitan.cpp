#include <iostream>
using namespace std;
#include<stdlib.h>
#include<time.h>

int busqueda(int numero, int vector[], int tope) {
    int posicion;
    int i = 0;


    while (numero != vector[i] && i < tope) {
        i++;
    }


    if (i == tope) {
        posicion = -1;
    }
    else {
        posicion = i;
    }

    return posicion;
}
int generarRANDOM(int limite_inferior, int limite_superior) {
    int numero;
    numero = limite_inferior + rand() % (limite_superior - limite_inferior);
    return numero;
}


int GenerarNumero(int limite_inferior, int limite_superior, int vec[], int TOPE) {
    int numero;
    int busquedaPosicion;
    numero = generarRANDOM(limite_inferior, limite_superior);


    busquedaPosicion = busqueda(numero, vec, TOPE);



    while (busquedaPosicion != -1) {
        numero = limite_inferior + rand() % (limite_superior - limite_inferior);
        busquedaPosicion = busqueda(numero, vec, TOPE);
    }




    return numero;
}

int Bolillero(int limite_inferior, int limite_superior, int vec[], int TOPE) {
    int pelotas;
    pelotas = generarRANDOM(limite_inferior, limite_superior);
    while (vec[pelotas - 1] == 1) {
        pelotas = generarRANDOM(limite_inferior, limite_superior);
        
    }

    vec[pelotas - 1] = 1;

    return pelotas;
}






string pedirString() {
    string repetir;
    cout << "Quiere repetir el juego? Ingrese SI o NO" << endl;
    cin >> repetir;
    while ((repetir != "SI") && (repetir != "NO")) {
        cout << "Eror la palabra ingresada no es valida, ingrese de nuevo " << endl;
        cin >> repetir;
    }
    return repetir;
}


void generarTablero(int vector[], int tope, int LIMITE_INFERIOR, int LIMITE_SUPERIOR) {
    int numeroRandom;
    for (int i = 0; i < tope; i++) {

        numeroRandom = GenerarNumero(LIMITE_INFERIOR, LIMITE_SUPERIOR, vector, tope);
        vector[i] = numeroRandom;

    }


}

char pedirChar(string msj) {
    char ingreso;
    cout << msj << endl;
    cin >> ingreso;
    while ((ingreso != 'S') && (ingreso != 'R')) {
        cout << "Eror la letra ingresada no es valida, ingrese de nuevo " << endl;
        cin >> ingreso;
    }
    return ingreso;
}


void mostrarPelotas(int pelotas, int casillas, int tablero) {
    cout << pelotas << " Esta en el tablero del jugador " << tablero << endl;
    cout << "Le faltan completar " << casillas << " casilleros" << endl;
    cin.get();
}

void mostrarTABLERO(int vec[], int TOPE, int tab) {
    cout << "sus numeros del tablero " << tab << ": " << endl;
    for (int i = 0; i < TOPE; i++) {
        cout << vec[i] << endl;
    }
}

void calcularGanador(int libre1, int libre2, int vector[]) {
    if (libre1 > libre2) {
        cout << "El ganador del BINGO es el jugador 2" << endl;
        vector[1]++;
    }
    else {
        cout << "El ganador del BINGO es el jugador 1" << endl;
        vector[0]++;
    }
}

void mostrarGanador(int vector[]) {
    if (vector[1] > vector[0]) {
        cout << "El ganador del Juego total es el jugador 2" << endl;

    }
    else {
        cout << "El ganador del juego total el jugador 1" << endl;

    }
}



int main() {
    srand(time(NULL));


    const int CANTIDAD_NUMEROS = 15;
    const int LIMITE_INFERIOR = 1;
    const int LIMITE_SUPERIOR = 99;

    const string MSJ_PREGCHAR = "desea jugar con este tablero o quiere generar uno nuevo?  Si desea continuar con este Tablero presione S, de lo contrario presione R ";

    const int tab1 = 1;
    const int tab2 = 2;

    int numeroRandom;






    int tablero1;
    int tablero2;


    int casillaLibres1;
    int casillaLibres2;




    int pelotas;


    int posicion;

    char cursoJuego;

    string repetirJuego;

    int juegosGanados1 = 0;
    int juegosGanados2 = 0;
    int vecGanador[2]{ 0 };
    do {
        int vecTablero1[CANTIDAD_NUMEROS]{ 0 };
        int vecTablero2[CANTIDAD_NUMEROS]{ 0 };
        int vecPelotas[LIMITE_SUPERIOR]{ 0 };
        int numero_de_pelota;
        numero_de_pelota = 0;



        do {
            generarTablero(vecTablero1, CANTIDAD_NUMEROS, LIMITE_INFERIOR, LIMITE_SUPERIOR);

            mostrarTABLERO(vecTablero1, CANTIDAD_NUMEROS, tab1);
            cin.get();
            cursoJuego = pedirChar(MSJ_PREGCHAR);
        } while (cursoJuego == 'R');

        system("cls");

        do {
            generarTablero(vecTablero2, CANTIDAD_NUMEROS, LIMITE_INFERIOR, LIMITE_SUPERIOR);

            mostrarTABLERO(vecTablero2, CANTIDAD_NUMEROS, tab2);
            cin.get();
            cursoJuego = pedirChar(MSJ_PREGCHAR);
        } while (cursoJuego == 'R');

        system("cls");

        casillaLibres1 = CANTIDAD_NUMEROS;
        casillaLibres2 = CANTIDAD_NUMEROS;

        do {
            pelotas = Bolillero(LIMITE_INFERIOR, LIMITE_SUPERIOR, vecPelotas, LIMITE_SUPERIOR);
            vecPelotas[pelotas - 1] = 1;
            
            cout << "la pelota que salio es " << pelotas << " : " << endl;
            cin.get();
            posicion = busqueda(pelotas, vecTablero1, CANTIDAD_NUMEROS);

            if (posicion != -1) {
                casillaLibres1--;
                mostrarPelotas(pelotas, casillaLibres1, tab1);

            }

            posicion = busqueda(pelotas, vecTablero2, CANTIDAD_NUMEROS);

            if (posicion != -1) {
                casillaLibres2--;
                mostrarPelotas(pelotas, casillaLibres2, tab2);

            }
            numero_de_pelota++;
        } while (casillaLibres1 > 0 && casillaLibres2 > 0);

        calcularGanador(casillaLibres1, casillaLibres2, vecGanador);
        repetirJuego = pedirString();
        system("cls");
    } while (repetirJuego == "SI");
    system("cls");
    mostrarGanador(vecGanador);

}