from aiohttp import web


async def handler(request):
    return web.Response(text='Hello, World!')


app = web.Application()
app.add_routes([web.get('/', handler)])

app.run_app(app, host='localhost', port=3001)
