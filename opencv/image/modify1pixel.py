#!/usr/bin/env python3

import cv2
import numpy as np

img = cv2.imread('lena.jpg')
img[30,30] = [255, 255, 255]
cv2.imshow('my image', img)
cv2.waitKey()
