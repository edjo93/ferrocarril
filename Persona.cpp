#ifndef PERSONA_CPP
#define	PERSONA_CPP
	#include<string>
	#include<string.h>
	#include"UserExcept.cpp"
	#include<iostream>
	using namespace std;
	class Persona{
		private:
			int id;
			char nombre[20];
			int edad;
			char cargo[20];
		public:
			Persona(){//persona en blanco
				id=0;
				edad=0;
			}
			Persona(int id,string nombre,int edad,string cargo){
				setId(id);
				setNombre(nombre);
				setEdad(edad);
				setCargo(cargo);
			}
			 int getId() {
		        return id;
		    }
		
		     void setId(int id) {
		        bool result=false;
		        
				while(!result){
		        	try
					{
						result=idValido(id);
		        		this->id=id;		
					}
					catch(UserExcept&e){
						cout<<"\nmyexcept: "<<e.what();
						cout<<endl;
					}
					if(!result){
						cout<<"nuevo id: ";cin>>id;
						cout<<endl;
					}
				}
		    }
		
		     string getNombre() {
		        return nombre;
		    }
		
		     void setNombre(string nombre) {
		        const char*co=nombre.data();
				int longitud=nombre.size();
				longitud=(longitud<20?longitud:19);
				strncpy(this->nombre,co,longitud);
				this->nombre[longitud]='\0';
		    }
		
		     int getEdad() {
		        return edad;
		    }
		
		     void setEdad(int edad) {
		        bool result=false;
		        while(!result){
		        	try
		        	{
		        		result=edadValida(edad);
		        		this->edad=edad;
					}
					catch(UserExcept&e){
						cout<<"\nmyexcept: "<<e.what();
						cout<<endl;
					}
					if(!result){
						cout<<"\nnueva edad: ";cin>>edad;
						cout<<endl;
					}
				}
		    }
		
		    string getCargo() {
		        return cargo;
		    }
		
		     void setCargo(string cargo) {
		        const char*co=cargo.data();
				int longitud=cargo.size();
				longitud=(longitud<20?longitud:19);
				strncpy(this->cargo,co,longitud);
				this->cargo[longitud]='\0';
		    }
			bool idValido(int id)	{
				if(id<1){
					throw UserExcept("el id no es valido");
				}
				return true;
			}
			bool edadValida(int edad){
				if(edad<15||edad>90){
					throw UserExcept("la edad no es valida");
				}
				return true;
			}
			void print(){
				cout<<"id: "<<id<<endl;
				cout<<"nombre: "<<nombre<<endl;
				cout<<"edad: "<<edad<<endl;
				cout<<"cargo: "<<cargo<<endl;
			}
	};
#endif
