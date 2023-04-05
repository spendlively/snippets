from flask import Flask, request, render_template, make_response, url_for
from markupsafe import Markup
from werkzeug.utils import redirect

app = Flask(__name__)


@app.route("/")
def hello():
    return "Hello World!"


# http://localhost:5000/user/Denis
@app.route('/user/')
@app.route('/user/<username>')
def show_user_profile(username='Noname'):
    return 'User %s' % username


# http://localhost:5000/post/123
@app.route('/post/<int:post_id>')
def show_post(post_id):
    # show the post with the given id, the id is an integer
    print(type(post_id))
    return 'Post %d' % post_id


@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        return 'POST'
    else:
        return 'GET'


@app.route('/hi/')
@app.route('/hi/<name>')
def hi(name=None):
    return render_template('hi.html', name=name)


@app.route('/markup/')
def markup():
    return Markup('<strong>Hello %s!</strong>') % '<blink>hacker</blink>'


@app.route('/params/')
def params():
    search_word = request.args.get('key', '')
    return 'param key = ' + search_word


@app.route('/cookie/')
def cookie():
    resp = make_response(render_template('hi.html'))
    resp.set_cookie('username', 'ivan')
    resp.headers['X-Something'] = 'A value'
    return resp


@app.route('/redirect/')
def redir():
    return redirect('/')


@app.route('/abort')
def abort():
    abort(404)


if __name__ == "__main__":
    # app.run()
    # reload server after each code change
    app.run(debug=True)
