#!/usr/bin/env python3

def translate(userName,module,method,inMessage):
    print("***PYTHONWORLD***\nHello ",
        userName,
        ", I received your message from C, \"",
        inMessage,
        "\"",sep="")
    
    outMessage = input("What would you like to send to C world?")

    ## Dynamically import module by parameter
    CGT = __import__(module)

    ## Set up function pointer to call method in imported module
    method_to_call = getattr(CGT, method)
    method_to_call(outMessage,userName);

    ## This will execute after call back has finished executing
    print("***PYTHONWORLD***\nUnwinding Python")
    return 1