# Запускам
docker run -d \
    --name pg \
    -e POSTGRES_PASSWORD=postgres \
    -e PGDATA=/var/lib/postgresql/data/pgdata \
    -v /Users/anthony/psqldata:/var/lib/postgresql/data \
    -p 5432:5432 \
    postgres

# Заходим в CLI
docker exec -it pg psql -Upostgres -dpostgres

# Создаем себе пользователя и БД
postgres=# create database books;
postgres=# create user anthony with encrypted password 'anthony';
postgres=# grant all privileges on database books to anthony;

# Проверяем
docker exec -it pg psql -Uanthony -dbooks

# Создаем миграции
https://github.com/pressly/goose
go get -u github.com/pressly/goose/cmd/goose
goose -dir migrations create init sql

# Применяем миграции и проверяем
goose -dir migrations postgres "user=anthony password=anthony dbname=books sslmode=disable" up
docker exec pg psql -Uanthony -dbooks -c "\dt"
docker exec pg psql -Uanthony -dbooks -c "select * from books";

# Полезное
https://github.com/BurntSushi/toml
https://github.com/jackc/pgx
http://go-database-sql.org/errors.html
https://github.com/golang/go/issues/24329#issuecomment-373145906
