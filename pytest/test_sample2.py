import pytest
import allure

@allure.feature('sample_test_class')
class TestClass:  
    @allure.story('sample_test_one')
    def test_one(self):  
        x = "this"  
        assert 'h' in x  
  
    @allure.story('sample_test_two')
    def test_two(self):  
        x = "hello"  
        assert hasattr(x, 'check')

    def test_three(self):  
        x = "hello"  
        assert hasattr(x, 'hello, world')
