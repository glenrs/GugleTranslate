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
    while(fgets(outMessage,100,stdin) == NULL) {
        printf("What would you like translated to Python World?\n");
    }
    
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

//This stores converts the names of the c functions to python function names.
static PyMethodDef CGTMethods[] = {
    {"translate", cgt_translate, METH_VARARGS,"Accepts messages from python and then sends messages back to Python."},
    {NULL, NULL, 0, NULL}
};

//This is what actually builds the Python Module
static PyModuleDef CGTModule = {
    PyModuleDef_HEAD_INIT, "GCT", NULL, -1, CGTMethods
};

//This will initialize the python module
PyObject* PyInit_CGT(void) {
    Py_Initialize();
    return PyModule_Create(&CGTModule);
}

