# GugleTranslate

Gugle Translate has been designed to "translate" C and Python code. The process is designed to execute as describe in the image below.

![Alt text](/image/prompt.png "Optional Title")

## Implementation
Three implementations have been created since some complications arise in Python's limitations. These limitations arise when compiling the latest python3.6 and C11 versions. There are some Python libraries such as Cython that help this functionality accross C and Python. These implementations avoid using these libraries in order to allow for the most mutability. 

1. Embedded Python3.6 in C11. This implementation starts in C11 code. It will ask for a message to send to python, and then transfer to Python. The Python code receives a callback function by argument and reports to the callback function after it finishes writing the message from C in Python code.

2. Extending Python3.6 with C99. Python is extended with basic python built in libraries. These functions use C99. Although there appears to be ways to update compilation to C11, when newer versions of Python3 are used, these functions default to C99.

3. Extending embedded Python3.6 in C11. This implementations allows for the most mutability possible. This allows the user to use the exact versions of C and Python. The downsight is this does not start in Python. C will start, but will then import a python script that will execute by calling C embedded modules in Python. 

## Execution

The docker image glenrs/gugletranslate has been developed for easy execution of the three implementations. Please run the docker container in interactive mode in order to choose which implementation to run. (code below)

```
docker pull glenrs/gugletranslate
docker run -it --rm --name gt glenrs/gugletranslate /bin/bash
```

The following three commands will allow for easy execution of the three implementations

1. Embedded Python3.6 in C11

```
./executeC11ToPython3.6.sh
```

2. Extending Python3.6 with C99

```
./executePython3.6ToC99.sh
```

3. Extending embedded Python3.6 in C11

```
./executePython3.6ToC11.sh
```

