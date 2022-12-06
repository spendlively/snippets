#!/usr/bin/env bash

curl -X GET -H "nodename: 1" http://localhost:8881/ ;
curl -X GET -H "nodename: 2" http://localhost:8881/ ;
curl -X GET -H "nodename: 3" http://localhost:8881/ ;

