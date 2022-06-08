# Programmer: Jack
# Student ID: 1930026143
# Date: 2020/1/24
# Requirements:
from time import sleep
from selenium import webdriver

bro = webdriver.Firefox(executable_path='./geckodriver.exe')

bro.get('http://www.taobao.com/')
# 定位搜索框的标签
search_input = bro.find_element_by_id('q')
# 标签交互
search_input.send_keys('Iphone')

# 执行js代码
bro.execute_script('window.scrollTo(0, document.body.scrollHeight)') # 鼠标滚轮
sleep(2)

search_bottom = bro.find_element_by_class_name('btn-search')
search_bottom.click()

sleep(5)

bro.get('http://www.baidu.com/')
# 回退
bro.back()
sleep(2)
bro.forward()

bro.quit()



