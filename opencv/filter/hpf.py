#!/usr/bin/env python3

import cv2
import numpy as np
from scipy import ndimage

kernal_3x3 = np.array([[-1, -1, -1],
                       [-1, 8, -1],
                       [-1, -1, -1]])
kernal_5x5 = np.array([[-1, -1, -1, -1, -1],
                       [-1, 1, 2, 1, -1],
                       [-1, 2, 4, 2, -1],
                       [-1, 1, 2, 1, -1],
                       [-1, -1, -1, -1,-1]])

# 使用函数cv2.imread() 读入图像。这幅图像应该在此程序的工作路径，或者给函数提供完整路径，第二个参数是要告诉函数应该如何读取这幅图片。
#    • cv2.IMREAD_COLOR：读入一副彩色图像。图像的透明度会被忽略，这是默认参数。
#    • cv2.IMREAD_GRAYSCALE：以灰度模式读入图像
img = cv2.imread('lena.jpg',0)       # 注：此处后面要加上0，表示已灰度模式读入图像
k3 = ndimage.convolve(img, kernal_3x3)  # 注：使用ndimage.convolve()时，滤波核的维度应与原始图像的维度相同，故此采用灰度图
k5 = ndimage.convolve(img, kernal_5x5)

blurred = cv2.GaussianBlur(img, (11, 11), 0)
g_hpf = img - blurred
cv2.imshow("image", img)
cv2.imshow("3x3", k3)
cv2.imshow("5x5", k5)
cv2.imshow("g_hpf", g_hpf)
cv2.waitKey()
cv2.destroyAllWindows()
