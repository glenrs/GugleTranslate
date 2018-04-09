# GugleTranslate

Gugle Translate has been designed to "translate" C and Python code. There are some Python libraries such as Cython that help this functionality accross C and Python. Gugle Translate avoids using these libraries in order to allow for the most versatility. The process is designed to execute as described in the image below.

![Alt text](/image/prompt.png "Optional Title")

## Implementation
Three implementations have been created since some complications arise in Python's limitations. These limitations occur when compiling the latest python3.6 and C11 versions. 

1. Embedded Python3.6 in C11 (Language 1 is C11 and Language 2 is Python3.6). This accomplishes the task as described

2. Extending Python3.6 with C99 (Language 1 is Python3.6 and Language 2 is C99). Extending Python uses functions that already exist in python. Although there appears to be ways to update compilation to C11, when newer versions of Python3 are used, these functions default to C99.

3. Extending embedded Python3.6 in C11 (Language 1 is Python3.6 and Language 2 is C11). This implementations allows for the most versatility possible. This implementation allows the user to use the exact versions of C and Python when compiling. The downsight is this does not "start" in Python. C will start, but will then import a python script that will execute. This script calls C embedded modules in Python. Python official documentation [Section 1.4](https://docs.python.org/3/extending/embedding.html) comments, "Simply forget for a while that the application starts the Python interpreter."

## Execution

The docker image glenrs/gugletranslate has been developed for easy execution of the three implementations. Please run the docker container in interactive mode in order to choose which implementation to run. (code below)

```
docker pull glenrs/gugletranslate
docker run -it --rm glenrs/gugletranslate /bin/bash
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

