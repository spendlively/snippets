
try:
    1 / 0
    '42' + 10
except (ZeroDivisionError, TypeError):
    print('Error')


try:
    1 / 0
    '42' + 10
except (ZeroDivisionError, TypeError) as e:
    print(type(e), e)


try:
    exception = Exception('spam', 'eggs')
    raise exception
except ZeroDivisionError:
    print('ZeroDivisionError')
except TypeError:
    print('TypeError')
except Exception as e:
    print(e)


