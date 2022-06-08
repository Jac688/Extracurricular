# Programmer: Jack
# Student ID: 1930026143
# Date: 2020/1/24
# Requirements:

# UA伪装——UA检测
import requests
import json
if __name__ == "__main__":
    url = 'https://fanyi.baidu.com/sug'
    # UA伪装
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:89.0) Gecko/20100101 Firefox/89.0'
    }
    word = input('enter a word: ')
    data = {
        'kw':word
    }
    # 响应数据为json, 使用.json()
    request = requests.post(url = url, data=data, headers=headers)
    dic_obj = request.json()

    filename = word+'.json'
    fp = open(filename , 'w', encoding='utf-8')
    json.dump(dic_obj, fp=fp, ensure_ascii=False)

    print("success!")