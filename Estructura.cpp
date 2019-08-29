#ifndef ESTRUCTURA_CPP
#define ESTRUCTURA_CPP
	#include<string>
	#include<string.h>
	using namespace std;
	class Estructura{
		private:
			int peso;
			char material[20];
		public:
			Estructura(int peso,string material){//constructor por defecto
				setPeso(peso);
				setMaterial(material);
			}	
			 int getPeso() {
		        return peso;
		    }
		
		     void setPeso(int peso) {
		        this->peso = peso;
		    }
		
		     string getMaterial() {
		        return material;
		    }
		
		     void setMaterial(string material) {
		        const char*co=material.data();
				int longitud=material.size();
				longitud=(longitud<20?longitud:19);
				strncpy(this->material,co,longitud);
				this->material[longitud]='\0';
		    }
			
	};
#endif
