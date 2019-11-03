#!/usr/bin/env python3

import cv2
import numpy as np
from matplotlib import pyplot as plt

img = np.zeros((512,512,3),np.uint8)  #生成一个空彩色图像
cv2.rectangle(img,(20,20),(411,411),(55,255,155),5)
plt.imshow(img,'brg')
plt.show()
