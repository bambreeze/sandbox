#!/usr/bin/env python3

import cv2
import numpy as np

img = cv2.imread('lena.jpg')
roi = img[0:10, 0:50]
img[10:20, 50:100] = roi # 此处需考虑所用图像的尺寸，不能超过，并确保两个区域的大小一样
cv2.imshow('my image', img)
cv2.waitKey()
