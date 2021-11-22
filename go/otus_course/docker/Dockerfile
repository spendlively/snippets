FROM golang:latest
LABEL maintainer="OTUS Vladimir D"
WORKDIR /app
COPY . .
RUN go build -o main .
CMD ["./main"]
