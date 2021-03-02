#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const char *nombre_archivo = "archivo.dat";
const char *nombre_archivo2 = "archivo2.dat";
struct Estudiante {

	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
	

};

void abrir();
void abrir2();
void ingresar();
void modificar();
void eliminar();

main(){

	abrir2();
	abrir();
	ingresar();
	modificar();
	eliminar();

}

void abrir(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");
	if (!archivo){
		archivo = fopen(nombre_archivo,"w+b");

	}

	Estudiante estudiante;
	int registro = 0;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"_____________________________________________________________________________________________"<<endl;
	cout<<"id |"<<"Codigo  |"<<"Nombres      |"<<"Apellidos      |"<<"Telefono    |"<<endl;
	do{
		cout<<"_____________________________________________________________________________________________"<<endl;
		cout<<registro<<" | "<<estudiante.codigo<<" | "<<estudiante.nombres<<" | "<<estudiante.apellidos<<" | "<<estudiante.telefono<<endl;
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		registro +=1;
	} while(feof(archivo)==0);
	fclose(archivo);
}

void abrir2(){
	system("cls");
	FILE* archivo2 = fopen(nombre_archivo2,"rb");
	if (!archivo2){
		archivo2 = fopen(nombre_archivo,"w+b");
	}
	Estudiante estudiante;
	fclose(archivo2);
}

void ingresar(){
	char continuar;
	FILE* archivo = fopen(nombre_archivo,"ab");
	Estudiante estudiante;
	string nombre,apellido;
	do{
		fflush(stdin);
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese los Nombres:";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese los Apellidos:";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		
		cout<<"Desea ingresar otro dato (s/n): ";
		cin>>continuar;

	}while(continuar == 's'||continuar == 'S');
	fclose(archivo);
	abrir();
}

void modificar(){
	FILE* archivo = fopen(nombre_archivo,"r+b");
	int id;
	string nombre,apellido;
	Estudiante estudiante;

	cout<<"Ingrese el ID que desea modificar:";
	cin>>id;

	fseek(archivo,id*sizeof(Estudiante),SEEK_SET);
  	cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese los Nombres:";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese los Apellidos:";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		fclose(archivo);
		abrir();

}

void eliminar(){
	/*FILE* archivo = fopen(nombre_archivo,"r+b");
	FILE* archivo2 = fopen(nombre_archivo2,"r+b");
	int cam;
	int tre;
	int id;
	bool enco=false;
	string nombre,apellido;
	Estudiante estudiante;
	
	cout<<"Ingrese el ID que desea eliminar:";
	cin>>id;
	while(feof(archivo)==0){
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		if(id==id){
			enco=true;
			cout<<"El registro ha sido eliminado";
						
		}else{
			FILE* archivo2 = fopen(nombre_archivo2,"r+b");
			Estudiante estudiante;
			string nombre,apellido;
			int codigo,telefono;
			
			fseek(archivo,id*sizeof(Estudiante),SEEK_SET);
				codigo=estudiante.codigo;
				nombre=estudiante.nombres;
				apellido=estudiante.apellidos;
				telefono=estudiante.telefono;
			fwrite(&estudiante,sizeof(Estudiante),1,archivo);
			fclose(archivo2);
		}
		
	}
	if(enco=false){
		cout<<"resgitro no encontrado";
		
	}
	fclose(archivo);
	fclose(archivo2);
	remove(nombre_archivo);
	rename(nombre_archivo2,nombre_archivo);*/
	FILE* archivo = fopen(nombre_archivo,"r+b");
	int id;
	string nombre,apellido;
	Estudiante estudiante;

	cout<<"Ingrese el ID que desea eliminar: ";
	cin>>id;

	fseek(archivo,id*sizeof(Estudiante),SEEK_SET);
		estudiante.codigo=0;
		nombre=" ";
		strcpy(estudiante.nombres,nombre.c_str());
		apellido=" ";
		strcpy(estudiante.apellidos,apellido.c_str());
		estudiante.telefono=0;
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		fclose(archivo);
		abrir();
	};





