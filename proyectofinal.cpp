#include <iostream>
#include<string>
#include <string.h>
using namespace std;

const int longCad=20;
struct CostoPorArticulo{
    char nombreArticul[longCad+1];//nombre del articulo puede tener 20 caracteres maximo y el ultimo sera remplazado por '\0'
    int cantidad;
    float precio;
    float costoPorArticulo;
};
//declaracion de funciones
void readata(int n,struct CostoPorArticulo art[]);
void costoxartic(int n,struct CostoPorArticulo art[]);
void despliegue (int n,struct CostoPorArticulo art[]);
float costototalcompra (int n,struct CostoPorArticulo art[]);

int main(){
	int n;
	cout<<"**Programa para recibos de compras**"<<endl<<endl;
	cout<<"Escriba la cantidad de Articulos comprados: "<<endl;
	cin>>n;
	fflush(stdin);//limpiar la entrada de teclado
	CostoPorArticulo art[n];
	readata(n,art);
	despliegue (n,art);
	costoxartic(n,art);
	costototalcompra (n,art);
return 0;
}

void readata(int n,struct CostoPorArticulo art[]){//Funcion para insertar datos
	string nom;
	for(int i=0; i<n; i++){   
		cout<<"Articulo "<<i+1<<endl;
		cout<<"Introducir el nombre: "<<endl;
		getline(cin,nom);//toma el valor de la cadena nom desde teclado
		strncpy (art[i].nombreArticul,nom.c_str(),longCad);//copia los valores de nom al arreglo de nombrearticulo
		art[i].nombreArticul[longCad]='\0';//introduce un '/0' en la ultima posicion donde no hay datos en el arreglo
		cout<<"Introducir Cantidad: "<<endl;
		cin>>art[i].cantidad;
        cout<<"Introducir Costo Por Unidad: "<<endl;
		cin >> art[i].costoPorArticulo;
		fflush(stdin);//limpiar la entrada de teclado
	}
}

void costoxartic(int n,struct CostoPorArticulo art[]){
	for (int i=0;i<n;i++){
		art[i].precio=(art[i].cantidad*art[i].costoPorArticulo);//el arreglo precio multiplica la cantidad y costo/unidad para sacar el costo total del articulo
		cout<<"Articulo "<<i+1<<endl;
		cout<<"Precio: "<<art[i].precio<<endl;//se imprime el precio del articulo
	}
}

void despliegue (int n,struct CostoPorArticulo art[]){//imprime el contenido de los arreglos
	for(int i=0; i<n ; i++){	
		cout<<"Articulo: "<<i+1<<endl;
		cout<<"Nombre: "<<art[i].nombreArticul<<endl;
		cout<<"Cantidad: " << art[i].cantidad<<endl;
        cout<<"Costo por unidad: "<<art[i].costoPorArticulo<<endl;
		
	}
}

float costototalcompra (int n,struct CostoPorArticulo art[]){//suma el total de articulos
	int cont=0;//este contador sirve para mostrar la cantidad de articulos procesados
	double tot=0.0;//Sirve como acumulador para la suma
	for (int i=0; i<n; i++){
		tot += art[i].precio;
		cont++;
	}
	cout<<"El costo total de la compra es de: "<<tot<<"$ para un total de "<<cont<<" articulos.";
	return 0;
}

