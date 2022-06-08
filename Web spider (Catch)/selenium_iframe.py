# Programmer: Jack
# Student ID: 1930026143
# Date: 2020/1/24
# Requirements:
from selenium import webdriver
from time import sleep
from selenium.webdriver import ActionChains

bro = webdriver.Firefox(executable_path='./geckodriver.exe')
bro.get('http://www.runoob.com/try/try.php?filename=jqueryui-api-droppable')

# 如果的标签存在于iframe标签中，泽必须通过一下操定位
bro.switch_to.frame('iframeResult') # 切换标签定位的作用域
div = bro.find_element_by_id('draggable')

print(div)

# 动作链
action = ActionChains(bro)
action.click_and_hold(div) # 按住鼠标
for i in range(5):
    action.move_by_offset(17, 0).perform()
    sleep(0.5)

action.release()
bro.quit()