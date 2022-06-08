# Programmer: Jack
# Student ID: 1930026143
# Date: 2020/1/24
# Requirements:

import requests
import json

if __name__ == '__main__':
    url = 'https://movie.douban.com/j/search_subjects'
    headers = {
        'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:89.0) Gecko/20100101 Firefox/89.0'
    }
    # 得到参数
    param = {
        'type': 'movie',
        'tag': '热门',
        'sort': 'recommend',
        'page_limit': '20',
        'page_start': '80'
    }
    request = requests.get(url=url, headers=headers, params=param)
    list_data = request.json()

    fp = open('./douban.json', 'w', encoding='utf-8')
    json.dump(list_data, fp=fp, ensure_ascii=False)
    print('Success')