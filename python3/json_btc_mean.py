#!/usr/bin/env python3

import json
import pygal
import math
from itertools import groupby

filename = 'btc_close_2017.json'
with open(filename) as f:
    btc_data = json.load(f)

dates = []
months = []
weeks = []
weekdays = []
close = []
for btc_dict in btc_data:
    dates.append(btc_dict['date'])
    months.append(int(btc_dict['month']))
    weeks.append(int(btc_dict['week']))
    weekdays.append(btc_dict['weekday'])
    close.append(int(float(btc_dict['close'])))

def draw_line(x_data, y_data, title, y_legend):
    xy_map = []
    for x, y in groupby(sorted(zip(x_data, y_data)), key=lambda _: _[0]):
        y_list = [v for _, v in y]
        xy_map.append([x, sum(y_list) / len(y_list)])
    x_unique, y_mean = [*zip(*xy_map)]

    line_chart = pygal.Line()
    line_chart.title = title

    # FIXME
    new_x_unique = []
    for x in x_unique:
        new_x_unique.append(str(x))
    line_chart.x_labels = new_x_unique

    line_chart.add(y_legend, y_mean)
    line_chart.render_to_file(title+'.svg')
    return line_chart

idx_month = dates.index('2017-12-01')
line_chart_month = draw_line(months[:idx_month], close[:idx_month], 'Monthly Close Price Chart', 'Monthly Mean')
line_chart_month

idx_week = dates.index('2017-12-11')
line_chart_week = draw_line(weeks[1:idx_week], close[1:idx_week], 'Weekly Close Price Chart', 'Weekly Mean')
line_chart_week

idx_week = dates.index('2017-12-11')
wd = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday']
weekdays_int = [wd.index(w) + 1 for w in weekdays[1:idx_week]]
line_chart_weekday = draw_line(weekdays_int, close[1:idx_week], 'Weekday Close Price Chart', 'Weekday Mean')
line_chart_weekday

