#!/usr/bin/env python3

import cv2
import numpy as np

img = cv2.imread('lena.jpg')
img[:, :, 1] = 0
cv2.imshow('my image', img)
cv2.waitKey()
