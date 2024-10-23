FROM scratch
WORKDIR /app
COPY . .

RUN apt-get install libgtk-4-dev
EXSPOSE 5000

RUN useradd app
USER app

CMD []