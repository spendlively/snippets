from django.shortcuts import render
from django.views import generic

from .models import Book, Author, BookInstance, Genre


def index(request):
    """
    Функция отображения для домашней страницы сайта.
    """
    # Генерация "количеств" некоторых главных объектов
    num_books = Book.objects.all().count()
    num_instances = BookInstance.objects.all().count()
    # Доступные книги (статус = 'a')
    num_instances_available = BookInstance.objects.filter(status__exact='a').count()
    num_authors = Author.objects.count()  # Метод 'all()' применен по умолчанию.
    title = 'Dynamic Title!'

    # Number of visits to this view, as counted in the session variable.
    num_visits = request.session.get('num_visits', 0)
    request.session['num_visits'] = num_visits + 1

    # Отрисовка HTML-шаблона index.html с данными внутри
    # переменной контекста context
    return render(
        request,
        'index.html',
        context={'num_books': num_books, 'num_instances': num_instances,
                 'num_instances_available': num_instances_available, 'num_authors': num_authors,
                 'title': title, 'num_visits': num_visits},
    )


class BookListView(generic.ListView):
    model = Book

    # Переопределение некоторых аттрибутов
    # context_object_name = 'my_book_list'   # ваше собственное имя переменной контекста в шаблоне
    # queryset = Book.objects.filter(title__icontains='war')[:5] # Получение 5 книг, содержащих слово 'war' в заголовке
    # template_name = 'books/my_arbitrary_template_name_list.html'  # Опред имени вашего шаблона и его расположения

    # Переопределение некоторых методов
    # Переопределение метода получения списка всех записей
    # def get_queryset(self):
    #     return Book.objects.filter(title__icontains='war')[:5]  # Получить 5 книг, содержащих 'war' в заголовке

    # Переопределение метода get_context_data для передачи доп данных в контекст шаблона
    # def get_context_data(self, **kwargs):
    #     # В первую очередь получаем базовую реализацию контекста
    #     context = super(BookListView, self).get_context_data(**kwargs)
    #     # Добавляем новую переменную к контексту и иниуиализируем ее некоторым значением
    #     context['some_data'] = 'This is just some data'
    #     return context


class BookDetailView(generic.DetailView):
    model = Book


class AuthorListView(generic.ListView):
    model = Author


class AuthorDetailView(generic.DetailView):
    model = Author
