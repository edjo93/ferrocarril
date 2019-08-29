#ifndef USEREXCEPT_CPP
#define USEREXCEPT_CPP
	#include<stdexcept>
	using namespace std;
	class UserExcept:public runtime_error{
		public:
			UserExcept(char*mensaje):runtime_error(mensaje){
				
			}
	};
#endif
