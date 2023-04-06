from PIL import Image, ImageDraw, ImageFont
#打开图片
img = Image.open("./suzume no tojimari.bmp")
#调用画图模块
draw = ImageDraw.Draw(img)
#设置字体
tfont = ImageFont.truetype("./league-gothic.ttf",24)
#添加文字
'''
    参数一：文字在图片中的位置：(x,y)
    参数二：文字内容
    参数三：字体颜色
    参数四：字体类型
'''
draw.text((50,30),"lly whb",fill="green",font=tfont)
#保存图片
img.save("./output_test/word_addition.bmp")
#显示图片
img.show()