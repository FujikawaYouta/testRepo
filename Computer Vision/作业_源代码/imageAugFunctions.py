from PIL import Image
import os
def Rotation(pilCurrent,index,path,angel):
    savingPath=path+(str)(index)+'.jpg'
    pilRotate=pilCurrent.rotate(angel)
    pilRotate.save(savingPath)
def grayScaleConversion(pilCurrent,index,path):
    savingPath=path+(str)(index)+'.jpg'
    pilRotate=pilCurrent.convert('L')
    pilRotate.save(savingPath)
def FlipLeftRight(pilCurrent,index,path):
    savingPath=path+(str)(index)+'.jpg'
    pilRotate=pilCurrent.transpose(Image.FLIP_LEFT_RIGHT)
    pilRotate.save(savingPath)
def FlipTopBottom(pilCurrent,index,path):
    savingPath=path+(str)(index)+'.jpg'
    pilRotate=pilCurrent.transpose(Image.FLIP_TOP_BOTTOM)
    pilRotate.save(savingPath)