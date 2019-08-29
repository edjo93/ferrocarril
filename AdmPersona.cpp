#ifndef ADMPERSONA_CPP
#define ADMPERSONA_CPP
	#include"Persona.cpp"
	#include<fstream>
	#include<iostream>
	using namespace std;
	class AdmPersona{//esta clase ejecuta las operaciones de agregar ,modificar,listar y eliminar personas en un archivo binario
		private:
			string ruta;//ruta del archivo
		public:
			AdmPersona(string ruta){
				this->ruta=ruta;
			}
			void agregar(){//agrega una persona al archivo
				//escribir
				ofstream escribir(ruta.c_str(),ios::binary);
				if(!escribir){//si no se puede abrir el archivo hay un error
					cout<<"\nno se pudo abrir el archivo\n";
					return;//devuelve el control al menu
				}
				int id;
				string nombre;
				int edad;
				string cargo;
				cout<<"\n--agregar persona--\n";
				cout<<"\nid: ";
				cin>>id;
				cin.ignore(100,'\n');
				cout<<"\nnombre: ";
				getline(cin,nombre);
				cout<<"\nedad: ";
				cin>>edad;
				cin.ignore(100,'\n');
				cout<<"\ncargo: ";
				getline(cin,cargo);
				Persona p(id,nombre,edad,cargo);
				//enviar informacion al archivo
				//escribir.seekp(0,ios::end);
				escribir.write(reinterpret_cast<char*>(&p),sizeof(p));
				escribir.close();
			}	
			void listar(){
				ifstream leer(ruta.c_str(),ios::binary);
				if(!leer){
					cout<<"\nno se pudo abrir el archivo\n";
					return;
				}
				Persona persona;
				//leer + cout
			
				leer.read(reinterpret_cast<char*>(&persona),sizeof(persona));
				int i=1;
				cout<<"\n--personas---\n";
				while(!leer.eof()){
					cout<<"\n\n----"<<i++<<"----\n";
					persona.print();
					leer.read(reinterpret_cast<char*>(&persona),sizeof(persona));
				}
				leer.close();
			}
			void modificar(){
				fstream both(ruta.c_str(),ios::in|ios::out|ios::binary);//por defecto el archivo esta abierto para entrada y salida
				if(!both){
					cout<<"\nno se pudo abrir el archivo\n";
					return;
				}
				//verificar pos
				cout<<"\n--modificar persona--\n";
				cout<<"pos?: ";
				int pos;
				cin>>pos;
				Persona persona;
				//leer si en la posicion hay una persona
				both.seekg((pos-1)*sizeof(persona));
				both.read(reinterpret_cast<char*>(&persona),sizeof(persona));
				if(both.gcount()<sizeof(persona)){//no se ha leido una persona
					//no hay persona en pos
					cout<<"\nno person at pos\n";
				}else{
					//si encontro hay que modificar los datos
					int id;
					string nombre;
					int edad;
					string cargo;
					
					cout<<"\nid: ";
					cin>>id;
					persona.setId(id);
					cin.ignore(100,'\n');
					cout<<"\nnombre: ";
					getline(cin,nombre);
					persona.setNombre(nombre);
					cout<<"\nedad: ";
					cin>>edad;
					persona.setEdad(edad);
					cin.ignore(100,'\n');
					cout<<"\ncargo: ";
					getline(cin,cargo);
					persona.setCargo(cargo);
					//enviar informacion al archivo
					both.seekp((pos-1)*sizeof(persona));//posiciona para escribir
					both.write(reinterpret_cast<char*>(&persona),sizeof(persona));
					both.close();
				}
			}
			void eliminar(){
				// se elimina un registro - el registro que se desea eliminar, 
				//   se coloca en un estado inconsistente para no ser agregado al vector
				fstream both(ruta.c_str(),ios::out|ios::in|ios::binary);
				if(!both){
					cout<<"\nproblema al abrir el archivo\n";
					return;
				}
				Persona personas[100];
				int contador=0;
				cout<<"\n--eliminar--\n";
				int pos;
				cout<<"\npos?: ";
				cin>>pos;
				Persona persona;
				both.seekg((pos-1)*sizeof(persona));//en la posicion solicitada vemos si hay una persona
				both.read(reinterpret_cast<char*>(&persona),sizeof(persona));
				if(both.gcount()<sizeof(persona)){
					//no se encontro ninguna persona para esa posicion
					cout<<"\nno hay registro en pos\n";
				}else{
					//si encontro
					//en pos modificamos la persona y la ponemos en un estado inconsistente
					Persona personaBlanco;
					both.seekp((pos-1)*sizeof(personaBlanco));//posicion correcta para escribir
					both.write(reinterpret_cast<char*>(&personaBlanco),sizeof(personaBlanco));//escribir persona en blanco
					//colocar en un arreglo todas las personas validas
					both.seekg(0,ios::beg);
					both.read(reinterpret_cast<char*>(&persona),sizeof(persona));
					while(!both.eof()){
						if(persona.getId()!=0){
							personas[contador++]=persona;
						}
						both.read(reinterpret_cast<char*>(&persona),sizeof(persona));
					}
					//reemplazar el archivo con todas las personas del vector
					//borrar el archivo viejo
					both.close();
					remove(ruta.c_str());
					//creamos otro archivo
					ofstream newFile(ruta.c_str(),ios::app);
					for(int i=0;i<contador;i++){
						newFile.write(reinterpret_cast<char*>(&personas[i]),sizeof(personas[i]));
					}
					
					newFile.close();
				}
			}
			void removeArchivo(){
				remove("archivo.bin");
			}
	};
#endif
