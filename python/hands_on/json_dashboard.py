#!/usr/bin/env python3

import json
import pygal
import math
from itertools import groupby

with open('btc_price_dashboard.html', 'w', encoding='utf8') as html_file:
    html_file.write(
            '<html><head><title>BTC Price Dashboard</title><meta charset="utf-8"></head><body>\n')
    for svg in [
            'btc_price.svg',
            'btc_log_price.svg',
            'Monthly Close Price Chart.svg',
            'Weekly Close Price Chart.svg',
            'Weekday Close Price Chart.svg'
    ]:
        html_file.write('   <object type="image/svg+xml" data="{0}" height=500></object>\n'.format(svg))
    html_file.write('</body></html>')
