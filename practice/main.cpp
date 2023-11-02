
#include <stdio.h>

int	gl_var = 1;
int f(void) {return 2; }

namespace Foo{
	int	gl_var = 3;
	int f(void) {return 4; }
}

namespace Bar {
	int gl_var = 5;
	int	f(void) {return 6; }
}

namespace Huf = Bar; //namespace alias

/**
 * @brief gl_var and ::gl_var is same
 * 
 * @return int 
 */
int main(void){
	printf("gl_var: %d\n", gl_var);
	printf("f(): %d\n", f());
	printf("Foo:gl_var %d\n", Foo::gl_var);
	printf("f(): %d\n", Foo::f());
	printf("Bar:gl_var: %d\n", Bar::gl_var);
	printf("f(): %d\n", Bar::f());
	printf("Bar:gl_var: %d\n", Huf::gl_var);
	printf("f(): %d\n", Huf::f());
	printf("::gl_var: %d\n", ::gl_var);
	printf("::f(): %d\n", ::f());
	return(0);
}