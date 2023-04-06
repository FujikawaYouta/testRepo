from PIL import Image
import os
import imageAugFunctions as iaf
if __name__ == '__main__':
    deviceClasses=['charger-samples','earphoneCharger-samples',
             'mobileBattery-samples','None-samples','smartphone-samples']
    for deviceClass in deviceClasses:
        path='D:\Grade II\Computer Vision\作业_源代码\imageSamples\\'+deviceClass
        filelist=os.listdir(path)

        path_all=[]
        for f in filelist:
            if f.endswith('.jpg'):
                path_all.append(os.path.join(path,f))
                
        pil_ims=[]
        for p in path_all:
            pil_ims.append(Image.open(p))
        print(len(pil_ims))
        counting=0
        savingPathRotation='.\imageAugmentedRotation\\'+deviceClass+'\\'
        savingPathGray='.\imageAugmentedGray\\'+deviceClass+'\\'
        savingPathFlipLR='.\imageAugmentedFlipLR\\'+deviceClass+'\\'
        savingPathFlipTB='.\imageAugmentedFlipTB\\'+deviceClass+'\\'

        for pilCurrent in pil_ims:
            iaf.Rotation(pilCurrent,counting,savingPathRotation,60)
            iaf.grayScaleConversion(pilCurrent,counting,savingPathGray)
            iaf.FlipLeftRight(pilCurrent,counting,savingPathFlipLR)
            iaf.FlipTopBottom(pilCurrent,counting,savingPathFlipTB)
            counting=counting+1
