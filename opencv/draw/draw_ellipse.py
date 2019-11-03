#!/usr/bin/env python3

import cv2
import numpy as np
from matplotlib import pyplot as plt

img = np.zeros((512,512,3),np.uint8)#生成一个空彩色图像
cv2.ellipse(img,(256,256),(150,100),0,0,180,250,-1)
#注意最后一个参数-1，表示对图像进行填充，默认是不填充的，如果去掉，只有椭圆轮廓了
plt.imshow(img,'brg')
plt.show()
