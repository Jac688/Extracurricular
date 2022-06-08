# Programmer: Jack
# Student ID: 1930026143
# Date: 2020/1/24
# Requirements:
import requests
from lxml import etree
headers = {
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:89.0) Gecko/20100101 Firefox/89.0'
}
url = 'https://www.pearvideo.com/'
page_text = requests.get(url = url, headers = headers).text
tree = etree.HTML(page_text)
li_list = tree.xpath('//ul[@class="vervideo-blist clearfix"]/li')
for li in li_list:
    detail = li.xpath('./div/a/@href')[0]
    detail_url = 'https://www.pearvideo.com/'+detail
    name = li.xpath('./div/a/div[2]/text()')[0]+'.mp4'
    print(name, detail_url)
    detail_text = requests.get(url=detail_url, headers=headers).text
    video_list = tree.xpath('//div[@id="JprismPlayer"]/video/@src')
    print(video_list)
# urls = []

# dic = {
#   'name' = name
#   'url'  = url
# }
# urls.append(dic)
# def get_video:
#   url = dic['url]
#   持久化储存
#
# 多线程处理
# pool = Pool(4)
# pool.map(get_video, urls）
# pool.close()
# pool.join()


