# Programmer: Jack
# Student ID: 1930026143
# Date: 2020/1/24
# Requirements:
import asyncio
import time
async def request(url):
    print('正在下载', url)
    # 不是sleep()
    await asyncio.sleep(2)
    print('下载完毕', url)

start = time.time()
urls = {
    'www.baidu.com',
    'www.sogou.com',
}

stasks = []
for url in urls:
    c = request(url)
    task = asyncio.ensure_future(c)
    stasks.append(task)

loop = asyncio.get_event_loop()
# 需要将任务列表封装到wait中
loop.run_until_complete(asyncio.wait(stasks))

print(time.time()-start)
