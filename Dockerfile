FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    build-essential \
    libgtk-4-dev \
    pkg-config \
    cmake \
    make

COPY . .

RUN mkdir build
RUN cd build
RUN cmake ..
RUN make all

CMD ./poker.o