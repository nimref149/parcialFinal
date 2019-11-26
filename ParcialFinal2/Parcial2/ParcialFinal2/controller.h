int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

//int controller_addEmployee(LinkedList* pArrayListEmployee);

//int controller_editEmployee(LinkedList* pArrayListEmployee);

int controller_removeEmployee(LinkedList* pArrayListEmployee);

//int controller_ListDatos(LinkedList* pArrayListEmployee);

//int controller_sortEmployee(LinkedList* pArrayListEmployee);

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

//int autoId(LinkedList* pArrayListEmployee,int inicio);

//int buscarIdMayor(LinkedList* pArrayListEmployee);

//int BuscarDatosPorId(LinkedList* pArrayListEmployee,int id);

//int menuModificarEmpleado(LinkedList* pArrayListEmployee,int index);

int controller_ListDatosOrdenado(LinkedList* pArrayListEmployee);
int menuCargarArchivo(LinkedList*lista);
int FiltrarDatos(LinkedList* lista);
