
#include <stdexcept>

void	test(){
	try {
		if (there's exception) {
			throw std::exception();
		}
		else {
			//do something
		}
	}
	catch (std::exception e){
		//handle error here
	}
}