How to install & run Pytest
===========================
$ pip3 install -U pytest
$ pip3 install pytest-html
$ pip3 install pytest-xdist
$ pytest --version

$ pytest
$ pytest test_sample2.py 

$ pytest -q
$ pytest -v

$ pytest -k greate
$ pytest -m others -v

$ pytest -n 3
$ pytest test_failure.py -v --maxfail=1
$ pytest test_failure.py -v --maxfail=2
$ pytest test_failure.py -v --maxfail=3

$ pytest --junitxml="result.xml"
$ pytest --html="report.html"

How to generate html report with Allure
=======================================
$ pip install allure-pytest
$ brew install allure

$ pytest --alluredir ./allure-results/
$ allure generate ./allure-results/ -o ./allure-reports/ --clean
$ allure open ./allure-reports/

Example
=======
$ pytest --alluredir ./allure-results/; cp -r ./allure-reports/history/ ./allure-results/history; allure generate ./allure-results/ -o ./allure-reports/ --clean; allure open allure-reports/





