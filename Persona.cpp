#ifndef PERSONA_CPP
#define	PERSONA_CPP
	class Persona{
		private:
			int id;
			char nombre[20];
			int edad;
			string cargo[20];
		public:
			 int getId() {
		        return id;
		    }
		
		     void setId(int id) {
		        this->id = id;
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
		        this->edad = edad;
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
	};
#endif
