#include <iostream>
#include <dlfcn.h>

typedef void (*PrintResultFunction)(int result);
typedef int (*CalculateResultFunction)(int a, int b);

int main() {
    void *lib = dlopen("lib/lib_business_logic.so", RTLD_LAZY);
    if (!lib) {
        std::cerr << "Error opening library: " << dlerror() << std::endl;
        return 1;
    }

   /*PrintResultFunction printResultFunction = (PrintResultFunction)dlsym(lib, "PrintResult");
    if (!printResultFunction) {
        std::cerr << "Error loading PrintResult function: " << dlerror() << std::endl;
        dlclose(lib);
        return 1;
    }
*/
    CalculateResultFunction calculateResultFunction = (CalculateResultFunction)dlsym(lib, "calculateResult");
    if (!calculateResultFunction) {
        std::cerr << "Error loading calculateResult function: " << dlerror() << std::endl;
        dlclose(lib);
        return 1;
    }

    // Вызов функций
    int result = calculateResultFunction(10, 5);
   // printResultFunction(result);

    dlclose(lib);
    return 0;
}

