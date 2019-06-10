# sudo pip3 install aiohttp

import asyncio
import aiohttp


async def main():
    async with aiohttp.ClientSession() as session:
        async with session.get('http://httpbin.org/get') as response:
            print(await response.text())


loop = asyncio.get_event_loop()
loop.run_until_complete(main())
