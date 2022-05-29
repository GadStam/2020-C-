#include<iostream>
#include<string>
using namespace std;

int ingresarDNI(string msj) {
	int dni;
	cout << msj << endl;
	cin >> dni;
	while (dni < 0) {
		cout << "ERROR" << endl;
		cin >> dni;
	}
	return dni;
}

string ingresarApellido(string msj) {
	string apellido;
	cout << msj << endl;
	cin >> apellido;
	return apellido;
}

string ingresarMetodoPago(string msj) {
	string metodo;
	cout << msj << endl;
	cin >> metodo;
	while ((metodo != "Efectivo") && (metodo != "Tarjeta")) {
		cout << "ERROR, solo puede ingresar Efecetivo o Tarjeta" << endl;
		cin >> metodo;
	}
	return metodo;
}

string ingresarProducto() {
	string producto;
	cout << "ingrese el producto" << endl;
	cin >> producto;
	while ((producto != "Barkito")&& (producto != "FIN") && (producto != "quitamanchas") && (producto != "firmesasandwich") && (producto != "harinadapan") && (producto != "aceiteNosepega") && (producto != "mateKozi2") && (producto != "percha") && (producto != "stancafe")) {
		cout << "ERROR, EL PRODUCTO NO ES VALIDO" << endl;
		cin >> producto;
	}
	return producto;
}

int ingresarCantidad() {
	int cantidad;
	cout << "ingrese la cantidad del producto" << endl;
	cin >> cantidad;
	while (cantidad < 0) {
		cout << "ERROR, la cantidad debe ser mayor a 0" << endl;
		cin >> cantidad;
	}
	return cantidad;
}

void Final(string Apellido, int ventaMayor, int ventas_efectivo, int ventas_tarjeta, int Stock_Barkito, int Stock_QuitaManchas, int Stock_Sandwich, int Stock_Aceite, int Stock_Harina, int Stock_Mate, int Stock_Percha, int Stock_Cafe, int recaudo_diario) {
	cout << "El Apellido de la persona que mas gasto es " << Apellido << " Y el importe mayor fue" << ventaMayor << endl;
	cout << "La cantidad de ventas en efectivo fue " << ventas_efectivo <<endl;
	cout << "La cantidad de ventas en tarjeta fue " << ventas_tarjeta << endl;

	cout << "NOMBRE PRODUCTO    STOCK " <<endl;
	cout << "BARKITO   " << Stock_Barkito << endl;
	cout << "QUITAMANCHAS   " << Stock_QuitaManchas << endl;
	cout << "FIRMESASANDWICH   " << Stock_Sandwich << endl;
	cout << "ACEITENOSEPEGA   " << Stock_Aceite << endl;
	cout << "HARINADAPAN   " << Stock_Harina << endl;
	cout << "MATEKOZI2   " << Stock_Mate << endl;
	cout << "PERCHAS   " << Stock_Percha << endl;
	cout << "STANCAFE   " << Stock_Cafe << endl;


	cout << "El recaudo diario fue de " << recaudo_diario << endl;


}


int main() {
	setlocale(LC_ALL, "spanish");



	const string BARKITO = "barkito";
	const string QUITAMANCHAS = "quitamanchas";
	const string FIRMEZA_SANDWICH = "firmesasandwich";
	const string HARINADAPAN = "harinadapan";
	const string ACEITENOSEPEGA = "aceiteNosepega";
	const string MATEKOZI2 = "mateKozi2";
	const string Percha = "percha";
	const string StanCafe = "stancafe";

	const int PRECIO_BARKITO = 30;
	const int PRECIO_QUITAMANCHAS = 50;
	const int PRECIO_FIRMEZA = 15;
	const int PRECIO_HARINA = 20;
	const int PRECIO_ACEITE = 60;
	const int PRECIO_MATE = 25;
	const int PRECIO_PERCHA = 5;
	const int PRECIO_CAFE = 18;

	int Stock_Barkito = 17;
	int Stock_QuitaManchas = 5;
	int Stock_Sandwich = 10;
	int Stock_Harina = 3;
	int Stock_Aceite = 24;
	int Stock_Mate = 12;
	int Stock_Percha = 30;
	int Stock_Cafe = 28;


	int DNI;
	string apellido;
	string pago;

	string producto;
	int cantidad_producto;

	int costoProducto;

	int ventaTotal;
	
	int ventas_efectivo;
	ventas_efectivo = 0;

	int ventas_tarjeta;
	ventas_tarjeta = 0;

	int ventaMayor;
	ventaMayor = 0;
	string apellidoMayorVenta;

	int recaudo_diario;
	recaudo_diario = 0;


	const string MENSAJE_DNI = "ingrese su DNI, si ingresa 0 su pedido terminara y dara comienza al proximo cliente";
	const string MENSAJE_APELLIDO = "ingrese su apellido";
	const string MENSAJE_METODO = "ingrese su metodo de pago puede ser en Tarjeta o en Efectivo (escribir solo con la primer mayuscula)";

	do {
		DNI = ingresarDNI(MENSAJE_DNI);

		if(DNI != 0){
		apellido = ingresarApellido(MENSAJE_APELLIDO);
		pago = ingresarMetodoPago(MENSAJE_METODO);
		ventaTotal = 0;

		do {
			costoProducto = 0;
			producto = ingresarProducto();
			if (producto != "FIN") {
				cantidad_producto = ingresarCantidad();

				if (producto == BARKITO) {
					if (cantidad_producto > Stock_Barkito) {
						cout << "ERROR, NO HAY STOCK DEL PRODUCTO" << endl;
					}
					else{
					costoProducto = cantidad_producto * PRECIO_BARKITO;
					Stock_Barkito = Stock_Barkito - cantidad_producto;
					}
				}
				if (producto == QUITAMANCHAS) {
					if (cantidad_producto > Stock_QuitaManchas) {
						cout << "ERROR, NO HAY STOCK DEL PRODUCTO" << endl;
					}
					else {
						costoProducto = cantidad_producto * PRECIO_QUITAMANCHAS;
						Stock_QuitaManchas = Stock_QuitaManchas - cantidad_producto;
					}
				}
				else if (producto == FIRMEZA_SANDWICH) {
					if (cantidad_producto > Stock_Sandwich) {
						cout << "ERROR, NO HAY STOCK DEL PRODUCTO" << endl;
					}
					else {
						costoProducto = cantidad_producto * PRECIO_FIRMEZA;
						Stock_Sandwich = Stock_Sandwich - cantidad_producto;
					}
				}
				else if (producto == HARINADAPAN) {
					if (cantidad_producto > Stock_Harina) {
						cout << "ERROR, NO HAY STOCK DEL PRODUCTO" << endl;
					}
					else {
						costoProducto = cantidad_producto * PRECIO_HARINA;
						Stock_Harina = Stock_Harina - cantidad_producto;
					}
				}
				else if (producto == ACEITENOSEPEGA) {
					if (cantidad_producto > Stock_Aceite) {
						cout << "ERROR, NO HAY STOCK DEL PRODUCTO" << endl;
					}
					else {
						costoProducto = cantidad_producto * PRECIO_ACEITE;
						Stock_Aceite = Stock_Aceite - cantidad_producto;
					}
				}
				else if (producto == MATEKOZI2) {
					if (cantidad_producto > Stock_Mate) {
						cout << "ERROR, NO HAY STOCK DEL PRODUCTO" << endl;
					}
					else {
						costoProducto = cantidad_producto * PRECIO_MATE;
						Stock_Mate = Stock_Mate - cantidad_producto;
					}
				}
				else if (producto == Percha) {
					if (cantidad_producto > Stock_Percha) {
						cout << "ERROR, NO HAY STOCK DEL PRODUCTO" << endl;
					}
					else {
						costoProducto = cantidad_producto * PRECIO_PERCHA;
						Stock_Percha = Stock_Percha - cantidad_producto;
					}
				}
				else if (producto == StanCafe) {
					if (cantidad_producto > Stock_Cafe) {
						cout << "ERROR, NO HAY STOCK DEL PRODUCTO" << endl;
					}
					else {
						costoProducto = cantidad_producto * PRECIO_CAFE;
						Stock_Cafe = Stock_Cafe - cantidad_producto;
					}
				}

				ventaTotal = ventaTotal + costoProducto;
			}
	} while (producto != "FIN");

		if(pago=="Efectivo"){
			ventaTotal = ventaTotal * 0.9;
			ventas_efectivo = ventas_efectivo++;
	}
		else{
			ventas_tarjeta=ventas_tarjeta++;
		}
		if(ventaTotal > ventaMayor ){
			ventaMayor = ventaTotal;
			apellidoMayorVenta = apellido;
		}
		recaudo_diario = recaudo_diario + ventaTotal;
	

		cout << apellido << endl;
		cout << DNI << endl;
		cout << pago << endl;
		cout << ventaTotal << endl;


		}
		}while (DNI != 0);
	
		Final(apellidoMayorVenta, ventaMayor, ventas_efectivo, ventas_tarjeta, Stock_Barkito, Stock_QuitaManchas, Stock_Sandwich, Stock_Aceite, Stock_Harina, Stock_Mate, Stock_Percha, Stock_Cafe, recaudo_diario);
		
		
		
		system("pause");

}