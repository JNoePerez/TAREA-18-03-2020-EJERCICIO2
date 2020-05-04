#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

struct ventas{
	int tipoent;
	float descuento;
	float precio;
	int unidades;
	float totalvta;
	float totalso;
	string socio;
};
void venta();
void reporte();
int main(){
int opc;

cout<<" 1. Ventas"<<endl;
cout<<" 2. Reporte"<<endl;

cout<<" Ingrese opcion: "<<endl;
cin>>opc;

if (opc==1){
venta();
}
if (opc==1){
reporte();
}

}
	
void venta(){
	string tipoprod;
	string socio;
	float precio;
	int unidades;
	float descuento;
	float totalvta;
	float totalso;
	string s;
	
	cout<<"----- Entradas -----"<<endl;
	cout<<" Ingrese tipo de Entrada: "<<endl;
	cout<<" ZONA	\t Identificacion \t Precio"<<endl;
	cout<<" VIP  	\t 		V      	  \t Q 350.00"<<endl;
	cout<<" PLATEA  \t 		P      	  \t Q 130.00"<<endl;
	cout<<" POPULAR \t 		E      	  \t Q 50.00"<<endl;
	
		cout<<"\n \n 	Identificacion: ";
	cin>>tipoprod;
	cout<<"\n \n 	Indique el numero de unidades a comprar: ";
	cin>>unidades;
	
	if (tipoprod =="v" or "V"){
		
		if(unidades>=3 && unidades <=6 ){
		descuento = 0.05;
		precio = 350.00;
		totalvta = (precio - (descuento * precio) )* unidades; 	
	}
	if(unidades>=7 && unidades <= 9 ){
		descuento = 0.075;
		precio = 350.00;
		totalvta = (precio - (descuento * precio) )* unidades; 	
	}if(unidades>9 ){
		descuento = 0.10;
		precio = 350.00;
		totalvta = (precio - (descuento * precio) )* unidades;	
	}
	}

 	if (tipoprod =="P" or "p"){
		if(unidades>=3 && unidades <=6 ){
		descuento = 0.05;
		precio = 130.00;
		totalvta = (precio - (descuento * precio) )* unidades; 	
	}
	if(unidades>=7 && unidades <= 9 ){
		descuento = 0.075;
		precio = 130.00;
		totalvta = (precio - (descuento * precio) )* unidades; 	
	}if(unidades>9 ){
		descuento = 0.10;
		precio = 130.00;
		totalvta = (precio - (descuento * precio) )* unidades; 	
	} 	
	}
	
	
	if (tipoprod =="E" or "e"){
		if(unidades>=3 && unidades <=6 ){
		descuento = 0.05;
		precio = 50.00;
		totalvta = (precio - (descuento * precio) )* unidades; 	
	}
	if(unidades>=7 && unidades <= 9 ){
		descuento = 0.075;
		precio = 50.00;
		totalvta = (precio - (descuento * precio) )* unidades; 	
	}if(unidades>9 ){
		descuento = 0.10;
		precio = 50.00;
		totalvta = (precio - (descuento * precio) )* unidades; 	
	} 
	}
	
	cout<<"Tipo Prod: "<<tipoprod<<"Descuento: "<<descuento<<"Precio: "<<precio<<"Unidades: "<<unidades<<"Total de la venta: "<<totalvta;
	
	cout<<"\n \n 	Es socio S=si N=no: ";
	cin>>socio;
	if(socio== "s" or "S"){
		
	totalso=(totalvta - (0.08 * totalvta)); 
		cout<<"Tipo Prod: "<<tipoprod<<"Descuento: "<<descuento<<"Precio: "<<precio<<"Unidades: "<<unidades<<"Total de la venta: "<<totalso;
	}else{
	
	cout<<"Tipo Prod: "<<tipoprod<<"Descuento: "<<descuento<<"Precio: "<<precio<<"Unidades: "<<unidades<<"Total de la venta: "<<totalvta;
		
	}	
	ofstream grabararchivo;
	try {
		grabararchivo.open("Boletos.txt",ios::app);
		grabararchivo<<tipoprod<<"\t"<<descuento<<"\t"<<precio<<"\t"<<unidades<<"\t"<<totalso<<endl;
		grabararchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	
	cout<<"\n"<<"Ventas Actuales"<<endl;
	cout<<"Tipo Prod  Descuento  Precio  Unidades  TotalVenta"<<endl;
	ifstream leerarchivo;
	try {
		leerarchivo.open("Boletos.txt",ios::in);				
		while (getline(leerarchivo, s))
			cout<<s<<endl;		
		leerarchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	
}

void reporte(){
//mostrar el total global de la venta del dia y
//determinar el total de lo vendido por producto, mostrando tambien el porcentaje
//con relacion al total.
	ifstream db;
	float tp,d,p,u,tv=0;
	float sumatotal=0;
	float tp1=0;
	float tp2=0;
	float tp3=0;	
	try{	
		db.open("Boletos.txt",ios::in);
		
		while (db >>tp >> d >>p>> u>>tv){
			sumatotal = tv + sumatotal;	
			if (tp==1)
				tp1+=tv;
			else if (tp==2)
				tp2+=tv;
			else if (tp==3)
				tp3+=tv;
		}	
		db.close();
		
		cout<<setprecision(5)<<"Total de Ventas:          "<<sumatotal<<endl;
		cout<<"Desgloce por producto:  "<<endl;
		cout<<setprecision(5)<<" VIP   "<<tp1<<" - % sobre el total: "<<setprecision(3)<<tp1*100/sumatotal<<endl;
		cout<<setprecision(5)<<" PLATEA "<<tp2<<" - % sobre el total: "<<setprecision(3)<<tp2*100/sumatotal<<endl;
		cout<<setprecision(5)<<" POPULAR   "<<tp3<<" - % sobre el total: "<<setprecision(3)<<tp3*100/sumatotal<<endl;
		
	}
	catch (exception X){		
			cout<<"Error para abrir archivo"<<endl;			
			exit(1);
	}		
	
	
}

