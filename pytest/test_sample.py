import pytest
import allure

@allure.story('sample_fun')
def func(x):
    return x + 1

@allure.story('sample_answer')
def test_answer():
    assert func(3) == 5

def test_answer2():
    assert func(5) == 6
    
def test_answer3():
    assert func(6) == 7
