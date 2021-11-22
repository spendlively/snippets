////////////////////
//Docker-контейнер//
////////////////////
 - приложение, упакованное вместе с его зависимостями
 - в контейнере нет своего ядра, оно использует ядро хостовой системы
 - нет crontab
 - в контейнере не должно быть ssh-сервера
 - рекоммендуют не использовать в контейнере больше одного приложения

//////////////////
//Принцип работы//
//////////////////
//Namespaces
 - появились в ядре linux от 2.3
 - предоставляет возможности изоляции окружения
 - позволяют спользовать свои pid, net, mount-точки монтирования
 - Namespace прекращает свое существование после окончания работы PID1

//CGroups
 - отвечает за выделение ресурсов в контейнерах
 - CPU, memory, IO
 - ограничение ресурсов

//UnionFS
 - файловая система кот предоставляется для докеров
 - состоит из слоев
 - каждый нижележащий слой после опр действий становится доступен в режиме read-only
 - самый верхний слой доступен для чтения и записи
 - нижние слои доступны только для чтения
 - если какие-то действия требуют очистку кешей, производить их нужно в том же слое:
RUN apt-get install nginx -y
RUN apt-get clean -y
# apt-get clean место не освободит

/////////////////
//Docker deamon//
/////////////////
 - предоставляет rest-api, кот доступно по unix-сокету и по tcp-сокету
 - вызывается при помощи docker-cli или curl
 - docker deamon'ы общаются м/у собой

//Docker-cli
 - принимает команды от пользователя
 - взаимодействует с api docker deamon

///////////////////
//Docker registry//
///////////////////
 - репозиторий для образов
 - Docker hub (public, private)
 - Gitlab

//RunC

/////////////////////
//Пример докерфайла//
/////////////////////
FROM ubuntu:16.04
RUN apt-get update -y && apt-get upgrade -y \
    && apt-get install nginx wget openssl apt-transport-https curl -y \
    && apt-get clean -y
RUN echo "daemon off;" >> /etc/nginx/nginx.conf
EXPOSE 443
CMD [ "nginx" ]

///////////
//Команды//
///////////
docker pull nginx
docker run -d -p 80:80 nginx
docker run -it -p 80:80 nginx
docker stop $(docker ps -aq)
docker stop cont_hash
docker build -t id/cont-name:ver .
docker push id/cont-name:ver

///////////////
//Docker сети//
///////////////
//Доступные модули (драйвера сети)
//None
 - создается только loopback интерфейс
 - нет доступа в контейнер и из контейнера
 - например для тестов

//Host
 - контейнер использует namespace хоста
 - сеть не управляется самим докером
 - хорошая производительность как у хостовой сети
 - нельзя запустить 2 контейнера кот будут слушать один и тот же порт

//Bridge
 - предоставляет отдельносозданный один bridge - docker0
 - все контейнеры по умолчанию всегда подключаются в него
 - позволяет объединить докерконтейнеры в сеть
 - позволяет экспоузить порты наружу
 - не спользовать использовать EXPOSE в докерфайлах
 - указывать порты при запуске контейнера?
 - нет service discovery - контейнеры не смогут найти друг друга до dns
 - Взаимодействие контейнеров между собой
 - по ip
 - docker links (deprecated)
 - docker dns
 - внешний service discovery/dns

//Macvlan
 - Работает на основе sub-interfaces Linux
 - Более производительный, чем bridge
 - Если нужно подключить контейнер к локальной сети
 - Особенности:
    - Легко исчерпать пул DHCP
    - Много MAC адресов в L2 сегменте
    - Сетевой интерфейс в promiscuous mode

//Overlay
 - Позволяет объединить в одну сеть контейнеры нескольких Docker хостов
 - Работает поверх VXLAN
 - Необходимо хранить состояние распределенной сети


//Практика
//Просмотр запущенных контейнеров
docker ps
//в том числе остановленные
docker ps -a

//Запустить контейнер из образа nginx
//-d - запустить контейнер в detach-режиме, интерфейс контейнера отцеплен от интерфейса хостовой машины
//--rm - удалить контейнер после остановки
//--name web - запустить контейнер с именем web
//-p 80:80 - пробросить порт 80 контейнера в порт 80 хоста
//ПЕРВЫМ ВСЕГДА ИДЕТ ПОРТ ХОСТА
//nginx - контейнер запускается на основе образа nginx:latest
docker run -d --rm --name web -p 80:80 nginx

//Просмотр логов контейнер (все логи пришедшие в STDIN и STDOUT контейнера)
docker logs web
//или
docker logs hash
//или
docker logs 2

//Подключиться к контейнеру
docker exec -it bash

//Просмотр конфигурации контейнера
docker inspect web

//Остановить контейнер
docker stop 2
docker ps -a
//ничего не выведет т.к. мы использовали опцию --rm при запуске

//ENV vs ARGS
 - ENV - можно использовать для проброса переменных окружения для контейнера
 - ARGS - можно использовать только во время сборки и в контейнер они не попадут

//COPY vs ADD
 - COPY - скопирует файл или папку в контейнер
 - ADD - предоставляет больше возможностей (скачать урл с интернета, распаковать архив)
 - Если нужно закинуть архив в контейнер нужно итспользовать COPY, т.к. ADD по умолчанию его разархивирует
 - По умолчанию нужно использовать COPY

//Dockerfile команды
 - WORKDIR - каталог, кот открывается после подключения к контейнеру
 - COPY . . - скопировать содержание текущей директории в WORKDIR
 - RUN go build -o main . - выполниь "go build -o main ." в контейнере
 - CMD ["./main"] - запустить ./main

//Запустить сборку образа
//-t qwerty/asdfgh:0.1 - REPOSITORY = "qwerty/asdfgh" и TAG = "0.1"
//. - собираем в тек директории и эта директория будет передана в кач билд-контекста
//Для собрки будет использоваться файл с именем Dockerfile
docker build -t qwerty/asdfgh:0.1 .

//Просмотр собранных образов
docker images
//REPOSITORY = qwerty/asdfgh
//TAG = 0.1

/////////////////////
//Multistage сборка//
/////////////////////
//Для сборки golang приложения ./main будет использовать образ golang:latest
//После чего ./main скопируется в образ alpine:latest
//Размер финального контейнера будет ~14мб вместо 800мб
docker build -f Dockerfile.multistage -t qwerty/asdfgh:0.2 .


//////////////////
//docker-compose//
//////////////////
 - позволяет описывать этапы запуска контейнеров

//Запуск
//Билдим необх образы
docker build -t mrgreyves/nginx:0.1 .
docker build -t mrgreyves/php-fpm:0.1 .
//Запускаем docker-compose
docker-compose up -d

//Остановка
docker-compose down

//Описание файла
//Версия docker-compose файла
version: "3.7"
//Список сервисов (контейнеры)
services:
  //Описание сервиса web
  web:
    //Контейнер на основе образа "mrgreyves/nginx:0.1"
    image: mrgreyves/nginx:0.1
    //Имя контейнера
    container_name: web
    //Зависит от сервиса php
    depends_on:
        - php
    //Монтуруемые файлы: "локальный файл":"файл в контейнере"
    volumes:
      - ./default.conf:/etc/nginx/sites-available/default
      - ./default.conf:/etc/nginx/sites-enabled/default
      - ./info.php:/var/www/info.php
      - ./test.php:/var/www/test.php
      - ./mysql.php:/var/www/mysql.php
    //Экспойзим: "локальный порт 80":"файл в контейнере 80"
    ports:
        - "80:80"
    //Указываем к какой сети подключен наш контейнер
    networks:
      front_net:
        //IP адресс контейнера
        ipv4_address: 10.20.30.10
        //ОБЯЗАТЕЛЬНО!!! Под каким доменным именем блудет доступен сервис!
        aliases:
          - web


  php:
    image: mrgreyves/php-fpm:0.1
    volumes:
      - ./info.php:/var/www/info.php
      - ./test.php:/var/www/test.php
      - ./mysql.php:/var/www/mysql.php
    networks:
      front_net:
        aliases:
          - php

  not-db:
    image: mysql:5.7.28
    container_name: not-db
    environment:
      //Прокидываем переменную окружения
      MYSQL_ROOT_PASSWORD: root
    networks:
      front_net:
        ipv4_address: 10.20.30.30
        aliases:
          - db

//Описание сетей (front_net)
networks:
  front_net:
    ipam:
      driver: default
      //Конфиг сети
      config:
        - subnet: "10.20.30.0/24"
