import pytest
import allure

def func(x):
    return x + 1

@allure.feature('sample_func')
@allure.story('sample_simple')
def test_answer():
    assert func(3) == 5

@allure.feature('sample_func')
@allure.story('sample_simple')
def test_answer2():
    assert func(5) == 6
    
def test_answer3():
    assert func(6) == 7
