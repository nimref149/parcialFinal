int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

//int controller_addEmployee(LinkedList* pArrayListEmployee);

//int controller_editEmployee(LinkedList* pArrayListEmployee);

int controller_removeEmployee(LinkedList* pArrayListEmployee);

int controller_ListLlamada(LinkedList* pArrayListEmployee);

//int controller_sortEmployee(LinkedList* pArrayListEmployee);

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

int autoId(LinkedList* pArrayListEmployee,int inicio);

int buscarIdMayor(LinkedList* pArrayListEmployee);

int BuscarLlamadaPorId(LinkedList* pArrayListEmployee,int id);

//int menuModificarEmpleado(LinkedList* pArrayListEmployee,int index);

int FiltrarLlamada(LinkedList* lista);
int menuCargarArchivo(LinkedList*lista);
