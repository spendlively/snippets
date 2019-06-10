from flask import Flask, render_template

app = Flask(__name__)


@app.route('/')
def index_page():
    return render_template('index.html')


# Если указать '/hello/' будет работать и для '/hello/', и для '/hello',
# но если указать '/hello' будет работать только для '/hello'
@app.route('/hello/')
def hello_page():
    return '<h1>Hello page!</h1>'


@app.route('/hello/<name>')
def hello_name(name):
    return '<h1>Hello, {0}!</h1>'.format(name)


# Если файл вызван непосредственно python3 filename.py
# то запускается сервер на localhost:5000
if __name__ == '__main__':
    app.run(host='localhost', port=5555)
