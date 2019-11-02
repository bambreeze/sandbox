#!/usr/bin/env python3

import cv2
import numpy as np
import os

# 创建一个120000个随机字节的数组
randomByteArray = bytearray(os.urandom(120000))  #os.urandom(n) 返回n个随机byte值的string，作为加密使用
flatNumpyArray = np.array(randomByteArray)

# 将数组转换为400 x 300的灰度图像
garyImage = flatNumpyArray.reshape(300, 400)
cv2.imwrite('randomGary.png', garyImage)

# 将数组转换为400 x 300的彩色图像
bgrImage = flatNumpyArray.reshape(100, 400, 3)
cv2.imwrite('randomColor.png', bgrImage)
