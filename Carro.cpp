#ifndef CARRO_CPP
#define CARRO_CPP
	#include"Rueda.cpp"
	#include"Base.cpp"
	#include"Soporte.cpp"
	#include"Cubierta.cpp"
	//clase compuesta por estructuras metalicas
	class Carro{
		private:
			string funcion;
			int capacidad;
			int longitud;
			int anchura;
			Rueda*rueda;
			Base*base;
			Soporte*soporte;
			Cubierta*cubierta;
		public:
			 string getFuncion() {
		        return funcion;
		    }
		
		     void setFuncion(string funcion) {
		        this->funcion = funcion;
		    }
		
		     int getCapacidad() {
		        return capacidad;
		    }
		
		     void setCapacidad(int capacidad) {
		        this->capacidad = capacidad;
		    }
		
		     int getLongitud() {
		        return longitud;
		    }
		
		     void setLongitud(int longitud) {
		        this->longitud = longitud;
		    }
		
		     int getAnchura() {
		        return anchura;
		    }
		
		     void setAnchura(int anchura) {
		        this->anchura = anchura;
		    }
		    void setRueda(Rueda*rueda){
		    	this->rueda=rueda;
			}
			Rueda* getRueda(){
				return rueda;
			}
			void setBase(Base* base){
				this->base=base;
			}
			Base* getBase(){
				return base;
			}
			void setSoporte(Soporte*soporte){
				this->soporte=soporte;
			}
			Soporte* getSoporte(){
				return soporte;
			}
			void setCubierta(Cubierta*cubierta){
				this->cubierta=cubierta;
			}
			
	};
#endif
