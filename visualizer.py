import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("output.csv")

df.plot(x="time", y=["position", "velocity", "acceleration"])
plt.title("Rocket Launch Simulation")
plt.xlabel("Time (s)")
plt.ylabel("Value")
plt.grid(True)
plt.show()
