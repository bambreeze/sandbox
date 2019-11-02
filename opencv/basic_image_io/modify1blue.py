#!/usr/bin/env python3

import cv2
import numpy as np

img = cv2.imread('lena.jpg')
print(img.item(30, 30, 0))  # 打印当前坐标点的蓝色值
img.itemset((30, 30, 0), 255)
print(img.item(150, 120, 0))
