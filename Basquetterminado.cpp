#include<iostream>
#include<string>
using namespace std;

int ingresarCantEquipos(string msj) {
	int cantidad;
	cout << msj << endl;
	cin >> cantidad;
	while (cantidad <= 0) {
		cout << "ERROR, la cantidad de equipos tiene que ser mayor a 0" << endl;
		cin >> cantidad;
	}
	return cantidad;
}

string nombreEquipo(string msj, int cant) {
	string nombre;
	cout << msj << cant << endl;
	cin >> nombre;
	return nombre;
}

string ingresarConferencia(string msj) {
	string conferencia;
	cout << msj << endl;
	cin >> conferencia;
	while ((conferencia != "Oeste") && (conferencia != "Este")) {
		cout << "ERROR, solo puede ingresar Este o Oeste" << endl;
		cin >> conferencia;
	}
	return conferencia;
}

string ingresarApellido(string msj, int cant) {
	string apellido;
	cout << msj << cant << endl;
	cin >> apellido;
	return apellido;
}

int ingresarEdad(string msj) {
	int edad;
	cout << msj << endl;
	cin >> edad;
	while (edad <= 15) {
		cout << "ERROR, debe ser mayor de 15 años" << endl;
		cin >> edad;
	}
	return edad;
}

int ingresarAltura(string msj) {
	int altura;
	cout << msj << endl;
	cin >> altura;
	while ((altura < 120) && (altura > 300)) {
		cout << "ERROR, debe ser mayor de 120 cm y menor de 300 cm de altura" << endl;
		cin >> altura;
	}
	return altura;
}

int ingresarValores(string msj) {
	int valores;
	cout << msj << endl;
	cin >> valores;
	while ((valores < 1) && (valores > 5)) {
		cout << "ERROR, el valor tiene que estar entre 1 y 5" << endl;
		cin >> valores;
	}
	return valores;
}

bool esMejor(float promedio, float elMayorPromedio, string conferencia, string conf) {
	bool valido;
	if ((conferencia == conf) && (promedio > elMayorPromedio)) {
		valido = true;
	}
	else {
		valido = false;
	}

	return valido;
}

int main() {
	setlocale(LC_ALL, "spanish");


	const string Este = "Este";
	const string Oeste = "Oeste";


	int cantidadEquipos;
	string nombre_Equipo;
	string conferencia;

	string apellido;
	int edad;
	int altura;
	int scoring;
	int firmeza;
	int rebotes;
	float promedioEstadisticas;


	//por equipo
	float mejorEstadisticas;
	string apellidoMejorPromedio;

	int total_puntos_rebotes;
	float promedioRebotesEquipo;
	float promedio_mejor_equipo_rebotes;
	string nombre_mejor_equipo_rebotes;

	float mayorAlturaOeste;
	string apellidoJugadoMasAltoOeste;

	float jovenMas3ScoringEquipo;
	string apellidoJoven3Scoring;

	int mejorScoringEste;
	string apellidoMejorScoringEste;

	int total_puntos_firmeza;
	float promedioFirmezaEquipo;
	float promedio_peor_equipo_firmeza;
	string nombre_peor_equipo_firmeza;

	float total_puntos_este;
	float total_puntos_oeste;

	float cantidad_equipos_oeste;
	float cantidad_equipos_este;

	float promedio_este;
	float promedio_oeste;

	float total_puntos_equipo;


	const string MENSAJE_CANTIDAD_EQUIPOS = "ingrese la cantidad de equipos, no puede ingresar 0";
	const string MENSAJE_NOMBRE_EQUIPOS = "ingese el nombre de su equipo, usted es el equipo ";
	const string MENSAJE_CONFERENCIA = "ingrese la conferencia de su equipo, solo puede ingresar Este o Oste";
	const string MENSAJE_APELLIDO = "ingese el apellido del jugador";
	const string MENSAJE_EDAD = "ingese su edad, debe ser mayor de 15";
	const string MENSAJE_ALTURA = "Ingrese su altura en CM, debe ser mayor de 120 cm y menor de 300 cm de altura";
	const string MENSAJE_SCORING = "ingrese el scoring, tiene que estra entre 1 y 5";
	const string MENSAJE_FIRMEZA = "ingrese la firmeza, tiene que estra entre 1 y 5";
	const string MENSAJE_REBOTES = "ingrese los rebotes, tiene que estra entre 1 y 5";



	const int CANTIDAD_JUGADORES = 2;

	cantidadEquipos = ingresarCantEquipos(MENSAJE_CANTIDAD_EQUIPOS);



	total_puntos_este = 0;
	total_puntos_oeste = 0;
	promedio_este = 0;
	promedio_oeste = 0;

	promedio_mejor_equipo_rebotes = 0;



	for (int i = 0; i < cantidadEquipos; i++) {

		nombre_Equipo = nombreEquipo(MENSAJE_NOMBRE_EQUIPOS, i + 1);
		conferencia = ingresarConferencia(MENSAJE_CONFERENCIA);

		mejorEstadisticas = 0;
		total_puntos_rebotes = 0;
		promedioRebotesEquipo = 0;
		
		mayorAlturaOeste = 0;
		jovenMas3ScoringEquipo = 999;
		mejorScoringEste = 0;
		total_puntos_firmeza = 0;
		promedioFirmezaEquipo = 0;
		promedio_peor_equipo_firmeza = 6;








		for (int j = 0; j < CANTIDAD_JUGADORES; j++) {
			apellido = ingresarApellido(MENSAJE_APELLIDO, j + 1);
			edad = ingresarEdad(MENSAJE_EDAD);
			altura = ingresarAltura(MENSAJE_ALTURA);
			scoring = ingresarValores(MENSAJE_SCORING);
			firmeza = ingresarValores(MENSAJE_FIRMEZA);
			rebotes = ingresarValores(MENSAJE_REBOTES);

			promedioEstadisticas = (scoring + rebotes + firmeza) / 3;




			total_puntos_equipo = 0;
			cantidad_equipos_oeste = 1;
			cantidad_equipos_este = 1;

			total_puntos_equipo = total_puntos_equipo + (scoring + firmeza + rebotes);


			if (promedioEstadisticas > mejorEstadisticas) {
				mejorEstadisticas = promedioEstadisticas;
				apellidoMejorPromedio = apellido;
			}

			if (esMejor(altura, mayorAlturaOeste, conferencia, Oeste)) {
				mayorAlturaOeste = altura;
				apellidoJugadoMasAltoOeste = apellido;
			}

			if (scoring > 3) {
				if (edad < jovenMas3ScoringEquipo) {
					jovenMas3ScoringEquipo = edad;
					apellidoJoven3Scoring = apellido;
				}
			}
			if (esMejor(scoring, mejorScoringEste, conferencia, Este)) {
				mejorScoringEste = scoring;
				apellidoMejorScoringEste = apellido;
			}

			total_puntos_rebotes = total_puntos_rebotes + rebotes;
			total_puntos_firmeza = total_puntos_firmeza + firmeza;

		}

		// FOR general

		cout << nombre_Equipo << endl;
		cout << conferencia << endl;
		cout << "el nombre del jugador con mejor promedio de estadisticas es " << apellidoMejorPromedio << endl;

		promedioRebotesEquipo = total_puntos_rebotes / CANTIDAD_JUGADORES;
		promedioFirmezaEquipo = total_puntos_firmeza / CANTIDAD_JUGADORES;

		if (promedioRebotesEquipo > promedio_mejor_equipo_rebotes) {
			promedio_mejor_equipo_rebotes = promedioRebotesEquipo;
			nombre_mejor_equipo_rebotes = nombre_Equipo;
		}

		if (promedioFirmezaEquipo < promedio_peor_equipo_firmeza) {
			promedio_peor_equipo_firmeza = promedioFirmezaEquipo;
			nombre_peor_equipo_firmeza = nombre_Equipo;
		}

		if (conferencia == "Oeste") {
			total_puntos_oeste = total_puntos_oeste + total_puntos_equipo;
			cantidad_equipos_oeste = cantidad_equipos_oeste + 1;
		}
		else {
			total_puntos_este = total_puntos_este + total_puntos_equipo;
			cantidad_equipos_este = cantidad_equipos_este + 1;

		}

	}
	promedio_oeste = total_puntos_oeste / cantidad_equipos_oeste;
	promedio_este = total_puntos_este / cantidad_equipos_este;

	cout << "el nombre del equipo con mayor promedio de rebotes es " << nombre_mejor_equipo_rebotes << endl;
	cout << "el apellido del jugador mas alto de la conferencia oeste es " << apellidoJugadoMasAltoOeste << endl;
	cout << "el nombre del equipo con menor promedio de firmeza es " << nombre_peor_equipo_firmeza << endl;
	cout << "el apellido del jugador mas joven en tener 3 mas de scoring es " << apellidoJoven3Scoring << endl;
	cout << "el apellido del jugador con mejor scoring de la conf este es " << apellidoMejorScoringEste << endl;
	cout << "el promedio de valoracion de la conf este es " << promedio_este << endl;
	cout << "el promedio de valoracion de la conf Oeste es " << promedio_oeste << endl;



	system("pause");

}