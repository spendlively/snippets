
//0. Установка
//0.1 protoc
https://github.com/protocolbuffers/protobuf/releases
https://github.com/protocolbuffers/protobuf/blob/master/src/README.md
./configure
make
make check
sudo make install
sudo ldconfig # refresh shared library cache.

//0.2 Обновляем protoc-gen-go и protoc-gen-go-grpc
go get -u google.golang.org/protobuf/cmd/protoc-gen-go
go get -u google.golang.org/grpc/cmd/protoc-gen-go-grpc

//0.3 evans
go get github.com/ktr0731/evans



//1. protobuf file определяет message request и message response
syntax = "proto3";
package search;
option go_package = "./;searchpb";

service Google {
    // Search returns a Google search result for the query.
    rpc Search(Request) returns (Result) {
    }
}

message Request {
    string query = 1;
}

message Result {
    string title = 1;
    string url = 2;
    string snippet = 3;
}



//2. компилятор protoc генерит 2 файла
protoc search.proto --go_out=. --go-grpc_out=.

//2.1 файл для организации rpc
package searchpb;
type GoogleClient interface {
    // Search returns a Google search result for the query.
    Search(ctx context.Context, in *Request, opts ...grpc.CallOption) (*Result, error)
}

type GoogleServer interface {
    // Search returns a Google search result for the query.
    Search(context.Context, *Request) (*Result, error)
}

// 2.2 файл для go со структурами
type Request struct {
    Query string `protobuf:"bytes,1,opt,name=query" json:"query,omitempty"`
}

type Result struct {
    Title string `protobuf:"bytes,1,opt,name=title" json:"title,omitempty"`
    Url string `protobuf:"bytes,2,opt,name=url" json:"url,omitempty"`
    Snippet string `protobuf:"bytes,3,opt,name=snippet" json:"snippet,omitempty"`
}



//3. Типы данных protobuf
double (float64)
float (float32)
bool (bool)
string (string) UTF-8 / 7-bit ASCII
bytes ([]byte)
int{32,64} (отрицательные значения - 10 байт)
uint{32,64}
sint{32,64} (ZigZag для отрицательных значений)

//Дефолтные значения
string: пустая строка
number (int32/64 etc.): 0
bytes: пустой слайс
enum: первое значение
repeated: пустой слайс
Message - зависит от языка, в Go - nil

//Дефолтное значение enum - первое поле
//поэтоиу следует делоть первое поле "неопреленное-по-умлолчанию"
//EYE_COLOR_UNSPECIFIED = 0;
enum EyeColor {
    EYE_COLOR_UNSPECIFIED = 0;
    EYE_GREEN = 1;
    EYE_BLUE = 2;
}
message Person {
    string name = 1;
    repeated string phone_numbers = 2;
    EyeColor eye_color = 3;
}

//Если нужен null, можео использовать обертки
oneof string {
    string value = 5;
}
//string value = 5 если либо его нет


//Пакеты
//пакет содержит весь путь до себя через точку
package my.date
//Файл лежит в my/date/mydate.proto


//go_package
//Путь, куда будет генериться гошный код
option go_package = "./;simplepb"
./ - в тужу директорию, куда укажем protoc
;simplepb - через точку с зяпятой именование гошного пакета
//если не сделать имя пакета будет совпадать с именем протобафного пакета



//oneof позволяет использовать одно поле из
- в го будет ряд интерфейсов
- можно делать type-switch по интерфейсам или по типу, который лежит в oneof
message Message {
    int32 id = 1;
    oneof auth {
        string mobile = 2;
        string email = 3;
        int32 userid = 4;
    }
}



//Полезные well known типы от гугла (Timestamp, Duration)
syntax = "proto3";
import "google/protobuf/timestamp.proto";
import "google/protobuf/duration.proto";
message MyMessage {
    google.protobuf.Timestamp last_online = 1;
    google.protobuf.Duration session_length = 2;
}



//Кроме well known типов гугл выкладывает доп thitd party типы
https://github.com/googleapis/googleapis/blob/master/google/api/http.proto



//Правила обраьной совместимости
 - не менять теги
 - не менять нумерацию полей
 - старый код будет игнорировать новые поля
 - при неизвестных полях испольуются дефолтные значения
 - поля можно удалять, но не переиспользовать тег / добавить префик OBSOLETE_ / сделать поле reserved



//Styleguide
https://developers.google.com/protocol-buffers/docs/style
 - строка 80, отступ 2
 - файлы lower_snake_case.proto
 - сообщения CamelCase, поля - underscore_separated_names
 - CAPITALS_WITH_UNDERSCORES для enums

message SongServerRequest {
    required string song_name = 1;
}

enum Foo {
    FOO_UNSPECIFIED = 0;
    FOO_FIRST_VALUE = 1;
    FOO_SECOND_VALUE = 2;
}



//Генерация
protoc \
    --proto_path=api/elections/ \
    --go_out=elections/pb \
    --go-grpc_out=elections/pb \
    api/elections/*.proto

//Сгенерить структурки для месседжей
--go_out=elections/pb

//Сгенеритьл сервис для rpc
--go-grpc_out=elections/pb \

//путь к протобаф файлам
api/elections/*.proto


//Куда генерить
//Вариант 1
В какой-то отдельный пакет, который отвечает только за protobuf



//Как это использовать
//Сервер elections/server/main.go
//1. начинаем слушать на каком-то порту
 - дефолтный порт для сервера 50051)

//2. стартуем сервер
server := grpc.NewServer()

//3. связываем сервер с нашим сервисом
pb.RegisterElectionsServer(server, new(Service))

//3.1. наш сервис должен реализовывать интерфейс регистратора
func (s *Service) SubmitVote(ctx context.Context, req *pb.SubmitVoteRequest) (*pb.SubmitVoteResponse, error) {}

//3.2 Заглушка, кот реализует SubmitVote, чтобы защититься от отсутствия реализации
type Service struct {
	pb.UnimplementedElectionsServer
}

//4. Сервим сервер на нашем порту
if err := server.Serve(lsn); err != nil {
    log.Fatal(err)
}

//5. Обработка запроса
func (s *Service) SubmitVote(ctx context.Context, req *pb.SubmitVoteRequest) (*pb.SubmitVoteResponse, error) {}



//Как это использовать
//Клиент elections/client/main.go
//1. Коннект к серверу
conn, err := grpc.Dial(":50051", grpc.WithInsecure())

//2. Создание клиента
client := pb.NewElectionsClient(conn)

//3. создаем реквест
req, err := getRequest(reader)

//4. Вызов метода client.SubmitVote
if _, err := client.SubmitVote(context.Background(), req); err != nil {}



//Запуск
 - Запуск сервера (CTRL + ShIFT + F10)
 - Запуск клиента (CTRL + ShIFT + F10)
 - В консоли клиента отправляем запрос: 123 456 789



//evans
 - cli-утилита для работы с grpc

//Запуск
 - make evans
//или
evans --proto api/elections/elections.proto repl

//Получение подсказки
call + [TAB]





//Route map
 - описать все единым контрактом
 - одной командой генерим для него обвязки
 - реализуем сервер, зарегистрировали в нем наш сервис
 - реализуем клиент и выполняем запросы



//Испоьлзование GRPC
- самый частый юзкейс - использование стримов
- если нет стримов, возможно нужно отказаться от grpc



//GRPC GateWay
 - позволяет работать с grpc сервером через обычный http

