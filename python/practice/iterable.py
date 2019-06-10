

class MyIterable:

    def __init__(self, start, stop):
        if not stop > start:
            raise ValueError('Start must be lass than stop')
        self.start = start
        self.stop = stop
        self.current = start

    def __iter__(self):
        return self

    def __next__(self):
        if self.current < self.stop:
            self.current += 1
            return self.current
        raise StopIteration

    def reset(self):
        self.current = self.start - 1


it = MyIterable(start=1, stop=3)

# 1
print(it.current)
print(next(it))
print(next(it))

it.reset()

# 2
for i in it:
    print(i, end="\n")

it.reset()

# 3
iterable = iter(it)
print(next(iterable))
print(next(iterable))
print(next(iterable))

