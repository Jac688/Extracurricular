# Programmer: Jack
# Student ID: 1930026143
# Date: 2020/1/24
# Requirements:

import requests
if __name__ == "__main__":
    # 指定url
    url = 'https://www.sogou.com/'
    # 发送请求
    request = requests.get(url = url)
    # 中文解码: page_text = request.text.encode('ISO-8859-1')
    page_text = request.text.encode('ISO-8859-1')
    print(page_text)
    #写道一个当前目录的新的html
    with open('./sogou.html', 'w', encoding='utf-8') as fp:
        fp.write(page_text)
