import pandas as pd
import matplotlib.pyplot as plt

# Load CSV data
df = pd.read_csv("output.csv")

# Plot 1: Rocket Motion (position, velocity, acceleration)
fig1, ax1 = plt.subplots(figsize=(10, 6))
df.plot(x="time", y=["position", "velocity", "acceleration"], ax=ax1)
ax1.set_title("Rocket Motion Over Time")
ax1.set_xlabel("Time (s)")
ax1.set_ylabel("Value")
ax1.grid(True)
fig1.tight_layout()
fig1.savefig("motion_plot.png")  # Save for README

# Plot 2: Thrust vs Fuel Mass
fig2, ax2 = plt.subplots(figsize=(10, 6))
ax2.plot(df["time"], df["thrust"], label="Thrust (N)", color="red")
ax2.set_ylabel("Thrust (N)", color="red")
ax2.tick_params(axis='y', labelcolor="red")
ax2.grid(True)

# Fuel mass on second Y axis
ax3 = ax2.twinx()
ax3.plot(df["time"], df["fuel_mass"], label="Fuel Mass (kg)", color="green")
ax3.set_ylabel("Fuel Mass (kg)", color="green")
ax3.tick_params(axis='y', labelcolor="green")

ax2.set_title("Thrust and Fuel Mass Over Time")
ax2.set_xlabel("Time (s)")
fig2.tight_layout()
fig2.savefig("thrust_fuel_plot.png")  # Save for README
