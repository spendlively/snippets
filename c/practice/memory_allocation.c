#include <stdio.h>
#include <stdlib.h>

int main() {

    long count = 1000000000;
    //malloc возвращает void*, поэтому нужно вручную приводить тип у правильному
    //в malloc нужно передавать размертолько в байтах, поэтому нужно использовать sizeof
    //sizeof определяется на этапе компиляции
//    char *ptr = (char *) malloc(count);
    char *ptr = (char *) malloc(count * sizeof(char));
    char any_key;

    //ОС может отказать в выделении памяти, поэтому желательно проверить на NULL
    if (NULL == ptr) {
        printf("Can not allocate %ld bytes! Exiting...\n", count);
        exit(1);
    }

    //Если процессор 32-битный (или компилятор 32-битный)
    //адресовать можно максимум 2^32 = 4млрд ячеек = 4Гибибайта (4096Мб)
    //по факту ос может выдать еще меньше

    printf("You have allocated %ld bytes!\nEnter any key: \n", count);
    scanf("%c", &any_key);

    //Когда процесс освобождается, вся память освобождается,
    //но лучше явно ее освобождать с помощью free
    free(ptr);

    //calloc предразначена для создания массивов
    //инициализирует память нулями
    //не нужно вручную умножать размер на sizeof
//    calloc(size, sizeof(char))

    return 0;
}
