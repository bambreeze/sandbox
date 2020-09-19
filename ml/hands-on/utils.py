# To support both python 2 and python 3
from __future__ import division, print_function, unicode_literals

# Ignore useless warnings (see SciPy issue #5998)
import warnings
warnings.filterwarnings(action="ignore", message="^internal gelsd")

# Common imports
import os
import sys
import numpy as np
import pandas as pd
from pandas.plotting import scatter_matrix
import matplotlib as mpl
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

# Where to save the figures
PROJECT_ROOT_DIR = sys.path[0]
DATASET_PATH = os.path.join(PROJECT_ROOT_DIR, "datasets")
IMAGES_PATH = os.path.join(PROJECT_ROOT_DIR, "images")

# to make this notebook's output stable across runs
np.random.seed(42)

# To plot pretty figures
mpl.rc('axes', labelsize=14)
mpl.rc('xtick', labelsize=12)
mpl.rc('ytick', labelsize=12)

def save_fig(fig_id, sub_dir=".", tight_layout=True, fig_extension="png", resolution=300):
    os.makedirs(os.path.join(IMAGES_PATH, sub_dir), exist_ok=True)
    path = os.path.join(os.path.join(IMAGES_PATH, sub_dir), fig_id + "." + fig_extension)
    print("Saving figure", fig_id)
    if tight_layout:
        plt.tight_layout()
    plt.savefig(path, format=fig_extension, dpi=resolution)
