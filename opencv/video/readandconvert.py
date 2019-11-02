#!/usr/bin/env python3

import cv2

videoCapture = cv2.VideoCapture('myvideo.avi')
fps = videoCapture.get(cv2.CAP_PROP_FPS)
size = (int(videoCapture.get(cv2.CAP_PROP_FRAME_WIDTH)), int(videoCapture.get(cv2.CAP_PROP_FRAME_HEIGHT)))
videoWriter = cv2.VideoWriter('MyOutputVid.avi', cv2.VideoWriter_fourcc('I', '4', '2', '0'), fps, size)
success, frame = videoCapture.read()
while success:  # 循环直到所有帧结束
    videoWriter.write(frame)
    success, frame = videoCapture.read()
