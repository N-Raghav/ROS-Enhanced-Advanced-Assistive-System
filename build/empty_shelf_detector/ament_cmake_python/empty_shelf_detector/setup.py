from setuptools import find_packages
from setuptools import setup

setup(
    name='empty_shelf_detector',
    version='0.1.0',
    packages=find_packages(
        include=('empty_shelf_detector', 'empty_shelf_detector.*')),
)
