FROM ubuntu:trusty

RUN apt-get install -y -q g++
    apt-get install -y -q make

COPY . /test-poisson-jramzi
WORKDIR /test-poisson-jramzi
CMD ./test.sh
