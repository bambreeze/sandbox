#!/usr/bin/env python3

import cv2
import numpy as np
import utils

# VConvolutionFilter 表示一般的滤波器
class VConvolutionFilter(object):
    """A filter that applies a convolution to V(or all of BGR)."""

    def __init__(self, kernel):
        self._kernel = kernel

    def apply(self, src, dst):
        """Apply the filter with a BGR or gray source/destination."""
        cv2.filter2D(src, -1, self._kernel, dst)

# SharpenFilter 表示特定的锐化滤波器
class SharpenFilter(VConvolutionFilter):
    """A sharpen filter with a 1-pixel radius."""
    def __init__(self):
        kernel = np.array([[-1, -1, -1],
                              [-1, 9, -1],
                              [-1, -1, -1]])
        VConvolutionFilter.__init__(self, kernel)

# 边缘检测滤波器
class FindEdgesFilter(VConvolutionFilter):
    """A edge-finding filter with a 1-pixel radius."""
    def __init__(self):
        kernel = np.array([[-1, -1, -1],
                              [-1, 8, -1],
                              [-1, -1, -1]])
        VConvolutionFilter.__init__(self, kernel)

# 邻近平均滤波器
class BlurFilter(VConvolutionFilter):
    """A edge-finding filter with a 1-pixel radius."""
    def __init__(self):
        kernel = np.array([[0.04, 0.04, 0.04, 0.04, 0.04],
                              [0.04, 0.04, 0.04, 0.04, 0.04],
                              [0.04, 0.04, 0.04, 0.04, 0.04],
                              [0.04, 0.04, 0.04, 0.04, 0.04],
                              [0.04, 0.04, 0.04, 0.04, 0.04]])
        VConvolutionFilter.__init__(self, kernel)

class EmbossFilter(VConvolutionFilter):
    """A edge-finding filter with a 1-pixel radius."""
    def __init__(self):
        kernel = np.array([[-2, -1, 0],
                              [-1, 1, 1],
                              [0, 1, 2]])
        VConvolutionFilter.__init__(self, kernel)

def  strokeEdges(src, dst, blurKsize=7, edgeKsize=5):
    '''
    该函数实现性能更好的边缘检测
    
    这里使用medianBlur()作为模糊函数，使用Laplacian()作为边缘检测函数。在使用medianBlur()之后，
    需要将图像从BGR色彩空间转换为灰度色彩空间。在得到Laplacian()函数结果之后，需要将图像转换为
    黑色边缘和白色背景(之前是白色边缘黑色背景)。然后将其归一化，并乘以源图像以便能将边缘变黑。
    
    args:
        src：源图像数据 BGR色彩空间       
        blurKsize：模糊滤波卷积核的宽和高  小于3，不进行模糊处理
        edgeKsize：边缘检测卷积核的宽和高

　　return:
　　　　 dst：目标图像数据 灰度色彩空间
    '''
    if blurKsize >= 3:
        #先模糊处理
        blurredSrc = cv2.medianBlur(src,blurKsize)
        #BGR格式转化为灰度格式
        graySrc = cv2.cvtColor(blurredSrc,cv2.COLOR_BGR2GRAY)
    else:
        graySrc = cv2.cvtColor(src,cv2.COLOR_BGR2GRAY)
        
    #边缘检测 对灰度图像检测效果更好
    cv2.Laplacian(graySrc,cv2.CV_8U,graySrc,ksize = edgeKsize)
    
    #颜色反向处理 并归一化
    normalizedInverseAlpha = (1.0/255)*(255 - graySrc)
    
    #通道分离 B,G,R 单通道图像
    channels = cv2.split(src)
    
    #计算后的结果分别与每个通道相乘
    for channel in channels:
        #这里是点乘，即对应元素相乘
        channel[:] = channel * normalizedInverseAlpha
            
    #通道合并(只能合并多个单通道成为多通道)
    cv2.merge(channels, dst)
