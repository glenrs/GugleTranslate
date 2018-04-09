FROM ubuntu:16.04

WORKDIR /usr/src/app
COPY src/ ./

RUN apt-get update
RUN apt-get install -y software-properties-common vim
RUN add-apt-repository ppa:jonathonf/python-3.6
RUN apt-get update

## Python 3.6
RUN apt-get install -y build-essential python3.6 python3.6-dev

## C11
RUN apt-get install -y build-essential gcc

CMD ["/bin/bash"]
