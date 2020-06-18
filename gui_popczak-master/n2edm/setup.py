import setuptools

with open("README.md", "r") as fh:
    long_description = fh.read()

setuptools.setup(
    name="n2edm",
    version="1.0.2",
    author="Arkadiusz Popczak",
    author_email="arepop@arepop.com",
    description="Package created for n2EDM experiment to schedule mesurementr.",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://gitlab.com/n2edm/gui_popczak",
    packages=['n2edm'],
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
    python_requires='>=3.6',
    install_requires=["pyqt5 <= 5.12",
                      "matplotlib",
                      "libconf"],
)
