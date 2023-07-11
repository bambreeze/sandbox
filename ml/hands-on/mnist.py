from sklearn.linear_model import SGDClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import cross_val_score
from sklearn.model_selection import cross_val_predict
from sklearn.metrics import confusion_matrix
from sklearn.metrics import precision_score, recall_score
from sklearn.metrics import f1_score
from sklearn.metrics import roc_curve
from sklearn.metrics import roc_auc_score
from sklearn.preprocessing import StandardScaler
from utils import *

#def sort_by_target(mnist):
#    reorder_train = np.array(sorted([(target, i) for i, target in enumerate(mnist.target[:60000])]))[:, 1]
#    reorder_test = np.array(sorted([(target, i) for i, target in enumerate(mnist.target[60000:])]))[:, 1]
#    mnist.data[:60000] = mnist.data[reorder_train]
#    mnist.target[:60000] = mnist.target[reorder_train]
#    mnist.data[60000:] = mnist.data[reorder_test + 60000]
#    mnist.target[60000:] = mnist.target[reorder_test + 60000]

#try:
#    from sklearn.datasets import fetch_openml
#    mnist = fetch_openml('mnist_784', version=1, cache=True)
#    mnist.target = mnist.target.astype(np.int8) # fetch_openml() returns targets as strings
#    sort_by_target(mnist) # fetch_openml() returns an unsorted dataset
#except ImportError:
#    from sklearn.datasets import fetch_mldata
#    mnist = fetch_mldata('MNIST original')

###############################################################################
# Load the data
###############################################################################
mnist_path = os.path.join(PROJECT_ROOT_DIR, "datasets", "mnist", "mnist_784.csv")
mnist = pd.read_csv(mnist_path)
print(mnist.info())
print(mnist.head())
print(mnist.describe())

X = mnist.drop("class", axis=1) # drop labels for training set
X = X.values # pd dataframe -> numpy array
print(X.shape)

y = mnist["class"].copy()
y = y.values # pd dataframe -> numpy array
print(y.shape)

X_train, X_test, y_train, y_test = X[:60000], X[60000:], y[:60000], y[60000:]
shuffle_index = np.random.permutation(60000)
X_train, y_train = X_train[shuffle_index], y_train[shuffle_index]

###############################################################################
# Visualize the data
###############################################################################
some_digit = X[36000]
some_digit_image = some_digit.reshape(28, 28)
plt.imshow(some_digit_image, cmap = mpl.cm.binary,
           interpolation="nearest")
plt.axis("off")
save_fig("some_digit_plot", "mnist")
#plt.show()
print(y[36000])

###############################################################################
# Prepare the data
###############################################################################
# ...

###############################################################################
# Select and train a model - Binary classifier
###############################################################################
y_train_5 = (y_train == 5)
y_test_5 = (y_test == 5)
sgd_clf = SGDClassifier(max_iter=5, tol=-np.infty, random_state=42)

# Train the model
sgd_clf.fit(X_train, y_train_5)

# Make a prediction
print(sgd_clf.predict([some_digit]))

# performance measure - Measuring Accuracy Using K-fold cross-validation
print(cross_val_score(sgd_clf, X_train, y_train_5, cv=3, scoring="accuracy"))

# performance measure - Precision and Recall
y_train_pred = cross_val_predict(sgd_clf, X_train, y_train_5, cv=3)
print(precision_score(y_train_5, y_train_pred))
print(recall_score(y_train_5, y_train_pred))
print(f1_score(y_train_5, y_train_pred))

# performance measure - Confusion Matrix
print(confusion_matrix(y_train_5, y_train_pred))

# performance measure - ROC curves
y_scores = cross_val_predict(sgd_clf, X_train, y_train_5, cv=3,
                             method="decision_function")
print(roc_auc_score(y_train_5, y_scores))
fpr, tpr, thresholds = roc_curve(y_train_5, y_scores)
plot_roc_curve(fpr, tpr)
save_fig("roc_curve_plot", "mnist")
#plt.show()

print(X_train, y_train_5, y_train_pred)

###############################################################################
# Select and train a model - Multiclass classification
###############################################################################
# Select the model
sgd_clf = SGDClassifier(max_iter=5, tol=-np.infty, random_state=42)
forest_clf = RandomForestClassifier(n_estimators=10, random_state=42)

# Train the model
sgd_clf.fit(X_train, y_train)
forest_clf.fit(X_train, y_train)

# Make a prediction
print(sgd_clf.predict([some_digit]))
print(forest_clf.predict([some_digit]))

# Cross-Validation
print(cross_val_score(sgd_clf, X_train, y_train, cv=3, scoring="accuracy"))
print(cross_val_score(forest_clf, X_train, y_train, cv=3, scoring="accuracy"))

scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train.astype(np.float64))
print(cross_val_score(sgd_clf, X_train_scaled, y_train, cv=3, scoring="accuracy"))

# Confusion Matrix
y_train_pred = cross_val_predict(sgd_clf, X_train_scaled, y_train, cv=3)
conf_mx = confusion_matrix(y_train, y_train_pred)
print(conf_mx)

plt.matshow(conf_mx, cmap=plt.cm.gray)
save_fig("confusion_matrix_plot", "mnist", tight_layout=False)
#plt.show()

row_sums = conf_mx.sum(axis=1, keepdims=True)
norm_conf_mx = conf_mx / row_sums
np.fill_diagonal(norm_conf_mx, 0)
plt.matshow(norm_conf_mx, cmap=plt.cm.gray)
save_fig("confusion_matrix_errors_plot", "mnist", tight_layout=False)
#plt.show()

plot_confusion_matrix(norm_conf_mx)
save_fig("confusion_matrix_errors_plot_color", "mnist", tight_layout=False)