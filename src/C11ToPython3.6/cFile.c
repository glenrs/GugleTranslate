#include <Python.h>

//This entire module is generated for the Callback function
//This is the callback function
static PyObject* cgt_callback(PyObject *self, PyObject *args) {
    const char *message, *userName;

    if(!PyArg_ParseTuple(args,"ss",&message,&userName))
        return NULL;
    
    //Username is already passed by reference because it is a char array.
    printf("***CWORLD***\nThanks %s! The call back received your message from Python, \"%s\"\n",userName,message);

    return Py_None;
}

//Sets function names c to python
static PyMethodDef CGTMethods[] = {
    {"callback", cgt_callback, METH_VARARGS,"Accepts messages from python and then sends messages back to Python."},
    {NULL, NULL, 0, NULL}
};

//Generate module
static PyModuleDef CGTModule = {
    PyModuleDef_HEAD_INIT, "CGT", NULL, -1, CGTMethods,
    NULL, NULL, NULL, NULL
};

//Initialize module
static PyObject* PyInit_cgt(void) {
    return PyModule_Create(&CGTModule);
}

int main(int argc, char *argv[]) {
    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue;

    printf("***CWorld***\nWelcome to Gugle Translate. Before starting, what is your name?\n");
    char name[20];
    fgets(name,20,stdin);
    name[strlen(name)-1] = '\0';
    printf("What would you like to send to Python?\n");

    char message[100];
    fgets(message,100,stdin);
    message[strlen(message)-1] = '\0';

    PyImport_AppendInittab("CGT", &PyInit_cgt);
    Py_Initialize();

    //This reads the first argument which is the name of the python module
    pName = PyUnicode_DecodeFSDefault(argv[1]);
    pModule = PyImport_Import(pName);

    Py_DECREF(pName);

    if (pModule != NULL) {
        //The function is stored in the second argument
        pFunc = PyObject_GetAttrString(pModule, argv[2]);
        if (pFunc && PyCallable_Check(pFunc)) {
            // "CGT" is the name of the module created and "callback" is the callback function name
            pArgs = Py_BuildValue("ssss",name,"CGT","callback",message);

            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if (pValue != NULL) {
                printf("***CWORD***\n");
                Py_DECREF(pValue);
            }
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr,"Call failed\n");
                return 1;
            }
        }
        else {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function \"%s\"\n", argv[2]);
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"%s\"\n", argv[1]);
        return 1;
    }
    if (Py_FinalizeEx() < 0) {
        return 120;
    }
    printf("Unwinding C\n");
    return 0;
}
