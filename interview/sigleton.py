#!/bin/env python3
import sys, os
import json

class Singleton(object):
    def __init__(self, cls):
        print("in Singleton init()...")
        self._cls = cls
        self._instance = {}

    def __call__(self, *args):
        print("in Singleton call()...")
        if self._cls not in self._instance:
            self._instance[self._cls] = self._cls(*args)
        return self._instance[self._cls]

@Singleton
class Config(object):
    def __init__(self):
        print("in Config init()...")
        with open('config.json','r+') as f:
            self.cfg = json.load(f)

    def get(self, name):
        print("in Config get()...")
        return self.cfg.get(name)

if __name__ == '__main__':
    cfg1 = Config()
    print(cfg1.get('version'))
    print(cfg1.get('name'))
    cfg2 = Config()
    print(cfg2.get('version'))