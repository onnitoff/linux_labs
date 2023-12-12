#include "func1.h"
#include "func2.h"
#include <iostream>
#include <dlfcn.h>

typedef void (*PrintResultFunction)(int result);
typedef int (*CalculateResultFunction)(int a, int b);


int main() {
	void *lib = dlopen("./libFunc1_Func2.so", RTLD_LAZY);
    if (!lib) {
        std::cerr << "Error opening library: " << dlerror() << std::endl;
        return 1;
    }
    
    PrintResultFunction printResultFunction = (PrintResultFunction)dlsym(lib, "func1_print");
    if (!printResultFunction) {
        std::cerr << "Error loading PrintResult function: " << dlerror() << std::endl;
        dlclose(lib);
        return 1;
    }
    
    CalculateResultFunction calculateResultFunction = (CalculateResultFunction)dlsym(lib, "func2_math");
    if (!calculateResultFunction) {
        std::cerr << "Error loading calculateResult function: " << dlerror() << std::endl;
        dlclose(lib);
        return 1;
    }
    
    
	
	int result = calculateResultFunction(20, 5);
	
	printResultFunction(result);
	
	dlclose(lib);
	return 0;



}
