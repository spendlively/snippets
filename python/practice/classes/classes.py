class MyClass1:
    pass


mc1 = MyClass1()
print(MyClass1, type(MyClass1), MyClass1.__bases__)
print(mc1, type(mc1), mc1.__class__)


# <class '__main__.MyClass1'> <class 'type'> (<class 'object'>,)
# <__main__.MyClass1 object at 0x7fb54e7d0da0> <class '__main__.MyClass1'> <class '__main__.MyClass1'>


class MyClass2(object):
    pass


mc2 = MyClass2()
mc3 = MyClass2()
print(MyClass2, type(MyClass2), MyClass2.__bases__)
print(mc2, type(mc2), mc2.__class__)
# <class '__main__.MyClass2'> <class 'type'> (<class 'object'>,)
# <__main__.MyClass2 object at 0x7fb54e7d0e10> <class '__main__.MyClass2'> <class '__main__.MyClass2'>


print(mc2 is mc2)  # True
print(mc2 is mc3)  # False

l1 = [1, 2, 3]
l2 = [1, 2, 3]
print(l1 == l2)  # True
print(l1 is l2)  # False


# Наследуемся от object
# self передается всегда явно
class Point(object):
    z = 10

    # вызывается при создании объекта
    def __init__(self, x, y):
        self.x = x
        self.y = y

    # магический метод toString
    def __str__(self):
        return '<Point {0} {1}>'.format(self.x, self.y)


p = Point(2, 3)
print(p.x, p.y, p.z, Point.z)
print(isinstance(p, Point))  # True
print(p)


# Магические методы
# __iadd__


# Наследование
class Vehicle:
    speed = 0
    age = 0

    def move(self):
        print('Vehicle move')


class Car(Vehicle):
    def move(self):
        super().move()
        # super().__init__()
        print('Car move')


car = Car()
print(Car, Car.__bases__, car, car.__class__.__class__)
car.move()


#  Множественное наследование
class One:
    pass


class Two:
    pass


class OneTwo(One, Two):
    pass


one_two = OneTwo()
print(one_two)

