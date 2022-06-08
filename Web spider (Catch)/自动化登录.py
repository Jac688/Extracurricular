# Programmer: Jack
# Student ID: 1930026143
# Date: 2020/1/24
# Requirements:
from time import sleep
from selenium import webdriver

bro = webdriver.Firefox(executable_path='./geckodriver.exe')
bro.get('https://qzone.qq.com/')
bro.switch_to.frame('login_frame')

a_tag= bro.find_element_by_id('switcher_plogin')
a_tag.click()

username = bro.find_element_by_id('u')
password = bro.find_element_by_id('p')

username.send_keys('564927768')
password.send_keys('Xsj011014')

btn = bro.find_element_by_id('login_button')
btn.click()
sleep(10)
