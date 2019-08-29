#include"AdmPersona.cpp"
int main(){
	AdmPersona admPersona("./archivo.bin");
	
	//admPersona.agregar();
	admPersona.listar();
	admPersona.eliminar();
	admPersona.listar();
	
	return 0;
}
