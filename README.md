adaline-intro
=============

Assignment:
-----------

> Use the data set at http://archive.ics.uci.edu/ml/datasets/Concrete+Compressive+Strength 
to demonstrate the adaptive linear element’s use in multivariate regression. 
You should generate a learning curve (error vs. iterations).  Use 80% of the 
data set for training, and 20% for testing.  Show the error of the 
generalization results as well (after training, see how well it does on the 
test data.)  Use online learning.

The Data
--------
The data is in a tab-delimited text document exported from the Excel sheet 
provided at the link above. I split it into a learning set and a test set.

The first eight columns are input and the last one is output. I am to write an 
adaline to learn this data and then output the error vs iteration graph.

Background
----------
The data set is analyzing components of concrete vs its compression strength.
The columns are:

1. Cement (kg per m^3)
2. Blast Furnace Slag (kg per m^3)
3. Fly Ash (kg per m^3)
4. Water (kg per m^3)
5. Superplasticizer (kg per m^3)
6. Coarse Aggregate (kg per m^3)
7. Fine Aggregate (kg per m^3)
8. Age (days)

Result: Concrete compressive strength (MPa)