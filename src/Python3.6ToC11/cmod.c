#include <Python.h>

//translates user input to python and sends it to the callback function.
//After receiving the callback, this function unwinds.
static PyObject* cgt_translate(PyObject *self, PyObject *args) {
    const char *userName;
    const char *inMessage;
    PyObject *callBackFunction;

    if(!PyArg_ParseTuple(args,"sOs",&userName,&callBackFunction,&inMessage))
        return NULL;
    
    //Add a reference to the new callback
    Py_XINCREF(callBackFunction);

    //Username is already passed by reference because it is a char array.
    printf("***CWORLD***\nHello %s, I received your message \"%s\". What would you like translated to Python World?\n",userName,inMessage);

    //Get user input and prepare to send it back to python
    char outMessage[100];
    PyObject *argList;
    fgets(outMessage,100,stdin);
    
    //Get rid of the end of line character
    outMessage[strlen(outMessage)-1] = '\0';
    argList = Py_BuildValue("(s)",outMessage);

    //Get call back result in python object
    PyObject_CallObject(callBackFunction,argList);
    Py_DECREF(callBackFunction);
    printf("***CWORLD***\n");
    printf("unwinding c\n");

    return Py_None;
}

static PyMethodDef CGTMethods[] = {
    {"translate", cgt_translate, METH_VARARGS,"Accepts messages from python and then sends messages back to Python."},
    {NULL, NULL, 0, NULL}
};

static PyModuleDef CGTModule = {
    PyModuleDef_HEAD_INIT, "CGT", NULL, -1, CGTMethods,
    NULL, NULL, NULL, NULL
};

static PyObject* PyInit_cgt(void) {
    return PyModule_Create(&CGTModule);
}

int main(int argc, char *argv[]) {
    PyObject *pName, *pModule;

    //This function initalizes the module CGT that can be called by python
    PyImport_AppendInittab("CGT", &PyInit_cgt);
    Py_Initialize();

    printf("***CWORLD***\n");
    printf("Note that this is extended embedded Python in C. This main function calls a python script that can execute C modules. This is the only way to specify exactly which compiling method will be used. This is why it starts and ends in C.\n");

    //This function reads the python script location by argument.
    pName = PyUnicode_DecodeFSDefault(argv[1]);

    //This function executes the script that is being stored as a PyObject pointer.
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    printf("***finishing in c***\n");
    printf("Note that this is extended embedded Python in C. This main function calls a python script that can execute C modules. This is the only way to specify exactly which compiling method will be used. This is why it starts and ends in C.\n");
    if (Py_FinalizeEx() < 0) {
        return 120;
    }
    return 0;
}
