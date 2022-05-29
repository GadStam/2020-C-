#include<iostream>
using namespace std;
#include<stdlib.h>
#include<time.h>

void Bienvenida(string mensaje1, string mensaje2, string mensaje3) {
	cout << mensaje1;
	cout << mensaje2;
	cout << mensaje3;
}

string pedirNivel(string mensaje) {
	string nivel;
	cout << mensaje;
	cin >> nivel;
	while (nivel != "FACIL" && nivel != "MEDIO" && nivel != "DIFICIL") {
		cout << "El nivel ingresado no es valido";
		cin >> nivel;

	}
	return nivel;
}

int DefinirMaximo(string nivel) {
	int maximo;
	if (nivel == "FACIL") {
		maximo = 100;
	}
	else if (nivel == "MEDIO") {
		maximo = 300;
	}
	else {
		maximo = 500;
	}

	return maximo;

}


int GenerarNumero(int limite_inferior, int limite_superior) {
	int numero;
	numero = limite_inferior + rand() % (limite_superior - limite_inferior);
	cout << numero;
	return numero;
}

int IngresarNumero(int limite_inferior, int limite_superior, string mensaje) {


	int respuesta;
	cout << mensaje << limite_inferior << " y " << limite_superior << endl;
	cin >> respuesta;
	return respuesta;
}

bool ValidarRespuesta(int numero, int RespuestaUsuario) {
	return numero == RespuestaUsuario;

}

bool ValidarNumero(int Numero, int intentos, int limite_inferior, int limite_superior, string MENSAJE_INGRESAR_NUMERO) {
	bool valido;
	valido = false;
	int NumeroIngresado = IngresarNumero(limite_inferior, limite_superior, MENSAJE_INGRESAR_NUMERO);
	while (intentos > 0 && Numero != NumeroIngresado) {
		if (NumeroIngresado < Numero) {

			cout << "El numero que ingreso es menor, ingrese mayor";

		}
		else if (NumeroIngresado > Numero) {

			cout << "El numero que ingreso es mayor, ingres menor";

		}
		intentos--;
		NumeroIngresado = IngresarNumero(limite_inferior, limite_superior, MENSAJE_INGRESAR_NUMERO);
	}

	if (ValidarRespuesta(NumeroIngresado, Numero)) {
		valido = true;
	}



	return valido;

}


void main() {
	int random;
	int Intentos;
	Intentos = 10;

	string nivel;


	const int limite_inferior = 1;
	int limite_superior;
	const string Bienvenida1 = "Bienvenido al juego GUESS THE NUMBER \n en este juego deberas adivinar un numero ";
	const string Bienvenida2 = " tendras 10 oportunidades de arriesgar y luego de arriesgar,\n si no acertaste te indicaremos si el numero ingresado es mayor o menor del que tiene que adivinar, MUCHA SURTE";
	const string Bienvenida3 = "Ahora tendras que elegir el nivel que quieres. Los niveles son FACIL(1-100), MEDIO(1-300), DIFICIL (1-500)";
	const string MENSAJE_NIVEL = "Ingrese aqui el nivel que quiere jugar. FACIL,MEDIO,DIFICIL";
	const string MENSAJE_INGRESAR_NUMERO = "Aqui tiene que ingresar el numero que va a arriesgar, recuerde que el numero que tiene que adivinar esta entre";
	srand(time(NULL));

	Bienvenida(Bienvenida1, Bienvenida2, Bienvenida3);

	nivel = pedirNivel(MENSAJE_NIVEL);

	limite_superior = DefinirMaximo(nivel);

	random = GenerarNumero(limite_inferior, limite_superior);



	if (!ValidarNumero(random, Intentos, limite_inferior, limite_superior, MENSAJE_INGRESAR_NUMERO)) {

		cout << "PERDISTE, te quedaste sin intentos" << endl;
	}
	else {
		cout << "GANASTE" << endl;
	}











	system("color 89");
	system("pause");
}

