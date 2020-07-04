import pytest
import allure

@allure.feature('sample_class')
class TestClass:  
    name = "Jack"
    age  = 8
    addr = "CA"

    @allure.story('sample_class_char')
    def test_char_one(self):  
        x = "this"  
        assert 'h' in x  
  
    @allure.story('sample_class_char')
    def test_char_two(self):  
        x = "this"  
        assert 'u' in x  
  
    @allure.story('sample_class_attr')
    def test_attr_name(self):
        x = "name"  
        assert hasattr(self, x)

    @allure.story('sample_class_attr')
    def test_attr_age(self):
        x = "age"
        assert hasattr(self, x)

    @allure.story('sample_class_attr')
    def test_attr_school(self):
        x = "school"
        assert hasattr(self, x)

    @allure.story('sample_class_jack')
    def test_jack_name(self):
        assert self.name == "Jack"

    @allure.story('sample_class_jack')
    def test_jack_age(self):
        assert self.age == 8
