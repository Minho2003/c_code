# plot_graph.py
import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("/Users/Minho/Desktop/coding/input_csv.csv")
plt.plot(df['x'], df['y'])
plt.title("Simple Line Graph")
plt.savefig("/Users/Minho/Desktop/coding/output.png")
plt.show()

