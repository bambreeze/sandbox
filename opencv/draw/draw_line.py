#!/usr/bin/env python3

import cv2
import numpy as np
from matplotlib import pyplot as plt

img = np.zeros((512,512),np.uint8)#生成一个空灰度图像
cv2.line(img,(0,0),(511,511),255,5)
plt.imshow(img,'gray')
plt.show()
