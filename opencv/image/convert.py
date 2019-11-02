#!/usr/bin/env python3

import cv2
import numpy as np

# convert to different image format
image = cv2.imread('lena.jpg')            # 将‘flower.jpg’的图片与.py文件放在同一目录下，或者使用绝对路径
cv2.imwrite('lena.png',image)

# read as gray image
garyImage = cv2.imread('lena.jpg', cv2.IMREAD_GRAYSCALE)
cv2.imwrite('lena_gray.png', garyImage)
