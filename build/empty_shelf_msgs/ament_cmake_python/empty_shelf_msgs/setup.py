from setuptools import find_packages
from setuptools import setup

setup(
    name='empty_shelf_msgs',
    version='0.1.0',
    packages=find_packages(
        include=('empty_shelf_msgs', 'empty_shelf_msgs.*')),
)
