import plotly.graph_objects as go
import pandas as pd
form datetime import datetime

df = pd.read_scv('https://raw.githubusercontent.com/plotly/datasets/master/finance-charts-apple.csv')
fig = go.Fegure(data = [go.Candlestick(x = df['DATA'], open = df['AAPL.Open'], high = df['AAPL.High'], low = df['AAPL.Low'], close = df['AAPL.Close'])])
fig.show
