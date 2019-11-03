#!/usr/bin/env python3

import cv2
import numpy as np

img = np.zeros((200, 200), dtype = np.uint8)   # 创建一个200x200大小的黑色空白图像，
img[50:150, 50:150] = 255                      # 在图像的中央放置一个白色方块

ret, thresh = cv2.threshold(img, 127, 255, 0)  #对图像进行二值化操作
contours, hierarchy = cv2.findContours(thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)  # 寻找轮廓
color = cv2.cvtColor(img, cv2.COLOR_GRAY2BGR)  # 颜色空间转换
img = cv2.drawContours(color, contours, -1, (0, 255, 0), 2)  # 画出轮廓，-1,表示所有轮廓，画笔颜色为(0, 255, 0)，即Green，粗细为3
cv2.imshow("contours",color)
cv2.waitKey()
cv2.destroyAllWindows()
