#include <iostream>
using namespace std;


int pedirDNI(string msj) {
    int DNI;
    cout << msj;
    cin >> DNI;
    while (DNI < 0) {
        cout << "el DNI ingresado no es valido, intente de nuevo: ";
        cin >> DNI;
    }
    return DNI;
}

int busqueda(string cadena, string vector[], int tope) {
    int posicion;
    int i = 0;


    while (cadena != vector[i] && i < tope) {
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

string pedirCadena(string msj) {
    string cadena;
    cout << msj;
    cin >> cadena;
    return cadena;
}

string PedirYate(string msj, string vec[], int TOPE, string error) {
    string yate;
    int posicion;
    yate = pedirCadena(msj);
    posicion = busqueda(yate, vec, TOPE);
    
    while (posicion == -1) {
        yate = pedirCadena(error);
        posicion = busqueda(yate, vec, TOPE);
    }


    return yate;
}


bool hayStock(int vec[], int posicion){
    bool validar;
    if(vec[posicion] == 0){
        validar = true;
    }
    else {
        validar = false;
    }
    return validar;
}





char pedirCaracter(string msj) {
    char caracter;
    cout << msj;
    cin >> caracter;
    while ((caracter != 'T') && (caracter != 'E')) {
        cout << "La forma de pago ingresada no es valida, vuelva a intentarlo: ";
        cin >> caracter;
    }
    return caracter;
}


int pedirEmpleado(string msj) {
    int empleado;
    cout << msj;
    cin >> empleado;
    while ((empleado < 0) || (empleado > 11)) {
        cout << "el numero de empleado ingresado no es valido, intente de nuevo: ";
        cin >> empleado;
    }
    return empleado;
}





int calcularmaxVendedor(int vector[], int TOPE) {
    int maximo;
    maximo = 0;

    int posicion;

    for (int i = 0; i < TOPE; i++) {
        if (vector[i] > maximo) {
            maximo = vector[i];
            posicion = i;
        }
    }
    return posicion;

}






void mostrarFINAL(int vecCANTIDAD[], string vecYATES[], int TOPE) {
    for (int i = 0; i < TOPE; i++) {
        cout << vecYATES[i] << " vendio " << vecCANTIDAD[i] << endl;
    }
}

void mostrarEmpleado(int MayorVendedor, int tarjeta, int efectivo) {
    cout << "El empleado que mas vendio fu el numero: " << MayorVendedor + 1 << endl;
    cout << "Lo recudado por ventas en tarjeta fue : " << tarjeta << endl;
    cout << "Lo recudado por ventas en Efectivo fue : " << efectivo << endl;

}





int main() {
    setlocale(LC_ALL, "spanish");
    const int CANTIDAD_YATES = 5;
    const int CANTIDAD_EMPLEADOS = 10;

    const string MSJ_DNI = "Ingrese su DNI: ";
    const string MSJ_PEDIR_YATE = "Ingrese el Yate que quiere: ";
    const string MSJ_FORMAPAGO = "Ingrese la forma de pago (T = tarjeta) o (E = efectivo)";
    const string MSJ_EMPLEADO = "Ingrese el numero del empleado que lo atendio del 1 al 10 : ";
    const string MSJ_ERROR_YATE = "el yate que ingreso no es valido, vuelva a ingresar el Yate";

    const int FIN_DE_DATOS = 0;




    string vecYATES[CANTIDAD_YATES]{ "Megayate", "Catamaran", "Velero", "Grande", "Pequeno" };

    int vecStockYates[CANTIDAD_YATES]{ 5,0,20,18,9 };

    int vecPrecioYates[CANTIDAD_YATES]{ 2000,10000,1200,500,700 };

    int vecEmpleados[CANTIDAD_EMPLEADOS]{ 0 };

    int vecCantidadVendidos[CANTIDAD_YATES]{ 0 };


    int DNI;
    string YatePedido;
    int posicion;
    char formaPago;
    int empleadoIngresado;



    

    int precio;
    int mayorVendedor = 0;

    int compras_tarjeta = 0;
    int compras_efectivo = 0;




    DNI = pedirDNI(MSJ_DNI);

    while (DNI != FIN_DE_DATOS) {



        YatePedido = PedirYate(MSJ_PEDIR_YATE, vecYATES, CANTIDAD_YATES, MSJ_ERROR_YATE);
       

        posicion = busqueda(YatePedido, vecYATES, CANTIDAD_YATES);
     

            if (hayStock(vecStockYates, posicion)) {
                cout << "No hay stock del yate ingresado, repita el proceso: ";

            }
            else {
                formaPago = pedirCaracter(MSJ_FORMAPAGO);
                empleadoIngresado = pedirEmpleado(MSJ_EMPLEADO);
                precio = vecPrecioYates[posicion];

                if (formaPago == 'E') {

                    precio = (precio * 9) / 10;
                    compras_efectivo = compras_efectivo + precio;
                }

                else {
                    compras_tarjeta = compras_tarjeta + precio;
                }


                cout << "EL DNI del cliente es " << DNI << endl;
                cout << "EL precio de la compra es: " << precio << endl;




                vecCantidadVendidos[posicion]++;
                vecEmpleados[empleadoIngresado - 1]++;

                vecStockYates[posicion]--;
            }

            DNI = pedirDNI(MSJ_DNI);
        }



    
    mayorVendedor = calcularmaxVendedor(vecEmpleados, CANTIDAD_EMPLEADOS);

    mostrarFINAL(vecCantidadVendidos, vecYATES, CANTIDAD_YATES);

    mostrarEmpleado(mayorVendedor, compras_tarjeta, compras_efectivo);

    system("pause");
}
